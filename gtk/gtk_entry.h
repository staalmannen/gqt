
GtkWidget *gtk_entry_new()
{
	return new QLineEdit();
}

// XXX: is this deprecated?
void gtk_entry_set_editable(GtkEntry *entry, gboolean editable)
{
	Q_ASSERT(entry);

	entry->setReadOnly(editable);
}

void gtk_entry_set_text(GtkEntry *entry, const gchar *text)
{
	Q_ASSERT(entry);

	entry->setText(text);
}

void gtk_entry_append_text(GtkEntry *entry, const gchar *text)
{
	Q_ASSERT(entry);

	// Yuck, QLineEdit has no append() method, unlike QTextEdit
	entry->setText(entry->text() + text);
}

