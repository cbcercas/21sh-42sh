#!/bin/sh

path_of_file=`dirname $0`"/../../.."

#echo "[ Testing for 'ls -l | cat -e' ]"
$path_of_file/../Minishell -t parser "ls -l | cat -e"
