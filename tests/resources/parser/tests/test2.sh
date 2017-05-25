#!/bin/sh

path_of_file=`dirname $0`"/../../.."

#echo "[****** Testing for ' ' *******]"
../Minishell -t parser " "
