#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            IN CORRECTION                            #
#######################################################################
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out<in ; cat out ; rm out in" {
	run bash -c  'echo toto > in ; cat -e >out<in ; cat out ; rm out in'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
@test "EXEC: Testing [CREATE] for true && false && ls" {
	run bash -c  'true && false && ls'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true && false && ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true && false || ls" {
	run bash -c  'true && false || ls'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true && false || ls'
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
@test "EXEC: Testing [CREATE] for true || false || ls" {
	run bash -c  'true || false || ls'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true || false || ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && true && ls" {
	run bash -c  'false && true && ls'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && true && ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && true || ls" {
	run bash -c  'false && true || ls'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && true || ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false || true && ls" {
	run bash -c  'false || true && ls'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false || true && ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false || true || ls" {
	run bash -c  'false || true || ls'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false || true || ls'
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
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
@test "EXEC: Testing [CREATE] for cat < NO_SUCH_file" {
	run bash -c  'cat < NO_SUCH_file'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cat < NO_SUCH_file'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo lol && echo pouet && echo truc; cat pouet && echo lol; false && echo pouet" {
	run bash -c  'echo lol && echo pouet && echo truc; cat pouet && echo lol; false && echo pouet'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo lol && echo pouet && echo truc; cat pouet && echo lol; false && echo pouet'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for env env env env env env env -i env ls" {
	run bash -c  'env env env env env env env -i env ls'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env env env env env env env -i env ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for cd /; cd -; cd /; cd ../; cd;" {
	run bash -c  'cd /; cd -; cd /; cd ../; cd;'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /; cd -; cd /; cd ../; cd;'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for ls | wc -l > toto; echo abc | wc -l >> toto; cat -e toto ; rm -rf toto" {
	run bash -c  'ls | wc -l > toto; echo abc | wc -l >> toto; cat -e toto ; rm -rf toto'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls | wc -l > toto; echo abc | wc -l >> toto; cat -e toto ; rm -rf toto'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for ls /dev | grep tty | sort -r | rev > toto ; < toto cat | rev | wc -l > titi ; rm -rf titi" {
	run bash -c  'ls /dev | grep tty | sort -r | rev > toto ; < toto cat | rev | wc -l > titi ; rm -rf titi'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls /dev | grep tty | sort -r | rev > toto ; < toto cat | rev | wc -l > titi ; rm -rf titi'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo ~" {
	run bash -c  'echo ~'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo ~'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo ~/toutou" {
	run bash -c  'echo ~/toutou'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo ~/toutou'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo true || echo false && echo maarek && echo joseph" {
	run bash -c  'echo true || echo false && echo maarek && echo joseph'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo true || echo false && echo maarek && echo joseph'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo check only && echo priority || echo operators;" {
	run bash -c  'echo check only && echo priority || echo operators;'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo check only && echo priority || echo operators;'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo toto; echo tata; echo titi;" {
	run bash -c  'echo toto; echo tata; echo titi;'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto; echo tata; echo titi;'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo toto; echo tata; echo titi; echo jojo; echo jiji; echo jaja" {
	run bash -c  'echo toto; echo tata; echo titi; echo jojo; echo jiji; echo jaja'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto; echo tata; echo titi; echo jojo; echo jiji; echo jaja'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for ls / | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | sort" {
	run bash -c  'ls / | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | sort'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls / | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | sort'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo toto tata titi tete tutu toutou tuitui touatoua touytouy merciiiiiiiiiiiii" {
	run bash -c  'echo toto tata titi tete tutu toutou tuitui touatoua touytouy merciiiiiiiiiiiii'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto tata titi tete tutu toutou tuitui touatoua touytouy merciiiiiiiiiiiii'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for rm -rf toto" {
	run bash -c  'rm -rf toto'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm -rf toto'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo "$TERM"" {
	run bash -c  'echo "$TERM"'
    expect=$(echo "$output" | sed s/bash/$name_exec/g )
    stat="$status"
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "$TERM"'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo "EXITING STATUS:"
    echo "$name_exec:$status = bash:$stat"
    [ "${output}" = "$expect" ]
    [ "$status" -eq $stat ]
    check_leaks_function exec
}
