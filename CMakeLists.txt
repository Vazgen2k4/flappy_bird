cmake_minimum_required(VERSION 3.10)

# Укажите название вашего проекта
project(FlappyBird)


# Добавьте директорию с файлами raylib
set(CMAKE_CXX_STANDARD 14) # Убедитесь, что стандарт C++ 14 выбран
include_directories(${RAYLIB_PATH}/include)
link_directories(${RAYLIB_PATH}/lib)

# Найдите исходные файлы во всех подпапках
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

# Создайте исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})

# Линкуйте библиотеку raylib
target_link_libraries(${PROJECT_NAME} raylib)
