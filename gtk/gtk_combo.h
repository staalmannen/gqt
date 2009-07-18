GtkWidget *gtk_combo_new()
{
	return new GtkCombo();
}

// This is deprecated
void gtk_combo_set_popdown_strings(GtkCombo *combo, GList *strings)
{
	Q_ASSERT(combo && strings);

	combo->clear();

	const void *item;

	foreach (item, *strings)
	{
		combo->addItem(QString((const char *)item));
	}
}
