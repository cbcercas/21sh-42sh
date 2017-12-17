#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            IN CORRECTION                            #
#######################################################################
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out<in ; cat out ; rm out in" {
	run bash -c  'echo toto > in ; cat -e >out<in ; cat out ; rm out in'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto > in ; cat -e >out<in ; cat out ; rm out in'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out <in ; cat out ; rm out in" {
	run bash -c  'echo toto > in ; cat -e >out <in ; cat out ; rm out in'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto > in ; cat -e >out <in ; cat out ; rm out in'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true || false && ls" {
	run bash -c  'true || false && ls'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true || false && ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for cd /tmp && cd / | ls" {
	run bash -c  'cd /tmp && cd / | ls'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp && cd / | ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo a > file | echo b > file; cat file ; rm file" {
	run bash -c  'echo a > file | echo b > file; cat file ; rm file'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a > file | echo b > file; cat file ; rm file'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo a||echo b&&echo c&&echo d;false&&false||false&&false;true" {
	run bash -c  'echo a||echo b&&echo c&&echo d;false&&false||false&&false;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a||echo b&&echo c&&echo d;false&&false||false&&false;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo lol && echo pouet && echo truc" {
	run bash -c  'echo lol && echo pouet && echo truc'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo lol && echo pouet && echo truc'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && echo lol;true" {
	run bash -c  'false && echo lol;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && echo lol;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && echo pouet;true" {
	run bash -c  'false && echo pouet;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && echo pouet;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo pouet || echo lol" {
	run bash -c  'echo pouet || echo lol'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo pouet || echo lol'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true && false && ls;true" {
	run bash -c  'true && false && ls;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true && false && ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true && false || ls;true" {
	run bash -c  'true && false || ls;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true && false || ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true || false && ls;true" {
	run bash -c  'true || false && ls;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true || false && ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true || false || ls;true" {
	run bash -c  'true || false || ls;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true || false || ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && true && ls;true" {
	run bash -c  'false && true && ls;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && true && ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && true || ls;true" {
	run bash -c  'false && true || ls;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && true || ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false || true && ls;true" {
	run bash -c  'false || true && ls;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false || true && ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false || true || ls;true" {
	run bash -c  'false || true || ls;true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false || true || ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for ls this_file_does_not_exist 2>&1 > /tmp/redir_test_file;rm -f /tmp/redir_test_file;echo abc && echo def; echo 123 > /tmp/test_redir_file_stdout;echo \"---\" ; echo \"---\" ;cat /tmp/test_redir_file_stdout;rm -f /tmp/test_redir_file_stdout" {
	run bash -c  'ls this_file_does_not_exist 2>&1 > /tmp/redir_test_file;rm -f /tmp/redir_test_file;echo abc && echo def; echo 123 > /tmp/test_redir_file_stdout;echo \"---\" ; echo \"---\" ;cat /tmp/test_redir_file_stdout;rm -f /tmp/test_redir_file_stdout'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls this_file_does_not_exist 2>&1 > /tmp/redir_test_file;rm -f /tmp/redir_test_file;echo abc && echo def; echo 123 > /tmp/test_redir_file_stdout;echo \"---\" ; echo \"---\" ;cat /tmp/test_redir_file_stdout;rm -f /tmp/test_redir_file_stdout'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo 'abc' > /tmp/redir_stdin_close;/bin/cat -e <&- </tmp/redir_stdin_close;echo 'def' <&- </tmp/redir_stdin_close;echo end;cat -e /tmp/redir_stdin_close;rm -f /tmp/redir_stdin_close" {
	run bash -c  'echo 'abc' > /tmp/redir_stdin_close;/bin/cat -e <&- </tmp/redir_stdin_close;echo 'def' <&- </tmp/redir_stdin_close;echo end;cat -e /tmp/redir_stdin_close;rm -f /tmp/redir_stdin_close'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'abc' > /tmp/redir_stdin_close;/bin/cat -e <&- </tmp/redir_stdin_close;echo 'def' <&- </tmp/redir_stdin_close;echo end;cat -e /tmp/redir_stdin_close;rm -f /tmp/redir_stdin_close'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo 'abc' > /tmp/redir_lessgreat_file;/bin/cat 3<>/tmp/redir_lessgreat_file <&3 -e" {
	run bash -c  'echo 'abc' > /tmp/redir_lessgreat_file;/bin/cat 3<>/tmp/redir_lessgreat_file <&3 -e'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'abc' > /tmp/redir_lessgreat_file;/bin/cat 3<>/tmp/redir_lessgreat_file <&3 -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo 'def' | cat 3<>/tmp/redir_lessgreat_file >&3 -e;/bin/cat -e /tmp/redir_lessgreat_file" {
	run bash -c  'echo 'def' | cat 3<>/tmp/redir_lessgreat_file >&3 -e;/bin/cat -e /tmp/redir_lessgreat_file'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'def' | cat 3<>/tmp/redir_lessgreat_file >&3 -e;/bin/cat -e /tmp/redir_lessgreat_file'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo 'ghi' > /tmp/redir_lessgreat_file 4<>/tmp/redir_lessgreat_file ; cat -e /tmp/redir_lessgreat_file ; rm -f /tmp/redir_lessgreat_file" {
	run bash -c  'echo 'ghi' > /tmp/redir_lessgreat_file 4<>/tmp/redir_lessgreat_file ; cat -e /tmp/redir_lessgreat_file ; rm -f /tmp/redir_lessgreat_file'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'ghi' > /tmp/redir_lessgreat_file 4<>/tmp/redir_lessgreat_file ; cat -e /tmp/redir_lessgreat_file ; rm -f /tmp/redir_lessgreat_file'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo lol | wc -l | xargs echo > /tmp/testfile ; cat /tmp/testfile;cat -e < /tmp/testfile | wc -c | xargs echo;cat -e < /tmp/testfile | wc -c | xargs echo > /tmp/testfile2;cat /tmp/testfile2 ; rm /tmp/testfile /tmp/testfile2" {
	run bash -c  'echo lol | wc -l | xargs echo > /tmp/testfile ; cat /tmp/testfile;cat -e < /tmp/testfile | wc -c | xargs echo;cat -e < /tmp/testfile | wc -c | xargs echo > /tmp/testfile2;cat /tmp/testfile2 ; rm /tmp/testfile /tmp/testfile2'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo lol | wc -l | xargs echo > /tmp/testfile ; cat /tmp/testfile;cat -e < /tmp/testfile | wc -c | xargs echo;cat -e < /tmp/testfile | wc -c | xargs echo > /tmp/testfile2;cat /tmp/testfile2 ; rm /tmp/testfile /tmp/testfile2'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo a | cat -e" {
	run bash -c  'echo a | cat -e'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo a | cat | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e" {
	run bash -c  'echo a | cat | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a | cat | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo def > /tmp/redir_one_to_all;cat 9</tmp/redir_one_to_all 8<&9 7<&8 6<&7 -e 5<&6 4<&5 3<&4 2<&3 1<&2 <&1;rm -f /tmp/redir_one_to_all" {
	run bash -c  'echo def > /tmp/redir_one_to_all;cat 9</tmp/redir_one_to_all 8<&9 7<&8 6<&7 -e 5<&6 4<&5 3<&4 2<&3 1<&2 <&1;rm -f /tmp/redir_one_to_all'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo def > /tmp/redir_one_to_all;cat 9</tmp/redir_one_to_all 8<&9 7<&8 6<&7 -e 5<&6 4<&5 3<&4 2<&3 1<&2 <&1;rm -f /tmp/redir_one_to_all'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo abcd > /tmp/redir_multi_op_great >> /tmp/redir_multi_op_dgreat;file /tmp/redir_multi_op_great;file /tmp/redir_multi_op_dgreat;rm -f /tmp/redir_multi_op_great /tmp/redir_multi_op_dgreat" {
	run bash -c  'echo abcd > /tmp/redir_multi_op_great >> /tmp/redir_multi_op_dgreat;file /tmp/redir_multi_op_great;file /tmp/redir_multi_op_dgreat;rm -f /tmp/redir_multi_op_great /tmp/redir_multi_op_dgreat'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abcd > /tmp/redir_multi_op_great >> /tmp/redir_multi_op_dgreat;file /tmp/redir_multi_op_great;file /tmp/redir_multi_op_dgreat;rm -f /tmp/redir_multi_op_great /tmp/redir_multi_op_dgreat'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo merde > /tmp/redir_echo_in;cat 3</tmp/redir_echo_in <&3;rm -f /tmp/redir_echo_in" {
	run bash -c  'echo merde > /tmp/redir_echo_in;cat 3</tmp/redir_echo_in <&3;rm -f /tmp/redir_echo_in'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo merde > /tmp/redir_echo_in;cat 3</tmp/redir_echo_in <&3;rm -f /tmp/redir_echo_in'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for ls;" {
	run bash -c  'ls;'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls;'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true && true   || echo 1" {
	run bash -c  'true && true   || echo 1'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true && true   || echo 1'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true && false   || echo 3" {
	run bash -c  'true && false   || echo 3'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true && false   || echo 3'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && true   || echo 5" {
	run bash -c  'false && true   || echo 5'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && true   || echo 5'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && false   || echo 7 ; true" {
	run bash -c  'false && false   || echo 7 ; true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && false   || echo 7 ; true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true ||   true && echo 9" {
	run bash -c  'true ||   true && echo 9'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true ||   true && echo 9'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true ||   false && echo 11" {
	run bash -c  'true ||   false && echo 11'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true ||   false && echo 11'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false ||   true && echo 13" {
	run bash -c  'false ||   true && echo 13'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false ||   true && echo 13'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false ||   false && echo 15 ; true" {
	run bash -c  'false ||   false && echo 15 ; true'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false ||   false && echo 15 ; true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo a&&echo b;echo c||echo d" {
	run bash -c  'echo a&&echo b;echo c||echo d'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a&&echo b;echo c||echo d'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo a&&echo b;echo c||echo d;" {
	run bash -c  'echo a&&echo b;echo c||echo d;'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a&&echo b;echo c||echo d;'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for cat toto" {
	run bash -c  'cat toto'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cat toto'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for cat < DOES_NOT_EXIST 2>/tmp/redir_not_exist_cat; cat -e /tmp/redir_not_exist_cat; rm -r /tmp/redir_not_exist_cat" {
	run bash -c  'cat < DOES_NOT_EXIST 2>/tmp/redir_not_exist_cat; cat -e /tmp/redir_not_exist_cat; rm -r /tmp/redir_not_exist_cat'
    expect=$output
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cat < DOES_NOT_EXIST 2>/tmp/redir_not_exist_cat; cat -e /tmp/redir_not_exist_cat; rm -r /tmp/redir_not_exist_cat'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
