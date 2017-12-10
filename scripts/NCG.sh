#!/bin/bash

export EXEC_PATH=`dirname $0`

if grep -q "NCG" $EXEC_PATH/../.comment_state; then
	echo "Comments already in Normed Style. Doing nothing."
	exit
fi

echo -e "\n###################################"
echo -e "###   Normed Comment Generator  ###"
echo -e "###################################"

find $EXEC_PATH/../ -iname "*.c" -o -iname "*.h" > filelist.tmp

while read line; do
     	sed "s/^\/\*\*/\/\*/g" $line | sed "s/^\ \*/\*\*/g" | sed "s/^\*\*\//\*\//g" > tmp
     	cat tmp > $line
     	echo $line
done < filelist.tmp
rm filelist.tmp
rm tmp
echo "Comments converted to Norm Style"
echo "NCG" > $EXEC_PATH/../.comment_state
