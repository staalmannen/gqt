// XXX: heavily stubbed
class GQTAboutDialog : public QWidget
{
 private:
	QString program_name;
	QString licence;
	QString version;
	QString comments;
 public:
	GQTAboutDialog() : QWidget()
	{
	}
};

GtkWidget *gtk_about_dialog_new()
{
	return new GQTAboutDialog();
}

void gtk_about_dialog_set_program_name(GtkAboutDialog *diag, const gchar *s)
{
	Q_ASSERT(diag && s);
}

void gtk_about_dialog_set_licence(GtkAboutDialog *diag, const gchar *s)
{
	Q_ASSERT(diag && s);

}

void gtk_about_dialog_set_version(GtkAboutDialog *diag, const gchar *s)
{
	Q_ASSERT(diag && s);

}

void gtk_about_dialog_set_comments(GtkAboutDialog *diag, const gchar *s)
{
	Q_ASSERT(diag && s);

}
