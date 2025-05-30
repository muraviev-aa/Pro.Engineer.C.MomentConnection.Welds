#include "temp_function.h"

void apply_css(void)
{
    GtkCssProvider *provider = gtk_css_provider_new();
    GError *error = NULL;

    if (!gtk_css_provider_load_from_path(provider, "resources/style.css", &error))
    {
        g_warning("Failed to load CSS: %s", error->message);
        g_clear_error(&error);
    }

    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                              GTK_STYLE_PROVIDER(provider),
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_object_unref(provider);
}