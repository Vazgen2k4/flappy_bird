cmake_minimum_required(VERSION 3.10)

project(FlappyBird)

set(CMAKE_CXX_STANDARD 14)
set(RAYLIB_PATH "V:/program/msys_64/mingw64/include/raylib")


# Добавьте директории с заголовочными файлами
include_directories(src/include ${RAYLIB_PATH}/include)
link_directories(${RAYLIB_PATH}/lib)

# Собираем все файлы из src, исключая main.cpp
file(GLOB_RECURSE ALL_SOURCES "src/*.cpp" "src/*.h")
list(FILTER ALL_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Собираем тестовые файлы
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

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
add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES} ${ALL_SOURCES})

# Линкуем с библиотеками
target_link_libraries(${PROJECT_NAME}_tests PRIVATE gtest gtest_main raylib)

# Добавьте тесты в очередь CTest
add_test(NAME RunTests COMMAND ${PROJECT_NAME}_tests)
