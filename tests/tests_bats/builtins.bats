#! / Usr / bin / env bats

load test_helper

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

@test "BUILTINS: Testing [Builtin PWD] for 'cd -L file_link; pwd -L'" {
		if [[ !(-e file_link) ]]; then
    		ln -s . file_link
    	fi
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd file_link; pwd -L'
	expect=`cd file_link; pwd -L`
	rm -rf file_link
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "$output" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin PWD] for 'cd -L file_link; pwd -P'" {
		if [[ !(-e file_link) ]]; then
    		ln -s . file_link
    	fi
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd file_link; pwd -P'
	expect=`cd file_link; pwd -P`
	rm -rf file_link
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "$output" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin PWD] for 'cd -P file_link; pwd -L'" {
		if [[ !(-e file_link) ]]; then
    		ln -s . file_link
    	fi
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd -P file_link; pwd -L'
	expect=`cd -P file_link; pwd -L`
	rm -rf file_link
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "$output" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin PWD] for 'cd -P file_link; pwd -P'" {
		if [[ !(-e file_link) ]]; then
    		ln -s . file_link
    	fi
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd file_link; pwd -P'
	expect=`cd -P file_link; pwd -P`
	rm -rf file_link
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "$output" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "BUILTINS: Testing [Builtin PWD] for 'pwd /doesnt/exists'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'pwd /doesnt/exists'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->usage: pwd [-L | -P]"
	[ "${lines[0]}" = "usage: pwd [-L | -P]" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}
######################################################################
######################################################################

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

@test "BUILTIN_EXIT: Testing [arg_overflow] for 'echo aaa; exit 256; echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo aaa; exit 256; echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->aaa"
    echo
    [ "${lines[0]}" = "aaa" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [first_command_in_the_shell] for 'exit; echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'exit; echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [last_command_in_list] for 'true; false; exit'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true; false; exit'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [last_command_in_list] for 'true; false; exit'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'true; false; exit'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [no_argument_error] for 'false; exit; echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'false; exit; echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [no_argument_ok] for 'echo aaa; exit; echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo aaa; exit; echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "aaa" ]
    [ "${lines[1]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [print_after_exit_and] for 'echo aaa; exit 0 && echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo aaa; exit 0 && echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->exit"
    echo
    [ "${lines[0]}" = "aaa" ]
    [ "${lines[1]}" = "exit" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [print_after_exit_pipe] for 'echo a | echo b | echo b | exit 0 | echo end'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo a | echo b | echo b | exit 0 | echo end'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->end"
    echo
    [ "${lines[0]}" = "end" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_EXIT: Testing [valid_value] for 'echo aaa; exit 42; echo bbb'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo aaa; exit 42; echo bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->aaa"
    echo "                    ->exit"
    echo
    [ "${lines[0]}" = "aaa" ]
    [ "${lines[1]}" = "exit" ]
    [ "$status" -eq 42 ]
    check_leaks_function exec
}

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
######################################################################
######################################################################


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


@test "BUILTINS: Testing [Builtin CD] for 'cd -L file_link;pwd;cd..;pwd'" {
		if [[ !(-e file_link) ]]; then
    		ln -s . file_link
    	fi
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd -L file_link;pwd;cd ..;pwd'
	expect=`cd -L file_link;pwd;cd ..;pwd`
	rm -rf file_link
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "$output" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin CD] for 'cd -P file_link;pwd;cd ..;pwd'" {
	if [[ !(-e file_link) ]]; then
		ln -s . file_link
	fi
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd -P file_link;pwd;cd ..;pwd'
	expect=`cd -P file_link;pwd;cd ..;pwd`
	rm -rf file_link
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "$output" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [builtin_export_tabs_newline_spec] for 'mkdir -p \'/tmp/a b\'; cd \'/tmp/a b\'; pwd; cd /; rm -rf \'/tmp/a b\''" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c "mkdir -p '/tmp/a b'; cd '/tmp/a b'; pwd; cd /; rm -rf '/tmp/a b'"
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/a b"
	[ "${lines[0]}" = "/tmp/a b" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_CDPATH_spec] for 'mkdir -p /tmp/test_builtin_cd_folder; 2>&- export CDPATH=/tmp || setenv CDPATH /tmp; cd /; pwd; cd test_builtin_cd_folder; pwd; 2>&- unset CDPATH || unsetenv CDPATH; mkdir /tmp/bash-dir-a; 2>&- export CDPATH=.:/tmp || setenv CDPATH .:/tmp; cd bash-dir-a; pwd; printenv PWD; cd /; rmdir  /tmp/bash-dir-a; rm -rf /tmp/test_builtin_cd_folder'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'mkdir -p /tmp/test_builtin_cd_folder; 2>&- export CDPATH=/tmp || setenv CDPATH /tmp; cd /; pwd; cd test_builtin_cd_folder; pwd; 2>&- unset CDPATH || unsetenv CDPATH; mkdir /tmp/bash-dir-a; 2>&- export CDPATH=.:/tmp || setenv CDPATH .:/tmp; cd bash-dir-a; pwd; printenv PWD; cd /; rmdir  /tmp/bash-dir-a; rm -rf /tmp/test_builtin_cd_folder'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/"
    echo "                      /tmp/test_builtin_cd_folder"
    echo "                      /tmp/test_builtin_cd_folder"
    echo "                      /tmp/bash-dir-a"
    echo "                      /tmp/bash-dir-a"
    echo "                      /tmp/bash-dir-a"
	[ "${lines[0]}" = "/" ]
	[ "${lines[1]}" = "/tmp/test_builtin_cd_folder" ]
	[ "${lines[2]}" = "/tmp/test_builtin_cd_folder" ]
	[ "${lines[3]}" = "/tmp/bash-dir-a" ]
	[ "${lines[3]}" = "/tmp/bash-dir-a" ]
	[ "${lines[3]}" = "/tmp/bash-dir-a" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_basetests_spec] for 'cd /tmp; cd /; pwd; cd -; rm -rf test1_cd; rm -rf test2_cd; mkdir test1_cd; cd test1_cd; ls -a | cat -e; cd ..; ln -s test1_cd test2_cd; cd -P test2_cd; pwd | grep test1; cd ..; cd -P test2_cd; pwd | grep test2; cd ..; rm -rf test1_cd; rm -rf test2_cd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp; cd /; pwd; cd -; rm -rf test1_cd; rm -rf test2_cd; mkdir test1_cd; cd test1_cd; ls -a | cat -e; cd ..; ln -s test1_cd test2_cd; cd -P test2_cd; pwd | grep test1; cd ..; cd -P test2_cd; pwd | grep test2; cd ..; rm -rf test1_cd; rm -rf test2_cd'
	expected=`cd /tmp; cd /; pwd; cd -; rm -rf test1_cd; rm -rf test2_cd; mkdir test1_cd; cd test1_cd; ls -a | cat -e; cd ..; ln -s test1_cd test2_cd; cd -P test2_cd; pwd | grep test1; cd ..; cd -P test2_cd; pwd | grep test2; cd ..; rm -rf test1_cd; rm -rf test2_cd`
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expected"
	[ "${output}" = "$expected" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_dot_dot_spec] for 'mkdir -p /tmp/cd_test/dir1/dir2; cd /tmp/cd_test/dir1/dir2; pwd; cd ..; pwd | sed 's;/private;;'; cd /; rm -rf /tmp/cd_test'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c "mkdir -p /tmp/cd_test/dir1/dir2; cd /tmp/cd_test/dir1/dir2; pwd; cd ..; pwd | sed 's;/private;;'; cd /; rm -rf /tmp/cd_test"
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/cd_test/dir1/dir2"
    echo "                      /tmp/cd_test/dir1"
	[ "${lines[0]}" = "/tmp/cd_test/dir1/dir2" ]
	[ "${lines[1]}" = "/tmp/cd_test/dir1" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_err_home_spec] for 'unsetenv HOME; cd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv HOME; cd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->21sh: cd: HOME not set"
	[ "${lines[0]}" = "21sh: cd: HOME not set" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_err_oldpwd_spec1] for 'unsetenv OLDPWD; cd -'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv OLDPWD; cd -'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->21sh: cd: OLDPWD not set"
	[ "${lines[0]}" = "21sh: cd: OLDPWD not set" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "BUILTIN_CD: Testing [cd_err_oldpwd_spec2] for 'setenv OLDPWD=toto; cd -'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv OLDPWD=toto; cd -'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->cd: no such file or directory: -"
    echo "                      "
    echo "                      "
    echo "                      "
	[ "${lines[0]}" = "cd: no such file or directory: -" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_err_opt_spec] for 'cd -h'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd -h'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->cd: [-L/-P] [path], use "help cd"
	[ "${lines[0]}" = "cd: [-L/-P] [path], use "help cd" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_error_pwd] for 'cd . ; /bin/pwd ;'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd . ; /bin/pwd ;'
	expect=`bash -c 'cd . ; /bin/pwd ;'`
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "${output}" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_error_pwd] for 'cd /tmp; rm -rf toto; mkdir toto; unsetenv PWD; cd toto; pwd; cd -; setenv PWD=tata; cd toto; pwd; cd -; rm -rf toto; 2>&- cd tutu; cd /tmp; cd -; pwd; cd /tmp/toto; rm -rf /tmp/toto; cd -P .'" {
	skip "behaviour consistent but not similar to bash, sh or zsh"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp; rm -rf toto; mkdir toto; unsetenv PWD; cd toto; pwd; cd -; setenv PWD=tata; cd toto; pwd; cd -; rm -rf toto; 2>&- cd tutu; cd /tmp; cd -; pwd; cd /tmp/toto; rm -rf /tmp/toto'
	expect=`cd /tmp; rm -rf toto; mkdir toto; unsetenv PWD; cd toto; pwd; cd -; setenv PWD=tata; cd toto; pwd; cd -; rm -rf toto; 2>&- cd tutu; cd /tmp; cd -; pwd; cd /tmp/toto; rm -rf /tmp/toto`
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "${output}" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "BUILTIN_CD: Testing [cd_minus_spec] for 'cd /tmp; cd /; cd -; cd -P -; cd -L -; cd -P -; cd -L -; cd tutu 2>&-; cd -'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp; cd /; cd -; cd -P -; cd -L -; cd -P -; cd -L -; cd tutu 2>&-; cd -'
	expect=`cd /tmp; cd /; cd -; cd -P -; cd -L -; cd -P -; cd -L -; cd tutu 2>&-; cd -`
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "${output}" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_multiarg_spec] for 'cd /tmp /bin && pwd; cd /bin /tmp /usr && pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp /bin && pwd; cd /bin /tmp /usr && pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->cd: too many arguments"
    echo "                      cd: too many arguments"
	[ "${lines[0]}" = "cd: too many arguments" ]
	[ "${lines[1]}" = "cd: too many arguments" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_oldpwd] for 'cd /tmp; pwd; cd /; cd -; cd /tmp; pwd; cd -P -; cd -P -; cd -P /tmp; pwd; cd -; pwd; rm -rf /tmp/toto; mkdir /tmp/toto; cd /tmp; cd /tmp/toto; cd ..; pwd; cd -; pwd; cd /tmp; rm -rf /tmp/toto;'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp; pwd; cd /; cd -; cd /tmp; pwd; cd -P -; cd -P -; cd -P /tmp; pwd; cd -; pwd; rm -rf /tmp/toto; mkdir /tmp/toto; cd /tmp; cd /tmp/toto; cd ..; pwd; cd -; pwd; cd /tmp; rm -rf /tmp/toto;'
	expect=`cd /tmp; pwd; cd /; cd -; cd /tmp; pwd; cd -P -; cd -P -; cd -P /tmp; pwd; cd -; pwd; rm -rf /tmp/toto; mkdir /tmp/toto; cd /tmp; cd /tmp/toto; cd ..; pwd; cd -; pwd; cd /tmp; rm -rf /tmp/toto;`
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "${output}" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_opt_err_double_spec] for 'cd -P /tmp/nosuchfolder; cd /tmp/nosuchfolder -P'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd -P /tmp/nosuchfolder; cd /tmp/nosuchfolder -P'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->cd: no such file or directory: /tmp/nosuchfolder"
    echo "                      cd: too many arguments"
	[ "${lines[0]}" = "cd: no such file or directory: /tmp/nosuchfolder" ]
	[ "${lines[1]}" = "cd: too many arguments" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_simple_spec] for 'rm -rf /tmp/test_cd_4242; mkdir /tmp/test_cd_4242; cd /tmp/test_cd_4242; pwd; cd /; rm -rf /tmp/test_cd_4242'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'rm -rf /tmp/test_cd_4242; mkdir /tmp/test_cd_4242; cd /tmp/test_cd_4242; pwd; cd /; rm -rf /tmp/test_cd_4242'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/test_cd_4242"
	[ "${lines[0]}" = "/tmp/test_cd_4242" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "BUILTIN_CD: Testing [cd_sym_spec] for 'mkdir -p /tmp/test_cd_builtin/mydir; ln -s /tmp/test_cd_builtin/mydir /tmp/test_cd_builtin/mydir_sym1; ln -s /tmp/test_cd_builtin/mydir_sym1 /tmp/test_cd_builtin/mydir_sym2; cd /tmp/test_cd_builtin && cd mydir_sym1; pwd; cd -P /tmp/test_cd_builtin && cd mydir_sym1; pwd; cd -L /tmp/test_cd_builtin && cd mydir_sym1; pwd; cd /tmp/test_cd_builtin && cd mydir_sym2; pwd; cd -P /tmp/test_cd_builtin && cd mydir_sym2; pwd; cd -L /tmp/test_cd_builtin && cd mydir_sym2; pwd; cd /; rm -rf /tmp/test_cd_builtin'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'mkdir -p /tmp/test_cd_builtin/mydir; ln -s /tmp/test_cd_builtin/mydir /tmp/test_cd_builtin/mydir_sym1; ln -s /tmp/test_cd_builtin/mydir_sym1 /tmp/test_cd_builtin/mydir_sym2; cd /tmp/test_cd_builtin && cd mydir_sym1; pwd; cd -P /tmp/test_cd_builtin && cd mydir_sym1; pwd; cd -L /tmp/test_cd_builtin && cd mydir_sym1; pwd; cd /tmp/test_cd_builtin && cd mydir_sym2; pwd; cd -P /tmp/test_cd_builtin && cd mydir_sym2; pwd; cd -L /tmp/test_cd_builtin && cd mydir_sym2; pwd; cd /; rm -rf /tmp/test_cd_builtin'
	expect=`mkdir -p /tmp/test_cd_builtin/mydir; ln -s /tmp/test_cd_builtin/mydir /tmp/test_cd_builtin/mydir_sym1; ln -s /tmp/test_cd_builtin/mydir_sym1 /tmp/test_cd_builtin/mydir_sym2; cd /tmp/test_cd_builtin && cd mydir_sym1; pwd; cd -P /tmp/test_cd_builtin && cd mydir_sym1; pwd; cd -L /tmp/test_cd_builtin && cd mydir_sym1; pwd; cd /tmp/test_cd_builtin && cd mydir_sym2; pwd; cd -P /tmp/test_cd_builtin && cd mydir_sym2; pwd; cd -L /tmp/test_cd_builtin && cd mydir_sym2; pwd; cd /; rm -rf /tmp/test_cd_builtin`
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "${output}" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_with_spaces_spec] for 'rm -rf /tmp/cd_test\ 4242; mkdir /tmp/cd_test\ 4242; cd /tmp/cd_test\ 4242; pwd; cd /; rm -rf \'/tmp/cd_test 4242\''" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c "rm -rf /tmp/cd_test\ 4242; mkdir /tmp/cd_test\ 4242; cd /tmp/cd_test\ 4242; pwd; cd /; rm -rf '/tmp/cd_test 4242'"
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/cd_test 4242"
	[ "${lines[0]}" = "/tmp/cd_test 4242" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_with_spaces] for 'mkdir -p '/tmp/a b'; cd '/tmp/a b'; pwd; cd /; rm -rf '/tmp/a b''" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'mkdir -p "/tmp/a b"; cd "/tmp/a b"; pwd; cd /; rm -rf "/tmp/a b"'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/a b"
	[ "${lines[0]}" = "/tmp/a b" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [] for 'cd /////private///////..///////private/../../../../../../../////..//././././/./var/../private/././././//////./././///tmp/////////////////.; pwd; export -p PWD; cd /////dev/////.//.///././////./../////dev/../dev/cul/..; pwd; export -p PWD'" {
	skip "error sort, sur la sortie d'erreur et n'est pas verifiable"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /////private///////..///////private/../../../../../../../////..//././././/./var/../private/././././//////./././///tmp/////////////////.; pwd; export -p PWD; cd /////dev/////.//.///././////./../////dev/../dev/cul/..; pwd; export -p PWD'
	expect=`bash -c 'cd /////private///////..///////private/../../../../../../../////..//././././/./var/../private/././././//////./././///tmp/////////////////.; pwd; export -p PWD; cd /////dev/////.//.///././////./../////dev/../dev/cul/..; pwd; export -p PWD'`
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "${output}" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [simple] for 'cd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->"
	[ "${lines[0]}" = "" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [simple] for 'cd&&pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd&&pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$HOME"
	[ "${lines[0]}" = "$HOME" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [simple] for 'cd && pwd && cd -'" {
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

@test "BUILTIN_CD: Testing [simple] for 'cd ////./////.////// && pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd ////./////.////// && pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/"
	[ "${lines[0]}" = "/" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [simple] for 'cd /this/doesnt/exists'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /this/doesnt/exists'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$cdnosuch: /this/doesnt/exists"
	[ "${lines[0]}" = "$cdnosuch: /this/doesnt/exists" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [simple] for 'touch notadir && cd notadir ; rm notadir'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'touch notadir && cd notadir ; rm notadir'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->cd: not a directory: notadir"
	[ "${lines[0]}" = "cd: not a directory: notadir" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [simple] for 'setenv HOME=/tmp && cd && pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv HOME=/tmp && cd && pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp"
	[ "${lines[0]}" = "/tmp" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [simple] for 'setenv HOME=/tmp/nosuch && cd; pwd'" {
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

@test "BUILTIN_CD: Testing [simple] for 'cd -L file_link;pwd;cd..;pwd'" {
		if [[ !(-e file_link) ]]; then
    		ln -s . file_link
    	fi
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd -L file_link;pwd;cd ..;pwd'
	expect=`cd -L file_link;pwd;cd ..;pwd`
	rm -rf file_link
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "$output" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [simple] for 'cd -P file_link;pwd;cd ..;pwd'" {
	if [[ !(-e file_link) ]]; then
		ln -s . file_link
	fi
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd -P file_link;pwd;cd ..;pwd'
	expect=`cd -P file_link;pwd;cd ..;pwd`
	rm -rf file_link
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "$output" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [simple] for 'cd ////////.//////.//////...//////// && pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd ////////.//////./////...//////// && pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$cdnosuch: ////////.//////./////...////////"
	[ "${lines[0]}" = "$cdnosuch: ////////.//////./////...////////" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}
######################################################################
######################################################################

################################################################################
#                               Testing LOCAL VAR                              #
################################################################################

@test "BUILTINS: Testing [Builtin Local Var] for 'unset'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unset'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->unset: not enough arguments"
	[ "${lines[0]}" = "unset: not enough arguments" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTINS: Testing [Builtin Local Var] for 'unset'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unset'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->unset: not enough arguments"
	[ "${lines[0]}" = "unset: not enough arguments" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

######################################################################
######################################################################

################################################################################
#                               Testing ECHO                                   #
################################################################################

@test "BUILTIN_ECHO: Testing [args_no_opt] for 'echo abc 123'" {
    expect=`bash -c 'echo abc 123'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc 123'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [args_no_opt] for 'echo | cat -e'" {
    expect=`bash -c 'echo | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [args_no_opt] for 'echo def 456 ghi 789 '' quote'" {
    expect=`bash -c 'echo def 456 ghi 789 '' quote'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo def 456 ghi 789 '' quote'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [args_no_opt] for 'echo hehe | cat -e'" {
    expect=`bash -c 'echo hehe | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo hehe | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [args_no_opt] for 'echo 1 2 3 4 5 6 7 8 9 0 | cat -e'" {
    expect=`bash -c 'echo 1 2 3 4 5 6 7 8 9 0 | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 1 2 3 4 5 6 7 8 9 0 | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [dashdash_no_opt] for 'echo abc -- def'" {
    expect=`bash -c 'echo abc -- def'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo abc -- def'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [dashdash_no_opt] for 'echo -- ghi'" {
    expect=`bash -c 'echo -- ghi'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -- ghi'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [dashdash_no_opt] for 'echo zzz ---'" {
    expect=`bash -c 'echo zzz ---'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo zzz ---'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [dashdash_no_opt] for 'echo -- -n abc'" {
    expect=`bash -c 'echo -- -n abc'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -- -n abc'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [empty_strings] for 'echo "a" "" "" "b" | cat -e'" {
    expect=`bash -c 'echo "a" "" "" "b" | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "a" "" "" "b" | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [escapes_sequences_NOLOAD] for 'echo '\a\b\c\f\n\r\t\v''" {
    expect=`bash -c 'echo '\a\b\c\f\n\r\t\v''`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo '\a\b\c\f\n\r\t\v''
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [escapes_sequences_NOLOAD] for 'echo \0777 \0123 \0 '\01' "\02"'" {
    expect=`bash -c 'echo \0777 \0123 \0 '\01' "\02"'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo \0777 \0123 \0 '\01' "\02"'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [no_arg_no_opt] for 'echo | cat -e'" {
    expect=`bash -c 'echo | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [no_arg_opt_n] for 'echo -n | cat -e'" {
    expect=`bash -c 'echo -n | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -n | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [opt_invalid] for 'echo -a abc | cat -e'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -a abc | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->echo: invalid option -- 'a'"
    echo
    [ "${lines[0]}" = "echo: invalid option -- 'a'" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [opt_invalid] for 'echo -x abc | cat -e'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -x abc | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->echo: invalid option -- 'x'"
    echo
    [ "${lines[0]}" = "echo: invalid option -- 'x'" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [opt_invalid] for 'echo -- -abc abc | cat -e'" {
    expect=`bash -c 'echo -- -abc abc | cat -e'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -- -abc abc | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [tabs_newline] for 'echo 'a b   c			d\t\t\te\n\n\n\n''" {
    expect=`bash -c 'echo 'a b   c			d\t\t\te\n\n\n\n''`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo 'a b   c			d\t\t\te\n\n\n\n''
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [simple] for 'echo -e \"toto\ntata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -e "toto\ntata"'
  echo
	display_line_output
	echo
  ret=$( bash -c 'echo -e "toto\ntata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
  [ "$status" -eq 0 ]
check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [simple] for 'echo -e \"toto\\atata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "toto\\atata"'
  echo
	display_line_output
	echo
  ret=$( bash -c 'echo -e "toto\\atata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [simple] for 'echo -e toto\\btata'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -e toto\\btata'
  echo
	display_line_output
	echo
  ret=$( bash -c 'echo -e toto\\btata' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [simple] for 'echo -e \"toto\\atata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "toto\\atata"'
  echo
	display_line_output
	echo
  ret=$( bash -c 'echo -e "toto\\atata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [simple] for 'echo -E \"toto\ntata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -E "toto\ntata"'
  echo
	display_line_output
	echo
  ret=$( bash -c 'echo -E "toto\ntata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
  [ "$status" -eq 0 ]
check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [simple] for 'echo -E \"toto\\atata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "toto\\atata"'
  echo
	display_line_output
	echo
  ret=$( bash -c 'echo -E "toto\\atata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [simple] for 'echo -E toto\\btata'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -E toto\\btata'
  echo
	display_line_output
	echo
  ret=$( bash -c 'echo -E toto\\btata' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}

@test "BUILTIN_ECHO: Testing [simple] for 'echo -E \"toto\\atata\"'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo -E "toto\\atata"'
  echo
	display_line_output
	echo
  ret=$( bash -c 'echo -E "toto\\atata"' )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${output}" = "$ret" ]
check_leaks_function exec
}
######################################################################
######################################################################

################################################################################
#                               Testing ENV                                    #
################################################################################

@test "BUILTIN_ENV: Testing [cmd_cd] for 'env cd folder_not_exist'" {
    expect=`bash -c 'env ls'`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env ls'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [double_dash] for 'env -- myvar_aa=bb env | grep myvar_aa='" {
    expect=`env -- myvar_aa=bb env | grep myvar_aa=`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env -- myvar_aa=bb env | grep myvar_aa='
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [echo] for 'echo \"start\"; env myvar1=11 myvar2=22 echo aaa bbb ccc; env | grep myvar; echo \"end\"'" {
    expect=`echo "start"; env myvar1=11 myvar2=22 echo aaa bbb ccc; env | grep myvar; echo "end"`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'echo "start"; env myvar1=11 myvar2=22 echo aaa bbb ccc; env | grep myvar; echo "end"'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${output}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [env_env_env_env] for 'env myvar=aa env myvar=ab env | grep myvar; env myvar2=bb env myvar3=cc env | grep myvar | sort; env | grep myvar | sort'" {
    expect=`env myvar=aa env myvar=ab env | grep myvar; env myvar2=bb env myvar3=cc env | grep myvar | sort; env | grep myvar | sort`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env myvar=aa env myvar=ab env | grep myvar; env myvar2=bb env myvar3=cc env | grep myvar | sort; env | grep myvar | sort'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "myvar=ab" ]
    [ "${lines[1]}" = "myvar2=bb" ]
    [ "${lines[2]}" = "myvar3=cc" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [env_spec] for 'setenv hello=pouet; setenv ahah=hehe; env | grep hello | cat -e; env | grep ahah | cat -e; unsetenv hello; env | grep hello | cat -e; env temporary=hello | grep temporary | cat -e'" {
    expect=`setenv hello=pouet; setenv ahah=hehe; env | grep hello | cat -e; env | grep ahah | cat -e; unsetenv hello; env | grep hello | cat -e; env temporary=hello | grep temporary | cat -e`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv hello=pouet; setenv ahah=hehe; env | grep hello | cat -e; env | grep ahah | cat -e; unsetenv hello; env | grep hello | cat -e; env temporary=hello | grep temporary | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "hello=pouet$" ]
    [ "${lines[1]}" = "ahah=hehe$" ]
    [ "${lines[2]}" = "temporary=hello$" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [exit_code_error] for 'env echo a | grep b'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env echo a | grep b'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->"
    echo
    [ "${lines[0]}" = "" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [exit_code_invalid_var_name] for 'env -i ='" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env -i ='
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->="
    echo
    [ "${output}" = "=" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [exit_code_ok] for 'env echo a | grep a'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env echo a | grep a'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->a"
    echo
    [ "${lines[0]}" = "a" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [invalid_var_name] for 'env 42SHTESTS1=TOKEN1 42SHTESTS2=TOKEN2 42SHTESTS3=TOKEN3 ls; env =1 echo abc; env =; env 0=0; env echo abc'" {
    skip "_=/usr/bin/env"
    expect=`env 42SHTESTS1=TOKEN1 42SHTESTS2=TOKEN2 42SHTESTS3=TOKEN3 ls; env =1 echo abc; env =; env 0=0; env echo abc`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env 42SHTESTS1=TOKEN1 42SHTESTS2=TOKEN2 42SHTESTS3=TOKEN3 ls; env =1 echo abc; env =; env 0=0; env echo abc'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [modify_var] for 'setenv env_foo_1=bar1; echo ===== 1; env env_foo_2=bar2 env | grep env_foo_; echo ===== 2; env -i env_foo_2=bar3 env | grep env_foo_'" {
    expect=`setenv env_foo_1=bar1; echo ===== 1; env env_foo_2=bar2 env | grep env_foo_; echo ===== 2; env -i env_foo_2=bar3 env | grep env_foo_`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv env_foo_1=bar1; echo ===== 1; env env_foo_2=bar2 env | grep env_foo_; echo ===== 2; env -i env_foo_2=bar3 env | grep env_foo_'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "===== 1" ]
    [ "${lines[1]}" = "env_foo_1=bar1" ]
    [ "${lines[2]}" = "env_foo_2=bar2" ]
    [ "${lines[3]}" = "===== 2" ]
    [ "${lines[4]}" = "env_foo_2=bar3" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [opt_i_assign] for 'env -i aa=bb cc=dd; env -i aaa=bbb'" {
    expect=`env -i aa=bb cc=dd; env -i aaa=bbb`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env -i aa=bb cc=dd; env -i aaa=bbb'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "aa=bb" ]
    [ "${lines[1]}" = "cc=dd" ]
    [ "${lines[2]}" = "aaa=bbb" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [opt_i_path] for 'env ls; env PATH= ls; env PATH=\'\' ls; env PATH=/bin ls; env route; env PATH= route; env PATH=\'\' route; env PATH=/sbin route; env -i ls; env -i PATH= ls; env -i PATH=\'\' ls; env -i PATH=/bin ls; env -i route; env -i PATH= route; env -i PATH=\'\' route ; env -i PATH=/sbin route'" {
    skip ""
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env ls; env PATH= ls; env PATH="" ls; env PATH=/bin ls; env route; env PATH= route; env PATH="" route; env PATH=/sbin route; env -i ls; env -i PATH= ls; env -i PATH="" ls; env -i PATH=/bin ls; env -i route; env -i PATH= route; env -i PATH="" route ; env -i PATH=/sbin route'
    expect=`sh -c 'env ls; env PATH= ls; env PATH="" ls; env PATH=/bin ls; env route; env PATH= route; env PATH="" route; env PATH=/sbin route; env -i ls; env -i PATH= ls; env -i PATH="" ls; env -i PATH=/bin ls; env -i route; env -i PATH= route; env -i PATH="" route ; env -i PATH=/sbin route'`
     echo "ERROR:"
     display_line_output
     echo "$name_exec EXPECTED ->$expect"
     echo
     [ "${lines[0]}" = "$expect" ]
     [ "$status" -eq 0 ]
     check_leaks_function exec
}


@test "BUILTIN_ENV: Testing [opt_i_simple] for 'setenv foo=bar; echo ===== 1; env env | grep foo; echo ===== 2; env -i env | grep foo; env -i echo bla; echo bli'" {
    expect=`setenv foo=bar; echo ===== 1; env env | grep foo; echo ===== 2; env -i env | grep foo; env -i echo bla; echo bli`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv foo=bar; echo ===== 1; env env | grep foo; echo ===== 2; env -i env | grep foo; env -i echo bla; echo bli'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "===== 1" ]
    [ "${lines[1]}" = "foo=bar" ]
    [ "${lines[2]}" = "===== 2" ]
    [ "${lines[3]}" = "bla" ]
    [ "${lines[4]}" = "bli" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [subshell] for '(env -i A=1 B=2 C=3| cat -e) | wc'" {
    skip "subhell"
    expect=`(env -i A=1 B=2 C=3| cat -e) | wc`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c '(env -i A=1 B=2 C=3| cat -e) | wc'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [with_builtin_spec] for 'env echo abc'" {
    expect=`env echo abc`
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'env echo abc'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->$expect"
    echo
    [ "${lines[0]}" = "$expect" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_ENV: Testing [with_variable_assign_spec] for 'setenv env_test_var=456; env env_test_var=123 bash -c \'env | grep env_test_var\''" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv env_test_var=456; env env_test_var=123 bash -c "env | grep env_test_var"'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->env_test_var=123"
    echo
    [ "${lines[0]}" = "env_test_var=123" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
######################################################################
######################################################################

################################################################################
#                               Testing HISTORY                                #
################################################################################

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

######################################################################
######################################################################

################################################################################
#                               Testing SETENV                                 #
################################################################################

@test "BUILTIN_SETENV: Testing [arg_with_no_equal_no_value] for 'setenv emptyvar; env | grep emptyvar'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv emptyvar; env | grep emptyvar'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->setenv [name]=[value]"
    echo "              ->Sets the environment variable name with value value"
    echo "              ->If name already has a value, then it is replaced with the new one"
    echo
    [ "${lines[0]}" = "setenv [name]=[value]" ]
    [ "${lines[1]}" = "Sets the environment variable name with value value" ]
    [ "${lines[2]}" = "If name already has a value, then it is replaced with the new one" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_SETENV: Testing [arg_with_no_value] for 'setenv emptyvar=; env | grep emptyvar'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv emptyvar=; env | grep emptyvar'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->emptyvar="
    echo
    [ "${lines[0]}" = "emptyvar=" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_SETENV: Testing [setenv_simple_spec] for 'setenv setenv_var=bbb; setenv setenv_var=ccc; env | grep setenv_var='" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv setenv_var=bbb; setenv setenv_var=ccc; env | grep setenv_var='
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->setenv_var=ccc"
    echo
    [ "${lines[0]}" = "setenv_var=ccc" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_SETENV: Testing [space_in_value] for 'setenv var_123=\"1    2    3\"; env | grep var_123 | cat -e'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv var_123="1    2    3"; env | grep var_123 | cat -e'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->var_123=1    2    3$"
    echo
    [ "${lines[0]}" = "var_123=1    2    3$" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
######################################################################
######################################################################

################################################################################
#                               Testing UNSETENV                               #
################################################################################

@test "BUILTIN_UNSETENV: Testing [arg_with_no_equal_no_value] for 'unsetenv -x; unsetenv % ? -'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv -x; unsetenv % ? -'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->"
    echo
    [ "${lines[0]}" = "" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_UNSETENV: Testing [multiple] for 'setenv test_var1=111; setenv test_var2=222; setenv test_var3=333; env | grep test_var | sort; unsetenv test_var1 test_var2 test_var3; env | grep test_var | sort'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv test_var1=111; setenv test_var2=222; setenv test_var3=333; env | grep test_var | sort; unsetenv test_var1 test_var2 test_var3; env | grep test_var | sort'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->test_var1=111"
    echo "                test_var2=222"
    echo "                test_var3=333"
    echo
    [ "${lines[0]}" = "test_var1=111" ]
    [ "${lines[1]}" = "test_var2=222" ]
    [ "${lines[2]}" = "test_var3=333" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_UNSETENV: Testing [no_arg_no_err_msg] for 'unsetenv'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'unsetenv'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->unsetenv [name]"
    echo "                Deletes the environment variable name from local env"
    echo "                If name doesnt exists, nothing happens"
    echo "                Optional arguments shall be passed to utility."
    echo
    [ "${lines[0]}" = "unsetenv [name]" ]
    [ "${lines[1]}" = "Deletes the environment variable name from local env" ]
    [ "${lines[2]}" = "If name doesnt exists, nothing happens" ]
    [ "${lines[3]}" = "Optional arguments shall be passed to utility." ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}

@test "BUILTIN_UNSETENV: Testing [printenv_unset_variable] for 'setenv globalvar=456; env | grep globalvar=; unsetenv globalvar; env | grep globalvar=; setenv VAREMPTY=; printenv VAREMPTY; unsetenv VAREMPTY; printenv VAREMPTY'" {
    run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv globalvar=456; env | grep globalvar=; unsetenv globalvar; env | grep globalvar=; setenv VAREMPTY=; printenv VAREMPTY; unsetenv VAREMPTY; printenv VAREMPTY'
    echo "ERROR:"
    display_line_output
    echo "$name_exec EXPECTED ->globalvar=456"
    echo "                "
    echo
    [ "${lines[0]}" = "globalvar=456" ]
    [ "${lines[1]}" = "" ]
    [ "$status" -eq 0 ]
    check_leaks_function exec
}
######################################################################
######################################################################