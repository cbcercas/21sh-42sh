#!/bin/sh

path_of_file=`dirname $0`"/../../.."

#echo "[****** Testing for ;ls ******]"
$path_of_file/../Minishell -t parser ";ls"

#echo "[****** Testing for ;;ls ******]"
$path_of_file/../Minishell -t parser ";;ls"

#echo "[****** Testing for ls; ******]"
$path_of_file/../Minishell -t parser "ls;;"

#echo "[****** Testing for ;ls ******]"
$path_of_file/../Minishell -t parser "ls;"

#echo "[****** Testing for ;ls ******]"
$path_of_file/../Minishell -t parser ";"

#echo "[****** Testing for ;ls ******]"
$path_of_file/../Minishell -t parser ";;"

#echo "[****** Testing for ;ls ******]"
$path_of_file/../Minishell -t parser "qsdsdqs;;qsdqsdq"
