#!/bin/sh

################################################################################
#                              VARIABLES DECLARATION                           #
################################################################################

name_of_exec=$1

################################################################################
################################################################################


path_of_file=`dirname $0`"/.."

	echo "######## TESTING-LEXER #########"
cd `dirname $0`"/../.."
sh ./tests/resources/lexer/lexer.sh $name_of_exec > tests/resources/lexer/lexer_tobetested.out
cd tests
diff -U3 ./resources/lexer/lexer_ok.expected ./resources/lexer/lexer_tobetested.out
