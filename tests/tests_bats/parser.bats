#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            NO ERROR TESTS                           #
#######################################################################
@test "PARSER: Testing [OK] for NULL" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser ""
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for ' '" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser " "
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls -l'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls -l | cat -e'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l | cat -e"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls -l | cat -e | pleins | de  | pipe'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l | cat -e | pleins | de  | pipe"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls ; ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls ; ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls ; ls ; ls ; ls ; ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls ; ls ; ls ; ls ; ls"
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls || ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls || ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls || ls || ls || ls || ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls || ls || ls || ls || ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls && ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls && ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls && ls && ls && ls && ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls && ls && ls && ls && ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls & ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls & ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls & ls & ls & ls & ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls & ls & ls & ls & ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls -l | cat -e | lol | maman'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l | cat -e | lol | maman"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls;'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls;"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls;toto;'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls;toto;"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto.txt;'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l | cat -e; cat -e < lol; ls > toto.txt; rm toto.txt;"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for '<ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "<ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

@test "PARSER: Testing [OK] for 'ls -l | cat -e; cat -e < lol; toto && tata < ta > toto.txt; rm toto'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls -l | cat -e; cat -e < lol; toto && tata < ta > toto.txt; rm toto"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${okparser}"
  echo
  [ "${lines[0]}" = "${okparser}" ]
  [ "$status" -eq 0 ]
}

######################################################################
######################################################################


#######################################################################
#                            ERROR TESTS                              #
#######################################################################
@test "PARSER: Testing [Error] for '|ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "|ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_simple_p}"
  echo
  [ "${lines[0]}" = "${parser_error_simple_p}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for '||ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "||ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_double_p}"
  echo
  [ "${lines[0]}" = "${parser_error_double_p}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for '&ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "&ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_simple_es}"
  echo
  [ "${lines[0]}" = "${parser_error_simple_es}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for '&&ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "&&ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_double_es}"
  echo
  [ "${lines[0]}" = "${parser_error_double_es}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for '&ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "&ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_simple_es}"
  echo
  [ "${lines[0]}" = "${parser_error_simple_es}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for 'ls>'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls>"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_newline}"
  echo
  [ "${lines[0]}" = "${parser_error_newline}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for 'ls>>'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls>>"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_newline}"
  echo
  [ "${lines[0]}" = "${parser_error_newline}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for ';ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser ";ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_simple_pv}"
  echo
  [ "${lines[0]}" = "${parser_error_simple_pv}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for ';;ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser ";;ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_double_pv}"
  echo
  [ "${lines[0]}" = "${parser_error_double_pv}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for ls;; " {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser 'ls;;'
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_double_pv}"
  echo
  [ "${lines[0]}" = "${parser_error_double_pv}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for ';'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser ";"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_simple_pv}"
  echo
  [ "${lines[0]}" = "${parser_error_simple_pv}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for ';;'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser ";;"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_double_pv}"
  echo
  [ "${lines[0]}" = "${parser_error_double_pv}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for 'abc;;abc'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "abc;;abc"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_double_pv}"
  echo
  [ "${lines[0]}" = "${parser_error_double_pv}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for 'abc&&&&'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "abc&&&&"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_double_es}"
  echo
  [ "${lines[0]}" = "${parser_error_double_es}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for 'ls |&|'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls |&|"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_simple_p}"
  echo
  [ "${lines[0]}" = "${parser_error_simple_p}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for 'ls ||&;ls'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls ||&;ls"
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_simple_es}"
  echo
  [ "${lines[0]}" = "${parser_error_simple_es}" ]
  [ "$status" -eq 1 ]
}
######################################################################
######################################################################


#######################################################################
#                            TAKSMASTER TESTS                         #
#######################################################################

@test "PARSER: Testing [OK] TASKMASTER 'ls&'" {
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
@test "PARSER: Testing [Error] for 'sdfdsf; sfdsdf; ; sdfsdffd|| sdffd;sdfsdf '" {
  skip
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "sdfdsf; sfdsdf; ; sdfsdffd|| sdffd;sdfsdf "
  [ "${lines[0]}" = "${parser_error_simple_pv}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for '<<ls'" {
  skip
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls>"
  [ "${lines[0]}" = "${parser_error_newline}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for 'ls|'" {
  skip
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls|"
  [ "${lines[0]}" = "${parser_error_simple_p}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for 'ls||'" {
  skip
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls||"
  [ "${lines[0]}" = "${parser_error_double_p}" ]
  [ "$status" -eq 1 ]
}

@test "PARSER: Testing [Error] for 'ls&&'" {
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t parser "ls&&"
  skip
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->${parser_error_simple_es}"
  echo
  [ "${lines[0]}" = "${parser_error_simple_es}" ]
  [ "$status" -eq 1 ]
}
######################################################################
######################################################################
