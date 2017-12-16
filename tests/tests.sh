#!/bin/bash

################################################################################
#                              CREATE FUNCTION                                   #
################################################################################

load_bar()
{
	nb=$(($1/2))
	echo -ne "   ["
for i in `seq 1 "$nb"`;
do
	if [ $1 -le 40 ]; then
		echo -ne "\033[1;31m"
	elif [ $1 -le 60 ]; then
		echo -ne "\033[1;33m"
	elif [ $1 -le 70 ]; then
		echo -ne "\033[1;35m"
	else
		echo -ne "\033[1;32m"
	fi
        echo -ne "#"
done
echo -ne "\033[1;0m]\r"
echo -ne "($1%)"
}

create_test()
{
	file_bats="$path_of_file/tests_bats/create.bats"
	file_txt="$path_of_file/tests_bats/create.txt"
	nb_ligne=$(wc -l < "$file_txt")
	cnt=0
	echo -e "\n\033[1;36;1;4;5;7mCREATING TESTS LOAD in $file_txt > $file_bats!!\n\033[1;0m nb linges = ($nb_ligne)\n"
	echo "#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            IN CORRECTION                            #
#######################################################################" > $file_bats

	while read -r line
	do
		name="$line"
		echo '@test "EXEC: Testing [CREATE] for '"$name"'" {
    expect=`'"$name"'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c' "'$name'"'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}' >> "$file_bats"
sleep 0.01
(( count++ ))
load_bar $(($count * 100 /$nb_ligne)) $name
	done < "$file_txt"
	echo ""
}

################################################################################
################################################################################


################################################################################
#                              BASE FUNCTION                                   #
################################################################################

help_usage()
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
		help_usage
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
		help_usage
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
		help_usage
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
		help_usage
		exit 2;
	elif [ $1 = "A" ] || [ $1 = "all" ]; then
		create_test
		bats "$path_of_file/tests_bats/create.bats" $path_of_file"/tests_bats/lexer.bats" $path_of_file"/tests_bats/parser.bats" $path_of_file"/tests_bats/env.bats" $path_of_file"/tests_bats/expand.bats" $path_of_file"/tests_bats/ast.bats" $path_of_file"/tests_bats/exec.bats" $path_of_file"/tests_bats/builtins.bats"
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
		bats $path_of_file"/tests_bats/expand.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "ast" ] || [ $1 = "a" ]; then
		bats $path_of_file"/tests_bats/ast.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "exec" ] || [ $1 = "execution" ]; then
		create_test
		bats "$path_of_file/tests_bats/create.bats" $path_of_file"/tests_bats/exec.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "builtins" ] || [ $1 = "b" ]; then
		bats $path_of_file"/tests_bats/builtins.bats"
		ret=`expr $ret + $?`
		return 0;
	elif [ $1 = "malloc" ] || [ $1 = "m" ]; then
		cp $path_of_file/resources/.21sh_history.resource ~/.21sh_history
		bats $path_of_file"/tests_bats/malloc.bats"
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
	export TEST_BATS_SAN="yes"
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
		"--San")   set -- "$@" "-S 0" ;;
    *)        set -- "$@" "$args" ;;
  esac
done

while getopts ":s:b:hv:S" option
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
			help_usage
			exit 1;
			;;
		S)
			if [[ "$TESTS_CHECK_LEAKS" = "0" ]]; then
				export TEST_BATS_SAN="yes"
				bats $path_of_file/tests_bats/compile_test.bats
			else
				echo "S and V are incompatible"
				exit 2
			fi
			;;
		v)
			if [[ $TEST_BATS_SAN != "yes" ]]; then
				echo "arg=$OPTARG"
				export TESTS_CHECK_LEAKS=$OPTARG
			else
				echo "S and V are incompatible"
				exit 2
			fi
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
