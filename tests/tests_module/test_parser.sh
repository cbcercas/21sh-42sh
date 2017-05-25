#!/bin/sh

path_of_file=`dirname $0`"/.."
ret_parser=0

testing_parser_file()
{
	local path="$path_of_file/resources/parser/"
	local file="test"$1
	local output=$path'output/'$file".output"
	local filetest=$path'tests/'$file".sh"

	if [ $1 -lt 14 ]; then #les 14 premier test c'est le meme output
		local expected=$path"expected/testOK.expected"
	else
		local expected=$path'expected/'$file".expected"
	fi
	sh $filetest > $output
	diff -U3 $output $expected > /dev/null 2>&1

	if [ $? != 0 ]; then
		echo "\n\033[1;4;41m  Test: "$1" ERROR              \033[0m \033[1;40m \n"
		diff -U3 $output $expected
		ret_parser=`expr $ret_parser + $?`
		echo "\n\033[4;41m                              \033[0m"
	else
		echo "  \033[4;32mTest: "$1" Success\033[0m"
		result=$(($result + 1))
	fi
}

testing_parser()
{
	local nbtests=$1

	if [ $nbtests -lt 1 ]; then
		echo 'ERROR'
		exit 2;
	fi
	echo "#########TESTING-PARSER#########"
	i=1
	result=0
	while [ $i -le $1 ]
	do
		testing_parser_file $i
		i=$(($i + 1))
	done

	echo "\n  \033[1;33mRESULT: "$result'/'$1"\033[0m\n"
	echo "#################################"
}

testing_parser 19
return $ret_parser
