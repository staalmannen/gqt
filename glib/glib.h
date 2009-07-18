#ifndef __GLIB__
#define __GLIB__

#define gchar char
#define gboolean bool
#define gint int
#define guint unsigned int
#define gpointer void *
#define gulong unsigned long


#define FALSE false
#define TRUE true

void g_print(const gchar *text)
{
	Q_ASSERT(text);

	printf("%s", text);
}

#include <glib/glib_glist.h>
#include <glib/glib_signals.h>

#define G_CALLBACK(x) (GCallback)x

#endif
