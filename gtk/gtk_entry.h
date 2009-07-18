
GtkWidget *gtk_entry_new()
{
	return new QLineEdit();
}

// XXX: is this deprecated?
// XXX: dynamic_cast throws? or does it leave e NULL if the cast fails.. we want to Q_ASSERT this if it is the latter!
void gtk_entry_set_editable(GtkEntry *entry, gboolean editable)
{
	Q_ASSERT(entry);

	GtkEntry *e = dynamic_cast<GtkEntry *>(entry);
	e->setReadOnly(editable);
}

// XXX: dynamic_cast throws? or does it leave e NULL if the cast fails.. we want to Q_ASSERT this if it is the latter!
void gtk_entry_set_text(GtkEntry *entry, const gchar *text)
{
	Q_ASSERT(entry);

	GtkEntry *e = dynamic_cast<GtkEntry *>(entry);
	e->setText(text);
}

void gtk_entry_append_text(GtkEntry *entry, const gchar *text)
{
	Q_ASSERT(entry);

	GtkEntry *e = dynamic_cast<GtkEntry *>(entry);

	// Yuck, QLineEdit has no append() method, unlike QTextEdit
	e->setText(e->text() + text);
}

