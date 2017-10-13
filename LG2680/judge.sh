#!/bin/sh
g++ make.cpp -o make
g++ code.cpp -o code
g++ AC_code.cpp -o AC_code
$(i=0)
while true
do
	./make
	./code
	./AC_code
	if ! diff code.out AC_code.out ;then
		echo "WA"
		break
	fi
	echo "AC"
	echo  $((i=i+1));
	cls
done
