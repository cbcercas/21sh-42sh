#! / Usr / bin / env bats

load test_helper

####start####
@test "bin exist and works or compil test" {
	skip "it is usless"
	run make -C ${BATS_TEST_DIRNAME}/../../ fclean
	run make -j -C ${BATS_TEST_DIRNAME}/../../
	[ -f ${BATS_TEST_DIRNAME}/../../$name_exec ]
  [ "$status" -eq 0 ]
}
###########
