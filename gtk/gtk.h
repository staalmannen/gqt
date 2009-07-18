#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

#define GtkWidget QWidget
#define GtkBox QWidget /* ugh */
#define GtkContainer QWidget /* ugh */
#define GtkButton QPushButton
#define GtkLabel QLabel
#define GtkHBox QHBoxLayout

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

GtkWidget *gtk_window_new(GtkWindowType type)
{
	// XXX: handle GtkWindowType properly.
	return new GtkWidget(NULL);
}

// We can't return GtkWidget, as in Qt, layouts aren't widgets.
GtkWidget *gtk_hbox_new(gboolean homogenous, gint spacing)
{
	// Oh, dear god.
	// In GTK, layouts are children of widgets. In Qt, they aren't.
	// This fragile hack will work around that by creating a widget
	// and a layout, setting the layout on the widget, 
	// and returning the created widget. UGH.
	GtkWidget *g = new GtkWidget(NULL);
	GtkHBox *h = new GtkHBox(NULL);
	h->setSpacing(spacing);
	g->setLayout(h);
	return g;
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

void gtk_container_add(GtkContainer *container, GtkWidget *widget)
{
	Q_ASSERT(container && widget);

	// XXX: no idea if this is correct!
	gtk_box_pack_start(container, widget, false, false, 0);
}

void gtk_container_border_width(GtkContainer *container, guint border_width)
{
	Q_ASSERT(container && container->layout());
	container->layout()->setContentsMargins(border_width, border_width, border_width, border_width);
}

GtkWidget *gtk_label_new(const gchar *text)
{
	Q_ASSERT(text);

	return new GtkLabel(text, NULL);
}

GtkWidget *gtk_button_new_with_label(const gchar *text)
{
	Q_ASSERT(text);

	return new GtkButton(text, NULL);
}

void gtk_widget_show(GtkWidget *widget)
{
	Q_ASSERT(widget);

	widget->show();
}
