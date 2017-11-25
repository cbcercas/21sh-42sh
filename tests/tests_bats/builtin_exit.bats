#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            SIMPLE                                   #
#######################################################################

@test "BUILTIN_EXIT: Testing [arg_overflow] for 'echo aaa; exit 256; echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo aaa; exit 256; echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->aaa"
    echo
    [ "${lines[0]}" = "aaa" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [first_command_in_the_shell] for 'exit; echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'exit; echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [last_command_in_list] for 'true; false; exit'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true; false; exit'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [last_command_in_list] for 'true; false; exit'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true; false; exit'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [no_argument_error] for 'false; exit; echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false; exit; echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [no_argument_ok] for 'echo aaa; exit; echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo aaa; exit; echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "aaa" ]
    [ "${lines[1]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [print_after_exit_and] for 'echo aaa; exit 0 && echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo aaa; exit 0 && echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "aaa" ]
    [ "${lines[1]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [print_after_exit_pipe] for 'echo a | echo b | echo b | exit 0 | echo end'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a | echo b | echo b | exit 0 | echo end'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->end"
    echo
    [ "${lines[0]}" = "end" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [valid_value] for 'echo aaa; exit 42; echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo aaa; exit 42; echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->aaa"
    echo "                    ->exit"
    echo
    [ "${lines[0]}" = "aaa" ]
    [ "${lines[1]}" = "exit" ]
    [ "$status" -eq 42 ]
    check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin EXIT] for 'exit'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'exit'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->exit"
	[ "${lines[0]}" = "exit" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin EXIT] for 'exit 0'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'exit 0'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->exit"
	[ "${lines[0]}" = "exit" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "BUILTINS: Testing [Builtin EXIT] for 'exit 1'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'exit 1'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->exit"
	[ "${lines[0]}" = "exit" ]
	[ "$status" -eq 1 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin EXIT] for 'exit 2'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'exit 2'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->exit"
	[ "${lines[0]}" = "exit" ]
	[ "$status" -eq 2 ]
	check_leaks_function exec
}





