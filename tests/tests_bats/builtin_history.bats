#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            SIMPLE                                   #
#######################################################################

@test "BUILTIN_HISTORY: Testing [cmd_not_found_in_history] for 'echo abc; 2>&- export VAR=value || setenv VAR=value; echo def; pwd; echo ghi; echo "zut" > /tmp/history_cat_file; cat -e /tmp/history_cat_file; rm -f /tmp/history_cat_file; history merde; history -n merde; history -r merde; history -nr merde'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc; 2>&- export VAR=value || setenv VAR=value; echo def; pwd; echo ghi; echo "zut" > /tmp/history_cat_file; cat -e /tmp/history_cat_file; rm -f /tmp/history_cat_file; history merde; history -n merde; history -r merde; history -nr merde'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->abc"
    echo "              ->def"
    echo "              ->/Users/mleroy/21-42sh"
    echo "              ->ghi"
    echo "              ->zut$"
    echo "              ->21sh: history: merde: numeric argument required"
    echo
    [ "${lines[0]}" = "abc" ]
    [ "${lines[1]}" = "def" ]
    [ "${lines[2]}" = "/Users/mleroy/21-42sh" ]
    [ "${lines[3]}" = "ghi" ]
    [ "${lines[4]}" = "zut$" ]
    [ "${lines[5]}" = "21sh: history: merde: numeric argument required" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_HISTORY: Testing [empty_history] for 'history'" {
    rm ~/.21sh_history
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'history'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->21sh: history: no history (yet)"
    echo
    [ "${lines[0]}" = "21sh: history: no history (yet)" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_HISTORY: Testing [err_bad_opt] for 'echo abc; 2>&- export VAR=value || setenv VAR=value; echo def; pwd; echo ghi; echo "zut" > /tmp/history_cat_file; cat -e /tmp/history_cat_file; rm -f /tmp/history_cat_file; history -x; history -- -1; history 0 -1'" {
    rm ~/.21sh_history
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc; 2>&- export VAR=value || setenv VAR=value; echo def; pwd; echo ghi; echo "zut" > /tmp/history_cat_file; cat -e /tmp/history_cat_file; rm -f /tmp/history_cat_file; history -x; history -- -1; history 0 -1'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->abc"
    echo "              ->def"
    echo "              ->/Users/mleroy/21-42sh"
    echo "              ->ghi"
    echo "              ->zut$"
    echo "              ->21sh: history: -x: invalid option"
    echo "              ->history: usage: history [-c] [-d offset] [n] or history -awrn [filename] or history -ps arg [arg...]
                                                    2  echo abc; 2>&- export VAR=value || setenv VAR value; echo def; pwd; echo ghi; echo "zut" > /tmp/history_cat_file; cat -e /tmp/history_cat_file; rm -f /tmp/history_cat_file; history -x; history -- -1; history 0 -1"
   echo "              ->21sh: history: too many arguments"
   echo
   [ "${lines[0]}" = "abc" ]
   [ "${lines[1]}" = "def" ]
   [ "${lines[2]}" = "/Users/mleroy/21-42sh" ]
   [ "${lines[3]}" = "ghi" ]
   [ "${lines[4]}" = "zut$" ]
   [ "${lines[5]}" = "21sh: history: -x: invalid option" ]
   [ "${lines[6]}" = "history: usage: history [-c] [-d offset] [n] or history -awrn [filename] or history -ps arg [arg...]
                          2  echo abc; 2>&- export VAR=value || setenv VAR value; echo def; pwd; echo ghi; echo "zut" > /tmp/history_cat_file; cat -e /tmp/history_cat_file; rm -f /tmp/history_cat_file; history -x; history -- -1; history 0 -1" ]
   [ "${lines[7]}" = "21sh: history: too many arguments" ]
   [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_HISTORY: Testing [err_index_not_int] for 'echo abc; 2>&- export VAR=value || setenv VAR=value; echo def; pwd; echo ghi; echo \"zut\" > /tmp/history_cat_file; cat -e /tmp/history_cat_file; rm -f /tmp/history_cat_file; history a 2; history 1 a; history 1 2 3'" {
    rm ~/.21sh_history
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc; 2>&- export VAR=value || setenv VAR=value; echo def; pwd; echo ghi; echo "zut" > /tmp/history_cat_file; cat -e /tmp/history_cat_file; rm -f /tmp/history_cat_file; history a 2; history 1 a; history 1 2 3'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->abc"
    echo "              ->def"
    echo "              ->/Users/mleroy/21-42sh"
    echo "              ->ghi"
    echo "              ->zut$"
    echo "              ->21sh: history: a: numeric argument required"
    echo
    [ "${lines[0]}" = "abc" ]
    [ "${lines[1]}" = "def" ]
    [ "${lines[2]}" = "/Users/mleroy/21-42sh" ]
    [ "${lines[3]}" = "ghi" ]
    [ "${lines[4]}" = "zut$" ]
    [ "${lines[5]}" = "21sh: history: a: numeric argument required" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

