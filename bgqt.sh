#!/bin/sh
if [ ! -n "$1" ]
then
	test="test"
	echo "no test specified, running test"
else
	echo "running $1"
	test=$1
fi

# run MOC first
~/qt4-bin/bin/moc -i gtk/gtk_button.h -o gtk/moc_gtk_button.h
g++ "examples/$test.c" -o test -ggdb3 -I/home/w00t/gqt -I/home/w00t/qt4-bin/include -I/home/w00t/qt4-bin/include/QtGui -I/home/w00t/qt4-bin/include/QtCore -L/home/w00t/qt4-bin/lib -lQtCore -lQtGui -Wl,--rpath -Wl,/home/w00t/qt4-bin/lib
rm gtk/moc_gtk_button.h
./test
