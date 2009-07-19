#ifndef __GLIB__
#define __GLIB__

#define gchar char
#define gboolean bool
#define gint int
#define guint unsigned int
#define gpointer void *
#define gulong unsigned long
#define gssize size_t

// XXX: We can only get at this via a function call to QDir, which is obviously not going to work at the preprocessor level.
// We'll need to use Qt's system defines to make this work on windows.
#define G_DIR_SEPARATOR_S "/"

#define FALSE false
#define TRUE true

#define g_assert(x) Q_ASSERT(x);
#define g_free(x) delete x

void g_print(const gchar *text)
{
	Q_ASSERT(text);

	printf("%s", text);
}

// XXX: stub
void g_printerr(const gchar *fmt, ...)
{
}

const gchar *g_strerror(gint err)
{
	return strerror(err);
}

gchar *g_strdup(const gchar *str)
{
	return strdup(str);
}

#include <QDir>

const gchar *g_get_home_dir()
{
	QDir d = QDir::home();
	return d.absolutePath().toLatin1();
}

gchar *g_strconcat(const gchar *string, ...)
{
	va_list args;
	gchar *tmp;

	Q_ASSERT(string);

	QString s = string;

	va_start(args, string);
	tmp = va_arg(args, gchar *);
	while (tmp)
	{
		s += tmp;
	}
	va_end(args);

	// XXX: this isn't really efficient
	return strdup(s.toLatin1());
}

#include <glib/glib_glist.h>
#include <glib/glib_signals.h>
#include <glib/glib_gstring.h>

#define G_CALLBACK(x) (GCallback)x

#endif
