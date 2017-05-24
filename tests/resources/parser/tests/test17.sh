#!/bin/sh

#echo "[****** Testing for <ls ******]"
../Minishell -t parser "<ls"

#echo "[****** Testing for ls> ******]"
../Minishell -t parser "ls>"

#echo "[****** Testing for <<ls ******]"
../Minishell -t parser "<<ls"

#echo "[****** Testing for ls>> ******]"
../Minishell -t parser "ls>>"
