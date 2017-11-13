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
parser_error_simple_pv="$name_exec: Parse error near \`;'"
parser_error_double_pv="$name_exec: Parse error near \`;;'"

parser_error_simple_es="$name_exec: Parse error near \`&'"
parser_error_double_es="$name_exec: Parse error near \`&&'"

parser_error_simple_p="$name_exec: Parse error near \`|'"
parser_error_double_p="$name_exec: Parse error near \`||'"

parser_error_redir="$name_exec: Parse error near \`< or >'"
parser_error_redir_double="$name_exec: Parse error near \`>>'"

parser_error_newline="$name_exec: Parse error near \`\n'"

fatal="Fatal testing error: Couldn't catch the error."

history_loc="/tmp/.21sh_history"
home_tests="/tmp"
cdnosuch="cd: no such file or directory"
##########################


####message leaks########

if [[ $TESTS_CHECK_LEAKS -eq 1 ]]; then
val_cmd="valgrind --trace-children=yes --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes"
fi

if [[ $TESTS_CHECK_LEAKS -eq 2 ]]; then
val_cmd="valgrind --trace-children=yes --log-file=check_leaks_tmp.log --show-leak-kinds=all --leak-check=full --track-origins=yes"
fi

check_leaks_function()
{
	if [[ $TESTS_CHECK_LEAKS -ne 0 ]]; then
		leaks_direct=`grep -oP "definitely lost:\s+\K\w+" check_leaks_tmp.log`
		leaks_indirect=`grep -oP "indirectly lost:\s+\K\w+" check_leaks_tmp.log`
		leaks_reach=`grep -oP "still reachable:\s+\K\w+" check_leaks_tmp.log`
		display_error_leaks $1
		if [ $leaks_direct -ne "0" ] || [ $leaks_indirect -ne "0" ]; then
			mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/$1"
			cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/$1/TEST-$BATS_TEST_NUMBER-AST.log
		elif [ $leaks_reach -ne "0" ] && [ $TESTS_CHECK_LEAKS -eq 2 ]; then
			echo "[-- STILL REACHABLE!! --]"
			mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/$1"
			cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/$1/TEST-$BATS_TEST_NUMBER-AST.log
			[ $leaks_reach = "0" ]
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
