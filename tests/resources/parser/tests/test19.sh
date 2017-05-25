#!/bin/sh

path_of_file=`dirname $0`"/../../.."

$path_of_file/../Minishell -t parser "sdfdsf; sfdsdf; ; sdfsdffd|| sdffd;sdfsdf "

$path_of_file/../Minishell -t parser "asdasdasd&&&&&&&&&&&&"

$path_of_file/../Minishell -t parser "ls |&|"

$path_of_file/../Minishell -t parser "ls ||&;ls"

$path_of_file/../Minishell -t parser "ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto;"

$path_of_file/../Minishell -t parser "ls -l | cat -e"

$path_of_file/../Minishell -t parser "ls -l | cat -e; cat -e < lol; toto && tata < ta > toto.txt; rm toto;"
