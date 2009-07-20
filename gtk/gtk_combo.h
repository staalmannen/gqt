/**************************************************************
 * This code implements obsolete GTK interfaces.
 *************************************************************/

GtkWidget *gtk_combo_new() MARK_DEPRECATED;
GtkWidget *gtk_combo_new()
{
	return new GtkCombo();
}

static void foreach_iter(gpointer data, gpointer user_data)
{
	GtkCombo *g = (GtkCombo *)user_data;

	g->addItem((const char *)data);
}

void gtk_combo_set_popdown_strings(GtkCombo *combo, GList *strings) MARK_DEPRECATED;
void gtk_combo_set_popdown_strings(GtkCombo *combo, GList *strings)
{
	Q_ASSERT(combo && strings);

	combo->clear();

	g_list_foreach(strings, foreach_iter, combo);
}
