#! / Usr / bin / env bats

load test_helper

####start####
@test "BUILTINS: Testing [] for ''" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c ''
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->"
	[ "${lines[0]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}
#############

################################################################################
#                                  Testing PWD                                 #
################################################################################

@test "BUILTINS: Testing [Builtin PWD] for 'pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$PWD"
	[ "${lines[0]}" = "$PWD" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin PWD] for 'pwd -g' (Incorrect option)" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'pwd -g'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->pwd: invalind option -- 'g'"
	[ "${lines[0]}" = "pwd: invalid option -- 'g'" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "BUILTINS: Testing [Builtin PWD] for 'pwd -L'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'pwd -L'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$PWD"
	[ "${lines[0]}" = "$PWD" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin PWD] for 'pwd -P'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'pwd -P'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$PWD"
	[ "${lines[0]}" = "$PWD" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "BUILTINS: Testing [Buitin PWD] for 'pwd /doesnt/exists'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'pwd /doesnt/exists'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->usage: pwd [-L | -P]"
	[ "${lines[0]}" = "usage: pwd [-L | -P]" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

#TODO: Multiple commands with cd and pwd, for example 'pwd;cd;pwd'

################################################################################
#                                   Testing EXIT                               # 
################################################################################

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

################################################################################
#                                    Testing CD                                #
################################################################################

@test "BUILTINS: Testing [Builtin EXIT] for 'cd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->"
	[ "${lines[0]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}
