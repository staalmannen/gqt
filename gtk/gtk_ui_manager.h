class GQTUIManager;
typedef GQTUIManager GtkUIManager;

class GQTUIManager
{
	// XXX: implement me
};

GtkUIManager *gtk_ui_manager_new()
{
	return new GtkUIManager();
}

void gtk_ui_manager_insert_action_group(GtkUIManager *uiman, GtkActionGroup *actions, gint ignored)
{

}

void gtk_ui_manager_add_ui_from_string(GtkUIManager *uiman, const gchar *buffer, gssize length, GError **error)
{

}

GtkWidget *gtk_ui_manager_get_widget(GtkUIManager *uiman, const gchar *widget_name)
{

}

#define GtkAccelGroup void
GtkAccelGroup *gtk_ui_manager_get_accel_group(GtkUIManager *uiman)
{

}
