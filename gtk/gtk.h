#ifndef __GTK__
#define __GTK__

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QTextEdit>
#include <QMap>
#include <QMenuBar>

#include <glib/glib.h>

#define GtkWidget QWidget

#define GtkWindow QWidget
#define GtkBox QWidget /* ugh */
#define GtkContainer QWidget /* ugh */
#define GtkHBox QHBoxLayout
#define GtkVBox QVBoxLayout
#define GtkTable QWidget /* ugh */
#define GtkEntry QLineEdit
#define GtkCombo QComboBox
#define GtkTextView QTextEdit
#define GtkTextBuffer QTextEdit
#define GtkMenuBar QMenuBar
#define GtkMenuShell QWidget /* ugh */
#define GtkMenuItem QWidget


#define GtkButton GQTPushButton
#define GtkLabel QLabel

// Stupid GTK typecasting crap.
#define GTK_BOX(x) x
#define GTK_CONTAINER(x) x
#define GTK_TABLE(x) x
#define GTK_ENTRY(x) dynamic_cast<QLineEdit *>(x)
#define GTK_WINDOW(x) x
#define GTK_COMBO(x) dynamic_cast<QComboBox *>(x)
#define GTK_TEXT_VIEW(x) dynamic_cast<QTextEdit *>(x)
#define GTK_OBJECT(x) (void *)x
#define GTK_MENU_BAR(x) dynamic_cast<QMenuBar *>(x)
#define GTK_MENU_ITEM(x) x
#define GTK_MENU(x) x

static QApplication *gdk_app = NULL;

enum GtkWindowType
{
	GTK_WINDOW_TOPLEVEL,
	GTK_WINDOW_POPUP
};

enum GtkAttachOptions
{
	GTK_EXPAND,
	GTK_SHRINK,
	GTK_FILL
};


void gtk_init(int *argc, char ***argv)
{
	// Don't allow double calls
	Q_ASSERT(!gdk_app);

	gdk_app = new QApplication(*argc, *argv);
}

void gtk_main()
{
	// XXX: this is quite probably wrong.
	gdk_app->exec();
	delete gdk_app;
}

void gtk_main_quit()
{
	// This will break out of gdk_app->exec().
	QApplication::exit(0);
}

gboolean gtk_true()
{
	return TRUE;
}

gboolean gtk_false()
{
	return FALSE;
}

// TODO: respect expand, fill, padding
void gtk_box_pack_start(GtkBox *box, GtkWidget *child, gboolean expand, gboolean fill, guint padding)
{
	Q_ASSERT(box && child);

	if (!box->layout())
	{
		// XXX: is this behaviour correct? we need it for gtk_container_add() and the like on a main window (ugh)
		GtkHBox *h = new GtkHBox(NULL);
		h->setParent(box);
		box->setLayout(h);
	}

	// GtkBox is actually a QWidget with a layout set to work around GTK's
	// odd idea of layouts being widgets. Retrieve the set layout, and pack 
	box->layout()->addWidget(child);
	child->setParent(box);
}

void gtk_widget_show(GtkWidget *widget)
{
	Q_ASSERT(widget);

	widget->show();
}

void gtk_widget_destroy(GtkWidget *widget)
{
	Q_ASSERT(widget);

	delete widget;
}

#include <gtk/gtk_button.h>
#include <gtk/gtk_window.h>
#include <gtk/gtk_hbox.h>
#include <gtk/gtk_vbox.h>
#include <gtk/gtk_container.h>
#include <gtk/gtk_label.h>
#include <gtk/gtk_entry.h>
#include <gtk/gtk_table.h>
#include <gtk/gtk_combo.h>
#include <gtk/gtk_check_button.h>
#include <gtk/gtk_text_view.h>
#include <gtk/gtk_menu.h>

#endif
