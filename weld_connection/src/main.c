#include <stdio.h>
#include <gtk/gtk.h>
#include <signal.h>
#include <sqlite3.h>
#include "fillet_welds.h"
#include "groove_welds.h"
#include "min_yield_strength_60.h"
#include "temp_function.h"

GtkBuilder *builder;
GtkWidget *window_main;

// Функции для интерфейса
gboolean LoadFromPath(GtkCssProvider *provider, const gchar *path, GError **error)
{
    return gtk_css_provider_load_from_path(provider, path, error);
}

void AddProviderForScreen(GdkScreen *screen, GtkStyleProvider *provider, int priority)
{
    gtk_style_context_add_provider_for_screen(screen, provider, priority);
}

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);
    GtkCssProvider *provider = gtk_css_provider_new();
    GError *error = NULL;
    const gchar *cssPath = "resources/style.css"; // путь к css файлу

    // Создаем интерфейс
    CssProviderInterface interface;
    interface.load_from_path = LoadFromPath; // Указываем функцию загрузки
    interface.add_provider_for_screen = AddProviderForScreen; // Указываем функцию добавления провайдера

    builder = gtk_builder_new();
    if (!gtk_builder_add_from_file(builder, "resources/welds.glade", NULL))
    {
        g_printerr("Error loading weld.glade file\n");
        return 1;
    }

    window_main = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    g_signal_connect(window_main, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_builder_connect_signals(builder, NULL);

    gtk_window_set_title(GTK_WINDOW(window_main), "Расчет сварного шва приварки балки 1.0");
    gtk_window_set_icon_from_file(GTK_WINDOW(window_main), "resources/ant.gif", NULL);
    gtk_window_set_resizable(GTK_WINDOW(window_main), FALSE);

    // работа с *.css файлом
    apply_css(&interface, provider, cssPath, &error); // передаем интерфейс как первый аргумент
    gtk_widget_show_all(window_main);

    gtk_main();

    printf("TEST");

    g_object_unref(builder);
    return 0;
}