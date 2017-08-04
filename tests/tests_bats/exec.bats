#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            IN CORRECTION                            #
#######################################################################
@test "EXEC: Testing [IN CORRECTION] for foo" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'foo'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->21sh: command not found: foo"
    echo
    [ "${lines[0]}" = "21sh: command not found: foo" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for /bin/ls" {
    expect=`ls`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '/bin/ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for /bin/ls -laF" {
    expect=`/bin/ls -laF`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '/bin/ls -laF'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for /bin/ls -l -a -F" {
    expect=`/bin/ls -l -a -F`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '/bin/ls -l -a -F'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for echo It works" {
    expect=`echo It works`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo It works'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for cd /tmp ; /bin/pwd" {
    expect=`cd /tmp ; /bin/pwd`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp ; /bin/pwd'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for cd ../../ ; /bin/pwd" {
    expect=`cd ../../ ; /bin/pwd`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd ../../ ; /bin/pwd'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for cd ; /bin/pwd ; cd - ; /bin/pwd" {
    expect=`cd ; /bin/pwd ; cd - ; /bin/pwd`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd ; /bin/pwd ; cd - ; /bin/pwd'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for env" {
  skip "a fix"
    expect=`env`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for setenv FOO=bar ; env" {
  skip "a fix"
    expect=`setenv FOO=bar ; env`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv FOO=bar ; env'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for setenv FOO=bar ; /usr/bin/env" {
  skip "a fix"
    expect=`setenv FOO=bar ; /usr/bin/env`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv FOO=bar ; /usr/bin/env'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for unsetenv FOO ; env" {
    skip "a fix"
    expect=`unset FOO=bar ; env`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv FOO=bar ; env'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for unsetenv FOO ; /usr/bin/env" {
    skip "a fix"
    expect=`unset FOO=bar ; /usr/bin/env`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv FOO=bar ; /usr/bin/env'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for unsetenv PATH ; setenv PATH=\"/bin:/usr/bin\" ; ls" {
    expect=`ls`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv PATH ; setenv PATH=\"/bin:/usr/bin\" ; ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for unsetenv PATH ; ls" {
    expect="21sh: command not found: ls"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv PATH ; ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for unsetenv PATH ; /bin/ls" {
    expect=`/bin/ls`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv PATH ; /bin/ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for ls | cat -e" {
    expect=`ls | cat -e`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for ls | sort | cat -e" {
    expect=`ls | sort | cat -e`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls | sort | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for base64 /dev/urandom | head -c 1000 | grep 42 | wc -l | sed -e 's/1/Yes/g' -e 's/0/No/g'" {
    skip "a fix"
    expect=`base64 /dev/urandom | head -c 1000 | grep 42 | wc -l | sed -e 's/1/Yes/g' -e 's/0/No/g'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'base64 /dev/urandom | head -c 1000 | grep 42 | wc -l | sed -e 's/1/Yes/g' -e 's/0/No/g''
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for echo \"Testing redirections,\" > /tmp/test.txt" {
    expect=`echo "Testing redirections," > /tmp/test.txt`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo \"Testing redirections,\" > /tmp/test.txt'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for echo \"with multiple lines\" >> /tmp/test.txt" {
    expect=`echo "with multiple lines" >> /tmp/test.txt`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo \"with multiple lines\" >> /tmp/test.txt'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for wc -c < /tmp/test.txt" {
    expect=`wc -c < /tmp/test.txt`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'wc -c < /tmp/test.txt'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for ls -l && ls" {
    expect=`ls -l && ls`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls -l && ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for ls something || ls" {
    skip "a fixer"
    expect=`sh -c "ls something || ls"`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls something || ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  ls || ls something" {
    expect=`sh -c " ls || ls something"`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c ' ls || ls something'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  ls -1; touch test_file; ls -1" {
    rm -rf test_file
    expect=`sh -c "ls -1; touch test_file; ls -1"`
    rm -rf test_file
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls -1; touch test_file; ls -1'
    rm -rf test_file
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  mkdir testa ; cd testa ; ls -a ; ls | cat | wc -c > fifi ; cat fifi" {
    rm -rf testa
    expect=`sh -c "mkdir testa ; cd testa ; ls -a ; ls | cat | wc -c > fifi ; cat fifi"`
    rm -rf testa
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'mkdir testa ; cd testa ; ls -a ; ls | cat | wc -c > fifi ; cat fifi'
    echo "ERROR:"
      rm -rf testa
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  rm nosuchfile 2>&-" {
    expect=""
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm nosuchfile 2>&-'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  rm nosuchfile 2>&1 | cat -e" {
    expect=`sh -c 'rm no 2>&1 | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm no 2>&1 | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  echo \"No dollar character\" 1>&2 | cat -e" {
    expect="No dollar character"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "No dollar character" 1>&2 | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  rm nosuchfile 2>&1 | cat -e" {
    expect=`sh -c 'rm no 2>&1 | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm no 2>&1 | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [>&] for  rm nosuchfile 2>&- | cat -e" {
    expect=`sh -c 'rm no 2>&- | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm no 2>&- | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [>&] for  rm nosuchfile >&- | cat -e" {
    expect=`sh -c 'rm no >&- | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm no >&- | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [>&] for ls >&- | cat -e" {
    expect=`sh -c 'ls >&- | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls >&- | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

######################################################################
######################################################################


######################################################################
#                            Built/Echo                              #
######################################################################

@test "EXPAND: Testing [Built/Echo] with 'echo -e \"toto\ntata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -e "toto\ntata"'
  echo
	display_line_output
	echo
  ret=$( sh -c 'echo -e "toto\ntata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
  [ "$status" -eq 0 ]
check_leaks_function exec
}

@test "EXPAND: Testing [Built/Echo] with 'echo -e \"toto\\atata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "toto\\atata"'
  echo
	display_line_output
	echo
  ret=$( sh -c 'echo -e "toto\\atata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "EXPAND: Testing [Built/Echo] with 'echo -e toto\\btata'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -e toto\\btata'
  echo
	display_line_output
	echo
  ret=$( sh -c 'echo -e toto\\btata' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "EXPAND: Testing [Built/Echo] with 'echo -e \"toto\\atata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "toto\\atata"'
  echo
	display_line_output
	echo
  ret=$( sh -c 'echo -e "toto\\atata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "EXPAND: Testing [Built/Echo] with 'echo -e \"toto\\a\a\\\a\\t\t\\\t\n\\n\\\n\b\\b\\\bata\r\\r\\\r\f\\\f\\fdfgdg\v\\v\\\vsfsdf\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -e "toto\\a\a\\\a\\t\t\\\t\n\\n\\\n\b\\b\\\bata\r\\r\\\r\f\\\f\\fdfgdg\v\\v\\\vsfsdf"'
  echo
	display_line_output
	echo
  ret=$( sh -c 'echo -e "toto\\a\a\\\a\\t\t\\\t\n\\n\\\n\b\\b\\\bata\r\\r\\\r\f\\\f\\fdfgdg\v\\v\\\vsfsdf"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]

check_leaks_function exec
}

@test "EXPAND: Testing [Built/Echo] with 'echo -E \"toto\ntata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -E "toto\ntata"'
  echo
	display_line_output
	echo
  ret=$( sh -c 'echo -E "toto\ntata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
  [ "$status" -eq 0 ]
check_leaks_function exec
}

@test "EXPAND: Testing [Built/Echo] with 'echo -E \"toto\\atata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "toto\\atata"'
  echo
	display_line_output
	echo
  ret=$( sh -c 'echo -E "toto\\atata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "EXPAND: Testing [Built/Echo] with 'echo -E toto\\btata'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -E toto\\btata'
  echo
	display_line_output
	echo
  ret=$( sh -c 'echo -E toto\\btata' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "EXPAND: Testing [Built/Echo] with 'echo -E \"toto\\atata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -E "toto\\atata"'
  echo
	display_line_output
	echo
  ret=$( sh -c 'echo -E "toto\\atata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "EXPAND: Testing [Built/Echo] with 'echo -E \"toto\\a\a\\\a\\t\t\\\t\n\\n\\\n\b\\b\\\bata\r\\r\\\r\f\\\f\\fdfgdg\v\\v\\\vsfsdf\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -E "toto\\a\a\\\a\\t\t\\\t\n\\n\\\n\b\\b\\\bata\r\\r\\\r\f\\\f\\fdfgdg\v\\v\\\vsfsdf"'
  echo
	display_line_output
	echo
  ret=$( sh -c 'echo -E "toto\\a\a\\\a\\t\t\\\t\n\\n\\\n\b\\b\\\bata\r\\r\\\r\f\\\f\\fdfgdg\v\\v\\\vsfsdf"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]

check_leaks_function exec
}

@test "EXPAND: Testing [Built/Env] with 'env -i'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env -i'
  echo
	display_line_output
	echo
  ret=$( sh -c 'env -i' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "EXPAND: Testing [Built/Env] with 'env -i toto=tata'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env -i toto=tata'
  echo
	display_line_output
	echo
  ret=$( sh -c 'env -i toto=tata' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "EXPAND: Testing [Built/Env] with 'env -u toto ls'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env -u toto ls'
  echo
	display_line_output
	echo
  ret=$( sh -c 'env -u toto ls' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}
######################################################################
######################################################################
