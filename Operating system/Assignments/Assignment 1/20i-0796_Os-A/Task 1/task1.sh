#!/bin/bash
if [ $# = 0 ]
	then
	echo "Error - No Arguments Entered"
	exit
fi

if [ $# -gt 2 ]
	then
	echo "Error - More than two arguments Entered"
	exit
fi

if [ $1 == left ]
	then
	for (( i=1; i<=$2; i++ ))
	do
		for (( j=1; j<=i; j++ ))
		do
			echo -n "*"
		done
		echo ""
	done
	for (( k=1; k<=$2; k++ ))
	do
		for (( l=1; l<=$2-k; l++ ))
		do
			echo -n "*"
		done
		echo ""
	done
	
	exit
fi

if [ $1 == full ]
	then
	space=$2+4
	for (( i=1; i<=$2; i++ ))
	do
		for (( j=1; j<=space; j++ ))
		do
			echo -n " "
		done
		
		for ((k=1; k<=2*i-1; k++))
		do
			echo -ne "*"
		done
		((space=space-1))
		
		echo ""
	done
	space=6
	for (( i=1; i<$2; i++ ))
	do
		for (( j=1; j<=space; j++ ))
		do
			echo -n " "
		done
		
		for ((k=1; k<=2*($2-i)-1; k++))
		do
			echo -ne "*"
		done
		((space=space+1))
		
		echo ""
	done
	
	
	exit
fi

if [ $1 == right ]
	then
	space=1 
	for (( i=$2; i>=1; i-- ))
	do
		for (( j=1; j<=i; j++ ))
		do
			echo -ne " "
		done
		
		for ((k=1; k<=space-1; k++))
		do
			echo -n "*"
		done
		((space=space+1))
		echo ""
	done
	space=1
	for (( i=$2; i>=1; i-- ))
	do
		for (( j=1; j<=$2-i; j++ ))
		do
			echo -ne " "
		done
		
		for ((k=1; k<=$2-space+1; k++))
		do
			echo -n "*"
		done
		((space=space+1))
		echo ""
	done
	exit
fi

echo "Invalid Parameters"
