
GtkWidget *gtk_label_new(const gchar *text)
{
	Q_ASSERT(text);
	GtkLabel *g = new GtkLabel(text, NULL);

	// Set alignment so we mimic GTK's default.
	g->setAlignment(Qt::AlignCenter);

	return g;
}

