GtkWidget *gtk_menu_bar_new()
{
	return new QMenuBar(NULL);
}

GtkWidget *gtk_menu_new()
{
	return new QMenu(NULL);
}

void gtk_menu_item_set_submenu(GtkMenuItem *menu_item, GtkWidget *submenu)
{
	Q_ASSERT(menu_item && submenu);

#if 0
	if (submenu->actions().count())
	{
		// menubar
		//menu_item->addAction(submenu->actions()[0]);

	}
	else
	{
		// no idea what to do here. try pack?
		QMenu
		//gtk_container_add(menu_item, submenu);
		// if we're here, menu_item is a "parent" type item like gtk_menu_bar_new().
		// submenu		created from gtk_menu_item_new_with_label().
		//
	}


#endif
	submenu->setParent(menu_item);
}

GtkWidget *gtk_menu_item_new_with_label(const gchar *text)
{
	Q_ASSERT(text);

	QWidget *q = new QWidget(NULL);
	q->addAction(new QAction(text, q));
	return q;
}

void gtk_menu_shell_append(GtkMenuShell *menu_shell, GtkWidget *child)
{
#if 0
	Q_ASSERT(child && child->actions().count() > 0);

	QMenuBar *bar = dynamic_cast<QMenuBar *>(menu_shell);

	if (bar)
	{
		// adding to a menu bar
		//gtk_container_add(menu_shell, child);
		//QMenu *childm = dynamic_cast<QMenu *>(child);
		//bar->addMenu(childm);
		bar->addMenu(new QMenu("hi", NULL));
	}
	else
	{
		menu_shell->addAction(child->actions()[0]);

	}

#endif
	child->setParent(menu_shell);
}

#define gtk_menu_bar_append(x, y) gtk_menu_shell_append(x, y)
#define gtk_menu_append(x, y) gtk_menu_shell_append(x, y)
