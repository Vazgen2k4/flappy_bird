cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0135 NEW)

project(FlappyBird)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Najít knihovnu raylib
find_package(raylib REQUIRED)

# Přidat adresáře s hlavičkovými soubory
include_directories(src/include ${RAYLIB_PATH}/include)
link_directories(${RAYLIB_PATH}/lib)

# Sestavit všechny soubory ze složky src kromě main.cpp
file(GLOB_RECURSE ALL_SOURCES "src/*.cpp" "src/*.h")
# Sestavit testovací soubory
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp" ${ALL_SOURCES})

list(FILTER APP_SOURCES INCLUDE REGEX ".*main\\.cpp$")
list(FILTER TEST_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Kopírovat zdroje do adresáře sestavení
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Vytvořit hlavní spustitelný soubor
add_executable(${PROJECT_NAME} ${ALL_SOURCES})
target_link_libraries(${PROJECT_NAME} raylib)

# Přidat Google Test jako externí knihovnu
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.1.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Vytvořit cíl pro testy
set(TESTS_RUN_FILE_NAME ${PROJECT_NAME}Tests)

add_executable(${TESTS_RUN_FILE_NAME} ${TEST_SOURCES})
target_link_libraries(${TESTS_RUN_FILE_NAME} PRIVATE gtest gtest_main raylib)
add_test(NAME RunTests COMMAND ${TESTS_RUN_FILE_NAME})
