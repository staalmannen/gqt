#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

#define GtkWidget QWidget

#define GtkBox QWidget /* ugh */
#define GtkContainer QWidget /* ugh */
#define GtkHBox QHBoxLayout
#define GtkVBox QVBoxLayout


#define GtkButton QPushButton
#define GtkLabel QLabel

#define gchar char
#define gboolean bool
#define gint int
#define guint unsigned int

#define FALSE false
#define TRUE true

// Stupid GTK typecasting crap.
#define GTK_BOX(x) x
#define GTK_CONTAINER(x) x

static QApplication *app = NULL;

enum GtkWindowType
{
	GTK_WINDOW_TOPLEVEL,
	GTK_WINDOW_POPUP
};


void gtk_init(int *argc, char ***argv)
{
	// Don't allow double calls
	Q_ASSERT(!app);
	app = new QApplication(*argc, *argv);
}

void gtk_main()
{
	app->exec();
}

// TODO: respect expand, fill, padding
void gtk_box_pack_start(GtkBox *box, GtkWidget *child, gboolean expand, gboolean fill, guint padding)
{
	Q_ASSERT(box && child);

	if (!box->layout())
	{
		// XXX: is this behaviour correct? we need it for gtk_container_add() and the like on a main window (ugh)
		GtkHBox *h = new GtkHBox(NULL);
		box->setLayout(h);
	}

	// GtkBox is actually a QWidget with a layout set to work around GTK's
	// odd idea of layouts being widgets. Retrieve the set layout, and pack 
	box->layout()->addWidget(child);
}

void gtk_widget_show(GtkWidget *widget)
{
	Q_ASSERT(widget);

	widget->show();
}

#include <gtk/gtk_button.h>
#include <gtk/gtk_window.h>
#include <gtk/gtk_hbox.h>
#include <gtk/gtk_vbox.h>
#include <gtk/gtk_container.h>
#include <gtk/gtk_label.h>

