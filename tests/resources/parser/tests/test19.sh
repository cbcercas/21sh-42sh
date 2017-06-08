#!/bin/sh

path_of_file=`dirname $0`"/../../.."
name_of_exec=$1

$path_of_file/../$name_of_exec -t parser "sdfdsf; sfdsdf; ; sdfsdffd|| sdffd;sdfsdf "

$path_of_file/../$name_of_exec -t parser "asdasdasd&&&&&&&&&&&&"

$path_of_file/../$name_of_exec -t parser "ls |&|"

$path_of_file/../$name_of_exec -t parser "ls ||&;ls"

$path_of_file/../$name_of_exec -t parser "ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto;"

$path_of_file/../$name_of_exec -t parser "ls -l | cat -e"

$path_of_file/../$name_of_exec -t parser "ls -l | cat -e; cat -e < lol; toto && tata < ta > toto.txt; rm toto;"
