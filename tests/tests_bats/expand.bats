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
  echo "$name_exec EXPECTED ->$fatal"
	echo
  [ "${lines[0]}" = "$fatal" ]
check_leaks_function expand
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
check_leaks_function expand
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
check_leaks_function expand
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
check_leaks_function expand
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
check_leaks_function expand
}

@test "EXPAND: Testing [simple replace] 100 vars" {
  skip "Test takes to long and fails. TODO"
  i=0
  vars=""
  rets=""
  ent=""
  while [ $i != 100 ]
  do
    vars+="VAR$i=$i "
    rets+="$i=$i "
    ent+=VAR$i"=$i "
    i=`expr $i + 1`
  done
  vars+="VAR$i=$i"
  rets+="$i=$i"
  ent+=VAR$i"=$i"
  run $val_cmd env -i $vars ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "$vars"
  echo
  echo "ERROR: \"VAR0=0…\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->0=0 1=1 …"
  [ "${output}" = "${ent}" ]
check_leaks_function expand
}

#######################################################################
#######################################################################

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
check_leaks_function expand
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
  [ "${lines[0]}" = " " ]
check_leaks_function expand
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
check_leaks_function expand
}

#######################################################################
#######################################################################

#######################################################################
#                              DDQUOTE                                #
#######################################################################

@test "EXPAND: Testing [dbquote] with 'simple'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"tata\""
  echo
  echo "ERROR: \"tata\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tata"
	echo
  [ "${lines[0]}" = "tata" ]
check_leaks_function expand
}

@test "EXPAND: Testing [dbquote] with 'double 1'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"tata\" \"toto\""
  echo
  echo "ERROR: \"\"tata\" \"toto\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tata toto"
	echo
  [ "${lines[0]}" = "tata toto" ]
check_leaks_function expand
}

@test "EXPAND: Testing [dbquote] with 'double 2'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"tata\"\"toto\""
  echo
  echo "ERROR: \"\"tata\"\"toto\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tatatoto"
	echo
  [ "${lines[0]}" = "tatatoto" ]
check_leaks_function expand
}

@test "EXPAND: Testing [dbquote] with 'double 3'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"tata\"toto"
  echo
  echo "ERROR: \"\"tata\"toto\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tatatoto"
	echo
  [ "${lines[0]}" = "tatatoto" ]
check_leaks_function expand
}

@test "EXPAND: Testing [dbquote] with 'double 4'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"\$VAR2\"toto"
  echo
  echo "ERROR: \"\$VAR2\"toto\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tatatoto"
	echo
  [ "${lines[0]}" = "tatatoto" ]
check_leaks_function expand
}

@test "EXPAND: Testing [dbquote] with 'double \"\"a\"\"'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"\"\"a\"\"\""
  echo
  echo "ERROR: \"\"\"\"a\"\"\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->a"
	echo
  [ "${lines[0]}" = "a" ]
check_leaks_function expand
}

@test "EXPAND: Testing [dbquote] with 'double \"a\"\"a\"\"\" \"au\"'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"a\"\"a\"\"\" \"au\""
  echo
  echo "ERROR: \"a\"\"a\"\"\" \"au\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->aa au"
	echo
  [ "${lines[0]}" = "aa au" ]
check_leaks_function expand
}

#######################################################################
#######################################################################

#######################################################################
#                              QUOTE                                #
#######################################################################


@test "EXPAND: Testing [quote] with 'simple'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'tata'"
  echo
  echo "ERROR: \"'tata'\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tata"
	echo
  [ "${lines[0]}" = "tata" ]
check_leaks_function expand
}

@test "EXPAND: Testing [quote] with 'double 1'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'tata' 'toto'"
  echo
  echo "ERROR: \"'tata' 'toto'\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tata toto"
	echo
  [ "${lines[0]}" = "tata toto" ]
check_leaks_function expand
}

@test "EXPAND: Testing [quote] with 'double 2'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'tata''toto'"
  echo
  echo "ERROR: \"'tata''toto'\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tatatoto"
	echo
  [ "${lines[0]}" = "tatatoto" ]
check_leaks_function expand
}

@test "EXPAND: Testing [quote] with 'double 3'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'tata'toto"
  echo
  echo "ERROR: \"'tata'toto\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->tatatoto"
	echo
  [ "${lines[0]}" = "tatatoto" ]
check_leaks_function expand
}

@test "EXPAND: Testing [quote] with 'double 4'" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'\$VAR2'toto"
  echo
  echo "ERROR: \"'\$VAR2'toto\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->\$VAR2toto"
	echo
  [ "${lines[0]}" = "\$VAR2toto" ]
check_leaks_function expand
}

@test "EXPAND: Testing [quote] with 'double ''a'''" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'''a'''"
  echo
  echo "ERROR: \"'''a'''\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->a"
	echo
  [ "${lines[0]}" = "a" ]
check_leaks_function expand
}

@test "EXPAND: Testing [quote] with 'double 'a''a''' 'au''" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'a''a''' 'au'''"
  echo
  echo "ERROR: 'a''a''' 'au'''"
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->aa au"
	echo
  [ "${lines[0]}" = "aa au" ]
check_leaks_function expand
}
#######################################################################
#######################################################################

######################################################################
#                            MIX                                     #
######################################################################

@test "EXPAND: Testing [mix] 3" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\"''\" '\"\"'"
  echo
echo "ERROR: \"\"''\" '\"\"'\""
echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->'' \"\""
	echo
  [ "${lines[0]}" = "'' \"\"" ]
check_leaks_function expand
}

@test "EXPAND: Testing [mix] 4" {
  echo -e "blow\njob" > $history_loc
  run $val_cmd env -i VAR=toto VAR2=tata ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "'\"\$VAR\"' \"'\$VAR'\""
  echo
  echo "ERROR: \"'\"\$VAR\"' \"'\$VAR'\"\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->\"\$VAR\" 'toto'"
	echo
  [ "${lines[0]}" = "\"\$VAR\" 'toto'" ]
check_leaks_function expand
}

#######################################################################
#######################################################################

@test "EXPAND: Testing [spec] with '\$0'" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "\$0"
  echo
echo "ERROR: \"\$0\""
echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->$name_exec"
	echo
  [ "${lines[0]}" = "$name_exec" ]
	[ "${lines[1]}" = "" ]
check_leaks_function expand
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
check_leaks_function expand
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
check_leaks_function expand
}

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
  echo "$name_exec EXPECTED ->$home_tests"
  echo
  [ "${lines[0]}" = "$home_tests" ]
	[ "${lines[1]}" = "" ]
check_leaks_function expand
}

@test "EXPAND: Testing [~] 2" {
  run $val_cmd ${BATS_TEST_DIRNAME}/../../$name_exec -t expand "HELLO'~'toto\"~\""
  echo
  echo "ERROR: HELLO'~'toto\"~\""
  echo
	display_line_output
	echo
  echo "$name_exec EXPECTED ->HELLO~toto$home_tests"
  echo
  [ "${lines[0]}" = "HELLO~toto$home_tests" ]
	[ "${lines[1]}" = "" ]
check_leaks_function expand
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
check_leaks_function expand
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
check_leaks_function expand
}

######################################################################
######################################################################


######################################################################
######################################################################
