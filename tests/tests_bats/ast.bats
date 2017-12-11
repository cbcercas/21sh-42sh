#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            SIMPLE                                   #
#######################################################################
@test "AST: Testing [SIMPLE] for NULL (Empty string)" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast ""
    echo "ERROR:"
    echo "$name_exec OUTPUT   ->${lines[0]}"
    echo "$name_exec EXPECTED ->"
    echo
    [ "${lines[0]}" = "" ]
    [ "$status" -eq 0 ]
    check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for ' ' (Single space)" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast " "
  echo "ERROR:"
  echo "$name_exec OUTPUT   ->${lines[0]}"
  echo "$name_exec EXPECTED ->"
  echo
  [ "${lines[0]}" = "" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls"
  echo "ERROR:"
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                ls"
  echo
  [ "${lines[0]}" = "[--- Display tree ---]" ]
  [ "${lines[1]}" = "ls" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls -l'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls -l"
  echo "ERROR:"
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                ls -l"
  echo
  [ "${lines[0]}" = "[--- Display tree ---]" ]
  [ "${lines[1]}" = "ls -l" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls -l | cat -e'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls -l | cat -e"
  echo "ERROR:"
  expect=$(echo -e "[--- Display tree ---]\n    cat -e\n|\n    ls -l")
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                    cat -e"
  echo "                |"
  echo "                    ls -l"
  echo
  [ "$output" = "$expect" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls ; ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls ; ls"
  echo "ERROR:"
  expect=$(echo -e "[--- Display tree ---]\n    ls\n;\n    ls")
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                    ls"
  echo "                ;"
  echo "                    ls"
  echo
  [ "$output" = "$expect" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}



@test "AST: Testing [SIMPLE] for 'ls || ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls || ls"
  echo "ERROR:"
  expect=$(echo -e "[--- Display tree ---]\n    ls\n||\n    ls")
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                    ls"
  echo "                ||"
  echo "                    ls"
  echo
  [ "$output" = "$expect" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls && ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls && ls"
  echo "ERROR:"
  expect=$(echo -e "[--- Display tree ---]\n    ls\n&&\n    ls")
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                    ls"
  echo "                &&"
  echo "                    ls"
  echo
  [ "$output" = "$expect" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls & ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls & ls"
  echo "ERROR:"
  display_line_output
  echo "$name_exec EXPECTED ->$name_exec: Lexing error."
  echo
  [ "$output" = "$name_exec: Lexing error." ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls -l & echo & cat'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls -l & echo & cat"
  echo "ERROR:"
  display_line_output
  echo "$name_exec EXPECTED ->$name_exec: Lexing error."
  echo

  [ "${lines[0]}" = "$name_exec: Lexing error." ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls || ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls || ls"
  echo "ERROR:"
  expect=$(echo -e "[--- Display tree ---]\n    ls\n||\n    ls")
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                    ls"
  echo "                ||"
  echo "                    ls"
  echo
  [ "$output" = "$expect" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls;'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls;"
  echo "ERROR:"
  expect=$(echo -e "[--- Display tree ---]\n    ..\n;\n    ls")
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                    .."
  echo "                ;"
  echo "                    ls"
  echo
  [ "$output" = "$expect" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls >&2 ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls >&2 ls"
  echo "ERROR:"
  expect=$(echo -e "[--- Display tree ---]\n    ..\n>& 2\n    ls ls")
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                    .."
  echo "                 >&2"
  echo "                    ls ls"
  echo
  [ "$output" = "$expect" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls 1>&2 ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls 1>&2 ls"
  echo "ERROR:"
  expect=$(echo -e "[--- Display tree ---]\n    ..\n1 >& 2\n    ls ls")
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                    .."
  echo "                1>&2"
  echo "                    ls ls"
  echo
  [ "$output" = "$expect" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls 1>& 2 ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls 1>& 2 ls"
  echo "ERROR:"
  expect=$(echo -e "[--- Display tree ---]\n    ..\n1 >& 2\n    ls ls")
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                    .."
  echo "                1 >& 2"
  echo "                    ls ls"
  echo
  [ "$output" = "$expect" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'ls -l >&2 echo 1>& 2 cat'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls -l >&2 echo 1>& 2 cat"
  echo "ERROR:"
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]"
  echo "                        .."
  echo "                    .."
  echo "                        .."
  echo "                >& 2"
  echo "                        .."
  echo "                    1 >& 2"
  echo "                        ls -l echo cat"
  echo

  [ "${lines[0]}" = "[--- Display tree ---]" ]
  [ "${lines[1]}" = "        .." ]
  [ "${lines[2]}" = "    .." ]
  [ "${lines[3]}" = "        .." ]
  [ "${lines[4]}" = ">& 2" ]
  [ "${lines[5]}" = "        .." ]
  [ "${lines[6]}" = "    1 >& 2" ]
  [ "${lines[7]}" = "        ls -l echo cat" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'toto >&2 tata'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "toto >&2 tata" line
  echo "ERROR:"
  display_line_output
    echo "$name_exec EXPECTED ->[0]{>& 2} [1]{toto tata} "
  echo
  [ "${lines[0]}" = "[0]{>& 2} [1]{toto tata} " ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'toto <&2 tata'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "toto <&2 tata" line
  echo "ERROR:"
  display_line_output
    echo "$name_exec EXPECTED ->[0]{<& 2} [1]{toto tata} "
  echo
  [ "${lines[0]}" = "[0]{<& 2} [1]{toto tata} " ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'toto 2<&2 tata'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "toto 2<&2 tata" line
  echo "ERROR:"
  display_line_output
    echo "$name_exec EXPECTED ->[0]{2 <& 2} [1]{toto tata} "
  echo
  [ "${lines[0]}" = "[0]{2 <& 2} [1]{toto tata} " ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'toto 2>&2 tata'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "toto 2>&2 tata" line
  echo "ERROR:"
  display_line_output
    echo "$name_exec EXPECTED ->[0]{2 >& 2} [1]{toto tata} "
  echo
  [ "${lines[0]}" = "[0]{2 >& 2} [1]{toto tata} " ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

@test "AST: Testing [SIMPLE] for 'toto 2 >&2 tata'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "toto 2 >&2 tata" line
  echo "ERROR:"
  display_line_output
    echo "$name_exec EXPECTED ->[0]{>& 2} [1]{toto 2 tata} "
  echo
  [ "${lines[0]}" = "[0]{>& 2} [1]{toto 2 tata} " ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

#######################################################################
#######################################################################


#######################################################################
#                            MIX                                   #
#######################################################################


@test "AST: Testing [MIX] for 'ls -l |echo && cat'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "ls -l|echo&& cat"
  echo "ERROR:"
  expect=$(echo -e "[--- Display tree ---]
        ..
    cat
        ..
&&
        echo
    |
        ls -l")
  display_line_output
  echo "$name_exec EXPECTED ->[--- Display tree ---]
                        ..
                    cat
                        ..
                &&
                        echo
                    |
                        ls -l"
  echo
  [ "$output" = "$expect" ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}


@test "AST: Testing [MIX] for 'mkdir test ; cd test ; ls -a ; ls | cat | wc -c > fifi ; cat fifi" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t ast "mkdir test ; cd test ; ls -a ; ls | cat | wc -c > fifi ; cat fifi" line
  echo "ERROR:"
  display_line_output
    echo "$name_exec EXPECTED ->[0]{;} [1]{;} [2]{;} [3]{;} [4]{mkdir test} [5]{cd test} [6]{ls -a} [7]{|} [8]{|} [9]{ls} [10]{cat} [11]{> fifi} [12]{wc -c} [13]{cat fifi} "
  echo
  [ "${lines[0]}" = "[0]{;} [1]{;} [2]{;} [3]{;} [4]{mkdir test} [5]{cd test} [6]{ls -a} [7]{|} [8]{|} [9]{ls} [10]{cat} [11]{> fifi} [12]{wc -c} [13]{cat fifi} " ]
  [ "$status" -eq 0 ]
  check_leaks_function ast
}

######################################################################
######################################################################
