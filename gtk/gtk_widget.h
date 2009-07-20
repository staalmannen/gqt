
void gtk_widget_show(GtkWidget *widget)
{
	Q_ASSERT(widget);

	widget->show();
}

void gtk_widget_destroy(GtkWidget *widget)
{
	Q_ASSERT(widget);

	delete widget;
}

