
GtkWidget *gtk_entry_new()
{
	return new QLineEdit();
}

// XXX: is this deprecated?
// XXX: accepts widget because gtk_entry_new returns GtkWidget *sigh*
// XXX: dynamic_cast throws? or does it leave e NULL if the cast fails.. we want to Q_ASSERT this if it is the latter!
void gtk_entry_set_editable(GtkWidget *entry, gboolean editable)
{
	Q_ASSERT(entry);

	GtkEntry *e = dynamic_cast<GtkEntry *>(entry);
	e->setReadOnly(editable);
}

// XXX: accepts widget because gtk_entry_new returns GtkWidget *sigh*
// XXX: dynamic_cast throws? or does it leave e NULL if the cast fails.. we want to Q_ASSERT this if it is the latter!
void gtk_entry_set_text(GtkWidget *entry, const gchar *text)
{
	Q_ASSERT(entry);

	GtkEntry *e = dynamic_cast<GtkEntry *>(entry);
	e->setText(text);
}

void gtk_entry_append_text(GtkWidget *entry, const gchar *text)
{
	Q_ASSERT(entry);

	GtkEntry *e = dynamic_cast<GtkEntry *>(entry);

	// Yuck, QLineEdit has no append() method, unlike QTextEdit
	e->setText(e->text() + text);
}

