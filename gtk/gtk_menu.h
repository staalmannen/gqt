#if 0


  /*-- Create the menu bar --*/
  menubar = gtk_menu_bar_new();

  /*-- Add the menubar to the vbox --*/
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, TRUE, 0);
  gtk_widget_show(menubar);

  /*-- Add the text area to the window --*/
  gtk_container_add(GTK_CONTAINER(vbox), text);  

  /*-- Add the vbox to the main window --*/
  gtk_container_add(GTK_CONTAINER(window), vbox);
  
  /*---------------- Create File menu items ------------------*/

  // Create top menu item
  menuFile = gtk_menu_item_new_with_label ("File");

  // Append to menu bar
  gtk_menu_bar_append (GTK_MENU_BAR(menubar), menuFile);
  gtk_widget_show(menuFile);

  /*-- Create File submenu  --*/
  menu = gtk_menu_new();
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuFile), menu);

  /*-- Create New menu item under File submenu --*/
  menuitem = gtk_menu_item_new_with_label ("New");
  gtk_menu_append(GTK_MENU(menu), menuitem);
  gtk_widget_show (menuitem);

#endif

/*
 * XXX: this is to work around a (possible?) qt bug or odd behaviour that I can't quite put a handle on yet.
 * if a QMenuBar is created with a NULL parent, and later setParent()'d, it will flat out behave weirdly.
 *
 * this totally goes away if it is initialised with a parent..
 * test case code (obviously, modify as needed):
 #if 0
	gtk_init (&argc, &argv);
	// Create window
	QWidget *parent = new QWidget(NULL);
	QHBoxLayout *hb = new QHBoxLayout(NULL);
	hb->setParent(parent);
	parent->setLayout(hb);

	// Create menubar
	QMenuBar *mb = new QMenuBar(NULL);
	mb->setParent(parent);

	// Top level menu
	QMenu *toplevel = new QMenu("hi there", parent); <----- problem is here
//	toplevel->setParent(mb); <---- problem is here
	mb->addMenu(toplevel);

	QMenu *subitem = new QMenu("oh hi", NULL);
	subitem->setParent(toplevel);
	toplevel->addMenu(subitem);

	subitem = new QMenu("fzt", NULL);
	subitem->setParent(toplevel);
	toplevel->addMenu(subitem);

	// Pack menubar
	parent->layout()->setMenuBar(mb);
	parent->layout()->addWidget(new QTextEdit(parent));


	parent->show();
	gtk_main();
	exit(0);
#endif
 *
 */
static GtkMenuBar *gqt_current_mb = NULL;

void gtk_menu_bar_append(GtkMenuBar *menubar, GtkWidget *widget)
{
	QMenu *m = dynamic_cast<QMenu *>(widget);
	qDebug("gtk_menu_bar_append(): appending %p(%s) to menubar %p", m, m->title().toAscii().data(), menubar);

	Q_ASSERT(menubar && m);

	menubar->addMenu(m);
	m->setParent(menubar);
}

// Create a menu bar
GtkWidget *gtk_menu_bar_new()
{
	gqt_current_mb = new QMenuBar(NULL);
	return gqt_current_mb;
}

// Create a submenu
GtkWidget *gtk_menu_new()
{
	QMenu *q = new QMenu(NULL);
	qDebug("gtk_menu_new(): returning %p", q);
	return q;
}
QMap<void *, QMenu *> gqt_menu_hack_lookup;

void gtk_menu_item_set_submenu(GtkMenuItem *menu_item, GtkWidget *submenu)
{
	// grargh.. gtk_menu_new() isn't really needed by us (it way overcomplicates things) so use a map to
	// find the 'real' item and totally ignore the pointer returned by gtk_menu_new except for lookups..
	//qDebug("gtk_menu_item_set_submenu(): Setting %p to lookup to %p", submenu, menu_item);
	gqt_menu_hack_lookup[submenu] = menu_item;

	// but ensure the fake gtk_menu_new() item is deleted when the lookup menu is deleted.
	submenu->setParent(menu_item);
}

GtkWidget *gtk_menu_item_new_with_label(const gchar *text)
{
	Q_ASSERT(text);

	QWidget *q = new QMenu(text, gqt_current_mb);
	//qDebug("gtk_menu_item_new_with_label(): returning %p", q);
	return q;
}

void gtk_menu_append(GtkMenuShell *menu_shell, GtkWidget *child)
{
	QMap<void *,  QMenu *>::ConstIterator it = gqt_menu_hack_lookup.find(menu_shell);

	// If it's the end, we didn't see it go into gtk_menu_item_set_submenu
	Q_ASSERT(it != gqt_menu_hack_lookup.end());

	// so, we're really appending child_item to m
	QMenu *m = *it;
	QMenu *child_item = dynamic_cast<QMenu *>(child);

	m->addMenu(child_item);
	child_item->setParent(m);
}

