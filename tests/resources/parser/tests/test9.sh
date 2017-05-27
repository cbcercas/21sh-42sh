#!/bin/sh

path_of_file=`dirname $0`"/../../.."

#echo "[****** Testing for 'ls & ls' *]"
$path_of_file/../Minishell -t parser "ls & ls"
