#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            IN CORRECTION                            #
#######################################################################
@test "EXEC: Testing [IN CORRECTION] for foo" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'foo'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->21sh: command not found: foo"
    echo
    [ "${lines[0]}" = "21sh: command not found: foo" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for /bin/ls" {
    expect=`ls`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '/bin/ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for /bin/ls -laF" {
    expect=`/bin/ls -laF`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '/bin/ls -laF'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for /bin/ls -l -a -F" {
    expect=`/bin/ls -l -a -F`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '/bin/ls -l -a -F'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for echo It works" {
    expect=`echo It works`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo It works'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for cd /tmp ; /bin/pwd" {
    expect=`cd /tmp ; /bin/pwd`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp ; /bin/pwd'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for cd ../../ ; /bin/pwd" {
    expect=`cd ../../ ; /bin/pwd`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd ../../ ; /bin/pwd'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for cd ; /bin/pwd ; cd - ; /bin/pwd" {
    expect=`cd ; /bin/pwd ; cd - ; /bin/pwd`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd ; /bin/pwd ; cd - ; /bin/pwd'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for unsetenv PATH ; setenv PATH=\"/bin:/usr/bin\" ; ls" {
    expect=`ls`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv PATH ; setenv PATH="/bin:/usr/bin" ; ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for unsetenv PATH ; ls" {
    expect="21sh: command not found: ls"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv PATH ; ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for unsetenv PATH ; /bin/ls" {
    expect=`/bin/ls`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv PATH ; /bin/ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for ls | cat -e" {
    expect=`ls | cat -e`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for ls | sort | cat -e" {
    expect=`ls | sort | cat -e`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls | sort | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for base64 /dev/urandom | head -c 1000 | grep 42 | wc -l | sed -e 's/1/Yes/g' -e 's/0/No/g'" {
    skip "random test"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'base64 /dev/urandom | head -c 1000 | grep 42 | wc -l | sed -e 's/1/Yes/g' -e 's/0/No/g''
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->No or Yes"
    echo
    [ "${output}" = "Yes" ] || [ "${output}" = "No" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for echo \"Testing redirections,\" > /tmp/test.txt" {
    expect=`echo "Testing redirections," > /tmp/test.txt`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo \"Testing redirections,\" > /tmp/test.txt'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for echo \"with multiple lines\" >> /tmp/test.txt" {
    expect=`echo "with multiple lines" >> /tmp/test.txt`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo \"with multiple lines\" >> /tmp/test.txt'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for wc -c < /tmp/test.txt" {
    expect=`wc -c < /tmp/test.txt`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'wc -c < /tmp/test.txt'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for ls -l && ls" {
    expect=`ls -l && ls`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls -l && ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  ls || ls something" {
    expect=`sh -c " ls || ls something"`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c ' ls || ls something'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  ls -1; touch test_file; ls -1" {
    rm -rf test_file
    expect=`sh -c "ls -1; touch test_file; ls -1"`
    rm -rf test_file
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls -1; touch test_file; ls -1'
    rm -rf test_file
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  mkdir testa ; cd testa ; ls -a ; ls | cat | wc -c > fifi ; cat fifi ; rm -rf ../testa" {
    skip "merde travis !!!!!!"
    expect=$(bash -c 'mkdir testa ; cd testa ; ls -a ; ls | cat | wc -c > fifi ; cat fifi ; rm -rf ../testa')
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'mkdir testa ; cd testa ; ls -a ; ls | cat | wc -c > fifi ; cat fifi ; rm -rf ../testa'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  rm nosuchfile 2>&-" {
    expect=""
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm nosuchfile 2>&-'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  rm no 2>&1 | cat -e" {
    expect=`sh -c 'rm no 2>&1 | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm no 2>&1 | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  echo \"No dollar character\" 1>&2 | cat -e" {
    expect="No dollar character"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "No dollar character" 1>&2 | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [IN CORRECTION] for  rm nosuchfile 2>&1 | cat -e" {
    expect=`sh -c 'rm no 2>&1 | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm no 2>&1 | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "EXEC: Testing [>&] for  rm nosuchfile 2>&- | cat -e" {
    expect=`sh -c 'rm no 2>&- | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm no 2>&- | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

######################################################################
######################################################################

######################################################################
#                            AND OR                                  #
######################################################################

@test "AND_OR: Testing [and_or_mix] for 'echo a||echo b&&echo c&&echo d;cat e&&cat f||cat g&&cat h'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a||echo b&&echo c&&echo d;cat e&&cat f||cat g&&cat h'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->a"
    echo "                      c"
    echo "                      d"
    echo "                      cat: e: No such file or directory"
    echo "                      cat: g: No such file or directory"
	[ "${lines[0]}" = "a" ]
	[ "${lines[1]}" = "c" ]
	[ "${lines[2]}" = "d" ]
	[ "${lines[3]}" = "cat: e: No such file or directory" ]
	[ "${lines[4]}" = "cat: g: No such file or directory" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "AND_OR: Testing [and_spec] for 'echo lol && echo pouet && echo truc; cat pouet && echo lol; false && echo pouet'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo lol && echo pouet && echo truc; cat pouet && echo lol; false && echo pouet'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->lol"
    echo "                      pouet"
    echo "                      truc"
    echo "                      cat: pouet: No such file or directory"
	[ "${lines[0]}" = "lol" ]
	[ "${lines[1]}" = "pouet" ]
	[ "${lines[2]}" = "truc" ]
	[ "${lines[3]}" = "cat: pouet: No such file or directory" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "AND_OR: Testing [or_spec] for 'cat pouet || echo lol; echo pouet || echo lol'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cat pouet || echo lol; echo pouet || echo lol'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->cat: pouet: No such file or directory"
    echo "                      lol"
    echo "                      pouet"
	[ "${lines[0]}" = "cat: pouet: No such file or directory" ]
	[ "${lines[1]}" = "lol" ]
	[ "${lines[2]}" = "pouet" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "AND_OR: Testing [sequence_spec] for 'echo lol | cat -e ;echo lol > /tmp/test_sequence_file && cat /tmp/test_sequence_file;cat < /tmp/test_sequence_file; rm -f /tmp/test_sequence_file'" {
	expect=`echo lol | cat -e ;echo lol > /tmp/test_sequence_file && cat /tmp/test_sequence_file;cat < /tmp/test_sequence_file; rm -f /tmp/test_sequence_file`
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo lol | cat -e ;echo lol > /tmp/test_sequence_file && cat /tmp/test_sequence_file;cat < /tmp/test_sequence_file; rm -f /tmp/test_sequence_file'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "AND_OR: Testing [subshell_and] for '(false)&&echo a&&echo b'" {
	skip "subshell"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '(false)&&echo a&&echo b'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->"
	[ "${lines[0]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "AND_OR: Testing [true_false_mix] for 'mkdir testfolder; cd testfolder; touch a; touch b;true && false && ls; true && false || ls; true || false && ls; true || false || ls ; false && true && ls; false && true || ls; false || true && ls; false || true || ls; cd ..; rm -rf testfolder'" {
	expect=`mkdir testfolder; cd testfolder; touch a; touch b;true && false && ls; true && false || ls; true || false && ls; true || false || ls ; false && true && ls; false && true || ls; false || true && ls; false || true || ls; cd ..; rm -rf testfolder`
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'mkdir testfolder; cd testfolder; touch a; touch b;true && false && ls; true && false || ls; true || false && ls; true || false || ls ; false && true && ls; false && true || ls; false || true && ls; false || true || ls; cd ..; rm -rf testfolder'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
######################################################################
######################################################################


######################################################################
#                            PIPE                                    #
######################################################################


@test "PIPES: Testing [many_cat] for 'echo abc | cat | cat | cat -e | cat -e'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc | cat | cat | cat -e | cat -e'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->abc\$\$"
	[ "${lines[0]}" = "abc\$\$" ]
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
######################################################################
######################################################################

######################################################################
#                            REDIRECTIONS                            #
######################################################################

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
	skip "stderr m'enmerde, le test ne fonctionne pas en fonction du retour de cat qui peut etre légèrement différente en fonction des versions des bisoux"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cat < DOES_NOT_EXIST 2>/tmp/redir_not_exist_cat; cat -e /tmp/redir_not_exist_cat; rm -r /tmp/redir_not_exist_cat'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$name_exec: DOES_NOT_EXIST: No such file or directory"
    echo "                      cat: /tmp/redir_not_exist_cat: No such file or directory"
    echo "                      rm: cannot remove '/tmp/redir_not_exist_cat': No such file or directory"
	[ "${lines[0]}" = "$name_exec: DOES_NOT_EXIST: No such file or directory" ]
	[ "${lines[1]}" = "cat: /tmp/redir_not_exist_cat: No such file or directory" ]
	[ "${lines[2]}" = "rm: cannot remove '/tmp/redir_not_exist_cat': No such file or directory" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}



@test "REDIRECTIONS: Testing [err_permission] for 'touch /tmp/redirs_file; chmod 000 /tmp/redirs_file; echo abc > /tmp/redirs_file; cat -e /tmp/redirs_file; chmod u+rw /tmp/redirs_file; rm -f /tmp/redirs_file'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'touch /tmp/redirs_file; chmod 000 /tmp/redirs_file; echo abc > /tmp/redirs_file; cat -e /tmp/redirs_file; chmod u+rw /tmp/redirs_file; rm -f /tmp/redirs_file'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$name_exec: /tmp/redirs_file: No such file or directory"
    echo "                      cat: /tmp/redirs_file: Permission denied"
    echo "                      "
    echo "                      "
	[ "${lines[0]}" = "$name_exec: /tmp/redirs_file: No such file or directory" ]
	[ "${lines[1]}" = "cat: /tmp/redirs_file: Permission denied" ]
	[ "${lines[2]}" = "" ]
	[ "${lines[3]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "REDIRECTIONS: Testing [fd_above_limit] for 'cd /tmp; echo abc 10>&-; echo def 11>&-; echo ghi 10>fd_above_limit; cat -e fd_above_limit; rm -f fd_above_limit'" {
	skip "Skipped because of travis and problem when installing zsh"
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
	expect=`echo abcd > /tmp/redir_multi_op_great >> /tmp/redir_multi_op_dgreat; file /tmp/redir_multi_op_great; file /tmp/redir_multi_op_dgreat; rm -f /tmp/redir_multi_op_great /tmp/redir_multi_op_dgreat`
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abcd > /tmp/redir_multi_op_great >> /tmp/redir_multi_op_dgreat; file /tmp/redir_multi_op_great; file /tmp/redir_multi_op_dgreat; rm -f /tmp/redir_multi_op_great /tmp/redir_multi_op_dgreat'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/redir_multi_op_great: empty"
    echo "                      /tmp/redir_multi_op_dgreat: ASCII text"
    [ "${output}" = "$expect" ]
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
	echo "$name_exec EXPECTED ->"
	[ "${lines[0]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "REDIRECTIONS: Testing [] for 'echo 'def' > /tmp/redir_one_to_all; cat 9</tmp/redir_one_to_all 8<&9 7<&8 6<&7 -e 5<&6 4<&5 <&4; rm -f /tmp/redir_one_to_all'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c "echo 'def' > /tmp/redir_one_to_all; cat 9</tmp/redir_one_to_all 8<&9 7<&8 6<&7 -e 5<&6 4<&5 <&4; rm -f /tmp/redir_one_to_all"
  echo "ERROR:"
  display_line_output
  echo "$name_exec EXPECTED ->def$"
  [ "${lines[0]}" = "def$" ]
  [ "$status" -eq 0 ]
  check_leaks_function exec
}


@test "REDIRECTIONS: Testing [] for 'echo def > /tmp/redir_one_to_all; cat 9</tmp/redir_one_to_all 8<&9 7<&8 6<&7 -e 5<&6 4<&5 3<&4 2<&3 1<&2 <&1; rm -f /tmp/redir_one_to_all'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo def > /tmp/redir_one_to_all; cat 9</tmp/redir_one_to_all 8<&9 7<&8 6<&7 -e 5<&6 4<&5 3<&4 2<&3 1<&2 <&1; rm -f /tmp/redir_one_to_all'
  echo "ERROR:"
  display_line_output
  echo "$name_exec EXPECTED ->"
  [ "${lines[0]}" = "" ]
  [ "$status" -eq 0 ]
  check_leaks_function exec
}

######################################################################
######################################################################

######################################################################
#                            SIMPLE                                  #
######################################################################

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
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unknown_cmd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$name_exec: command not found: unknown_cmd"
	[ "${lines[0]}" = "$name_exec: command not found: unknown_cmd" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}