
GtkWidget *gtk_entry_new()
{
	return new QLineEdit();
}

// XXX: is this deprecated?
void gtk_entry_set_editable(GtkEntry *entry, gboolean editable)
{
	Q_ASSERT(entry);

	// The extra negation here is because gtk_entry_set_editable() wants 'false' for non-readable,
	// but setReadOnly will of course want 'true' in the same condition.
	entry->setReadOnly(!editable);
}

void gtk_entry_set_text(GtkEntry *entry, const gchar *text)
{
	Q_ASSERT(entry);

	entry->setText(text);
}

const gchar *gtk_entry_get_text(GtkEntry *entry)
{
	Q_ASSERT(entry);

	return entry->text().toAscii().constData();
}

void gtk_entry_append_text(GtkEntry *entry, const gchar *text)
{
	Q_ASSERT(entry);

	// Yuck, QLineEdit has no append() method, unlike QTextEdit
	entry->setText(entry->text() + text);
}

