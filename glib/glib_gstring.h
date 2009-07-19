class GString
{
	private:
		QString m_real;

	public:
		GString(const gchar *init)
		{
			
		}

		GString(gssize len, const gchar *init)
		{

		}

		gchar *str;
};

GString *g_string_new(const gchar *init)
{
	return new GString(init);
}

GString *g_string_new_len(const gchar *init, gssize len)
{
	return new GString(len, init);
}

gchar *g_string_free(GString *string, gboolean free_segment)
{
	// XXX: we need to return data if (!free_segment)
	delete string;
	return NULL;
}

// XXX: stub
void g_string_printf(GString *string, const gchar *format, ...)
{

}

#define g_string_sprintf g_string_printf
