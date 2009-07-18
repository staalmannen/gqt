typedef void (*GCallback)(void);
typedef void (*GClosureNotify)(void);
enum GConnectFlags
{
	FOOOF
};

/*
 * Let the magic begin!
 *
 * This map will store all hooked signals.
 * The first 'void *' key is the instance that is hooked (i.e. 'this').
 * It stores a map of signals which are hooked, i.e. 'clicked' -> pointer.
 */
static QMap<void *, QMap<QString, GCallback> > gqt_signals;

gulong g_signal_connect(gpointer instance, const gchar *detailed_signal, GCallback c_handler, gpointer data)
{
	Q_ASSERT(instance && detailed_signal && c_handler);
	qDebug("g_signal_connect(): Hooked %s signal on %p going to %p", detailed_signal, instance, c_handler);
	gqt_signals[instance][detailed_signal] = c_handler;
}

void gqt_signal_execute(void *widget, const gchar *signal)
{
	Q_ASSERT(widget && signal);

	QMap<void *, QMap<QString, GCallback> >::ConstIterator it = gqt_signals.constFind(widget);

	if (it == gqt_signals.end())
	{
		qDebug("No signals hooked on target widget %p", widget);
		return;
	}

	QMap<QString, GCallback> m = *it;
	QMap<QString, GCallback>::ConstIterator it2 = m.constFind(signal);

	if (it == gqt_signals.end())
	{
		qDebug("Signal %s not hooked on target widget %p", signal, widget);
		return;
	}

	qDebug("Invoking %s on %p", signal, widget);

	GCallback g = *it2;
	g();

}
