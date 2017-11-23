#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            SIMPLE                                   #
#######################################################################

@test "BUILTIN_UNSETENV: Testing [arg_with_no_equal_no_value] for 'unsetenv -x; unsetenv % ? -'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv -x; unsetenv % ? -'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->"
    echo
    [ "${lines[0]}" = "" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_UNSETENV: Testing [multiple] for 'setenv test_var1=111; setenv test_var2=222; setenv test_var3=333; env | grep test_var | sort; unsetenv test_var1 test_var2 test_var3; env | grep test_var | sort'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv test_var1=111; setenv test_var2=222; setenv test_var3=333; env | grep test_var | sort; unsetenv test_var1 test_var2 test_var3; env | grep test_var | sort'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->test_var1=111"
    echo "                test_var2=222"
    echo "                test_var3=333"
    echo
    [ "${lines[0]}" = "test_var1=111" ]
    [ "${lines[1]}" = "test_var2=222" ]
    [ "${lines[2]}" = "test_var3=333" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_UNSETENV: Testing [no_arg_no_err_msg] for 'unsetenv'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->unsetenv [name]"
    echo "                Deletes the environment variable name from local env"
    echo "                If name doesnt exists, nothing happens"
    echo "                Optional arguments shall be passed to utility."
    echo
    [ "${lines[0]}" = "unsetenv [name]" ]
    [ "${lines[1]}" = "Deletes the environment variable name from local env" ]
    [ "${lines[2]}" = "If name doesnt exists, nothing happens" ]
    [ "${lines[3]}" = "Optional arguments shall be passed to utility." ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_UNSETENV: Testing [printenv_unset_variable] for 'setenv globalvar=456; env | grep globalvar=; unsetenv globalvar; env | grep globalvar=; setenv VAREMPTY=; printenv VAREMPTY; unsetenv VAREMPTY; printenv VAREMPTY'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv globalvar=456; env | grep globalvar=; unsetenv globalvar; env | grep globalvar=; setenv VAREMPTY=; printenv VAREMPTY; unsetenv VAREMPTY; printenv VAREMPTY'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->globalvar=456"
    echo "                "
    echo
    [ "${lines[0]}" = "globalvar=456" ]
    [ "${lines[1]}" = "" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_UNSETENV: Testing [remove_all] for 'setenv test_var=abc; unsetenv * test_var does_not_exist; env; setenv test_var=def; env'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv test_var=abc; unsetenv * test_var does_not_exist; env; setenv test_var=def; env'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->test_var=def"
    echo
    [ "${lines[0]}" = "test_var=def" ]
    [ "${lines[1]}" = "" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}