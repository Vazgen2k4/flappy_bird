cmake_minimum_required(VERSION 3.10)

# Укажите название вашего проекта
project(FlappyBird)

# Установите стандарт C++
set(CMAKE_CXX_STANDARD 14) 

# Добавьте директории с заголовочными файлами
include_directories(src/include ${RAYLIB_PATH}/include)
link_directories(${RAYLIB_PATH}/lib)

# Найдите исходные файлы во всех подпапках
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

# Создайте исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})

# Линкуйте библиотеку raylib
target_link_libraries(${PROJECT_NAME} raylib)
