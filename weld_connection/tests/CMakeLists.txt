# Создаем цель для тестов
add_executable(weld_connection_tests
        temp_function_test.cpp
        fillet_welds_test.cpp
        groove_welds_test.cpp
        sqlite_test.cpp
        stress_test.cpp
        min_yield_strength_test_60.cpp
        main_test.cpp
)

add_library(sqlite3 STATIC ../resources/sqlite/sqlite3.c)

# Связываем с gtest и библиотекой sqlite
target_link_libraries(weld_connection_tests PRIVATE gtest gmock gtest_main sqlite3)

# Указываем include директории
target_include_directories(weld_connection_tests PRIVATE
        ../include
        ${gtest_SOURCE_DIR}/include
)

# Определяем путь к ресурсам как макрос для использования в коде
target_compile_definitions(weld_connection_tests PRIVATE RESOURCE_PATH="${RESOURCE_DIR}")

# Добавляем исходники из src, если нужно
target_sources(weld_connection_tests PRIVATE
        ../src/temp_function.c
        ../src/fillet_welds.c
        ../src/groove_welds.c
        ../src/min_yield_strength_60.c
        ../src/stress.c)
