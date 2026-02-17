#!/bin/bash

printf "[a] Add\n"
printf "[s] Substract\n"
printf "[m] Multiply\n"
printf "[d] Divide\n"
printf "[r] Ramainder\n"

#start:
read operator
printf "please entre two integer between 0 to 100\n"

read a1
read a2

until $a1 -le 100
do
	echo "number a1 is  error, please retry."
	read a1
done

until $a2 -le 100
do
        echo "number a2 is error, please retry."
	read a2
done

until $a1 -ge 0
do
        echo "number a1 is  error, please retry."
	read a1
done

until $a2 -ge 0
do
        echo "number a2 is error, please retry."
	read a2
done

case $operator in
	a) `expr $a1 + $a2`
	;;

	s) `expr $a1 - $a2`
	;;

	m) `expr $a1 * $a2`
	;;

	d) `expr $a1 / $a2`
	;;

	*) echo "error operator"
	;;

esac
