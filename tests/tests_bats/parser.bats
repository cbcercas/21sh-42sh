#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            NO ERROR TESTS                           #
#######################################################################
@test "Parser: Testing for NULL" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser ""
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for ' '" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser " "
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls -l'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls -l | cat -e'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l | cat -e"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls -l | cat -e | pleins | de  | pipe'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l | cat -e | pleins | de  | pipe"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls ; ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls ; ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls ; ls ; ls ; ls ; ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls ; ls ; ls ; ls ; ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls || ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls || ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls || ls || ls || ls || ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls || ls || ls || ls || ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls && ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls && ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls && ls && ls && ls && ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls && ls && ls && ls && ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls & ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls & ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls & ls & ls & ls & ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls & ls & ls & ls & ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls -l | cat -e | lol | maman'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l | cat -e | lol | maman"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls;'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls;"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls;toto;'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls;toto;"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto.txt;'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto.txt;"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for '<ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "<ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "Parser: Testing for 'ls -l | cat -e; cat -e < lol; toto && tata < ta > toto.txt; rm toto'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l | cat -e; cat -e < lol; toto && tata < ta > toto.txt; rm toto"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

######################################################################
######################################################################


#######################################################################
#                            ERROR TESTS                              #
#######################################################################
@test "Parser error: Testing for '|ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "|ls"
  [ "${lines[0]}" = "${parser_error_simple_p}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for '||ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "||ls"
  [ "${lines[0]}" = "${parser_error_double_p}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for '&ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "&ls"
  [ "${lines[0]}" = "${parser_error_simple_es}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for '&&ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "&&ls"
  [ "${lines[0]}" = "${parser_error_double_es}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for 'ls&&'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls&&"
  [ "${lines[0]}" = "${parser_error_simple_e}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for '&ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "&ls"
  [ "${lines[0]}" = "${parser_error_simple_e}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for 'ls>'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls>"
  [ "${lines[0]}" = "${parser_error_newline}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for 'ls>>'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls>>"
  [ "${lines[0]}" = "${parser_error_newline}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for ';ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser ";ls"
  [ "${lines[0]}" = "${parser_error_simple_pv}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for ';;ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser ";;ls"
  [ "${lines[0]}" = "${parser_error_double_pv}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for ls;; " {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser 'ls;;'
  [ "${lines[0]}" = "${parser_error_double_pv}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for ';'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser ";"
  [ "${lines[0]}" = "${parser_error_simple_pv}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for ';;'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser ";;"
  [ "${lines[0]}" = "${parser_error_double_pv}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for 'abc;;abc'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "abc;;abc"
  [ "${lines[0]}" = "${parser_error_double_pv}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for 'abc&&&&'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "abc&&&&"
  [ "${lines[0]}" = "${parser_error_double_es}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for 'ls |&|'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls |&|"
  [ "${lines[0]}" = "${parser_error_simple_p}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for 'ls ||&;ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls ||&;ls"
  [ "${lines[0]}" = "${parser_error_simple_es}" ]
  [ "$status" -eq 1 ]
}
######################################################################
######################################################################


#######################################################################
#                            TAKSMASTER TESTS                         #
#######################################################################

@test "Parser: Testing TASKMASTER 'ls&'" {
  skip
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls&s"
  [ "${lines[0]}" = "${parser_error_simple_p}" ]
  [ "$status" -eq 1 ]
}
######################################################################
######################################################################


#######################################################################
#                            SKIP TESTS                               #
#######################################################################
@test "Parser error: Testing for 'sdfdsf; sfdsdf; ; sdfsdffd|| sdffd;sdfsdf '" {
  skip
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "sdfdsf; sfdsdf; ; sdfsdffd|| sdffd;sdfsdf "
  [ "${lines[0]}" = "${parser_error_simple_pv}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for '<<ls'" {
  skip
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls>"
  [ "${lines[0]}" = "${parser_error_newline}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for 'ls|'" {
  skip
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls|"
  [ "${lines[0]}" = "${parser_error_simple_p}" ]
  [ "$status" -eq 1 ]
}

@test "Parser error: Testing for 'ls||'" {
  skip
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls||"
  [ "${lines[0]}" = "${parser_error_double_p}" ]
  [ "$status" -eq 1 ]
}
######################################################################
######################################################################
