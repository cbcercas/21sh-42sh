#!/bin/sh

path_of_file=`dirname $0`"/../../.."
name_of_exec=$1

#echo "[*** Testing for 'ls && ls' ***]"
$path_of_file/../$name_of_exec -t parser "ls && ls"
