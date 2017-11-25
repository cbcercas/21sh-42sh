#! / Usr / bin / env bats

load test_helper

####start###

@test ": Testing [] for ''" {
    skip "Template"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c ''
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->"
    echo "                      "
    echo "                      "
    echo "                      "
	[ "${lines[0]}" = "" ]
	[ "${lines[1]}" = "" ]
	[ "${lines[2]}" = "" ]
	[ "${lines[3]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

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
	[ "${lines[1]}" = "b" ]
	[ "${lines[2]}" = "c" ]
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

