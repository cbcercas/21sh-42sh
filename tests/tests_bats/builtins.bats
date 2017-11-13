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

@test "BUILTINS: Testing [Builtin CD] for 'cd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->"
	[ "${lines[0]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'cd&&pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd&&pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$HOME"
	[ "${lines[0]}" = "$HOME" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'cd && pwd && cd -'" {
	oldpwd_test=$PWD
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd && pwd && cd -'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$HOME"
	echo "					$oldpwd_test"
	[ "${lines[0]}" = "$HOME" ]
	[ "${lines[1]}" = "$oldpwd_test" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'cd ////./////.////// && pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd ////./////.////// && pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/"
	[ "${lines[0]}" = "/" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'cd /this/doesnt/exists'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /this/doesnt/exists'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$cdnosuch: /this/doesnt/exists"
	[ "${lines[0]}" = "$cdnosuch: /this/doesnt/exists" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'touch notadir && cd notadir ; rm notadir'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'touch notadir && cd notadir ; rm notadir'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->cd: not a directory: notadir"
	[ "${lines[0]}" = "cd: not a directory: notadir" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'setenv HOME=/tmp && cd && pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv HOME=/tmp && cd && pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp"
	[ "${lines[0]}" = "/tmp" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'setenv HOME=/tmp/nosuch && cd; pwd'" {
	pwdtest="$PWD"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv HOME=/tmp/nosuch && cd; pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$cdnosuch: /tmp/nosuch"
	echo "						$pwdtest"
	[ "${lines[0]}" = "$cdnosuch: /tmp/nosuch" ]
	[ "${lines[1]}" = "$pwdtest" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'setenv OLDPWD=/tmp && cd - && pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv OLDPWD=/tmp && cd - && pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp"
	echo "						/tmp"
	[ "${lines[0]}" = "/tmp" ]
	[ "${lines[1]}" = "/tmp" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'setenv OLDPWD=/tmp/nosuchdir && cd -;pwd'" {
	pwdtest="$PWD"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv OLDPWD=/tmp/nosuchdir && cd -;pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/nosuchdir"
	echo "						$cdnosuch: /tmp/nosuchdir"
	echo "						$pwdtest"
	[ "${lines[0]}" = "/tmp/nosuchdir" ]
	[ "${lines[1]}" = "$cdnosuch: /tmp/nosuchdir" ]
	[ "${lines[2]}" = "$pwdtest" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'setenv OLDPWD=/tmp/nosuchdir && cd -;pwd;cd -'" {
	pwdtest="$PWD"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv OLDPWD=/tmp/nosuchdir && cd -;pwd;cd -'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/nosuchdir"
	echo "						$cdnosuch"
	echo "						$pwdtest"
	echo "						/tmp/nosuchdir"
	echo "						$cdnosuch"
	[ "${lines[0]}" = "/tmp/nosuchdir" ]
	[ "${lines[1]}" = "$cdnosuch: /tmp/nosuchdir" ]
	[ "${lines[2]}" = "$pwdtest" ]
	[ "${lines[3]}" = "/tmp/nosuchdir" ]
	[ "${lines[4]}" = "$cdnosuch: /tmp/nosuchdir" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "BUILTINS: Testing [Builtin CD] for 'cd ////////.//////.//////...//////// && pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd ////////.//////./////...//////// && pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$cdnosuch: ////////.//////./////...////////"
	[ "${lines[0]}" = "$cdnosuch: ////////.//////./////...////////" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

#TODO: des HOME PWD OLDPWD Bizzares et des //././/.//.////.../////
