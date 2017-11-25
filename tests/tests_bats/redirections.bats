#! / Usr / bin / env bats

load test_helper

####star###

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
    echo "                      abcd 10"
    echo "                      $name_exec: 10: bad file descriptor"
    echo "                      222"
	[ "${lines[0]}" = "111" ]
	[ "${lines[1]}" = "$name_exec: 42: bad file descriptor" ]
	[ "${lines[2]}" = "abcd 10" ]
	[ "${lines[3]}" = "$name_exec: 10: bad file descriptor" ]
	[ "${lines[4]}" = "222" ]

	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [chmod_redir_zero] for 'echo 'test' > /tmp/redir_chmod_0; cat -e < /tmp/redir_chmod_0; rm -f /tmp/chmod_redir_0'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c "echo 'test' > /tmp/redir_chmod_0; cat -e < /tmp/redir_chmod_0; rm -f /tmp/chmod_redir_0" {
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->test$"
	[ "${lines[0]}" = "test$" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [dup_to_stdin] for 'echo merde > /tmp/redir_echo_in; cat 4</tmp/redir_echo_in <&4; rm -f /tmp/redir_echo_in'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo merde > /tmp/redir_echo_in; cat 4</tmp/redir_echo_in <&4; rm -f /tmp/redir_echo_in'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->merde"
	[ "${lines[0]}" = "merde" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [err_not_found] for 'cat < DOES_NOT_EXIST 2>/tmp/redir_not_exist_cat; cat -e /tmp/redir_not_exist_cat; rm -r /tmp/redir_not_exist_cat'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cat < DOES_NOT_EXIST 2>/tmp/redir_not_exist_cat; cat -e /tmp/redir_not_exist_cat; rm -r /tmp/redir_not_exist_cat'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$name_exec: no such file or directory: DOES_NOT_EXIST"
    echo "                      cat: /tmp/redir_not_exist_cat: No such file or directory"
    echo "                      rm: /tmp/redir_not_exist_cat: No such file or directory"
	[ "${lines[0]}" = "$name_exec: no such file or directory: DOES_NOT_EXIST" ]
	[ "${lines[1]}" = "cat: /tmp/redir_not_exist_cat: No such file or directory" ]
	[ "${lines[2]}" = "rm: /tmp/redir_not_exist_cat: No such file or directory" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}



@test "REDIRECTIONS: Testing [err_permission] for 'touch /tmp/redirs_file; chmod 000 /tmp/redirs_file; echo abc > /tmp/redirs_file; cat -e /tmp/redirs_file; chmod u+rw /tmp/redirs_file; rm -f /tmp/redirs_file'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'touch /tmp/redirs_file; chmod 000 /tmp/redirs_file; echo abc > /tmp/redirs_file; cat -e /tmp/redirs_file; chmod u+rw /tmp/redirs_file; rm -f /tmp/redirs_file'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$name_exec: no such file or directory: /tmp/redirs_file"
    echo "                      cat: /tmp/redirs_file: Permission denied"
    echo "                      "
    echo "                      "
	[ "${lines[0]}" = "$name_exec: no such file or directory: /tmp/redirs_file" ]
	[ "${lines[1]}" = "cat: /tmp/redirs_file: Permission denied" ]
	[ "${lines[2]}" = "" ]
	[ "${lines[3]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [fd_above_limit] for 'cd /tmp; echo abc 10>&-; echo def 11>&-; echo ghi 10>fd_above_limit; cat -e fd_above_limit; rm -f fd_above_limit'" {
	expect=`zsh -c 'cd /tmp; echo abc 10>&-; echo def 11>&-; echo ghi 10>fd_above_limit; cat -e fd_above_limit; rm -f fd_above_limit'`
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp; echo abc 10>&-; echo def 11>&-; echo ghi 10>fd_above_limit; cat -e fd_above_limit; rm -f fd_above_limit'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [great_less_bigfile] for 'man tar > /tmp/bigfile; man tar >> /tmp/bigfile; man tar >> /tmp/bigfile; man tar >> /tmp/bigfile; cat < /tmp/bigfile | wc; rm -f /tmp/bigfile'" {
	skip ""
	expect=`bash -c 'man tar > /tmp/bigfile; man tar >> /tmp/bigfile; man tar >> /tmp/bigfile; man tar >> /tmp/bigfile; cat < /tmp/bigfile | wc; rm -f /tmp/bigfile'`
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'man tar > /tmp/bigfile; man tar >> /tmp/bigfile; man tar >> /tmp/bigfile; man tar >> /tmp/bigfile; cat < /tmp/bigfile | wc; rm -f /tmp/bigfile'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [great_less_bigfile] for 'man tar > /tmp/bigfile 2>&- ; man tar >> /tmp/bigfile 2>&- ; man tar >> /tmp/bigfile 2>&- ; man tar >> /tmp/bigfile 2>&- ; cat < /tmp/bigfile | wc; rm -f /tmp/bigfile'" {
	expect=`bash -c 'man tar > /tmp/bigfile 2>&- ; man tar >> /tmp/bigfile 2>&- ; man tar >> /tmp/bigfile 2>&- ; man tar >> /tmp/bigfile 2>&- ; cat < /tmp/bigfile | wc; rm -f /tmp/bigfile'`
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'man tar > /tmp/bigfile 2>&- ; man tar >> /tmp/bigfile 2>&- ; man tar >> /tmp/bigfile 2>&- ; man tar >> /tmp/bigfile 2>&- ; cat < /tmp/bigfile | wc; rm -f /tmp/bigfile'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "REDIRECTIONS: Testing [lessgreat_input] for 'echo 'abc' > /tmp/redir_lessgreat_file; /bin/cat 4<>/tmp/redir_lessgreat_file <&4 -e'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'abc' > /tmp/redir_lessgreat_file; /bin/cat 4<>/tmp/redir_lessgreat_file <&4 -e'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->abc$"
	[ "${lines[0]}" = "abc$" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [lessgreatr_output] for 'echo 'def' | cat 5<>/tmp/redir_lessgreat_file >&5 -e; /bin/cat -e /tmp/redir_lessgreat_file'" {
	expect=`echo 'def' | cat 5<>/tmp/redir_lessgreat_file >&5 -e; /bin/cat -e /tmp/redir_lessgreat_file`
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'def' | cat 5<>/tmp/redir_lessgreat_file >&5 -e; /bin/cat -e /tmp/redir_lessgreat_file'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [] for 'o abcd > /tmp/redir_multi_op_great >> /tmp/redir_multi_op_dgreat; file /tmp/redir_multi_op_great; file /tmp/redir_multi_op_dgreat; rm -f /tmp/redir_multi_op_great /tmp/redir_multi_op_dgreat" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abcd > /tmp/redir_multi_op_great >> /tmp/redir_multi_op_dgreat; file /tmp/redir_multi_op_great; file /tmp/redir_multi_op_dgreat; rm -f /tmp/redir_multi_op_great /tmp/redir_multi_op_dgreat'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/redir_multi_op_great: empty"
    echo "                      /tmp/redir_multi_op_dgreat: ASCII text"
	[ "${lines[0]}" = "/tmp/redir_multi_op_great: empty" ]
	[ "${lines[1]}" = "/tmp/redir_multi_op_dgreat: ASCII text" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "REDIRECTIONS: Testing [] for 'echo lol | wc -l | xargs echo > /tmp/testfile; cat /tmp/testfile; cat -e < /tmp/testfile | wc -c | xargs echo; cat -e < /tmp/testfile | wc -c | xargs echo > /tmp/testfile2; cat /tmp/testfile2; rm /tmp/testfile /tmp/testfile2'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo lol | wc -l | xargs echo > /tmp/testfile; cat /tmp/testfile; cat -e < /tmp/testfile | wc -c | xargs echo; cat -e < /tmp/testfile | wc -c | xargs echo > /tmp/testfile2; cat /tmp/testfile2; rm /tmp/testfile /tmp/testfile2'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->1"
    echo "                      3"
    echo "                      3"
	[ "${lines[0]}" = "1" ]
	[ "${lines[1]}" = "3" ]
	[ "${lines[2]}" = "3" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [] for 'cat gnuk 2> /tmp/testfile; cat /tmp/testfile; cat gnuk 2>&1 | cat -e; rm /tmp/testfile; cat bouh >& /tmp/testfile; cat -e /tmp/testfile; rm /tmp/testfile'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cat gnuk 2> /tmp/testfile; cat /tmp/testfile; cat gnuk 2>&1 | cat -e; rm /tmp/testfile; cat bouh >& /tmp/testfile; cat -e /tmp/testfile; rm /tmp/testfile'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->cat: gnuk: No such file or directory"
    echo "                      cat: gnuk: No such file or directory$"
    echo "                      cat: bouh: No such file or directory"
	[ "${lines[0]}" = "cat: gnuk: No such file or directory" ]
	[ "${lines[1]}" = "cat: gnuk: No such file or directory$" ]
	[ "${lines[2]}" = "cat: bouh: No such file or directory" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [] for 'merde 2>&-'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'merde 2>&-'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->"
	[ "${lines[0]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [stdin_file] for 'echo lol > /tmp/testfile; cat < /tmp/testfile; cat < /tmp/testfile < lol; rm /tmp/testfile'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo lol > /tmp/testfile; cat < /tmp/testfile; cat < /tmp/testfile < lol; rm /tmp/testfile'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->lol"
    echo "                      $name_exec: lol: No such file or directory"
	[ "${lines[0]}" = "lol" ]
	[ "${lines[1]}" = "$name_exec: lol: No such file or directory" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [stdout_in_file] for 'echo abc && echo def; echo 123 > /tmp/test_redir_file_stdout; cat /tmp/test_redir_file_stdout; rm -f /tmp/test_redir_file_stdout'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc && echo def; echo 123 > /tmp/test_redir_file_stdout; cat /tmp/test_redir_file_stdout; rm -f /tmp/test_redir_file_stdout'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->abc"
    echo "                      def"
    echo "                      123"
	[ "${lines[0]}" = "abc" ]
	[ "${lines[1]}" = "def" ]
	[ "${lines[2]}" = "123" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [two_to_one] for 'ls this_file_does_not_exist 1>&2 2> /tmp/redir_test_file; rm -f /tmp/redir_test_file'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls this_file_does_not_exist 1>&2 2> /tmp/redir_test_file; rm -f /tmp/redir_test_file'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED -"
	[ "${lines[0]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}
