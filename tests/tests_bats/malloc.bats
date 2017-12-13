#! / Usr / bin / env bats

load test_helper
@test "EXEC: Testing [MALLOC] for MALLOC -M0 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M0 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M0 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M0 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M4 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M4 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M4 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M4 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M8 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M8 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M8 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M8 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M12 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M12 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M12 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M12 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M16 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M16 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M16 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M16 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M20 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M20 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M20 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M20 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M24 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M24 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M24 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M24 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M28 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M28 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M28 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M28 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M32 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M32 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M32 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M32 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M36 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M36 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M36 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M36 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M40 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M40 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M40 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M40 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M44 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M44 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M44 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M44 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M48 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M48 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M48 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M48 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M52 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M52 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M52 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M52 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M56 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M56 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M56 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M56 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M60 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M60 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M60 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M60 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M64 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M64 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M64 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M64 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M68 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M68 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M68 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M68 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M72 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M72 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M72 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M72 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M76 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M76 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M76 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M76 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M80 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M80 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M80 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M80 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M84 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M84 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M84 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M84 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M88 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M88 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M88 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M88 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M92 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M92 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M92 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M92 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M96 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M96 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M96 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M96 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M100 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M100 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M100 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M100 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M104 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M104 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M104 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M104 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M108 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M108 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M108 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M108 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M112 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M112 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M112 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M112 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M116 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M116 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M116 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M116 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M120 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M120 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M120 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M120 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M124 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M124 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M124 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M124 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M128 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M128 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M128 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M128 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M132 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M132 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M132 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M132 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M136 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M136 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M136 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M136 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M140 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M140 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M140 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M140 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M144 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M144 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M144 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M144 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M148 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M148 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M148 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M148 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M152 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M152 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M152 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M152 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M156 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M156 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M156 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M156 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M160 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M160 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M160 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M160 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M164 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M164 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M164 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M164 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M168 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M168 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M168 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M168 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M172 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M172 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M172 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M172 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M176 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M176 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M176 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M176 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M180 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M180 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M180 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M180 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M184 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M184 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M184 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M184 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M188 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M188 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M188 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M188 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M192 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M192 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M192 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M192 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M196 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M196 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M196 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M196 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M200 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M200 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M200 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M200 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M204 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M204 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M204 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M204 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M208 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M208 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M208 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M208 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M212 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M212 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M212 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M212 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M216 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M216 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M216 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M216 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M220 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M220 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M220 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M220 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M224 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M224 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M224 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M224 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M228 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M228 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M228 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M228 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M232 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M232 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M232 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M232 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M236 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M236 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M236 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M236 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M240 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M240 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M240 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M240 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M244 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M244 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M244 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M244 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M248 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M248 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M248 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M248 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M252 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M252 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M252 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M252 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M256 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M256 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M256 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M256 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M260 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M260 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M260 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M260 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M264 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M264 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M264 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M264 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M268 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M268 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M268 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M268 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M272 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M272 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M272 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M272 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M276 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M276 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M276 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M276 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M280 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M280 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M280 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M280 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M284 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M284 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M284 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M284 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M288 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M288 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M288 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M288 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M292 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M292 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M292 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M292 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M296 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M296 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M296 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M296 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M300 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M300 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M300 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M300 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M304 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M304 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M304 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M304 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M308 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M308 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M308 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M308 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M312 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M312 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M312 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M312 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M316 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M316 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M316 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M316 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M320 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M320 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M320 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M320 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M324 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M324 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M324 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M324 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M328 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M328 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M328 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M328 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M332 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M332 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M332 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M332 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M336 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M336 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M336 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M336 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M340 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M340 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M340 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M340 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M344 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M344 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M344 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M344 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M348 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M348 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M348 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M348 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M352 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M352 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M352 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M352 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M356 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M356 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M356 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M356 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M360 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M360 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M360 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M360 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M364 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M364 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M364 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M364 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M368 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M368 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M368 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M368 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M372 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M372 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M372 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M372 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M376 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M376 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M376 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M376 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M380 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M380 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M380 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M380 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M384 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M384 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M384 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M384 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M388 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M388 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M388 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M388 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M392 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M392 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M392 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M392 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M396 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M396 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M396 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M396 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M400 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M400 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M400 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M400 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M404 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M404 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M404 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M404 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M408 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M408 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M408 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M408 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M412 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M412 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M412 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M412 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M416 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M416 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M416 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M416 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M420 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M420 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M420 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M420 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M424 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M424 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M424 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M424 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M428 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M428 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M428 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M428 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M432 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M432 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M432 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M432 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M436 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M436 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M436 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M436 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M440 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M440 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M440 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M440 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M444 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M444 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M444 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M444 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M448 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M448 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M448 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M448 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M452 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M452 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M452 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M452 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M456 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M456 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M456 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M456 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M460 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M460 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M460 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M460 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M464 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M464 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M464 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M464 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M468 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M468 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M468 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M468 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M472 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M472 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M472 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M472 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M476 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M476 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M476 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M476 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M480 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M480 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M480 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M480 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M484 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M484 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M484 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M484 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M488 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M488 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M488 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M488 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M492 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M492 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M492 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M492 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M496 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M496 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M496 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M496 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M500 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M500 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M500 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M500 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M504 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M504 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M504 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M504 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M508 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M508 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M508 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M508 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M512 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M512 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M512 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M512 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M516 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M516 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M516 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M516 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M520 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M520 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M520 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M520 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M524 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M524 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M524 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M524 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M528 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M528 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M528 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M528 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M532 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M532 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M532 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M532 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M536 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M536 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M536 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M536 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M540 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M540 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M540 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M540 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M544 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M544 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M544 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M544 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M548 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M548 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M548 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M548 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M552 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M552 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M552 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M552 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M556 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M556 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M556 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M556 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M560 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M560 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M560 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M560 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M564 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M564 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M564 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M564 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M568 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M568 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M568 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M568 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M572 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M572 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M572 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M572 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M576 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M576 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M576 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M576 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M580 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M580 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M580 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M580 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M584 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M584 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M584 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M584 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M588 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M588 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M588 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M588 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M592 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M592 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M592 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M592 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M596 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M596 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M596 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M596 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M600 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M600 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M600 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M600 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M604 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M604 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M604 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M604 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M608 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M608 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M608 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M608 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M612 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M612 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M612 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M612 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M616 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M616 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M616 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M616 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M620 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M620 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M620 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M620 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M624 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M624 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M624 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M624 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M628 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M628 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M628 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M628 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M632 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M632 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M632 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M632 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M636 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M636 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M636 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M636 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M640 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M640 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M640 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M640 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M644 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M644 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M644 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M644 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M648 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M648 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M648 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M648 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M652 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M652 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M652 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M652 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M656 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M656 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M656 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M656 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M660 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M660 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M660 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M660 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M664 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M664 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M664 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M664 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M668 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M668 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M668 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M668 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M672 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M672 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M672 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M672 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M676 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M676 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M676 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M676 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M680 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M680 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M680 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M680 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M684 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M684 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M684 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M684 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M688 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M688 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M688 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M688 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M692 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M692 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M692 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M692 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M696 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M696 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M696 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M696 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M700 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M700 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M700 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M700 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M704 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M704 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M704 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M704 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M708 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M708 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M708 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M708 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M712 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M712 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M712 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M712 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M716 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M716 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M716 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M716 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M720 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M720 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M720 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M720 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M724 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M724 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M724 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M724 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M728 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M728 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M728 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M728 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M732 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M732 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M732 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M732 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M736 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M736 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M736 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M736 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M740 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M740 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M740 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M740 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M744 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M744 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M744 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M744 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M748 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M748 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M748 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M748 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M752 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M752 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M752 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M752 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M756 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M756 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M756 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M756 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M760 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M760 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M760 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M760 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M764 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M764 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M764 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M764 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M768 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M768 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M768 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M768 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M772 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M772 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M772 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M772 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M776 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M776 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M776 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M776 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M780 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M780 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M780 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M780 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M784 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M784 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M784 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M784 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M788 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M788 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M788 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M788 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M792 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M792 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M792 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M792 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M796 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M796 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M796 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M796 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M800 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M800 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M800 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M800 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M804 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M804 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M804 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M804 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M808 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M808 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M808 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M808 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M812 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M812 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M812 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M812 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M816 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M816 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M816 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M816 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M820 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M820 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M820 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M820 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M824 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M824 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M824 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M824 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M828 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M828 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M828 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M828 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M832 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M832 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M832 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M832 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M836 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M836 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M836 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M836 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M840 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M840 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M840 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M840 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M844 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M844 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M844 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M844 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M848 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M848 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M848 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M848 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M852 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M852 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M852 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M852 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M856 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M856 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M856 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M856 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M860 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M860 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M860 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M860 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M864 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M864 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M864 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M864 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M868 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M868 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M868 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M868 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M872 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M872 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M872 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M872 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M876 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M876 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M876 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M876 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M880 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M880 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M880 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M880 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M884 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M884 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M884 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M884 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M888 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M888 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M888 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M888 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M892 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M892 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M892 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M892 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M896 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M896 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M896 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M896 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M900 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M900 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M900 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M900 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M904 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M904 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M904 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M904 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M908 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M908 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M908 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M908 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M912 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M912 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M912 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M912 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M916 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M916 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M916 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M916 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M920 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M920 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M920 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M920 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M924 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M924 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M924 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M924 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M928 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M928 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M928 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M928 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M932 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M932 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M932 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M932 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M936 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M936 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M936 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M936 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M940 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M940 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M940 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M940 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M944 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M944 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M944 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M944 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M948 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M948 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M948 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M948 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M952 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M952 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M952 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M952 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M956 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M956 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M956 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M956 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M960 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M960 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M960 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M960 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M964 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M964 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M964 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M964 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M968 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M968 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M968 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M968 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M972 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M972 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M972 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M972 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M976 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M976 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M976 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M976 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M980 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M980 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M980 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M980 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M984 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M984 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M984 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M984 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M988 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M988 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M988 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M988 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M992 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M992 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M992 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M992 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M996 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M996 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M996 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M996 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1000 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1000 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1000 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1000 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1004 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1004 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1004 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1004 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1008 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1008 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1008 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1008 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1012 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1012 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1012 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1012 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1016 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1016 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1016 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1016 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1020 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1020 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1020 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1020 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1024 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1024 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1024 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1024 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1028 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1028 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1028 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1028 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1032 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1032 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1032 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1032 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1036 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1036 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1036 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1036 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1040 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1040 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1040 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1040 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1044 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1044 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1044 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1044 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1048 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1048 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1048 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1048 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1052 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1052 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1052 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1052 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1056 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1056 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1056 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1056 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1060 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1060 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1060 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1060 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1064 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1064 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1064 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1064 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1068 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1068 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1068 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1068 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1072 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1072 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1072 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1072 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1076 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1076 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1076 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1076 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1080 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1080 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1080 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1080 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1084 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1084 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1084 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1084 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1088 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1088 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1088 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1088 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1092 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1092 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1092 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1092 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1096 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1096 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1096 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1096 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1100 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1100 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1100 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1100 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1104 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1104 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1104 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1104 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1108 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1108 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1108 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1108 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1112 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1112 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1112 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1112 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1116 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1116 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1116 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1116 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1120 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1120 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1120 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1120 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1124 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1124 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1124 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1124 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1128 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1128 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1128 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1128 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1132 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1132 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1132 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1132 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1136 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1136 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1136 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1136 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1140 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1140 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1140 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1140 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1144 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1144 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1144 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1144 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1148 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1148 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1148 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1148 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1152 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1152 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1152 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1152 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1156 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1156 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1156 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1156 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1160 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1160 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1160 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1160 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1164 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1164 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1164 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1164 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1168 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1168 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1168 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1168 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1172 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1172 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1172 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1172 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1176 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1176 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1176 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1176 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1180 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1180 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1180 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1180 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1184 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1184 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1184 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1184 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1188 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1188 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1188 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1188 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1192 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1192 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1192 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1192 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1196 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1196 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1196 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1196 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1200 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1200 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1200 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1200 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1204 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1204 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1204 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1204 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1208 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1208 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1208 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1208 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1212 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1212 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1212 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1212 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1216 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1216 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1216 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1216 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1220 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1220 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1220 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1220 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1224 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1224 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1224 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1224 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1228 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1228 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1228 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1228 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1232 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1232 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1232 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1232 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1236 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1236 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1236 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1236 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1240 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1240 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1240 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1240 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1244 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1244 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1244 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1244 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1248 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1248 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1248 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1248 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1252 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1252 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1252 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1252 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1256 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1256 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1256 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1256 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1260 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1260 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1260 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1260 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1264 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1264 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1264 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1264 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1268 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1268 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1268 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1268 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1272 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1272 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1272 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1272 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1276 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1276 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1276 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1276 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1280 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1280 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1280 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1280 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1284 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1284 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1284 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1284 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1288 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1288 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1288 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1288 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1292 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1292 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1292 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1292 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1296 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1296 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1296 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1296 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1300 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1300 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1300 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1300 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1304 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1304 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1304 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1304 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1308 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1308 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1308 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1308 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1312 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1312 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1312 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1312 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1316 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1316 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1316 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1316 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1320 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1320 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1320 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1320 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1324 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1324 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1324 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1324 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1328 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1328 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1328 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1328 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1332 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1332 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1332 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1332 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1336 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1336 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1336 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1336 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1340 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1340 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1340 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1340 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1344 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1344 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1344 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1344 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1348 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1348 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1348 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1348 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1352 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1352 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1352 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1352 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1356 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1356 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1356 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1356 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1360 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1360 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1360 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1360 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1364 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1364 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1364 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1364 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1368 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1368 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1368 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1368 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1372 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1372 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1372 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1372 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1376 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1376 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1376 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1376 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1380 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1380 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1380 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1380 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1384 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1384 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1384 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1384 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1388 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1388 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1388 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1388 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1392 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1392 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1392 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1392 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1396 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1396 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1396 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1396 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1400 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1400 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1400 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1400 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1404 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1404 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1404 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1404 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1408 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1408 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1408 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1408 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1412 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1412 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1412 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1412 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1416 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1416 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1416 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1416 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1420 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1420 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1420 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1420 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1424 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1424 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1424 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1424 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1428 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1428 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1428 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1428 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1432 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1432 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1432 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1432 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1436 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1436 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1436 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1436 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1440 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1440 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1440 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1440 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1444 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1444 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1444 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1444 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1448 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1448 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1448 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1448 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1452 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1452 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1452 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1452 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1456 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1456 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1456 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1456 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1460 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1460 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1460 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1460 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1464 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1464 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1464 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1464 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1468 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1468 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1468 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1468 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1472 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1472 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1472 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1472 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1476 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1476 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1476 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1476 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1480 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1480 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1480 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1480 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1484 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1484 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1484 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1484 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1488 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1488 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1488 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1488 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1492 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1492 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1492 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1492 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1496 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1496 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1496 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1496 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
@test "EXEC: Testing [MALLOC] for MALLOC -M1500 " {
    run ${BATS_TEST_DIRNAME}/../../$name_exec -M1500 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    echo "ERROR:"
    echo "**************ERROR MALLOC -M1500 ***************"
    echo "status = $status"

		if [ "${output}" = "" ] ||  [ "$status" -ne 0 ] && [ "$status" -ne 1 ] && [ $TEST_BATS_SAN != "yes" ]
    	then
    		run valgrind --log-file=check_leaks_tmp.log --leak-check=full --track-origins=yes ${BATS_TEST_DIRNAME}/../../$name_exec -M1500 -d7 -c 'ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls ; ls -a ; ls | cat | cat -e ; base64 /dev/urandom | head -c 1000 | grep 42 | wc -l && ls || ls -la ; ls' 2>&1
    		mkdir -p "${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC"
    		cp check_leaks_tmp.log ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log
    			echo "======================================================================="
     			echo "**[----- MALLOC ERROR! -----]"
            	echo "=> check file log: ${BATS_TEST_DIRNAME}/../valgrind_log/MALLOC/TEST-$BATS_TEST_NUMBER-MALLOC.log"
            	echo "======================================================================="
    	[ 1 = 0 ]
    	fi
        [ "${output}" != "" ]
        [ "$status" -eq 0 ] || [ "$status" -eq 1 ]
}
