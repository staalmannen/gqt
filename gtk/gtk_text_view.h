GtkWidget *gtk_text_view_new()
{
	return new QTextEdit(NULL);
}

void gtk_text_view_set_editable(GtkTextView *text_view, gboolean setting)
{
	Q_ASSERT(text_view);

	// GTK is backwards from Qt, hence negation
	text_view->setReadOnly(!setting);
}

// Implementation of GtkTextBuffer goes here for now (sigh).
class GtkTextBuffer
{
 private:
	GtkTextView *m_parent;

 public:
	GtkTextBuffer(GtkTextView *parent)
	{
		this->m_parent = parent;
	}

	GtkTextView *parent() const
	{
		return this->m_parent;
	}
};

GtkTextBuffer *gtk_text_view_get_buffer(GtkTextView *text_view)
{
	// XXX: there is a memory leak here in that GtkTextBuffer is expected to be owned by GtkTextView,
	// and of course,  that is not the case with us.. we can't staticize this as multiple calls to
	// gtk_text_view_get_buffer() would then clobber the object meaning things would fuck up..
	return new GtkTextBuffer(text_view);
}

void gtk_text_buffer_set_text(GtkTextBuffer *buffer, const gchar *text, gint len)
{
	Q_ASSERT(buffer);

	if (len == -1)
		len = strlen(text);

	// QByteArray is necessary here in case text isn't a regular NULL terminated string.
	buffer->parent()->setText(QString(QByteArray(text, len)));
}
