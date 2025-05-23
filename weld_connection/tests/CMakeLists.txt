# Создаем цель для тестов
add_executable(weld_connection_tests
        fillet_welds_test.cpp
        groove_welds_test.cpp
        sqlite_test.cpp
        stress_test.cpp
        main_test.cpp
)

add_library(sqlite3 STATIC ../resources/sqlite/sqlite3.c)

# Связываем с gtest и библиотекой sqlite
target_link_libraries(weld_connection_tests PRIVATE gtest gtest_main sqlite3)

# Указываем include директории
target_include_directories(weld_connection_tests PRIVATE
        ../include
        ${gtest_SOURCE_DIR}/include
)

target_compile_definitions(weld_connection_tests PRIVATE RESOURCE_PATH="${RESOURCE_DIR}")

# Добавляем исходники из src, если нужно
target_sources(weld_connection_tests PRIVATE
        ../src/fillet_welds.c
        ../src/groove_welds.c
        ../src/stress.c)