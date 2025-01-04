cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0135 NEW)

project(FlappyBird)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Найти библиотеку raylib
find_package(raylib REQUIRED)

# Добавьте директории с заголовочными файлами
include_directories(src/include ${RAYLIB_PATH}/include)
link_directories(${RAYLIB_PATH}/lib)

# Собираем все файлы из src, исключая main.cpp
file(GLOB_RECURSE ALL_SOURCES "src/*.cpp" "src/*.h")
# Собираем тестовые файлы
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp" ${ALL_SOURCES})

list(FILTER APP_SOURCES INCLUDE REGEX ".*main\\.cpp$")
list(FILTER TEST_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Копируем ресурсы в директорию сборки
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Создаем основной исполняемый файл
add_executable(${PROJECT_NAME} ${ALL_SOURCES})
target_link_libraries(${PROJECT_NAME} raylib)

# Добавляем Google Test как внешнюю библиотеку
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.1.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Создаем таргет для тестов
set(TESTS_RUN_FILE_NAME ${PROJECT_NAME}Tests)

add_executable(${TESTS_RUN_FILE_NAME} ${TEST_SOURCES})
target_link_libraries(${TESTS_RUN_FILE_NAME} PRIVATE gtest gtest_main raylib)
add_test(NAME RunTests COMMAND ${TESTS_RUN_FILE_NAME})
