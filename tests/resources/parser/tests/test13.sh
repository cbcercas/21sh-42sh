#!/bin/sh

path_of_file=`dirname $0`"/../../.."

#echo "[****** Testing for 'ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto;' *]"
$path_of_file/../Minishell -t parser "ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto.txt;"
