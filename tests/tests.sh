#!/bin/bash

################################################################################
#                              BASE FUNCTION                                   #
################################################################################

help()
{
	echo -e "\nUsage:  ./tests.sh [tests][module]"
		echo -e "\t\033[1;m TESTS:\033[0m"
		echo -e "\t\t -s  \033[4mmodule\033[0m  It is option for \033[3m\"normal\"\033[0m tests with shell script, based on diff command"
		echo -e "\t\t -b  \033[4mmodule\033[0m  It is option for bats tests. You should install bats before."
		echo -e "\t\t -h  \033[4mmodule\033[0m  display this message"
		echo -e
		echo -e "\t\033[1;m MODULE:\033[0m"
		echo -e "\t\t'parser' or 'p'"
		echo -e "\t\t'lexer' or 'l'"
		echo -e "\t\t'env' or 'e'"
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
	echo -e "\n\033[1;4mChecking command:\033[0m"
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
			echo -e "ERR > Requirement missing." >&2 ;
			exit 1 ;
		}
	echo -e "Done.\n"
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
	if [ -f "$path_of_file/../$name_of_exec" ]
		then
		echo -e "\033[1;32m info: bin: $name_of_exec find\033[0m"
		else
		echo -e "\033[1;31m bin: $name_of_exec doesn't exist \033[0m"
		echo -e "don't forget command 'make'"
		exit 1;
	fi
	test_verif_command "bats echo sh bash env"
}

test_bats()
{
	test_bats_verif
	if [ $# != 1 ]; then
		help
		exit 2;
	elif [ $1 = "A" ] || [ $1 = "all" ]; then
		bats $path_of_file"/tests_bats/compile_test.bats" $path_of_file"/tests_bats/lexer.bats" $path_of_file"/tests_bats/parser.bats" $path_of_file"/tests_bats/env.bats"
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
	else
		help
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
	elif [ ${TRAVIS_BRANCH} = "parser" ]; then
		test_bats 'parser'
	elif [ ${TRAVIS_BRANCH} = "master" ]; then
		test_bats 'A'
	elif [ ${TRAVIS_BRANCH} = "env" ] || [ ${TRAVIS_BRANCH} = "environ" ]; then
		test_bats 'env'
	else
		echo -e "Tests doesn't exist for branch: ${TRAVIS_BRANCH}"
		echo -e "Create an issue to ask new tests for this branch"
		exit 1;
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
################################################################################
################################################################################


if [ $# = 0 ]; then
	tests_travis
fi

while getopts ":s:b:h" option
do
	case $option in
		s)
			echo -e "\n##################################"
			echo -e "######## Tests mode: sh ##########"
			echo -e "##################################"
			#check_path
			var_ret= test_sh $OPTARG
			;;
		b)
			echo -e "\n##################################"
			echo -e "######## Tests mode: bats ########"
			echo -e "##################################"
			#check_path
			test_bats $OPTARG
			;;
		h)
			help
			exit 1;
			;;
		:)
			echo -e "the option $OPTARG requiert an argument"
			exit 1
			;;
		\?)
			echo -e "\"$OPTARG\" : invalid option"
			exit 1
		;;
	esac
done
exit $ret
