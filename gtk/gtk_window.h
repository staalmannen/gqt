
GtkWidget *gtk_window_new(GtkWindowType type)
{
	// XXX: handle GtkWindowType properly.
	return new GtkWidget(NULL);
}

void gtk_window_set_title(GtkWindow *window, const gchar *title)
{
	Q_ASSERT(window && title);

	window->setWindowTitle(title);
}

// XXX: unimplemented
void gtk_window_set_default_size(GtkWindow *window, guint x, guint y)
{
	Q_ASSERT(window);
}
