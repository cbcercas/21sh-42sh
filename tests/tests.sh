#!/bin/bash

################################################################################
#                              BASE FUNCTION                                   #
################################################################################

help()
{
	echo -e "\nUsage:  ./tests.sh [tests][module]"
		echo -e "\t\033[1;m TESTS:\033[0m"
		echo -e "\t\t -s or --sh  \033[4mmodule\033[0m  It is option for \033[3m\"normal\"\033[0m tests with shell script, based on diff command"
		echo -e "\t\t -b or --bats \033[4mmodule\033[0m  It is option for bats tests. You should install bats before."
		echo -e "\t\t -h  or --help \033[4mmodule\033[0m  display this message\n"
		echo -e "\t\t -v  or --valgrind check leaks with valgrind"
		echo -e "\t\t -v=full  or --valgrind=full check all leaks with valgrind"
		echo -e "\t\t -v=default  or --valgrind=no check all leaks with valgrind"
		echo -e "\t\t -v=no  or --valgrind=no check all leaks with valgrind"
		echo -e
		echo -e "\t\033[1;m MODULE:\033[0m"
		echo -e "\t\t'parser' or 'p'"
		echo -e "\t\t'lexer' or 'l'"
		echo -e "\t\t'env' or 'e'"
		echo -e "\t\t'expand' or 'x'"
		echo -e "\t\t'ast' or 'a'"
		echo -e "\t\t'builtins' or 'b'"
		echo -e "\t\t'all' or 'A' \033[3mAll module [In bats tests: + compile test]\033[0m"
		echo -e
		echo -e "\t\033[1;m REQUIRED:\033[0m"
		echo -e "\t\tyou should have all command: 'diff bash cd echo -e [bats]'"
		echo -e "\t\texemple : .../test.sh -s parser"
}

check_path()
{
	var_path=${PWD##*/}

	if [ $var_path != "tests" ]; then
		echo -e "\033[1;31m"
		echo -e "ERROR, Wrong directory\033[0m"
		echo -e "You should be in .../tests/"
		echo -e "Actualy you are: $PWD"
		help
		exit 1;
	else
		echo -e "\033[1;32m info: Good directory\033[0m"
	fi
}

test_verif_command()
{
	echo -e "\n[--\033[1;4mChecking command:\033[0m--]"
	_needed_commands=$1;

	command -v command >/dev/null 2>&1 || {
			echo -e "WARNING> \"command\" not found. Check requirements skipped !"
			return 1 ;
		}
	for requirement in ${_needed_commands} ; do
		echo -e -n "checking for \"$requirement\" ... " ;
		command -v ${requirement} > /dev/null && {
				echo -e "ok" ;
				continue ;
			} || {
							echo -e "required but not found !" ;
							_return=1 ;
					}
		done
	[ -z "${_return}" ] || {
			echo -e "\033[1;31ERR > Requirement missing.\033[0m" >&2 ;
			exit 1 ;
		}
	echo -e "\033[1;32mDone.\033[0m\n"
}

################################################################################
################################################################################



################################################################################
#                              TEST SH FUNCTION                                #
################################################################################

test_sh()
{
	test_sh_verif
	if [ $# != 1 ]; then
		help
		exit 2;
	elif [ $1 = "A" ] || [ $1 = "all" ]; then
		sh "$path_of_file/"tests_module/test_lexer.sh $name_of_exec
		ret=`expr $ret + $?`
		echo -e "###### END TESTING-LEXER ########"
		echo -e "\n"
		sh "$path_of_file"/tests_module/test_parser.sh $name_of_exec
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "parser" ] || [ $1 = "p" ]; then
		sh "$path_of_file/"tests_module/test_parser.sh $name_of_exec
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "lexer" ] || [ $1 = "l" ]; then
		sh "$path_of_file/"tests_module/test_lexer.sh $name_of_exec
		ret=`expr $ret + $?`
		echo -e "###### END TESTING-LEXER ########"
		return 0;
	else
		help
		exit 1;
	fi
}

test_sh_verif()
{
	if [ -f "$path_of_file/../$name_of_exec" ]
		then
		echo -e "\033[1;32m info: bin: $name_of_exec find\033[0m"
		else
		echo -e "\033[1;31m bin: $name_of_exec doesn't exist \033[0m"
		echo -e "don't forget command 'make'"
		exit 1;
	fi
	test_verif_command "echo sh bash diff cd"
}

################################################################################
################################################################################



################################################################################
#                              BATS FUNCTION                                   #
################################################################################
test_bats_verif()
{
	if [ "$var_test_bats" != "A" ] && [ "$var_test_bats" != "all" ]
	then
		if [ -f "$path_of_file/../$name_of_exec" ]
		then
				echo -e "\033[1;32m info: bin: $name_of_exec find\033[0m"
		else
				echo -e "\033[1;31m bin: $name_of_exec doesn't exist \033[0m"
				echo -e "don't forget command 'make'"
				exit 1;
		fi
	fi
	if [[ $TESTS_CHECK_LEAKS -eq 0 ]]; then
		test_verif_command "bats echo sh bash env"
	else
		test_verif_command "bats echo sh bash env valgrind"
	fi
}

test_bats()
{
	test_bats_verif
	if [ $# != 1 ]; then
		help
		exit 2;
	elif [ $1 = "A" ] || [ $1 = "all" ]; then
		bats $path_of_file"/tests_bats/compile_test.bats" $path_of_file"/tests_bats/lexer.bats" $path_of_file"/tests_bats/parser.bats" $path_of_file"/tests_bats/env.bats" $path_of_file"/tests_bats/tests_expand.bats" $path_of_file"/tests_bats/ast.bats" $path_of_file"/tests_bats/exec.bats" $path_of_file"/tests_bats/builtins.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "parser" ] || [ $1 = "p" ]; then
		bats $path_of_file"/tests_bats/parser.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "lexer" ] || [ $1 = "l" ]; then
		bats $path_of_file"/tests_bats/lexer.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "env" ] || [ $1 = "e" ]; then
		bats $path_of_file"/tests_bats/env.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "expand" ] || [ $1 = "x" ]; then
		bats $path_of_file"/tests_bats/tests_expand.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "ast" ] || [ $1 = "a" ]; then
		bats $path_of_file"/tests_bats/ast.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "exec" ] || [ $1 = "execution" ]; then
		bats $path_of_file"/tests_bats/exec.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "builtins" ] || [ $1 = "b" ]; then
		bats $path_of_file"/tests_bats/builtins.bats"
		ret=`expr $ret + $?`
		return 0;
	else
		#help
		echo -e "../test.sh -h : for display help\n"
		exit 1;
	fi;
}

################################################################################
################################################################################


################################################################################
#                              TRAVIS FUNCTION                                 #
################################################################################

tests_travis()
{
	if [ -z ${TRAVIS_BRANCH} ]; then
		echo -e "\n[var \$TRAVIS_BRANCH not found]\n"
		echo -e "../test.sh -h : for display help\n"
		exit 1;
	fi
	if [ ${TRAVIS_BRANCH} = "lexer" ]; then
		test_bats 'lexer'
	elif [ ${TRAVIS_BRANCH} = "parser" ] || [ ${TRAVIS_BRANCH} = "parser2" ]; then
		test_bats 'parser'
	elif [ ${TRAVIS_BRANCH} = "master" ]; then
		test_bats 'A'
	elif [ ${TRAVIS_BRANCH} = "env" ] || [ ${TRAVIS_BRANCH} = "environ" ]; then
		test_bats 'env'
	elif [ ${TRAVIS_BRANCH} = "exp" ] || [ ${TRAVIS_BRANCH} = "expand" ]; then
		test_bats 'expand'
	elif [ ${TRAVIS_BRANCH} = "ast" ] || [ ${TRAVIS_BRANCH} = "AST" ]; then
		test_bats 'ast'
	elif [ ${TRAVIS_BRANCH} = "exec" ] || [ ${TRAVIS_BRANCH} = "ex" ]; then
		test_bats 'exec'
	else
		echo -e "Tests doesn't exist for branch: ${TRAVIS_BRANCH}"
		echo -e "Create an issue to ask new tests for this branch"
		exit 0;
	fi
}

################################################################################
################################################################################


################################################################################
#                              VARIABLES DECLARATION                           #
################################################################################
path_of_file=`dirname $0`
ret=0
name_of_exec="21sh"

var_test_bats=""
var_tests_sh="1"
var_test_valgrind=0
export TESTS_CHECK_LEAKS=0
################################################################################
################################################################################

if [ $# = 0 ]; then
	tests_travis
fi

#-- This module converts the long arguments into shorter ones for getopt --#
for arg in "$@"; do
  shift
  case "$arg" in
    "--help") set -- "$@" "-h" ;;
    "--bats") set -- "$@" "-b" ;;
    "--sh")   set -- "$@" "-s" ;;
		"--valgrind")   set -- "$@" "-v" ;;
    *)        set -- "$@" "$arg" ;;
  esac
done

for args in "$@"; do
  shift
  case "$args" in
		"-v")   set -- "$@" "-v 1" ;;
		"-v=full")   set -- "$@" "-v 2" ;;
		"-v=default")   set -- "$@" "-v 1" ;;
		"-v=no")   set -- "$@" "-v 0" ;;
		"--valgrind")   set -- "$@" "-v 1" ;;
		"--valgrind=full")   set -- "$@" "-v 2" ;;
		"--valgrind=default")   set -- "$@" "-v 1" ;;
		"--valgrind=no")   set -- "$@" "-v 0" ;;
    *)        set -- "$@" "$args" ;;
  esac
done

while getopts ":s:b:hv:" option
do
	case $option in
		s)
		echo -e "\033[1;33m \n================================================================\n"
		echo -e "\033[1;33m███████╗██╗  ██╗    ████████╗███████╗███████╗████████╗███████╗
██╔════╝██║  ██║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝
███████╗███████║       ██║   █████╗  ███████╗   ██║   ███████╗
╚════██║██╔══██║       ██║   ██╔══╝  ╚════██║   ██║   ╚════██║
███████║██║  ██║       ██║   ███████╗███████║   ██║   ███████║
╚══════╝╚═╝  ╚═╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝\033[0m"
		echo -e "\033[1;33m \n=================================================================\n\033[0m"
			#check_path
			#var_tests_sh="$OPTARG"
			var_ret= test_sh $OPTARG
			;;
		b)
			var_test_bats="$OPTARG"
			;;
		h)
			help
			exit 1;
			;;
		v)
			echo "arg=$OPTARG"
			export TESTS_CHECK_LEAKS=$OPTARG
			;;
		:)
			echo -e "the option $OPTARG requiert an argument\n"
			echo -e "../test.sh -h : for display help\n"
			exit 1
			;;
		\?)
			echo -e "\"$OPTARG\" : invalid option\n"
			echo -e "../test.sh -h : for display help\n"
			exit 1
		;;
	esac
done
if [[ "$var_test_bats" != "" ]]; then
	echo -e "\033[1;33m \n=================================================================================\n"
	echo -e "\033[1;33m
██████╗  █████╗ ████████╗███████╗    ████████╗███████╗███████╗████████╗███████╗
██╔══██╗██╔══██╗╚══██╔══╝██╔════╝    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝
██████╔╝███████║   ██║   ███████╗       ██║   █████╗  ███████╗   ██║   ███████╗
██╔══██╗██╔══██║   ██║   ╚════██║       ██║   ██╔══╝  ╚════██║   ██║   ╚════██║
██████╔╝██║  ██║   ██║   ███████║       ██║   ███████╗███████║   ██║   ███████║
╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚══════╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝\033[0m"
	echo -e "\033[1;33m \n==================================================================================\n\033[0m"
	if [[ $TESTS_CHECK_LEAKS -eq 1 ]]; then
		echo -e "\033[32;1;3m+++ [[-- VALGRIND TESTS: (It can take a long time.) --]]\033[0m"
	fi
	test_bats $var_test_bats
	rm -rf check_leaks_tmp.log
fi
exit $ret

#TODO: valgrind --trace-children=yes --log-file=toto.log --leak-check=full --track-origins=yes ./21sh
#ajout check leaks comme option
