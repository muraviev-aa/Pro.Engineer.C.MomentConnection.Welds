#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gtk/gtk.h>
#include <glib.h>
#include "temp_function.h"

class CssProviderMock
{
public:
    MOCK_METHOD(gboolean, load_from_path, (GtkCssProvider *, const gchar*, GError**), ());
    MOCK_METHOD(void, add_provider_for_screen, (GdkScreen *, GtkStyleProvider *, int), ());
};

class CssTest : public ::testing::Test
{
protected:
    GtkCssProvider *provider;
    GError *error;
    CssProviderInterface interface; // Интерфейс теперь является членом класса
    static CssProviderMock mock; // Сделаем mock статическим

    // Конструктор для инициализации полей
    CssTest() : provider(nullptr), error(nullptr), interface{} {}

    static gboolean LoadFromPath(GtkCssProvider *p, const gchar *path, GError **err)
    {
        return mock.load_from_path(p, path, err);
    }

    static void AddProviderForScreen(GdkScreen *screen, GtkStyleProvider *provider, int priority)
    {
        mock.add_provider_for_screen(screen, provider, priority);
    }

    void SetUp() override
    {
        gtk_init(nullptr, nullptr); // Инициализация GTK
        provider = gtk_css_provider_new();
        error = nullptr;

        // Настройка интерфейса с моками
        interface.load_from_path = LoadFromPath;
        interface.add_provider_for_screen = AddProviderForScreen;

        // Установка пользовательского обработчика логов
        g_log_set_handler(NULL,
                          static_cast<GLogLevelFlags>(G_LOG_LEVEL_WARNING | G_LOG_LEVEL_MESSAGE | G_LOG_LEVEL_CRITICAL),
                          [](const gchar *log_domain, GLogLevelFlags log_level,
                             const gchar *message, gpointer user_data) {
                              if (log_level == G_LOG_LEVEL_WARNING) {
                                  g_print("%s\n", message); // Печатаем только предупреждения
                              }
                          }, NULL);
    }

    void TearDown() override
    {
        g_object_unref(provider);
        if (error)
        {
            g_error_free(error);
            error = nullptr; // Убедитесь, что указатель обнуляется после освобождения памяти
        }
    }
};

// Определение статического члена
CssProviderMock CssTest::mock;

TEST_F(CssTest, LoadCssSuccessfully)
{
    EXPECT_CALL(mock, load_from_path(testing::_, testing::_, testing::_))
            .Times(1)
            .WillOnce(::testing::Return(TRUE));

    EXPECT_CALL(mock, add_provider_for_screen(testing::_, testing::_, testing::_))
            .Times(1);

    apply_css(&interface, provider, "resources/style.css", &error);

    ASSERT_EQ(error, nullptr);
}

// если функция apply_css успешно обрабатывает ошибку, то выводится сообщение о том,
// что загрузка CSS не удалась с текстом "Mocked error" --> тест работает правильно
// и ожидаемое поведение функции apply_css реализовано корректно
TEST_F(CssTest, LoadCssFails)
{
    EXPECT_CALL(mock, load_from_path(testing::_, testing::_, testing::_))
            .Times(1)
            .WillOnce(::testing::DoAll(
                    testing::SetArgPointee<2>(g_error_new(g_quark_from_string("test"), 0,
                                                          "Mocked error")),
                    ::testing::Return(FALSE)));

    EXPECT_CALL(mock, add_provider_for_screen(testing::_, testing::_, testing::_))
            .Times(0);

    GError *error = nullptr;

    apply_css(&interface, provider, "resources/style.css", &error);

    ASSERT_NE(error, nullptr);

    g_error_free(error);
}