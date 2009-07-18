// XXX: implement homogenous
// NOTE: columns and rows are ignored here, Qt doesn't require them
GtkWidget *gtk_table_new(guint rows, guint columns, gboolean homogenous)
{
	// Oh, dear god.
	// In GTK, layouts are children of widgets. In Qt, they aren't.
	// This fragile hack will work around that by creating a widget
	// and a layout, setting the layout on the widget, 
	// and returning the created widget. UGH.
	GtkWidget *g = new GtkWidget(NULL);
	QGridLayout *h = new QGridLayout(NULL);
	g->setLayout(h);
	return g;
}

void gtk_table_attach(GtkTable *table, GtkWidget *child,
		guint left_attach, guint right_attach,
		guint top_attach, guint bottom_attach,
		int xopt, int yopt,
		guint xpadding, guint ypadding)
{
	/*
	 * Adds a widget to a table. The number of 'cells' that a widget will occupy is specified by left_attach, right_attach, top_attach and bottom_attach.
	 * These each represent the leftmost, rightmost, uppermost and lowest column and row numbers of the table. (Columns and rows are indexed from zero). 
	 * table: The GtkTable to add a new widget to. 
	 * child: The widget to add. 
	 * left_attach: the column number to attach the left side of a child widget to. 
	 * right_attach: the column number to attach the right side of a child widget to. 
	 * top_attach: the row number to attach the top of a child widget to. 
	 * bottom_attach: the row number to attach the bottom of a child widget to. 
	 * xoptions: Used to specify the properties of the child widget when the table is resized. 
	 * yoptions: The same as xoptions, except this field determines behaviour of vertical resizing. 
	 * xpadding: An integer value specifying the padding on the left and right of the widget being added to the table. 
	 * ypadding: The amount of padding above and below the child widget.
	 */
	Q_ASSERT(table && table->layout() && child);

	// Make sure the column/rowspan values are going to be kosher
	Q_ASSERT(right_attach - left_attach > 0);
	Q_ASSERT(bottom_attach - top_attach > 0);

	qDebug("Adding item to table, left: %d, top %d, width %d, height %d", left_attach, top_attach, right_attach - left_attach, bottom_attach - top_attach);

	QGridLayout *g = dynamic_cast<QGridLayout *>(table->layout());
	Q_ASSERT(g);

	g->addWidget(child, top_attach, left_attach, right_attach - left_attach, bottom_attach - top_attach, Qt::AlignCenter);
}
