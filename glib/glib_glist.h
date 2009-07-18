#define GList QList<const gpointer>

// XXX: const is to avoid problems
GList *g_list_append(GList *list, const gpointer data)
{
	list->append(data);
}
