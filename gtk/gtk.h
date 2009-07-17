#include <QApplication>
#include <QWidget>

#define GtkWidget QWidget

static QApplication *app = NULL;

enum GtkWindowType
{
	GTK_WINDOW_TOPLEVEL,
	GTK_WINDOW_POPUP
};


void gtk_init(int *argc, char ***argv)
{
	// Don't allow double calls
	if (app)
		throw "Oh dear";

	app = new QApplication(*argc, *argv);
}

void gtk_main()
{
	app->exec();
}

GtkWidget *gtk_window_new(GtkWindowType type)
{
	// XXX: handle GtkWindowType properly.
	return new GtkWidget(NULL);
}

void gtk_widget_show(GtkWidget *widget)
{
	widget->show();
}
