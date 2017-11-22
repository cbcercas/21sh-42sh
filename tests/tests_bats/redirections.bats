#! / Usr / bin / env bats

load test_helper

####star###

@test "REDIRECTIONS: Testing [] for ''" {
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


@test "REDIRECTIONS: Testing [aggregate_builtin] for '>&2 echo "error" && echo "msg"; >&2 echo "check stderr restored"; echo "check stdout restored"'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '>&2 echo "error" && echo "msg"; >&2 echo "check stderr restored"; echo "check stdout restored"'
	expect=`bash -c '>&2 echo "error" && echo "msg"; >&2 echo "check stderr restored"; echo "check stdout restored"'`
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->error"
    echo "                      msg"
    echo "                      check stderr restored"
    echo "                      check sdtout restored"
	[ "${lines[0]}" = "error" ]
	[ "${lines[1]}" = "msg" ]
	[ "${lines[2]}" = "check stderr restored" ]
	[ "${lines[3]}" = "check stdout restored" ]

	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "REDIRECTIONS: Testing [aggregate_non_standart] for 'echo abc > /tmp/redir_aggregate_non_standard ;cat 4</tmp/redir_aggregate_non_standard <&4; rm -f /tmp/redir_aggregate_non_standard'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc > /tmp/redir_aggregate_non_standard ;cat 4</tmp/redir_aggregate_non_standard <&4; rm -f /tmp/redir_aggregate_non_standard'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->abc"
	[ "${lines[0]}" = "abc" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "REDIRECTIONS: Testing [all_operators_simple] for 'echo aaa > /tmp/redir_op;echo bbb >> /tmp/redir_op;echo ccc >> /tmp/redir_op; cat -e < /tmp/redir_op; echo ddd; rm -f /tmp/redir_op'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo aaa > /tmp/redir_op;echo bbb >> /tmp/redir_op;echo ccc >> /tmp/redir_op; cat -e < /tmp/redir_op; echo ddd; rm -f /tmp/redir_op'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->aaa$"
    echo "                      bbb$"
    echo "                      ccc$"
    echo "                      ddd"
	[ "${lines[0]}" = "aaa$" ]
	[ "${lines[1]}" = "bbb$" ]
	[ "${lines[2]}" = "ccc$" ]
	[ "${lines[3]}" = "ddd" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "REDIRECTIONS: Testing [bad_fd] for 'echo 111; echo abcd >&42; echo abcd >&3; echo abcd 10>&1; echo abcd >&10; echo 222'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 111; echo abcd >&42; echo abcd >&3; echo abcd 10>&1; echo abcd >&10; echo 222'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->111"
    echo "                      $name_exec: 42: bad file descriptor"
    echo "                      $name_exec: 42: bad file descriptor"
    echo "                      abcd 10"
    echo "                      $name_exec: 42: bad file descriptor"
    echo "                      222"
	[ "${lines[0]}" = "111" ]
	[ "${lines[1]}" = "$name_exec: 42: bad file descriptor" ]
	[ "${lines[2]}" = "$name_exec: 42: bad file descriptor" ]
	[ "${lines[3]}" = "abcd 10" ]
	[ "${lines[4]}" = "$name_exec: 42: bad file descriptor" ]
	[ "${lines[5]}" = "222" ]

	[ "$status" -eq 0 ]
	check_leaks_function exec
}