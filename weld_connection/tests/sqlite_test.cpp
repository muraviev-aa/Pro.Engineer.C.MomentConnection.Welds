#include <gtest/gtest.h>
#include <windows.h>
#include <sqlite3.h>
#include <iostream>

TEST(SQLiteTest, CanOpenDatabaseInResources)
{
    sqlite3 *db;
    const char *db_path = RESOURCE_PATH "/test.db";
    int rc = sqlite3_open(db_path, &db);
    EXPECT_EQ(rc, SQLITE_OK) << "Failed to open database at " << db_path;

    if (rc == SQLITE_OK)
    {
        sqlite3_close(db);
    }
}

TEST(SQLiteTest, CreateInsertSelect)
{
    sqlite3 *db;
    char *errMsg = nullptr;
    int rc;

    // Открываем базу данных
    rc = sqlite3_open(RESOURCE_PATH "/test.db", &db);
    ASSERT_EQ(rc, SQLITE_OK) << "Failed to open database";

    // Создаем таблицу
    const char *createTableSQL = "CREATE TABLE IF NOT EXISTS test_table (id INTEGER PRIMARY KEY, value TEXT);";
    rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
    ASSERT_EQ(rc, SQLITE_OK) << "Failed to create table: " << errMsg;
    sqlite3_free(errMsg);

    // Вставляем данные
    const char *insertSQL = "INSERT INTO test_table (value) VALUES ('Hello'), ('World');";
    rc = sqlite3_exec(db, insertSQL, nullptr, nullptr, &errMsg);
    ASSERT_EQ(rc, SQLITE_OK) << "Failed to insert data: " << errMsg;
    sqlite3_free(errMsg);

    // Читаем данные
    const char *selectSQL = "SELECT value FROM test_table WHERE id=1;";
    std::string value;
    auto callback = [](void *data, int argc, char **argv, char **) -> int {
        if (argc > 0 && argv[0])
        {
            *(static_cast<std::string *>(data)) = argv[0];
        }
        return 0;
    };

    value.clear();
    rc = sqlite3_exec(db, selectSQL, callback, &value, &errMsg);
    ASSERT_EQ(rc, SQLITE_OK) << "Failed to select data: " << errMsg;

    EXPECT_EQ(value, "Hello") << "Unexpected value retrieved";

    // Удаляем таблицу (опционально)
    const char *dropTableSQL = "DROP TABLE test_table;";
    rc = sqlite3_exec(db, dropTableSQL, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK)
    {
        sqlite3_free(errMsg);
        // Не критично для теста
    }

    // Закрываем базу данных
    rc = sqlite3_close(db);
    EXPECT_EQ(rc, SQLITE_OK) << "Failed to close database";
}