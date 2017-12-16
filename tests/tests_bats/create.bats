#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            IN CORRECTION                            #
#######################################################################
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out<in ; cat out ; rm out in" {
    expect=`echo toto > in ; cat -e >out<in ; cat out ; rm out in`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto > in ; cat -e >out<in ; cat out ; rm out in'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out <in ; cat out ; rm out in" {
    expect=`echo toto > in ; cat -e >out <in ; cat out ; rm out in`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto > in ; cat -e >out <in ; cat out ; rm out in'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out <&in ; cat out ; rm out in" {
    expect=`echo toto > in ; cat -e >out <&in ; cat out ; rm out in`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto > in ; cat -e >out <&in ; cat out ; rm out in'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out<&in ; cat out ; rm out in" {
    expect=`echo toto > in ; cat -e >out<&in ; cat out ; rm out in`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto > in ; cat -e >out<&in ; cat out ; rm out in'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo toto > in ; cat -e >out<& in ; cat out ; rm out in" {
    expect=`echo toto > in ; cat -e >out<& in ; cat out ; rm out in`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo toto > in ; cat -e >out<& in ; cat out ; rm out in'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true || false && ls" {
    expect=`true || false && ls`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true || false && ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for cd /tmp && cd / | ls" {
    expect=`cd /tmp && cd / | ls`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp && cd / | ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo a > file | echo b > file; cat file ; rm file" {
    expect=`echo a > file | echo b > file; cat file ; rm file`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a > file | echo b > file; cat file ; rm file'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo a||echo b&&echo c&&echo d;false&&false||false&&false;true" {
    expect=`echo a||echo b&&echo c&&echo d;false&&false||false&&false;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a||echo b&&echo c&&echo d;false&&false||false&&false;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo lol && echo pouet && echo truc" {
    expect=`echo lol && echo pouet && echo truc`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo lol && echo pouet && echo truc'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && echo lol;true" {
    expect=`false && echo lol;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && echo lol;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && echo pouet;true" {
    expect=`false && echo pouet;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && echo pouet;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo pouet || echo lol" {
    expect=`echo pouet || echo lol`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo pouet || echo lol'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true && false && ls;true" {
    expect=`true && false && ls;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true && false && ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true && false || ls;true" {
    expect=`true && false || ls;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true && false || ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true || false && ls;true" {
    expect=`true || false && ls;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true || false && ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for true || false || ls;true" {
    expect=`true || false || ls;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true || false || ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && true && ls;true" {
    expect=`false && true && ls;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && true && ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false && true || ls;true" {
    expect=`false && true || ls;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false && true || ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false || true && ls;true" {
    expect=`false || true && ls;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false || true && ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for false || true || ls;true" {
    expect=`false || true || ls;true`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false || true || ls;true'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for ls this_file_does_not_exist 2>&1 > /tmp/redir_test_file;rm -f /tmp/redir_test_file;echo abc && echo def; echo 123 > /tmp/test_redir_file_stdout;echo \"---\" ; echo \"---\" ;cat /tmp/test_redir_file_stdout;rm -f /tmp/test_redir_file_stdout" {
    expect=`ls this_file_does_not_exist 2>&1 > /tmp/redir_test_file;rm -f /tmp/redir_test_file;echo abc && echo def; echo 123 > /tmp/test_redir_file_stdout;echo \"---\" ; echo \"---\" ;cat /tmp/test_redir_file_stdout;rm -f /tmp/test_redir_file_stdout`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'ls this_file_does_not_exist 2>&1 > /tmp/redir_test_file;rm -f /tmp/redir_test_file;echo abc && echo def; echo 123 > /tmp/test_redir_file_stdout;echo \"---\" ; echo \"---\" ;cat /tmp/test_redir_file_stdout;rm -f /tmp/test_redir_file_stdout'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo 'abc' > /tmp/redir_stdin_close;/bin/cat -e <&- </tmp/redir_stdin_close;echo 'def' <&- </tmp/redir_stdin_close;echo end;cat -e /tmp/redir_stdin_close;rm -f /tmp/redir_stdin_close" {
    expect=`echo 'abc' > /tmp/redir_stdin_close;/bin/cat -e <&- </tmp/redir_stdin_close;echo 'def' <&- </tmp/redir_stdin_close;echo end;cat -e /tmp/redir_stdin_close;rm -f /tmp/redir_stdin_close`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'abc' > /tmp/redir_stdin_close;/bin/cat -e <&- </tmp/redir_stdin_close;echo 'def' <&- </tmp/redir_stdin_close;echo end;cat -e /tmp/redir_stdin_close;rm -f /tmp/redir_stdin_close'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo 'abc' > /tmp/redir_lessgreat_file;/bin/cat 3<>/tmp/redir_lessgreat_file <&3 -e" {
    expect=`echo 'abc' > /tmp/redir_lessgreat_file;/bin/cat 3<>/tmp/redir_lessgreat_file <&3 -e`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'abc' > /tmp/redir_lessgreat_file;/bin/cat 3<>/tmp/redir_lessgreat_file <&3 -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
@test "EXEC: Testing [CREATE] for echo 'def' | cat 3<>/tmp/redir_lessgreat_file >&3 -e;/bin/cat -e /tmp/redir_lessgreat_file" {
    expect=`echo 'def' | cat 3<>/tmp/redir_lessgreat_file >&3 -e;/bin/cat -e /tmp/redir_lessgreat_file`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'def' | cat 3<>/tmp/redir_lessgreat_file >&3 -e;/bin/cat -e /tmp/redir_lessgreat_file'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
