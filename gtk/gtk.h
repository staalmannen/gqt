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

typedef QWidget GtkWidget;
typedef QWidget GtkWindow;

typedef QWidget GtkBox; /* ugh */
typedef QWidget GtkContainer; /* ugh */
typedef QHBoxLayout GtkHBox;
typedef QVBoxLayout GtkVBox;
typedef QWidget GtkTable;

typedef QLineEdit GtkEntry;
typedef QComboBox GtkCombo;
typedef QTextEdit GtkTextView;
	typedef QTextEdit GtkTextBuffer;
typedef QMenuBar GtkMenuBar;
typedef QMenu GtkMenuShell;
typedef QMenu GtkMenuItem;

typedef QLabel GtkLabel;


// Stupid GTK typecasting crap.
#define GTK_BOX(x) x
#define GTK_CONTAINER(x) x
#define GTK_TABLE(x) x
#define GTK_ENTRY(x) dynamic_cast<QLineEdit *>(x)
#define GTK_WINDOW(x) x
#define GTK_COMBO(x) dynamic_cast<QComboBox *>(x)
#define GTK_TEXT_VIEW(x) dynamic_cast<QTextEdit *>(x)
#define GTK_OBJECT(x) (void *)x /* obsolete */
#define G_OBJECT(x) (void *)x
#define GTK_MENU_BAR(x) dynamic_cast<QMenuBar *>(x)
#define GTK_MENU_ITEM(x) dynamic_cast<QMenu *>(x)
#define GTK_MENU(x) dynamic_cast<QMenu *>(x)
#define GTK_LABEL(x) dynamic_cast<QLabel *>(x)
#define GTK_ABOUT_DIALOG(x) dynamic_cast<GQTAboutDialog *>(x)

enum GtkAttachOptions
{
	GTK_EXPAND,
	GTK_SHRINK,
	GTK_FILL
};


#include <gtk/gqt_dialog.h>
#include <gtk/gtk_box.h>
#include <gtk/gtk_main.h>
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
#include <gtk/gtk_about_dialog.h>
#include <gtk/gtk_widget.h>

#endif
