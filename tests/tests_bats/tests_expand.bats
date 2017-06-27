#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            ENV  NULL                                #
#######################################################################

@test "EXPAND: Testing [env null] with 'NULL'" {
  run $val_cmd env -i ${BATS_TEST_DIRNAME}/../../$name_exec -t expand ""
  echo
  echo "ERROR: \"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->"
	echo
  [ "${lines[0]}" = "" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [env null] with 'nothing to change'" {
  run $val_cmd env -i ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto tout nue |;&&"
  echo
  echo "ERROR: \"toto tout nue |;&&\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->toto tout nue |;&&"
	echo
  [ "${lines[0]}" = "toto tout nue |;&&" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

#######################################################################
#                            SIMPLE REPLACE                           #
#######################################################################

@test "EXPAND: Testing [simple replace] with 'toto'" {
  run $val_cmd env -i VAR1=toto ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\$VAR1"
  echo
  echo "ERROR: \"\$VAR1\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->toto"
	echo
  [ "${lines[0]}" = "toto" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [simple replace] with 'toto 2'" {
  run $val_cmd env -i VAR1=toto ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "coucou \$VAR1, comment tu vas \$VAR1"
  echo
  echo "ERROR: \"coucou \$VAR1, comment tu vas \$VAR1\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->coucou toto, comment tu vas toto"
	echo
  [ "${lines[0]}" = "coucou toto, comment tu vas toto" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [simple replace] with 'toto 3'" {
  run $val_cmd env -i VAR1=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "coucou \$VAR1, comment tu vas \$VAR2"
  echo
  echo "ERROR: \"coucou \$VAR1, comment tu vas \$VAR2\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->coucou toto, comment tu vas tata"
	echo
  [ "${lines[0]}" = "coucou toto, comment tu vas tata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [simple replace] 100 vars" {
  #skip "because is too long"
  i=0
  vars=""
  rets=""
  ent=""
  while [ $i != 100 ]
  do
    vars+="VAR$i=$i "
    rets+="$i=$i "
    ent+="$"VAR$i"=$i "
    i=`expr $i + 1`
  done
  run $val_cmd env -i $vars ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "$vars"
  echo
  echo "ERROR: \"VAR0=0…\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->0=0 1=1 …"
  [ "${output}" = "${rets}" ]
check_leaks_function parser
}

#######################################################################
#######################################################################

run $val_cmd env -i VAR1=toto VAR2=tata sh -c "echo \"\""
#######################################################################
#                            $ ERROR                                  #
#######################################################################

@test "EXPAND: Testing [$ error] with '$ $ $ $ $ $'" {
  run $val_cmd env -i VAR1=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "$ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $"
  echo
  echo "ERROR: \"$ $ $ …\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->$ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $"
	echo
  [ "${lines[0]}" = "$ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [$ error] with '\$var12'" {
  run $val_cmd env -i VAR1=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\$VAR12 \$VAR21"
  echo
echo "ERROR: \"\$VAR12 \$VAR21\""
echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->"
  echo
  [ "${lines[0]}" = "" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [$ error] with '\$var1\$var2'" {
  run $val_cmd env -i VAR1=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\$VAR1\$VAR2"
  echo
  echo "ERROR: \"\$VAR1\$VAR2\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tototata"
  echo
  [ "${lines[0]}" = "tototata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

#######################################################################
#######################################################################

#######################################################################
#                            HIST                                     #
#######################################################################

@test "EXPAND: Testing [hist] with '!'" {
  echo -e "ls\ntoto" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "!1"
  echo
  echo "ERROR: \"!1\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->ls"
  echo
  [ "${lines[0]}" = "ls" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hist] with '! blow'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "!1!2"
  echo
  echo "ERROR: \"!1!2\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->blowjob"
	echo
  [ "${lines[0]}" = "blowjob" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hist] with '!!'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "!!"
  echo
  echo "ERROR: \"!!\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->job"
	echo
  [ "${lines[0]}" = "job" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hist] with '!j'" {
  echo -e "jab\nblow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "!j"
  echo
  echo "ERROR: \"!j\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->job"
	echo
  [ "${lines[0]}" = "job" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hist] with '!ja'" {
  echo -e "jab\nblow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "!ja"
  echo
  echo "ERROR: \"!ja\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->jab"
	echo
  [ "${lines[0]}" = "job" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hist] with 'he!llo !1 i cs !2 ls'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "he!llo !1 i cs !2 ls"
  echo
  echo "ERROR: \"he!llo !1 i cs !2 ls\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->hello blow i cs job ls"
	echo
  [ "${lines[0]}" = "hello blow i cs job ls" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}
#######################################################################
#######################################################################

#######################################################################
#                            HIST  ERROR                              #
#######################################################################

@test "EXPAND: Testing [hist error] with '! '" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "hello !"
  echo
  echo "ERROR: \"hello !\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->hello !"
	echo
  [ "${lines[0]}" = "hello !" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hist error] with '!!!!!!! '" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "hello !!!!!!!"
  echo
  echo "ERROR: \"hello !!!!!!!\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->hello jobjobjob!"
	echo
  [ "${lines[0]}" = "hello jobjobjob!" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hist error] with '!'" {
  echo -e "blo!2w\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "hello !1"
  echo
  echo "ERROR: \"hello !1\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->hello blo!2w"
	echo
  [ "${lines[0]}" = "hello blo!2w" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hist error] with '!3000'" {
  echo -e "blo!2w\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "!3000"
  echo
  echo "ERROR: \"!3000\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->21sh: !30000: event not found"
	echo
  [ "${lines[0]}" = "21sh: !30000: event not found" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hist error] with 'tata !hello toto'" {
  echo -e "blo!2w\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "tata !hello toto"
  echo
  echo "ERROR: \"tata !hello toto\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->21sh: !hello: event not found"
	echo
  [ "${lines[0]}" = "21sh: !hello: event not found" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}
#######################################################################
#######################################################################

#######################################################################
#                              DDQUOTE                                #
#######################################################################

@test "EXPAND: Testing [dbquote] with 'simple'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"tata\""
  echo
  echo "ERROR: \"tata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tata"
	echo
  [ "${lines[0]}" = "tata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [dbquote] with 'double 1'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"tata\" \"toto\""
  echo
  echo "ERROR: \"\"tata\" \"toto\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tata toto"
	echo
  [ "${lines[0]}" = "tata toto" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [dbquote] with 'double 2'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"tata\"\"toto\""
  echo
  echo "ERROR: \"\"tata\"\"toto\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tatatoto"
	echo
  [ "${lines[0]}" = "tatatoto" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [dbquote] with 'double 3'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"tata\"toto"
  echo
  echo "ERROR: \"\"tata\"toto\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tatatoto"
	echo
  [ "${lines[0]}" = "tatatoto" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [dbquote] with 'double 4'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"\$VAR2\"toto"
  echo
  echo "ERROR: \"\"\$VAR2\"toto\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tatatoto"
	echo
  [ "${lines[0]}" = "tatatoto" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [dbquote] with 'double \"\"a\"\"'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"\"\"a\"\"\""
  echo
  echo "ERROR: \"\"\"\"a\"\"\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->a"
	echo
  [ "${lines[0]}" = "a" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [dbquote] with 'double \"a\"\"a\"\"\" \"au\"'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"a\"\"a\"\"\""
  echo
  echo "ERROR: \"\"a\"\"a\"\"\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->aa au"
	echo
  [ "${lines[0]}" = "aa au" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

#######################################################################
#######################################################################

#######################################################################
#                              QUOTE                                #
#######################################################################


@test "EXPAND: Testing [quote] with 'simple'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'tata'"
  echo
  echo "ERROR: \"'tata'\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tata"
	echo
  [ "${lines[0]}" = "tata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [quote] with 'double 1'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'tata' 'toto'"
  echo
  echo "ERROR: \"'tata' 'toto'\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tata toto"
	echo
  [ "${lines[0]}" = "tata toto" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [quote] with 'double 2'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'tata''toto'"
  echo
  echo "ERROR: \"'tata''toto'\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tatatoto"
	echo
  [ "${lines[0]}" = "tatatoto" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [quote] with 'double 3'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'tata'toto"
  echo
  echo "ERROR: \"'tata'toto\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tatatoto"
	echo
  [ "${lines[0]}" = "tatatoto" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [quote] with 'double 4'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'\$VAR2'toto"
  echo
  echo "ERROR: \"'\$VAR2'toto\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->\$VAR2toto"
	echo
  [ "${lines[0]}" = "\$VAR2toto" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [quote] with 'double 4'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'\$VAR2'toto'!2'"
  echo
  echo "ERROR: \"'\$VAR2'toto'!2'\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->\$VAR2toto!2"
	echo
  [ "${lines[0]}" = "\$VAR2toto!2" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [quote] with 'double 5'" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'\$VAR2'toto'!2'"
  echo
echo "ERROR: \"'\$VAR2'toto'!2'\""
echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->\$VAR2toto!2"
	echo
  [ "${lines[0]}" = "\$VAR2toto!2" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [quote] with 'double ''a'''" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'''a'''"
  echo
  echo "ERROR: \"'''a'''\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->a"
	echo
  [ "${lines[0]}" = "a" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [quote] with 'double 'a''a''' 'au''" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'a''a'''"
  echo
  echo "ERROR: \"'a''a'''\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->aa au"
	echo
  [ "${lines[0]}" = "aa au" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}
#######################################################################
#######################################################################

######################################################################
#                            MIX                                     #
######################################################################

@test "EXPAND: Testing [mix] 1" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'\$VAR2'toto "\$VAR1" !2"
  echo
  echo "ERROR: \"'\$VAR2'toto "\$VAR1" !2\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->\$VAR2toto blow job"
	echo
  [ "${lines[0]}" = "\$VAR2toto blow job" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [mix] 2" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'!10'\"\$VAR1\"'''a'''\"b\"\$VAR1"
  echo
  echo "ERROR: \"'!10'\"\$VAR1\"'''a'''\"b\"\$VAR1\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->!10blowabblow"
	echo
  [ "${lines[0]}" = "!10blowabblow" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [mix] 3" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"''\" '\"\"'"
  echo
echo "ERROR: \"\"''\" '\"\"'\""
echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->'' \"\""
	echo
  [ "${lines[0]}" = "'' \"\"" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [mix] 4" {
  echo -e "blow\njob" > /tmp/.21sh_history
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'\"\$VAR\"' \"'\$VAR'\""
  echo
  echo "ERROR: \"'\"\$VAR\"' \"'\$VAR'\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->\"\$VAR\" 'toto'"
	echo
  [ "${lines[0]}" = "\"\$VAR\" 'toto'" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

#######################################################################
#######################################################################

@test "EXPAND: Testing [hard] 1" {
  echo -e "blow\njob\n!2\n!3\n!!" > /tmp/.21sh_history
  run $val_cmd env -i VAR=\$VAR2 VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'!2'!4\$VAR"
  echo
  echo "ERROR: \"'!2'!4\$VAR\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->!2!3\$VAR2"
	echo
  [ "${lines[0]}" = "!2!3" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hard] 2" {
  echo -e "blow\njob\n!2\n!3\n!!" > /tmp/.21sh_history
  run $val_cmd env -i VAR=\$VAR2 VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\'\$VAR2\'\\\"'\$VAR'\\\""
  echo
  echo "ERROR: \"\'\$VAR2'\\\"'\$VAR'\\\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->'tata'\"\$VAR\""
	echo
  [ "${lines[0]}" = "'tata'\"\$VAR\"" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hard] 3" {
  echo -e "blow\njob\n!2\n!3\n!!" > /tmp/.21sh_history
  run $val_cmd env -i VAR=\$VAR2 VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"\'\$VAR2\'\"\\\"'\$VAR'\\\""
  echo
  echo "ERROR: \"\"\'\$VAR2'\"\\\"'\$VAR'\\\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->'tata'\"\$VAR\""
	echo
  [ "${lines[0]}" = "\'tata\'\"\$VAR\"" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [MEGA hard] HARD" {
  echo -e "blow\njob\n!2\n!3\n!!" > /tmp/.21sh_history
  run $val_cmd env -i VAR=\$VAR2 VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"\'\$VAR2\'\" '\\\"'\$VAR2'\\\"'"
  echo
  echo "ERROR: \"\"\'\$VAR2\'\" '\\\"'\$VAR2'\\\"'\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->\'tata\' \\\"tata\\\""
	echo
  [ "${lines[0]}" = "\'tata\' \\\"tata\\\"" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [spec] with '\$0'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\$0"
  echo
echo "ERROR: \"\$0\""
echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->${BATS_TEST_DIRNAME}/../../$name_exec"
	echo
  [ "${lines[0]}" = "${BATS_TEST_DIRNAME}/../../$name_exec" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [spec] with '\$?'" {
  skip "faut une global, et l'exec  https://superuser.com/questions/247127/what-is-and-in-linux/247131"
  echo
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\$?"
  echo
  echo "ERROR: \"\$?\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->0"
	echo
  [ "${lines[0]}" = "0" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [spec] with '\$\$'" {
  skip "je sais pas le test, c'est l'ID du shell"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\$\$"
  id=$!
  echo
  echo "ERROR: \"\$\$\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->$id"
	echo
  [ "${lines[0]}" = "$id" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

######################################################################
#                            CAR                                     #
######################################################################
@test "EXPAND: Testing [car] with '\\n'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\ntata"
  echo
  echo "ERROR: \"toto\\ntata\""
  echo
	display_line_output
	echo
  ret=$( sh -c "echo \"toto\ntata\"" )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${lines[0]}" = "$ret" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\a'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\atata"
  echo
  echo "ERROR: \"toto\\atata\""
  echo
	display_line_output
	echo
  ret=$( sh -c "echo \"toto\atata\"" )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${lines[0]}" = "$ret" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\b'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\btata"
  echo
  echo "ERROR: \"toto\\btata\""
  echo
	display_line_output
	echo
  ret=$( sh -c "echo \"toto\btata\"" )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${lines[0]}" = "$ret" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\t'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\ttata"
  echo
  echo "ERROR: \"toto\\ttata\""
  echo
	display_line_output
	echo
  ret=$( sh -c "echo \"toto\ttata\"" )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${lines[0]}" = "$ret" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\r'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\rtata"
  echo
  echo "ERROR: \"toto\\rtata\""
  echo
	display_line_output
	echo
  ret=$( sh -c "echo \"toto\btata\"" )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${lines[0]}" = "$ret" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\f'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\ftata"
  echo
  echo "ERROR: \"toto\\ftata\""
  echo
	display_line_output
	echo
  ret=$( sh -c "echo \"toto\ftata\"" )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${lines[0]}" = "$ret" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\v'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\vtata"
  echo
  echo "ERROR: \"toto\\vtata\""
  echo
	display_line_output
	echo
  ret=$( sh -c "echo \"toto\ftata\"" )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${lines[0]}" = "$ret" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\\\ tata"
  echo
  echo "ERROR: \"toto\\\\tata\""
  echo
	display_line_output
	echo
  ret=$( sh -c "echo \"toto\\tata\"" )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${lines[0]}" = "$ret" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\\\n'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\\\ntata"
  echo
  echo "ERROR: \"toto\\\\ntata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->toto\\ntata"
	echo
  [ "${lines[0]}" = "toto\\ntata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\\\a'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\\\atata"
  echo
  echo "ERROR: \"toto\\\\atata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->toto\\atata"
	echo
  [ "${lines[0]}" = "toto\\atata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\\\b'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\\\btata"
  echo
  echo "ERROR: \"toto\\\\btata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->toto\\btata"
	echo
  [ "${lines[0]}" = "toto\\btata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\\\t'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\\\ttata"
  echo
  echo "ERROR: \"toto\\\\ttata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->toto\\ttata"
	echo
  [ "${lines[0]}" = "toto\\ttata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\\\r'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\\\rtata"
  echo
  echo "ERROR: \"toto\\\\rtata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->toto\\rtata"
	echo
  [ "${lines[0]}" = "toto\\rtata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\\\f'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\\\ftata"
  echo
  echo "ERROR: \"toto\\\\ftata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->toto\\ftata"
	echo
  [ "${lines[0]}" = "toto\\ftata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\\\v'" {
skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\\\vtata"
  echo
  echo "ERROR: \"toto\\\\vtata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->toto\\vtata"
	echo
  [ "${lines[0]}" = "toto\\vtata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [car] with '\\\\\\\'" {
	skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto\\\\\\\\ tata"
  echo
  echo "ERROR: \"toto\\\\\\\\ tata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->toto\\\\ tata"
	echo
  [ "${lines[0]}" = "toto\\\\ tata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hard] with '\'" {
	skip "Tu dois pas gere"
	ent="helld\\n com\\act\\rt\\\\t \\fn\\m x\\\\\\\\t\\\\a\\r\\v"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "$ent"
  echo
  echo "ERROR: \"$ent\""
  echo
	display_line_output
	echo
  ret=$( sh -c "echo \"$ent\"" )
  echo "$name_exec EXPECTED ->$ret"
  echo
  [ "${lines[0]}" = "$ret" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [hard] with '\a'" {
	skip "Tu dois pas gere"
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "toto'\\a'tata"
  echo
  echo "ERROR: \"toto'\\a'tata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tototata"
  echo
  [ "${lines[0]}" = "tototata" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

######################################################################
######################################################################

######################################################################
#                            ~                                       #
######################################################################

@test "EXPAND: Testing [~] 1" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "~"
  echo
  echo "ERROR: \"~\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->$HOME"
  echo
  [ "${lines[0]}" = "$HOME" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [~] 2" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "Hello'~'toto\"~\""
  echo
  echo "ERROR: \"Hello'~'toto\"~\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->HELLO~toto$HOME"
  echo
  [ "${lines[0]}" = "HELLO~toto$HOME" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [~] 3" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'\\~'"
  echo
  echo "ERROR: \"'\\~'\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->\\~"
  echo
  [ "${lines[0]}" = "\\~" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

@test "EXPAND: Testing [~] 4" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\\~"
  echo
  echo "ERROR: \"\\~\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->~"
  echo
  [ "${lines[0]}" = "~" ]
	[ "${lines[1]}" = "" ]
check_leaks_function parser
}

######################################################################
######################################################################
