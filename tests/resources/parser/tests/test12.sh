#!/bin/sh

path_of_file=`dirname $0`"/../../.."

#echo "[****** Testing for 'cat -e < ls' *]"
$path_of_file/../Minishell -t parser "cat -e < ls"
