cmake_minimum_required(VERSION 3.19)

cmake_policy(SET CMP0135 NEW)

project(Weld_connection)

# Добавляем GTK
set(CMAKE_C_STANDARD 11)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
pkg_check_modules(Cairo REQUIRED cairo)
pkg_check_modules(Pango REQUIRED pango)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
link_libraries(${GTK_LIBRARIES})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
#

include(FetchContent)

# Подключение googletest
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

# Путь к папке с исходниками SQLite
set(SQLITE_SRC_PATH "resources/sqlite")

# Создаем исполняемый файл
add_executable(weld_connection_app src/main.c
        ${SQLITE_SRC_PATH}/sqlite3.c)

get_filename_component(RESOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/resources" ABSOLUTE)
target_compile_definitions(weld_connection_app PRIVATE RESOURCE_PATH="${RESOURCE_DIR}")

target_include_directories(weld_connection_app PRIVATE include ${SQLITE_SRC_PATH})

target_sources(weld_connection_app PRIVATE
        ../src/fillet_welds.c
        ../src/groove_welds.c
        ../src/min_yield_strength_60.c
        ../src/stress.c)

add_subdirectory(tests)