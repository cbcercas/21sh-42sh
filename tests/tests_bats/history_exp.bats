#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            SIMPLE                                   #
#######################################################################


@test "HISTORY_EXP: Testing [bang_number] for 'echo !1" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo !1'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED -><something>"
    echo
    [ "${lines[0]}" != "" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "HISTORY_EXP: Testing [double_bang_empty_string] for '!!'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '!!'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED -><something> but not 21sh: command not found: !!"
    echo
    [ "${lines[0]}" != "21sh: command not found: !!" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "HISTORY_EXP: Testing [bang_number_empty_history] for '!1; !-1; echo !-3; echo !3; !-3; !3; echo !999999999999999999999999999; echo !-999999999999999999999999999; !999999999999999999999999999; !-999999999999999999999999999; echo !-0; echo !0; !-0; !0'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '!1; !-1; echo !-3; echo !3; !-3; !3; echo !999999999999999999999999999; echo !-999999999999999999999999999; !999999999999999999999999999; !-999999999999999999999999999; echo !-0; echo !0; !-0; !0'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo "                event not found"
    echo
    [ "${lines[0]}" = "event not found" ]
    [ "${lines[1]}" = "event not found" ]
    [ "${lines[2]}" = "event not found" ]
    [ "${lines[3]}" = "event not found" ]
    [ "${lines[4]}" = "event not found" ]
    [ "${lines[5]}" = "event not found" ]
    [ "${lines[6]}" = "event not found" ]
    [ "${lines[7]}" = "event not found" ]
    [ "${lines[8]}" = "event not found" ]
    [ "${lines[9]}" = "event not found" ]
    [ "${lines[10]}" = "event not found" ]
    [ "${lines[11]}" = "event not found" ]
    [ "${lines[12]}" = "event not found" ]
    [ "${lines[13]}" = "event not found" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}


