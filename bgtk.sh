#!/bin/sh
gcc examples/test.c -o test `pkg-config --cflags --libs gtk+`
./test
