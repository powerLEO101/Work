#!/bin/bash
g++ make.cpp -o make
g++ code.cpp -o code
g++ AC_code.cpp -o AC_code
while true
do
	./make>data.in
	./code<data.in>code.out
	./AC_code<data.in>AC_code.out
	if diff code.out AC_code.out ;then
		echo "AC"
	else
		echo "WA"
		break
	fi
done
