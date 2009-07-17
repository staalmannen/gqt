#!/bin/sh
if [ ! -n "$1" ]
then
	test="test"
	echo "no test specified, running test"
else
	echo "running $1"
	test=$1
fi

gcc "examples/$test.c" -o "$test" `pkg-config --cflags --libs gtk+`
./$test
