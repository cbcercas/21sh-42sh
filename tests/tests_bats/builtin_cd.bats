#! / Usr / bin / env bats

load test_helper

####start###

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

@test "BUILTIN_CD: Testing [cd_error_pwd] for 'cd . ; /bin/pwd ;'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd . ; /bin/pwd ;'
	expect="bash -c 'cd . ; /bin/pwd ;'"
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
	[ "${lines[0]}" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_error_pwd] for 'cd /tmp; rm -rf toto; mkdir toto; unsetenv PWD; cd toto; pwd; cd -; setenv PWD=tata; cd toto; pwd; cd -; rm -rf toto; 2>&- cd tutu; cd /tmp; cd -; pwd; cd /tmp/toto; rm -rf /tmp/toto; cd -P .'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp; rm -rf toto; mkdir toto; unsetenv PWD; cd toto; pwd; cd -; setenv PWD=tata; cd toto; pwd; cd -; rm -rf toto; 2>&- cd tutu; cd /tmp; cd -; pwd; cd /tmp/toto; rm -rf /tmp/toto; cd -P .'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/private/tmp/toto"
	echo "                      /private/tmp"
    echo "                      /private/tmp/toto"
    echo "                      /private/tmp"
    echo "                      /private/tmp"
    echo "                      /private/tmp"
    echo "                      cd: no such file or directory: /tmp/toto"
	[ "${lines[0]}" = "/private/tmp/toto" ]
	[ "${lines[1]}" = "/private/tmp" ]
	[ "${lines[2]}" = "/private/tmp/toto" ]
	[ "${lines[3]}" = "/private/tmp" ]
	[ "${lines[4]}" = "/private/tmp" ]
	[ "${lines[5]}" = "/private/tmp" ]
	[ "${lines[5]}" = "cd: no such file or directory: /tmp/toto" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_fat] for 'TO FAT'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'mkdir /tmp/test01; mkdir /tmp/test02; ln -s /tmp /tmp/tmp_sym; ln -s /tmp /tmp/test01/tmp_sym; ln -s /tmp/test01 /tmp/test02/test01_sym; ln -s /tmp/test01 /tmp/test01/test01_sym; ln -s /tmp/test01 /tmp/test01_sym; cd /tmp; pwd; cd tmp_sym; pwd; cd test01; pwd; cd tmp_sym; pwd; cd test01_sym; pwd; cd test01_sym; pwd; cd tmp_sym; pwd; cd test02; pwd; cd test01_sym; pwd; cd tmp_sym; pwd; cd ..; pwd; cd ..; pwd; cd ..; pwd; cd ..; pwd; cd ..; pwd; cd ..; pwd; cd ..; pwd; cd ..; pwd; cd test01/tmp_sym/test01_sym/../test02/test01_sym/../../../tmp_sym; pwd; cd ../../../; pwd; cd /tmp/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02/test01_sym/tmp_sym; pwd; cd -P test01; pwd; cd -P /tmp/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02/test01_sym/tmp_sym; pwd; cd ../../../../../../../../../; pwd; cd ..; cd ..; cd ..; cd ..; pwd; cd /tmp/../../../../tmp/test01/./././test01_sym/./././test01_sym/tmp_sym/test02/test01_sym/test01_sym/.././././.././././test01_sym/.././../../tmp_sym/test01/../././.././tmp_sym/../tmp_sym/../tmp_sym/../tmp_sym/tmp_sym/tmp_sym/../../../.././././.; pwd; cd .//////////////..////////../././///./////././../////../../../../tmp/////.////.////////..////tmp///////////////test01/.///////////..////////////..///////////../////////////../////////././///tmp/.///////////; pwd; cd /////////////; pwd; rm -rf /tmp/tmp_sym; rm -rf /tmp/test01; rm -rf /tmp/test02; rm -rf /tmp/test01_sym'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->tmp"
    echo "                      /tmp/tmp_sym"
    echo "                      /tmp/tmp_sym/test01"
    echo "                      /tmp/tmp_sym/test01/tmp_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02/test01_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02/test01_sym/tmp_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02/test01_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym/test01_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym"
    echo "                      /tmp/tmp_sym/test01"
    echo "                      /tmp/tmp_sym"
    echo "                      /tmp/tmp_sym/test01/tmp_sym"
    echo "                      /tmp"
    echo "                      /tmp/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02/test01_sym/tmp_sym"
    echo "                      /private/tmp/test01"
    echo "                      /private/tmp"
    echo "                      /"
    echo "                      /"
    echo "                      /tmp/test01/test01_sym"
    echo "                      /tmp"
    echo "                      /"
	[ "${lines[0]}" = "/tmp" ]
	[ "${lines[1]}" = "/tmp/tmp_sym" ]
	[ "${lines[2]}" = "/tmp/tmp_sym/test01" ]
	[ "${lines[3]}" = "/tmp/tmp_sym/test01/tmp_sym" ]
	[ "${lines[4]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym" ]
	[ "${lines[5]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym" ]
	[ "${lines[6]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym" ]
	[ "${lines[7]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02" ]
	[ "${lines[8]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02/test01_sym" ]
	[ "${lines[9]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02/test01_sym/tmp_sym" ]
	[ "${lines[10]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02/test01_sym" ]
	[ "${lines[11]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02" ]
	[ "${lines[12]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym/tmp_sym" ]
	[ "${lines[13]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym/test01_sym" ]
	[ "${lines[14]}" = "/tmp/tmp_sym/test01/tmp_sym/test01_sym" ]
	[ "${lines[15]}" = "/tmp/tmp_sym/test01/tmp_sym" ]
	[ "${lines[16]}" = "/tmp/tmp_sym/test01" ]
	[ "${lines[17]}" = "/tmp/tmp_sym" ]
	[ "${lines[18]}" = "/tmp/tmp_sym/test01/tmp_sym" ]
	[ "${lines[19]}" = "/tmp" ]
	[ "${lines[20]}" = "/tmp/test01/tmp_sym/test01_sym/test01_sym/tmp_sym/test02/test01_sym/tmp_sym" ]
	[ "${lines[21]}" = "/private/tmp/test01" ]
	[ "${lines[22]}" = "/private/tmp" ]
	[ "${lines[23]}" = "/" ]
	[ "${lines[24]}" = "/" ]
	[ "${lines[25]}" = "/tmp/test01/test01_sym" ]
	[ "${lines[26]}" = "/tmp" ]
	[ "${lines[27]}" = "/" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}


@test "BUILTIN_CD: Testing [cd_minus_spec] for 'cd /tmp; cd /; cd -; cd -P -; cd -L -; cd -P -; cd -L -; cd tutu 2>&-; cd -'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp; cd /; cd -; cd -P -; cd -L -; cd -P -; cd -L -; cd tutu 2>&-; cd -'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp"
    echo "                      /"
    echo "                      /tmp"
    echo "                      /"
    echo "                      /tmp"
    echo "                      /"
	[ "${lines[0]}" = "/tmp" ]
	[ "${lines[1]}" = "/" ]
	[ "${lines[2]}" = "/tmp" ]
	[ "${lines[3]}" = "/" ]
	[ "${lines[4]}" = "/tmp" ]
	[ "${lines[5]}" = "/" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_multiarg_spec] for 'cd /tmp /bin && pwd; cd /bin /tmp /usr && pwd'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp /bin && pwd; cd /bin /tmp /usr && pwd'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp"
    echo "                      /bin"
	[ "${lines[0]}" = "/tmp" ]
	[ "${lines[1]}" = "/bin" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_oldpwd] for 'cd /tmp; pwd; cd /; cd -; cd /tmp; pwd; cd -P -; cd -P -; cd -P /tmp; pwd; cd -; pwd; rm -rf /tmp/toto; mkdir /tmp/toto; cd /tmp; cd /tmp/toto; cd ..; pwd; cd -; pwd; cd /tmp; rm -rf /tmp/toto;'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp; pwd; cd /; cd -; cd /tmp; pwd; cd -P -; cd -P -; cd -P /tmp; pwd; cd -; pwd; rm -rf /tmp/toto; mkdir /tmp/toto; cd /tmp; cd /tmp/toto; cd ..; pwd; cd -; pwd; cd /tmp; rm -rf /tmp/toto;'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp"
    echo "                      /tmp"
    echo "                      /tmp"
    echo "                      /private/tmp"
    echo "                      /private/tmp"
    echo "                      /private/tmp"
    echo "                      /private/tmp"
    echo "                      /private/tmp"
    echo "                      /tmp"
    echo "                      /tmp/toto"
    echo "                      /tmp/toto"
	[ "${lines[0]}" = "" ]
	[ "${lines[1]}" = "" ]
	[ "${lines[2]}" = "" ]
	[ "${lines[3]}" = "" ]
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
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/test_cd_builtin/mydir_sym1"
    echo "                      /private/tmp/test_cd_builtin/mydir_sym1"
    echo "                      /tmp/test_cd_builtin/mydir_sym1"
    echo "                      /tmp/test_cd_builtin/mydir_sym2"
    echo "                      /private/tmp/test_cd_builtin/mydir_sym2"
    echo "                      /tmp/test_cd_builtin/mydir_sym2"
	[ "${lines[0]}" = "/tmp/test_cd_builtin/mydir_sym1" ]
	[ "${lines[1]}" = "/private/tmp/test_cd_builtin/mydir_sym1" ]
	[ "${lines[2]}" = "/tmp/test_cd_builtin/mydir_sym1" ]
	[ "${lines[3]}" = "/tmp/test_cd_builtin/mydir_sym2" ]
	[ "${lines[4]}" = "/private/tmp/test_cd_builtin/mydir_sym2" ]
	[ "${lines[5]}" = "/tmp/test_cd_builtin/mydir_sym2" ]
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

@test "BUILTIN_CD: Testing [cd_wrong_dotdot] for 'cd /tmp; cd toto/..'" {
    skip "Template"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /tmp; cd toto/..'
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->cd: no such file or directory: toto/.."
	[ "${lines[0]}" = "cd: no such file or directory: toto/.." ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [cd_with_spaces] for 'mkdir -p '/tmp/a b'; cd '/tmp/a b'; pwd; cd /; rm -rf '/tmp/a b''" {
    skip "Template"
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'mkdir -p '/tmp/a b'; cd '/tmp/a b'; pwd; cd /; rm -rf '/tmp/a b''
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->/tmp/a b"
	[ "${lines[0]}" = "/tmp/a b" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}

@test "BUILTIN_CD: Testing [] for 'cd /////private///////..///////private/../../../../../../../////..//././././/./var/../private/././././//////./././///tmp/////////////////.; pwd; env PWD; cd /////dev/////.//.///././////./../////dev/../dev/cul/..; pwd; env PWD'" {
	run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -c 'cd /////private///////..///////private/../../../../../../../////..//././././/./var/../private/././././//////./././///tmp/////////////////.; pwd; env PWD; cd /////dev/////.//.///././////./../////dev/../dev/cul/..; pwd; env PWD'
	expect="$PWD"
	echo "ERROR:"
	display_line_output
	echo "$name_exec EXPECTED ->$expect"
    echo "                      $expect"
    echo "                      cd: no such file or directory: /////dev/////.//.///././////./../////dev/../dev/cul/.."
    echo "                      $expect"
    echo "                      $expect"
	[ "${lines[0]}" = "$expect" ]
	[ "${lines[1]}" = "$expect" ]
	[ "${lines[2]}" = "cd: no such file or directory: /////dev/////.//.///././////./../////dev/../dev/cul/.." ]
	[ "${lines[3]}" = "$expect" ]
	[ "${lines[4]}" = "$expect" ]
	[ "$status" -eq 0 ]
	check_leaks_function exec
}