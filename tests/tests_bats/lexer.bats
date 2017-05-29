#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            NULL TESTS                               #
#######################################################################
@test "Lexer: Testing for NULL" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer ""
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->"
  echo
  [ "${lines[0]}" = "" ]
}

@test "Lexer: Testing for ' '" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer " "
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->"
  echo
  [ "${lines[0]}" = "" ]
}

#######################################################################
#                            'ls' TESTS                               #
#######################################################################

@test "Lexer: Testing for 'l'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "l"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><l> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<l> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for '    ls    '" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "    ls    "
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for '        ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "        ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls          '" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls          "
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><ls> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

#######################################################################
#                            ls -l TESTS                              #
#######################################################################

@test "Lexer: Testing for 'ls -l'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l"
  echo "ERROR:"
  echo "$name_exec OUTPUT   -> ${lines[0]}"
	echo "                      ${lines[1]}"
	echo "                      ${lines[2]}"
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-l> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for '      ls -l'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "      ls -l"
  echo "ERROR:"
  echo "$name_exec OUTPUT   -> ${lines[0]}"
	echo "                      ${lines[1]}"
	echo "                      ${lines[2]}"
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-l> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls -l      '" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l       "
  echo "ERROR:"
  echo "$name_exec OUTPUT   -> ${lines[0]}"
	echo "                      ${lines[1]}"
	echo "                      ${lines[2]}"
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-l> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls-l'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls-l"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED -><ls-l> = TOKEN_TYPE_WORD"
  echo
  [ "${lines[0]}" = "<ls-l> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls    -   l'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls    -   l"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <l> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-> = TOKEN_TYPE_WORD" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<l> = TOKEN_TYPE_WORD" ]
}


#######################################################################
#                            ls -l | cat -e TESTS                     #
#######################################################################

@test "Lexer: Testing for 'ls -l | cat -e'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l | cat -e"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-l> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <|> = TOKEN_TYPE_PIPE"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <cat> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-e> = TOKEN_TYPE_WORD"
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
}

@test "Lexer: Testing for 'ls -l|cat -e'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l|cat -e"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-l> = TOKEN_TYPE_WORD"
	echo "                      <|> = TOKEN_TYPE_PIPE"
	echo "                      <cat> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-e> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
	[ "${lines[3]}" = "<|> = TOKEN_TYPE_PIPE" ]
	[ "${lines[4]}" = "<cat> = TOKEN_TYPE_WORD" ]
	[ "${lines[5]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[6]}" = "<-e> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls -l| cat -e'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l| cat -e"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-l> = TOKEN_TYPE_WORD"
	echo "                      <|> = TOKEN_TYPE_PIPE"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <cat> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-e> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
	[ "${lines[3]}" = "<|> = TOKEN_TYPE_PIPE" ]
	[ "${lines[4]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[5]}" = "<cat> = TOKEN_TYPE_WORD" ]
	[ "${lines[6]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[7]}" = "<-e> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls -l |cat -e'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls -l |cat -e"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-l> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <|> = TOKEN_TYPE_PIPE"
	echo "                      <cat> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <-e> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<-l> = TOKEN_TYPE_WORD" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<|> = TOKEN_TYPE_PIPE" ]
	[ "${lines[5]}" = "<cat> = TOKEN_TYPE_WORD" ]
	[ "${lines[6]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[7]}" = "<-e> = TOKEN_TYPE_WORD" ]
}


#######################################################################
#                            ls ; ls TESTS                            #
#######################################################################

@test "Lexer: Testing for 'ls ; ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls ; ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <;> = TOKEN_TYPE_SEMI"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<;> = TOKEN_TYPE_SEMI" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls ;ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls ;ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <;> = TOKEN_TYPE_SEMI"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<;> = TOKEN_TYPE_SEMI" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls; ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls; ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      <;> = TOKEN_TYPE_SEMI"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<;> = TOKEN_TYPE_SEMI" ]
	[ "${lines[2]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls;ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls;ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      <;> = TOKEN_TYPE_SEMI"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<;> = TOKEN_TYPE_SEMI" ]
	[ "${lines[2]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

#######################################################################
#                            ls || ls TESTS                           #
#######################################################################


@test "Lexer: Testing for 'ls || ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls || ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <||> = TOKEN_TYPE_OR_IF"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<||> = TOKEN_TYPE_OR_IF" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls ||ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls ||ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <||> = TOKEN_TYPE_OR_IF"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<||> = TOKEN_TYPE_OR_IF" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls|| ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls|| ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      <||> = TOKEN_TYPE_OR_IF"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<||> = TOKEN_TYPE_OR_IF" ]
	[ "${lines[2]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls||ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls||ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      <||> = TOKEN_TYPE_OR_IF"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<||> = TOKEN_TYPE_OR_IF" ]
	[ "${lines[2]}" = "<ls> = TOKEN_TYPE_WORD" ]
}


#######################################################################
#                            ls && ls TESTS                           #
#######################################################################


@test "Lexer: Testing for 'ls && ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls && ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <&&> = TOKEN_TYPE_AND_IF"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<&&> = TOKEN_TYPE_AND_IF" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls &&ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls &&ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <&&> = TOKEN_TYPE_AND_IF"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<&&> = TOKEN_TYPE_AND_IF" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls&& ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls&& ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      <&&> = TOKEN_TYPE_AND_IF"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<&&> = TOKEN_TYPE_AND_IF" ]
	[ "${lines[2]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls&&ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls&&ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      <&&> = TOKEN_TYPE_AND_IF"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<&&> = TOKEN_TYPE_AND_IF" ]
	[ "${lines[2]}" = "<ls> = TOKEN_TYPE_WORD" ]
}


#######################################################################
#                            ls & ls TESTS                           #
#######################################################################


@test "Lexer: Testing for 'ls & ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls & ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <&> = TOKEN_TYPE_AND"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<&> = TOKEN_TYPE_AND" ]
	[ "${lines[3]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[4]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls &ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls &ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <&> = TOKEN_TYPE_AND"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[2]}" = "<&> = TOKEN_TYPE_AND" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls& ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls& ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      <&> = TOKEN_TYPE_AND"
	echo "                      < > = TOKEN_TYPE_BLANK"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<&> = TOKEN_TYPE_AND" ]
	[ "${lines[2]}" = "< > = TOKEN_TYPE_BLANK" ]
	[ "${lines[3]}" = "<ls> = TOKEN_TYPE_WORD" ]
}

@test "Lexer: Testing for 'ls&ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "ls&ls"
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED -> <ls> = TOKEN_TYPE_WORD"
	echo "                      <&> = TOKEN_TYPE_AND"
	echo "                      <ls> = TOKEN_TYPE_WORD"
	echo
  [ "${lines[0]}" = "<ls> = TOKEN_TYPE_WORD" ]
	[ "${lines[1]}" = "<&> = TOKEN_TYPE_AND" ]
	[ "${lines[2]}" = "<ls> = TOKEN_TYPE_WORD" ]
}
