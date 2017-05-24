#!/bin/sh

#echo "[****** Testing for 'ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto;' *]"
../Minishell -t parser "ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto;"
