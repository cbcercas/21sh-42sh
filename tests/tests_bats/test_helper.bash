#!/bin/bash

name_exec="21sh"

display_line_output()
{
	local i=1
	echo "$name_exec OUTPUT   ->${lines[0]}"
	while test "${lines[$i]}" != ""
	do
		echo "                ${lines[$i]}"
		i=`expr $i + 1`
	done
}

####message parser#########
okparser="Parser say OK"
parser_error_simple_pv="Parser: Syntax error near ';'"
parser_error_double_pv="Parser: Syntax error near ';;'"

parser_error_simple_es="Parser: Syntax error near '&'"
parser_error_double_es="Parser: Syntax error near '&&'"

parser_error_simple_p="Parser: Syntax error near '|'"
parser_error_double_p="Parser: Syntax error near '||'"

parser_error_newline="Parser: Syntax error near '\n'"
##########################


####message leaks########

if [[ $TESTS_CHECK_LEAKS -eq 1 ]]; then
val_cmd="valgrind --trace-children=yes --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes"
fi

check_leaks_function()
{
	if [[ $TESTS_CHECK_LEAKS -eq 1 ]]; then
		leaks_direct=`grep -oP "definitely lost:\s+\K\w+" check_leaks_tmp.log`
		leaks_indirect=`grep -oP "indirectly lost:\s+\K\w+" check_leaks_tmp.log`
		display_error_leaks $1
		if [ $leaks_direct -ne "0" ] || [ $leaks_indirect -ne "0" ]; then
			mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/$1"
			cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/$1/TEST-$BATS_TEST_NUMBER-AST.log
		fi
		[ $leaks_direct = "0" ]
		[ $leaks_indirect = "0" ]
	fi
}

display_error_leaks()
{
	echo "======================================================================="
	echo "**[----- LEAKS DETECTED! -----]"
	echo "=> check file log: [...]/valgrind_log/$1/TEST-$BATS_TEST_NUMBER-MODULE.log"
	echo "======================================================================="
}
##########################
