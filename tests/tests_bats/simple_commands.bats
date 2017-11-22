#! / Usr / bin / env bats

load test_helper

####star###

@test "SIMPLE_COMMAND: Testing [] for ''" {
    skip "Template"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c ''
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->"
    echo "                      "
    echo "                      "
    echo "                      "
	[ "${lines[0]}" = "" ]
	[ "${lines[1]}" = "" ]
	[ "${lines[2]}" = "" ]
	[ "${lines[3]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "SIMPLE_COMMAND: Testing [exec_binary_with_dotdot_path] for 'cd /bin; ../bin/echo abc'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /bin; ../bin/echo abc'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->abc"
	[ "${lines[0]}" = "abc" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "SIMPLE_COMMAND: Testing [exec_binary_with_dotdotx2_path] for 'mkdir -p /tmp/42sh_dot_dot_test_folder; cd /tmp/42sh_dot_dot_test_folder; mkdir -p mydir; cd mydir; cp /bin/echo .; ../../42sh_dot_dot_test_folder/mydir/echo abc; cd .. && rm -rf mydir; cd /; rm -rf /tmp/42sh_dot_dot_test_folde'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'mkdir -p /tmp/42sh_dot_dot_test_folder; cd /tmp/42sh_dot_dot_test_folder; mkdir -p mydir; cd mydir; cp /bin/echo .; ../../42sh_dot_dot_test_folder/mydir/echo abc; cd .. && rm -rf mydir; cd /; rm -rf /tmp/42sh_dot_dot_test_folder'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->abc"
	[ "${lines[0]}" = "abc" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "SIMPLE_COMMAND: Testing [not_found] for 'unknown_cmd'" {
    skip "Template"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unknown_cmd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->21sh: command not found: unknown_cmd"
	[ "${lines[0]}" = "21sh: command not found: unknown_cmd" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}