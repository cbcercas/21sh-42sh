help()
{
	echo "Usage:  ./tests.sh [module]\n\n"
	echo "\tmodule:"
	echo "\t\tparser"
	echo "\t\tlexer"
	echo "\t\tall(all test)"
}


var_path=${PWD##*/}

if [ $var_path != "tests" ]; then
	echo "\033[1;31m"
	echo "ERROR, Wrong directory\033[0m"
	echo "You should be in .../tests/"
	echo "Actualy you are: $PWD"
	exit 1;
else
	echo "\033[1;32m info: Good directory\033[0m"
fi

if [ -f "../Minishell" ]
then
	echo "\033[1;32m info: bin: Minishell find\033[0m"
else
	echo "\033[1;31m bin: Minishell doesn't exist \033[0m"
	echo "don't forget command 'make'"
	exit 1;
fi

if [ $# != 1 ]; then
	help
	exit 2;
elif [ $1 = "all" ]; then
	sh tests_module/test_lexer.sh
	echo "\n"
	sh tests_module/test_parser.sh
	exit 0;
elif [ $1 = "parser" ]; then
	sh tests_module/test_parser.sh
	exit 0;
elif [ $1 = "lexer" ]; then
	sh tests_module/test_lexer.sh
	exit 0;
else
	help
	exit 2;
fi
