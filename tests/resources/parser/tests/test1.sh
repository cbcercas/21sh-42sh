#!/bin/sh

path_of_file=`dirname $0`"/../../.."

#echo "[****** Testing for NULL ******]"
$path_of_file/../Minishell -t parser ""
