#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            SIMPLE                                   #
#######################################################################

@test "BUILTIN_ECHO: Testing [args_no_opt] for 'echo abc 123'" {
    expect=`bash -c 'echo abc 123'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc 123'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [args_no_opt] for 'echo | cat -e'" {
    expect=`bash -c 'echo | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [args_no_opt] for 'echo def 456 ghi 789 '' quote'" {
    expect=`bash -c 'echo def 456 ghi 789 '' quote'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo def 456 ghi 789 '' quote'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [args_no_opt] for 'echo hehe | cat -e'" {
    expect=`bash -c 'echo hehe | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo hehe | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [args_no_opt] for 'echo 1 2 3 4 5 6 7 8 9 0 | cat -e'" {
    expect=`bash -c 'echo 1 2 3 4 5 6 7 8 9 0 | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 1 2 3 4 5 6 7 8 9 0 | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [dashdash_no_opt] for 'echo abc -- def'" {
    expect=`bash -c 'echo abc -- def'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc -- def'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [dashdash_no_opt] for 'echo -- ghi'" {
    expect=`bash -c 'echo -- ghi'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -- ghi'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [dashdash_no_opt] for 'echo zzz ---'" {
    expect=`bash -c 'echo zzz ---'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo zzz ---'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [dashdash_no_opt] for 'echo -- -n abc'" {
    expect=`bash -c 'echo -- -n abc'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -- -n abc'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [empty_strings] for 'echo "a" "" "" "b" | cat -e'" {
    expect=`bash -c 'echo "a" "" "" "b" | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "a" "" "" "b" | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [escapes_sequences_NOLOAD] for 'echo '\a\b\c\f\n\r\t\v\\''" {
    expect=`bash -c 'echo '\a\b\c\f\n\r\t\v\\''`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo '\a\b\c\f\n\r\t\v\\''
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [escapes_sequences_NOLOAD] for 'echo "\a\b\c\f\n\r\t\v\\"'" {
    expect=`bash -c 'echo "\a\b\c\f\n\r\t\v\\"'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "\a\b\c\f\n\r\t\v\\"'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [escapes_sequences_NOLOAD] for 'echo \a\b\c\f\n\r\t\v\\'" {
    expect=`bash -c 'echo \a\b\c\f\n\r\t\v\\'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo \a\b\c\f\n\r\t\v\\'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [escapes_sequences_NOLOAD] for 'echo \0777 \0123 \0 '\01' "\02"'" {
    expect=`bash -c 'echo \0777 \0123 \0 '\01' "\02"'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo \0777 \0123 \0 '\01' "\02"'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [no_arg_no_opt] for 'echo | cat -e'" {
    expect=`bash -c 'echo | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [no_arg_opt_n] for 'echo -n | cat -e'" {
    expect=`bash -c 'echo -n | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -n | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [opt_invalid] for 'echo -a abc | cat -e'" {
    expect=`bash -c 'echo -a abc | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -a abc | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [opt_invalid] for 'echo -x abc | cat -e'" {
    expect=`bash -c 'echo -x abc | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -x abc | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [opt_invalid] for 'echo -- -abc abc | cat -e'" {
    expect=`bash -c 'echo -- -abc abc | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -- -abc abc | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [tabs_newline] for 'echo 'a b   c			d\t\t\te\n\n\n\n''" {
    expect=`bash -c 'echo 'a b   c			d\t\t\te\n\n\n\n''`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'a b   c			d\t\t\te\n\n\n\n''
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

