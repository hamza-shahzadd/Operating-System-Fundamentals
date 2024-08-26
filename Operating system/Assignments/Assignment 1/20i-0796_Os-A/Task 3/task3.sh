#!/bin/bash


echo


cd "Main Dir"
x=1
while [ $x = 1 ]
do
    echo "Enter a string. Forward or Backwards! "
    read str
    if [ $str = forward ]
    then
        mkdir -p java cpp txt cc others
        for folder in $(find -type d)
        do 
            fol=${folder##*/}
            echo $fol
            if [ $folder != "." -a $fol != "java" -a $fol != "cpp" -a $fol != "cc" -a $fol != "others" -a $fol != "txt" ]
            then
                for file in $(find $folder -type f)
                do
                    if [ ${file##*.} = txt ]
                    then
                        #echo "Txt"
                        name=${file##*/}
                        new="./txt/$fol-$name"
                        echo $new
                        mv $file $new
                        

                    elif [ ${file##*.} = java ]
                    then
                    # echo "JAVA"
                        name=${file##*/}
                        new="./java/$fol-$name"
                        echo $new
                        mv $file $new
                    elif [ ${file##*.} = cpp ]
                    then
                        #echo "CPP"
                        name=${file##*/}
                        new="./cpp/$fol-$name"
                        echo $new
                        mv $file $new
                    elif [ ${file##*.} = cc ]
                    then
                        #echo "CC"
                        name=${file##*/}
                        new="./cc/$fol-$name"
                        echo $new
                        mv $file $new
                    else
                        #echo "other"
                        name=${file##*/}
                        new="./others/$fol-$name"
                        echo $new
                        mv $file $new
                    fi
                done
            rmdir $folder
            fi
        done
    elif [ $str = backward ]
    then
                
        for folder in $(find -type d)
        do
            fol=${folder##*/}
            
            if [ $folder != . ]
            then   
                echo $fol
                for file in $(find $folder -type f) 
                do 
                    name=${file##*/}
                    foldername=${name%-*}
                    newname=${name##*-}
                    newname=${newname%.*}
                    mkdir -p $foldername
                    new="./$foldername/$newname.${file##*.}"
                    #echo $new
                    mv $file $new
                    #echo $newname $foldername
                done
            fi
        done
        rmdir java cpp txt cc others  
    fi
    done        
    exit 0
