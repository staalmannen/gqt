#!/bin/sh
g++ examples/test.c -o test -I/home/w00t/gqt -I/home/w00t/qt4-bin/include -I/home/w00t/qt4-bin/include/QtGui -I/home/w00t/qt4-bin/include/QtCore -L/home/w00t/qt4-bin/lib -lQtCore -lQtGui -Wl,--rpath -Wl,/home/w00t/qt4-bin/lib
./test
