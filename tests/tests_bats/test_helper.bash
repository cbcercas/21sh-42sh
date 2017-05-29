#!/bin/bash

name_exec="21sh"

display_line_output()
{
	local i=1
	echo "$name_exec OUTPUT   -> ${lines[0]}"
	while test "${lines[$i]}" != ""
	do
		echo "                      ${lines[$i]}"
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
