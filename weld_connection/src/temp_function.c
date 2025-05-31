#include "temp_function.h"

void apply_css(CssProviderInterface *interface, GtkCssProvider *provider, const gchar *cssPath, GError **error)
{
    // Проверяем, что интерфейс и провайдер не равны NULL
    if (interface == NULL || provider == NULL || cssPath == NULL) {
        if (error) {
            *error = g_error_new(g_quark_from_string("apply_css"), 0, "Invalid arguments provided to apply_css");
        }
        return;
    }

    // Попытка загрузки CSS
    if (!interface->load_from_path(provider, cssPath, error))
    {
        if (error && *error) // Проверяем, что error не nullptr и указывает на объект ошибки
        {
            g_warning("Failed to load CSS: %s", (*error)->message);
        }
        else
        {
            g_warning("Failed to load CSS: Unknown error");
        }
        return; // Выходим из функции после обработки ошибки
    }

    GdkScreen *screen = gdk_screen_get_default();
    if (GDK_IS_SCREEN(screen))
    {
        interface->add_provider_for_screen(screen,
                                           GTK_STYLE_PROVIDER(provider),
                                           GTK_STYLE_PROVIDER_PRIORITY_USER);
    }
    else
    {
        g_warning("Invalid GdkScreen");
    }
}