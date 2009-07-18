
GtkWidget *gtk_button_new_with_label(const gchar *text)
{
	Q_ASSERT(text);

	return new GtkButton(text, NULL);
}

