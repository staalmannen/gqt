typedef QActionGroup GtkActionGroup;
typedef QAction GtkActionEntry;

GtkActionGroup *gtk_action_group_new(const gchar *name)
{
	// XXX: there is (quite obviously) a LEAK here.
	// QActionGroup requires a widget for parenting.

	// XXX 2: we ignore name, this requires implementing, perhaps via QObject::setProperty()?
	return new QActionGroup(new QWidget());
}

void gtk_action_group_add_actions(GtkActionGroup *ag, GtkActionEntry *actions, gint action_count, gpointer user_data)
{

}
