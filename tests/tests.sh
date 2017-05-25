#!/bin/sh

################################################################################
#                              BASE FUNCTION                                   #
################################################################################

help()
{
	echo "\nUsage:  ./tests.sh [tests][module]"
		echo "\t\033[1;m TESTS:\033[0m"
		echo "\t\t -s  \033[4mmodule\033[0m  It is option for \033[3m\"normal\"\033[0m tests with shell script, based on diff command"
		echo "\t\t -b  \033[4mmodule\033[0m  It is option for bats tests. You should install bats before."
		echo "\t\t -h  \033[4mmodule\033[0m  display this message"
		echo
		echo "\t\033[1;m MODULE:\033[0m"
		echo "\t\tparser or 'p'"
		echo "\t\tlexer or 'l'"
		echo "\t\tall or 'A' \033[3mAll module [In bats tests: + compile test]\033[0m"
		echo
		echo "\t\033[1;m UTILISATION:\033[0m"
		echo "\t\tYou should be in good directory: ../tests/"
		echo "\t\tyou should have all command: 'diff bash cd echo [bats]'"
}

check_path()
{
	var_path=${PWD##*/}

	if [ $var_path != "tests" ]; then
		echo "\033[1;31m"
		echo "ERROR, Wrong directory\033[0m"
		echo "You should be in .../tests/"
		echo "Actualy you are: $PWD"
		help
		exit 1;
	else
		echo "\033[1;32m info: Good directory\033[0m"
	fi
}

test_verif_command()
{
	echo "\n\033[1;4mChecking command:\033[0m"
	_needed_commands=$1;

	command -v command >/dev/null 2>&1 || {
			echo "WARNING> \"command\" not found. Check requirements skipped !"
			return 1 ;
		}
	for requirement in ${_needed_commands} ; do
		echo -n "checking for \"$requirement\" ... " ;
		command -v ${requirement} > /dev/null && {
				echo "ok" ;
				continue ;
			} || {
							echo "required but not found !" ;
							_return=1 ;
					}
		done
	[ -z "${_return}" ] || {
			echo "ERR > Requirement missing." >&2 ;
			exit 1 ;
		}
	echo "Done.\n"
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
		sh tests_module/test_lexer.sh
		echo "\n"
		sh tests_module/test_parser.sh
		return 0;
	elif [ $1 = "parser" ] || [ $1 = "p" ]; then
		sh tests_module/test_parser.sh
		return 0;
	elif [ $1 = "lexer" ] || [ $1 = "l" ]; then
		sh tests_module/test_lexer.sh
		return 0;
	else
		help
		exit 1;
	fi
}

test_sh_verif()
{
	if [ -f "../Minishell" ]
		then
		echo "\033[1;32m info: bin: Minishell find\033[0m"
		else
		echo "\033[1;31m bin: Minishell doesn't exist \033[0m"
		echo "don't forget command 'make'"
		exit 1;
	fi
	test_verif_command "echo sh bash diff cd"
}

################################################################################
################################################################################



################################################################################
#                              BATS FUNCTION                                   #
################################################################################
test_bats()
{
	test_verif_command "bats echo sh bash"
	if [ $# != 1 ]; then
		help
		exit 2;
	elif [ $1 = "A" ] || [ $1 = "all" ]; then
		bats tests_bats/compile_test.bats
		echo "\n"
		echo "lexer testing bats doesn't exist"
		echo "\n"
		bats tests_bats/parser.bats
		return 0;
	elif [ $1 = "parser" ] || [ $1 = "p" ]; then
		bats tests_bats/parser.bats
		return 0;
	elif [ $1 = "lexer" ] || [ $1 = "l" ]; then
		echo "lexer testing bats doesn't exist"
		return 0;
	else
		help
		exit 1;
	fi;
}

################################################################################
################################################################################


if [ $# = 0 ]; then
	help
	exit
fi

while getopts ":s:b:h" option
do
	case $option in
		s)
			echo "\n##################################"
			echo "######## Tests mode: sh ##########"
			echo "##################################"
			check_path
			var_ret= test_sh $OPTARG
			;;
		b)
			echo "\n##################################"
			echo "######## Tests mode: bats ########"
			echo "##################################"
			check_path
			test_bats $OPTARG
			;;
		h)
			help
			exit 1;
			;;
		:)
			echo "the option $OPTARG requiert an argument"
			exit 1
			;;
		\?)
			echo "\"$OPTARG\" : invalid option"
			exit 1
		;;
	esac
done
exit 0
