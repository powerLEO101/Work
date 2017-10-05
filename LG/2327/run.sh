#!/bin/sh
while [ 1 -le 1 ]
do 
	g++ code.cpp -o code;
	./code
	sleep 1s
	echo -r "--------------\n\n";
done
