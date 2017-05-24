#!/bin/sh

../Minishell -t parser "sdfdsf; sfdsdf; ; sdfsdffd|| sdffd;sdfsdf "

../Minishell -t parser "asdasdasd&&&&&&&&&&&&"

../Minishell -t parser "ls |&|"

../Minishell -t parser "ls ||&;ls"

../Minishell -t parser "ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto;"

../Minishell -t parser "ls -l | cat -e"

../Minishell -t parser "ls -l | cat -e; cat -e < lol; toto && tata < ta > toto.txt; rm toto;"
