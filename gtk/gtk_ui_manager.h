#include <QXmlStreamReader>

// Class to handle XML input and turn it into a tree of widgets.
class GQTUIParser : public QXmlStreamReader
{
 public:
	GQTUIParser(QString s) : QXmlStreamReader(s)
	{
	}

	GtkWidget *parseUi()
	{
		while (!this->atEnd())
		{
			this->readNext();

			if (this->isStartElement())
			{
				qDebug("GQTUIParser: Got %s with name %s", qPrintable(this->name().toString()), qPrintable(this->attributes().value("name").toString()));
			}

			if (this->isEndElement())
			{
			}
		}

		return NULL;
	}
};

// Class to manage building UI from XML.
class GQTUIManager
{
 private:
	GQTUIParser *parser;
};
typedef GQTUIManager GtkUIManager;


GtkUIManager *gtk_ui_manager_new()
{
	return new GtkUIManager();
}

void gtk_ui_manager_insert_action_group(GtkUIManager *uiman, GtkActionGroup *actions, gint ignored)
{

}

void gtk_ui_manager_add_ui_from_string(GtkUIManager *uiman, const gchar *buffer, gssize length, GError **error)
{
	Q_ASSERT(uiman && buffer && error);

	// GTK allows -1 if it's NULL terminated
	if (length == -1)
		length = strlen(buffer);

	Q_ASSERT(length > 0);

	GQTUIParser xml(QString(QByteArray(buffer, length)));

	xml.parseUi();
/*
	QApplication a(argc, argv);
	QWidget *p = new QWidget(NULL);
	QUiLoader l;
	l.createWidget("QComboBox", p, 0);
	p->show();
	a.exec();
	exit(0);
*/
}

GtkWidget *gtk_ui_manager_get_widget(GtkUIManager *uiman, const gchar *widget_name)
{
	return new QWidget();
}

#define GtkAccelGroup void
GtkAccelGroup *gtk_ui_manager_get_accel_group(GtkUIManager *uiman)
{

}
