
GtkWidget *gtk_button_new_with_label(const gchar *text)
{
	Q_ASSERT(text);

	return new GtkButton(text, NULL);
}

GtkWidget *gtk_toggle_button_new_with_label(const gchar *text)
{
	Q_ASSERT(text);

	GtkButton *b = new GtkButton(text, NULL);
	b->setCheckable(true);
	return b;
}
