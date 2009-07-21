#include <QXmlStreamReader>
#include <QUiLoader>

// Class to handle XML input and turn it into a tree of widgets.
class GQTUIParser : public QXmlStreamReader
{
	QWidget *tree_parent;
	QMap<QString, QString> widget_map;
 public:
	GQTUIParser() : QXmlStreamReader()
	{
		this->tree_parent = NULL;
		widget_map["menubar"] = "QMenuBar";
		widget_map["menu"] = "QMenu";
//		widget_map["menuitem"] = "QAction"; // oh, this is going to be fun.
	}

	GtkWidget *parseUi()
	{
		QUiLoader widgetloader;
		int current_depth = 0;
		int parent_depth = 0;
		QWidget *parent = NULL;
		QWidget *current;

		while (!this->atEnd())
		{
			this->readNext();

			if (this->isStartElement())
			{
				current_depth++;
				qDebug("GQTUIParser: Got %s with name %s", qPrintable(this->name().toString()), qPrintable(this->attributes().value("name").toString()));
				QMap<QString, QString>::ConstIterator it = widget_map.find(this->name().toString());

				if (it == widget_map.end())
					continue;


				if (current_depth > parent_depth)
				{
					qDebug("GQTUIParser: I can create %s as %s (and reset parent)", qPrintable(this->name().toString()), qPrintable(*it));
					current = parent = widgetloader.createWidget(*it, parent, this->attributes().value("name").toString());
					parent_depth = current_depth;
				}
				else
				{
					qDebug("GQTUIParser: I can create %s as %s (and NOT parent)", qPrintable(this->name().toString()), qPrintable(*it));
					current = widgetloader.createWidget(*it, parent, this->attributes().value("name").toString());
				}

				if (this->tree_parent == NULL)
					this->tree_parent = parent;

				// Just set some temporary crap so we can see what's going on, yeah?
				QMenu *test = dynamic_cast<QMenu *>(current);
				if (test)
				{
					test->setTitle(this->attributes().value("name").toString());
				}

				parent->show();
			}

			if (this->isEndElement())
			{
				current_depth--;
			}
		}

		return NULL;
	}
};

typedef GQTUIParser GtkUIManager;


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

	uiman->addData(QByteArray(buffer, length));

	uiman->parseUi();
}

GtkWidget *gtk_ui_manager_get_widget(GtkUIManager *uiman, const gchar *widget_name)
{
	return new QWidget();
}

#define GtkAccelGroup void
GtkAccelGroup *gtk_ui_manager_get_accel_group(GtkUIManager *uiman)
{

}
