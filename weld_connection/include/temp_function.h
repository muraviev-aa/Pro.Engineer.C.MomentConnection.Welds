#ifndef TEMP_FUNCTION_H
#define TEMP_FUNCTION_H

#include <gtk/gtk.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
    gboolean (*load_from_path)(GtkCssProvider *, const gchar *, GError **);
    void (*add_provider_for_screen)(GdkScreen *, GtkStyleProvider *, int);
} CssProviderInterface;

void apply_css(CssProviderInterface *interface, GtkCssProvider *provider, const gchar *cssPath, GError **error);

#ifdef __cplusplus
}
#endif

#endif //TEMP_FUNCTION_H