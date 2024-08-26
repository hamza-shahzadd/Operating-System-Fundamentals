#!/bin/bash

echo -e "Menu: \n 1. Invert Permissions of File \n 2. Seacrh string in file \n 3. Copy N lines of all files \n 4. Check date"
read choice
if [ $choice = 1 ]
		then
		echo "Option 01 Selected at" $(date) >> output.log
		echo "Enter File name"
		read filename
		echo "Filename: " $filename >> output.log
		ls -l $filename
		if [ -r $filename ]
			then
			chmod a-r $filename
		else	
			chmod a+r $filename
		fi
		if [ -w $filename ]
			then
			chmod a-w $filename
		else
			chmod a+w $filename
		fi
		if [ -x $filename ]
			then
			chmod a-x $filename
		else
			chmod a+x $filename
		fi
		ls -l $filename
		
		echo "INVERTING FILE PERMISSIONS"
        	echo "Permissions Changed" >> output.log
        	echo -ne "Updated Permissions of $fname :" >> output.log
        	ls -l $fname
        	ls -l $fname >> output.log
		
fi
if [ $choice = 2 ]
		then
		echo "Option 02 Selected at" $(date) >> output.log
		echo "Enter File name"
		read filename
		echo "File name: " $filename >> output.log 
		echo "Enter String"
		read string
		 echo "String: " $string >> output.log 
		newstring=${string//[.]/*}
		grep $newstring $filename
		echo "Output all the lines in $filename where $string is found. " >> output.log 
	
fi

if [ $choice = 3 ]
		then
		 echo "Option 03 Selected at" $(date) >> output.log
		current=1
		echo "Enter N"
		read N
		newfile="dummy.txt"
		touch dummy.txt
		echo " " > dummy.txt
		for f in *.*
		do
			if [[ "$f" == "$newfile" ]]
			then
				continue
			fi
			if ((current%2==0))
			then
				head -n $N $f>>dummy.txt
			else
				tail -n $N $f>>dummy.txt
			fi
			((current=current+1))
		done
		
fi		

if [ $choice = 4 ]
		then
		echo "Option 04 Selected at" $(date) >> output.log
		echo "Enter File name"
		read filename
		seconds=$(($(date +%s) - $(date +%s -r $filename)))
		echo $(date -r $filename)
		echo $seconds
		if (($seconds>86400))
		then
			touch $filename
		fi
		echo $(date -r $filename)
fi



