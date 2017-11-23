#! / Usr / bin / env bats

load test_helper

####star###

@test "PIPES: Testing [] for ''" {
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


@test "PIPES: Testing [many_cat] for 'echo abc | cat | cat | cat -e | cat -e'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc | cat | cat | cat -e | cat -e'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->abc$$"
	[ "${lines[0]}" = "abc$$" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "PIPES: Testing [pipe_simples] for 'echo lol | wc -l | xargs echo; echo lol | wc -l | xargs echo | cat -e'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo lol | wc -l | xargs echo; echo lol | wc -l | xargs echo | cat -e'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->1"
    echo "                      1$"
	[ "${lines[0]}" = "1" ]
	[ "${lines[1]}" = "1$" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}
