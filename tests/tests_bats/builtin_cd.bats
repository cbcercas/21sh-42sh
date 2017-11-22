#! / Usr / bin / env bats

load test_helper

####star###

@test "BUILTIN_CD: Testing [] for ''" {
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
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/"
    echo "                      /tmp"
    echo "                      .$"
    echo "                      ..$"
    echo "                      /private/tmp/test1_cd"
	[ "${lines[0]}" = "/" ]
	[ "${lines[1]}" = "/tmp" ]
	[ "${lines[2]}" = ".$" ]
	[ "${lines[3]}" = "..$" ]
	[ "${lines[4]}" = "/private/tmp/test1_cd" ]
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
    skip "I dont know the normal behaviour"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'setenv OLDPWD=toto; cd -'
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

@test "BUILTIN_CD: Testing [cd_err_opt_spec] for 'cd -h'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd -h'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->cd: [-L/-P] [path], use "help cd"
	[ "${lines[0]}" = "cd: [-L/-P] [path], use "help cd" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

