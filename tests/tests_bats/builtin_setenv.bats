#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            SIMPLE                                   #
#######################################################################

@test "BUILTIN_SETENV: Testing [arg_with_no_equal_no_value] for 'setenv emptyvar; env | grep emptyvar'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv emptyvar; env | grep emptyvar'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->setenv [name]=[value]"
    echo "              ->Sets the environment variable name with value value"
    echo "              ->If name already has a value, then it is replaced with the new one"
    echo
    [ "${lines[0]}" = "setenv [name]=[value]" ]
    [ "${lines[1]}" = "Sets the environment variable name with value value" ]
    [ "${lines[2]}" = "If name already has a value, then it is replaced with the new one" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_SETENV: Testing [arg_with_no_value] for 'setenv emptyvar=; env | grep emptyvar'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv emptyvar=; env | grep emptyvar'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->emptyvar="
    echo
    [ "${lines[0]}" = "emptyvar=" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_SETENV: Testing [setenv_simple_spec] for 'setenv setenv_var=bbb; setenv setenv_var=ccc; env | grep setenv_var='" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv setenv_var=bbb; setenv setenv_var=ccc; env | grep setenv_var='
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->setenv_var=ccc"
    echo
    [ "${lines[0]}" = "setenv_var=ccc" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_SETENV: Testing [space_in_value] for 'setenv var_123=\"1    2    3\"; env | grep var_123 | cat -e'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv var_123="1    2    3"; env | grep var_123 | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->var_123=1    2    3$"
    echo
    [ "${lines[0]}" = "var_123=1    2    3$" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}