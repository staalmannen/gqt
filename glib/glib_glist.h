#define GList QList<const gpointer> 

// XXX: const is to avoid problems
GList *g_list_append(GList *list, const gpointer data)
{
	if (!list)
	{
		list = new GList();
		qDebug("Created a new list");
	}
	list->append(data);
	return list;
}
