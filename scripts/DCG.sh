#!/bin/bash

echo -e "\n##################################"
echo -e "###   Doxygen Comment Generator  ###"
echo -e "##################################"

export EXEC_PATH=`dirname $0` 
find $EXEC_PATH/../ -iname "*.c" -o -iname "*.h" > filelist.tmp 

while read line; do  
       	sed "12,$ {s/^\/\*/\/\*\*/g;}" $line | sed "s/^\*\*/\ \*/g" | sed "s/^\*\//\ \*\//g" > tmp  
       	cat tmp > $line
done < filelist.tmp

rm filelist.tmp
rm tmp

echo "Comments converted to Doxygen Style"
