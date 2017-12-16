#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            IN CORRECTION                            #
#######################################################################
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out<in ; cat out ; rm out in" {
    expect=`echo toto > in ; cat -e >out<in ; cat out ; rm out in`
    stat="$?"
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
    expect=`echo toto > in ; cat -e >out <in ; cat out ; rm out in`
    stat="$?"
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
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out <&in ; cat out ; rm out in" {
    expect=`echo toto > in ; cat -e >out <&in ; cat out ; rm out in`
    stat="$?"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto > in ; cat -e >out <&in ; cat out ; rm out in'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out<&in ; cat out ; rm out in" {
    expect=`echo toto > in ; cat -e >out<&in ; cat out ; rm out in`
    stat="$?"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto > in ; cat -e >out<&in ; cat out ; rm out in'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out<& in ; cat out ; rm out in" {
    expect=`echo toto > in ; cat -e >out<& in ; cat out ; rm out in`
    stat="$?"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto > in ; cat -e >out<& in ; cat out ; rm out in'
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
    expect=`true || false && ls`
    stat="$?"
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
    expect=`cd /tmp && cd / | ls`
    stat="$?"
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
    expect=`echo a > file | echo b > file; cat file ; rm file`
    stat="$?"
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
    expect=`echo a||echo b&&echo c&&echo d;false&&false||false&&false;true`
    stat="$?"
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
    expect=`echo lol && echo pouet && echo truc`
    stat="$?"
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
    expect=`false && echo lol;true`
    stat="$?"
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
    expect=`false && echo pouet;true`
    stat="$?"
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
    expect=`echo pouet || echo lol`
    stat="$?"
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
    expect=`true && false && ls;true`
    stat="$?"
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
    expect=`true && false || ls;true`
    stat="$?"
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
    expect=`true || false && ls;true`
    stat="$?"
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
    expect=`true || false || ls;true`
    stat="$?"
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
    expect=`false && true && ls;true`
    stat="$?"
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
    expect=`false && true || ls;true`
    stat="$?"
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
    expect=`false || true && ls;true`
    stat="$?"
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
    expect=`false || true || ls;true`
    stat="$?"
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
    expect=`ls this_file_does_not_exist 2>&1 > /tmp/redir_test_file;rm -f /tmp/redir_test_file;echo abc && echo def; echo 123 > /tmp/test_redir_file_stdout;echo \"---\" ; echo \"---\" ;cat /tmp/test_redir_file_stdout;rm -f /tmp/test_redir_file_stdout`
    stat="$?"
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
    expect=`echo 'abc' > /tmp/redir_stdin_close;/bin/cat -e <&- </tmp/redir_stdin_close;echo 'def' <&- </tmp/redir_stdin_close;echo end;cat -e /tmp/redir_stdin_close;rm -f /tmp/redir_stdin_close`
    stat="$?"
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
    expect=`echo 'abc' > /tmp/redir_lessgreat_file;/bin/cat 3<>/tmp/redir_lessgreat_file <&3 -e`
    stat="$?"
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
    expect=`echo 'def' | cat 3<>/tmp/redir_lessgreat_file >&3 -e;/bin/cat -e /tmp/redir_lessgreat_file`
    stat="$?"
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
    expect=`echo 'ghi' > /tmp/redir_lessgreat_file 4<>/tmp/redir_lessgreat_file ; cat -e /tmp/redir_lessgreat_file ; rm -f /tmp/redir_lessgreat_file`
    stat="$?"
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
    expect=`echo lol | wc -l | xargs echo > /tmp/testfile ; cat /tmp/testfile;cat -e < /tmp/testfile | wc -c | xargs echo;cat -e < /tmp/testfile | wc -c | xargs echo > /tmp/testfile2;cat /tmp/testfile2 ; rm /tmp/testfile /tmp/testfile2`
    stat="$?"
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
    expect=`echo a | cat -e`
    stat="$?"
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
    expect=`echo a | cat | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e`
    stat="$?"
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
    expect=`echo def > /tmp/redir_one_to_all;cat 9</tmp/redir_one_to_all 8<&9 7<&8 6<&7 -e 5<&6 4<&5 3<&4 2<&3 1<&2 <&1;rm -f /tmp/redir_one_to_all`
    stat="$?"
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
    expect=`echo abcd > /tmp/redir_multi_op_great >> /tmp/redir_multi_op_dgreat;file /tmp/redir_multi_op_great;file /tmp/redir_multi_op_dgreat;rm -f /tmp/redir_multi_op_great /tmp/redir_multi_op_dgreat`
    stat="$?"
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
    expect=`echo merde > /tmp/redir_echo_in;cat 3</tmp/redir_echo_in <&3;rm -f /tmp/redir_echo_in`
    stat="$?"
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
@test "EXEC: Testing [CREATE] for echo abc | wc | exit 84" {
    expect=`echo abc | wc | exit 84`
    stat="$?"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc | wc | exit 84'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo abc | exit 1 | wc | exit 2" {
    expect=`echo abc | exit 1 | wc | exit 2`
    stat="$?"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc | exit 1 | wc | exit 2'
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
    expect=`ls;`
    stat="$?"
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
    expect=`true && true   || echo 1`
    stat="$?"
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
    expect=`true && false   || echo 3`
    stat="$?"
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
    expect=`false && true   || echo 5`
    stat="$?"
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
    expect=`false && false   || echo 7 ; true`
    stat="$?"
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
    expect=`true ||   true && echo 9`
    stat="$?"
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
    expect=`true ||   false && echo 11`
    stat="$?"
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
    expect=`false ||   true && echo 13`
    stat="$?"
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
    expect=`false ||   false && echo 15 ; true`
    stat="$?"
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
    expect=`echo a&&echo b;echo c||echo d`
    stat="$?"
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
    expect=`echo a&&echo b;echo c||echo d;`
    stat="$?"
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
