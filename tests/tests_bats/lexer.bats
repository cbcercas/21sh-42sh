#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            NULL TESTS                               #
#######################################################################
@test "LEXER: Testing [NULL] for NULL" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer ""
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->"
  echo
  [ "${lines[0]}" = "" ]
check_leaks_function lexer
}

@test "LEXER: Testing [NULL] for ' '" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer " "
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->"
  echo
  [ "${lines[0]}" = "" ]
check_leaks_function lexer
}

#######################################################################
#                            'ls' TESTS                               #
#######################################################################

@test "LEXER: Testing [Simple command] for 'l'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "l"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><l> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<l> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple command] for 'ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple command] for '    ls    '" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "    ls    "
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple command] for '        ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "        ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple command] for 'ls          '" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls          "
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

#######################################################################
#                            ls -l TESTS                              #
#######################################################################

@test "LEXER: Testing [Command opt] for 'ls -l'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
	echo "                ${lines[1]}"
	echo "                ${lines[2]}"
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-l> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Command opt] for '      ls -l'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "      ls -l"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
	echo "                ${lines[1]}"
	echo "                ${lines[2]}"
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-l> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Command opt] for 'ls -l      '" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l       "
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
	echo "                ${lines[1]}"
	echo "                ${lines[2]}"
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-l> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Command opt] for 'ls-l'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls-l"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><ls-l> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<ls-l> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Command opt] for 'ls    -   l'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls    -   l"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <->= TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <l> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-> = TOKEN_TYPE_WORD" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<l> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}


#######################################################################
#                            ls -l | cat -e TESTS                     #
#######################################################################

@test "LEXER: Testing [Simple pipe] for 'ls -l | cat -e'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l | cat -e"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-l> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <|> = TOKEN_TYPE_PIPE"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <cat> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-e> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<|> = TOKEN_TYPE_PIPE" ]
	[ "${lines[5]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[6]}" = "<cat> = TOKEN_TYPE_WORD" ]
	[ "${lines[7]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[8]}" = "<-e> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple pipe] for 'ls -l|cat -e'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l|cat -e"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-l> = TOKEN_TYPE_WORD"
	echo "                <|> = TOKEN_TYPE_PIPE"
	echo "                <cat> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-e> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
	[ "${lines[3]}" = "<|> = TOKEN_TYPE_PIPE" ]
	[ "${lines[4]}" = "<cat> = TOKEN_TYPE_WORD" ]
	[ "${lines[5]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[6]}" = "<-e> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple pipe] for 'ls -l| cat -e'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l| cat -e"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-l> = TOKEN_TYPE_WORD"
	echo "                <|> = TOKEN_TYPE_PIPE"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <cat> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-e> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
	[ "${lines[3]}" = "<|> = TOKEN_TYPE_PIPE" ]
	[ "${lines[4]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[5]}" = "<cat> = TOKEN_TYPE_WORD" ]
	[ "${lines[6]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[7]}" = "<-e> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple pipe] for 'ls -l |cat -e'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l |cat -e"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-l> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <|> = TOKEN_TYPE_PIPE"
	echo "                <cat> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <-e> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<|> = TOKEN_TYPE_PIPE" ]
	[ "${lines[5]}" = "<cat> = TOKEN_TYPE_WORD" ]
	[ "${lines[6]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[7]}" = "<-e> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}


#######################################################################
#                            ls ; ls TESTS                            #
#######################################################################

@test "LEXER: Testing [Simple semicolon] for 'ls ; ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls ; ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <;> = TOKEN_TYPE_SEMI"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<;> = TOKEN_TYPE_SEMI" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple semicolon] for 'ls ;ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls ;ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <;> = TOKEN_TYPE_SEMI"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<;> = TOKEN_TYPE_SEMI" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple semicolon] for 'ls; ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls; ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                <;> = TOKEN_TYPE_SEMI"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<;> = TOKEN_TYPE_SEMI" ]
	[ "${lines[2]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple semicolon] for 'ls;ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls;ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                <;> = TOKEN_TYPE_SEMI"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<;> = TOKEN_TYPE_SEMI" ]
	[ "${lines[2]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

#######################################################################
#                            ls || ls TESTS                           #
#######################################################################


@test "LEXER: Testing [Double pipe] for 'ls || ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls || ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <||> = TOKEN_TYPE_OR_IF"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<||> = TOKEN_TYPE_OR_IF" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Double pipe] for 'ls ||ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls ||ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <||> = TOKEN_TYPE_OR_IF"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<||> = TOKEN_TYPE_OR_IF" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Double pipe] for 'ls|| ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls|| ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                <||> = TOKEN_TYPE_OR_IF"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<||> = TOKEN_TYPE_OR_IF" ]
	[ "${lines[2]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Double pipe] for 'ls||ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls||ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                <||> = TOKEN_TYPE_OR_IF"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<||> = TOKEN_TYPE_OR_IF" ]
	[ "${lines[2]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}


#######################################################################
#                            ls && ls TESTS                           #
#######################################################################


@test "LEXER: Testing [Double ampersand] for 'ls && ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls && ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <&&> = TOKEN_TYPE_AND_IF"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<&&> = TOKEN_TYPE_AND_IF" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Double ampersand] for 'ls &&ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls &&ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <&&> = TOKEN_TYPE_AND_IF"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<&&> = TOKEN_TYPE_AND_IF" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Double ampersand] for 'ls&& ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls&& ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                <&&> = TOKEN_TYPE_AND_IF"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<&&> = TOKEN_TYPE_AND_IF" ]
	[ "${lines[2]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}

@test "LEXER: Testing [Double ampersand] for 'ls&&ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls&&ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
	echo "                <&&> = TOKEN_TYPE_AND_IF"
	echo "                <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<&&> = TOKEN_TYPE_AND_IF" ]
	[ "${lines[2]}" = "<ls> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}


#######################################################################
#                            ls & ls TESTS                           #
#######################################################################


@test "LEXER: Testing [Simple ampersand] for 'ls & ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls & ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->$name_exec: Lexing error."
	echo
  [ "${lines[0]}" = "$name_exec: Lexing error." ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple ampersand] for 'ls &ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls &ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->$name_exec: Lexing error."
	echo
  [ "${lines[0]}" = "$name_exec: Lexing error." ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple ampersand] for 'ls& ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls& ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->$name_exec: Lexing error."
	echo
  [ "${lines[0]}" = "$name_exec: Lexing error." ]
check_leaks_function lexer
}

@test "LEXER: Testing [Simple ampersand] for 'ls&ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls&ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->$name_exec: Lexing error."
	echo
  [ "${lines[0]}" = "$name_exec: Lexing error." ]
check_leaks_function lexer
}


#######################################################################
#                              Other tests                            #
#######################################################################

@test "LEXER: Testing [Other Test] for 'cd 21-42sh'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "cd 21-42sh"
  echo "ERROR:"
    display_line_output
    echo
  echo "$name_exec EXPECTED -><cd> = TOKEN_TYPE_WORD"
	echo "                < > = TOKEN_TYPE_BLANK"
	echo "                <21-42sh> = TOKEN_TYPE_WORD"
    echo
  [ "${lines[0]}" = "<cd> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<21-42sh> = TOKEN_TYPE_WORD" ]
check_leaks_function lexer
}
