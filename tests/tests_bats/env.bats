#! / Usr / bin / env bats

load test_helper

#######################################################################
#                            GET AND DISPLAY ENV                      #
#######################################################################

@test "ENV: Testing [get/display] with 'NULL'" {
  run env -i ${BATS_TEST_DIRNAME}/../../$name_exec -t env
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->"
	echo
  [ "${lines[0]}" = "" ]
	[ "${lines[1]}" = "" ]
}

@test "ENV: Testing [get/display] with vars simple and short" {
  run env -i 1VAR=1 2VAR=2 3VAR=3 ${BATS_TEST_DIRNAME}/../../$name_exec -t env
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=1"
  echo "                2VAR=2"
  echo "                3VAR=3"
	echo
  expect=`echo -e "\033[94m1VAR\033[0m=1\n\033[94m2VAR\033[0m=2\n\033[94m3VAR\033[0m=3"`
  [ "${output}" = "$expect" ]
  [ "${lines[3]}" = "" ]
}

@test "ENV: Testing [get/display] with var simple and long" {
  run env -i 1VAR="ItIsALongVariableVeryLongI'mBoringSoLoop:ItIsALongVariableVeryLongI'mBoringSoLoop:ItIsALongVariableVeryLongI'mBoringSoLoop:ItIsALongVariableVeryLongI'mBoringSoLoop:" ${BATS_TEST_DIRNAME}/../../$name_exec -t env
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=ItIsALongVariableVeryLongI'mBoringSoLoop:ItIsALongVariableVeryLongI'mBoringSoLoop:ItIsALongVariableVeryLongI'mBoringSoLoop:ItIsALongVariableVeryLongI'mBoringSoLoop:"
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m=ItIsALongVariableVeryLongI'mBoringSoLoop:ItIsALongVariableVeryLongI'mBoringSoLoop:ItIsALongVariableVeryLongI'mBoringSoLoop:ItIsALongVariableVeryLongI'mBoringSoLoop:"` ]
  [ "${lines[1]}" = "" ]
}

@test "ENV: Testing [get/display] with vars complex and short" {
  run env -i 1VAR=1=1=1=1======1 2VAR=2=two=deux:,%= 3VAR='3=3=3===hl0=?\(\)#' 4VAR= ${BATS_TEST_DIRNAME}/../../$name_exec -t env
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=1=1=1=1======1"
  echo "                2VAR=2=two=deux:,%="
  echo "                3VAR=3=3=3===hl0=?\(\)#"
  echo "                4VAR="
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m=1=1=1=1======1"` ]
	[ "${lines[1]}" = `echo -e "\033[94m2VAR\033[0m=2=two=deux:,%="` ]
  [ "${lines[2]}" = `echo -e "\033[94m3VAR\033[0m=3=3=3===hl0=?\(\)#"` ]
  [ "${lines[3]}" = `echo -e "\033[94m4VAR\033[0m="` ]
  [ "${lines[4]}" = "" ]
}

@test "ENV: Testing [get/display] 100 vars" {
  #skip "because is too long"
  i=0
  vars=""
  while [ $i != 100 ]
  do
    vars+=$var$i"VAR=$i "
    i=`expr $i + 1`
  done
  run env -i $vars ${BATS_TEST_DIRNAME}/../../$name_exec -t env $vars
  i=0
  vars=""
  while [ $i != 100 ]
  do
    vars+=`echo -e "\033[94m"`$var$i`echo -e "VAR\033[0m="`"$i "
    i=`expr $i + 1`
  done
  vars=$(echo "$vars" | sed -e 's/ /\'$'\n/g')
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->0VAR=0"
  echo "                1VAR=1"
  echo "                2VAR=2"
  echo "                 [...]"
  echo
  [ "${output}" = "${vars}" ]
}

#######################################################################
#######################################################################


#######################################################################
#                            SET VAR ENV                              #
#######################################################################
@test "ENV: Testing [set] vars with new vars simple in env NULL" {
  run env -i ${BATS_TEST_DIRNAME}/../../$name_exec -t env "set" 1VAR=1 2VAR=2
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=1"
  echo "                2VAR=2"
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m=1"` ]
	[ "${lines[1]}" = `echo -e "\033[94m2VAR\033[0m=2"` ]
  [ "${lines[2]}" = "" ]
}

@test "ENV: Testing [set] vars with new vars simple and short" {
  run env -i 1VAR=1 2VAR=2 ${BATS_TEST_DIRNAME}/../../$name_exec -t env "set" 3VAR=3 4VAR=4
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=1"
  echo "                2VAR=2"
  echo "                3VAR=3"
  echo "                4VAR=4"
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m=1"` ]
	[ "${lines[1]}" = `echo -e "\033[94m2VAR\033[0m=2"` ]
  [ "${lines[2]}" = `echo -e "\033[94m3VAR\033[0m=3"` ]
  [ "${lines[3]}" = `echo -e "\033[94m4VAR\033[0m=4"` ]
  [ "${lines[4]}" = "" ]
}

@test "ENV: Testing [set] twice the same var in env NULL" {
  run env -i ${BATS_TEST_DIRNAME}/../../$name_exec -t env "set" 1VAR=1 1VAR=1 2VAR=2
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=1"
  echo "                2VAR=2"
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m=1"` ]
	[ "${lines[1]}" = `echo -e "\033[94m2VAR\033[0m=2"` ]
  [ "${lines[2]}" = "" ]
}

@test "ENV: Testing [set] twice the same var not env NULL" {
  run env -i 1VAR=1 2VAR=2 ${BATS_TEST_DIRNAME}/../../$name_exec -t env "set" 3VAR=3 1VAR=1 3VAR=3
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=1"
  echo "                2VAR=2"
  echo "                3VAR=3"
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m=1"` ]
	[ "${lines[1]}" = `echo -e "\033[94m2VAR\033[0m=2"` ]
  [ "${lines[2]}" = `echo -e "\033[94m3VAR\033[0m=3"` ]
  [ "${lines[3]}" = "" ]
}

@test "ENV: Testing [set] already exist var in env NULL 1" {
  run env -i ${BATS_TEST_DIRNAME}/../../$name_exec -t env "set" 1VAR=1 1VAR=modif
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=modif"
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m=modif"` ]
  [ "${lines[1]}" = "" ]
}

@test "ENV: Testing [set] already exist var in env NULL 2" {
  run env -i ${BATS_TEST_DIRNAME}/../../$name_exec -t env "set" 1VAR=1 1VAR=modif 1VAR=
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR="
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m="` ]
  [ "${lines[1]}" = "" ]
}

@test "ENV: Testing [set] already exist vars not env NULL" {
  run env -i  1VAR=1 3VAR=3 2VAR=2 ${BATS_TEST_DIRNAME}/../../$name_exec -t env "set" 1VAR=1 1VAR=modif 2VAR=3 3VAR=toto
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=modif"
  echo "                3VAR=toto"
  echo "                2VAR=3"
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m=modif"` ]
  [ "${lines[1]}" = `echo -e "\033[94m3VAR\033[0m=toto"` ]
  [ "${lines[2]}" = `echo -e "\033[94m2VAR\033[0m=3"` ]
  [ "${lines[3]}" = "" ]
}

@test "ENV: Testing [set] 100 vars" {
  #skip "because is too long"
  i=0
  vars=""
  while [ $i != 100 ]
  do
    vars+=$var$i"VAR=$i "
    i=`expr $i + 1`
  done
  run env -i ${BATS_TEST_DIRNAME}/../../$name_exec -t env "set" $vars
  i=0
  vars=""
  while [ $i != 100 ]
  do
    vars+=`echo -e "\033[94m"`$var$i`echo -e "VAR\033[0m="`"$i "
    i=`expr $i + 1`
  done
  vars=$(echo "$vars" | sed -e 's/ /\'$'\n/g')
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->0VAR=0"
  echo "                1VAR=1"
  echo "                2VAR=2"
  echo "                 [...]"
  echo
  [ "${output}" = "${vars}" ]
}

#######################################################################
#######################################################################


######################################################################
#                            DEL VAR ENV                             #
######################################################################

@test "ENV: Testing [del] supress variables does not exist with env NULL" {
  run env -i ${BATS_TEST_DIRNAME}/../../$name_exec -t env del supress this please
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->"
	echo
  [ "${lines[0]}" = "" ]
	[ "${lines[1]}" = "" ]
}

@test "ENV: Testing [del] supress variables does not exist with env not NULL" {
  run env -i 1VAR=1 2VAR=2 3VAR=3 ${BATS_TEST_DIRNAME}/../../$name_exec -t env del supress this please
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=1"
  echo "                2VAR=2"
  echo "                3VAR=3"
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m=1"` ]
	[ "${lines[1]}" = `echo -e "\033[94m2VAR\033[0m=2"` ]
  [ "${lines[2]}" = `echo -e "\033[94m3VAR\033[0m=3"` ]
  [ "${lines[3]}" = "" ]
}

@test "ENV: Testing [del] supress twice same variable 1" {
  run env -i 1VAR=1 ${BATS_TEST_DIRNAME}/../../$name_exec -t env del 1VAR 1VAR
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->"
  echo
  [ "${lines[0]}" = "" ]
  [ "${lines[1]}" = "" ]
}

@test "ENV: Testing [del] supress twice same variable 2" {
  run env -i 1VAR=1 2VAR=2 ${BATS_TEST_DIRNAME}/../../$name_exec -t env del 1VAR 1VAR
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->2VAR=2"
  echo
  [ "${lines[0]}" = `echo -e "\033[94m2VAR\033[0m=2"` ]
  [ "${lines[1]}" = "" ]
}

@test "ENV: Testing [del] 1 var in env with 4 vars " {
  run env -i 1VAR=1 VARTOSUPRESS=plouf 2VAR=2 3VAR=3 ${BATS_TEST_DIRNAME}/../../$name_exec -t env del VARTOSUPRESS
  echo "ERROR:"
	display_line_output
	echo
  echo "$name_exec EXPECTED ->1VAR=1"
  echo "                2VAR=2"
  echo "                3VAR=3"
	echo
  [ "${lines[0]}" = `echo -e "\033[94m1VAR\033[0m=1"` ]
	[ "${lines[1]}" = `echo -e "\033[94m2VAR\033[0m=2"` ]
  [ "${lines[2]}" = `echo -e "\033[94m3VAR\033[0m=3"` ]
  [ "${lines[3]}" = "" ]
}

#######################################################################
#######################################################################
