# Tests:  
## Description:
*Some tests for Shell's modules.*  
------- --
## Utilisation:
In shell:  
`./$ROOT_BRANCH/tests/tests.sh [option] [module]`  
* exemple:  
      `./$ROOT_BRANCH/tests/tests.sh -b parser`

### Option:
  1. __--sh or -s [module]:__  
    It is option for "normal" tests with shell script, based on diff command. tests.sh call the scripts `$ROOT_BRANCH/tests/tests_module/test_$NAME_OF_MODULE.sh`. In `$ROOT_BRANCH/tests/ressouces/parser/`, there are three directories:
        * tests: with `tests[1-19].sh` script tests
        * expected: with `tests[1-19].expected` output expected
        * output: with `tests[1-19].output` output result of script tests    
__*(This option is no longer updated. By default, use the -b option)*__

  2. __--bats or -b [module]:__  
      -*lexer*  
      -*parser*  
      -*env* (it doesn't test the builtin env)  
      -*expand*  
      -*ast*  
  "-b" is option for tests with frameworks: bats.  
  __(You should install bats before)__ [Github-bats](https://github.com/sstephenson/bats)

  3. __--help or -h :__  
   Display help.

  4. __without option__  
    __If__ ${TRAVIS_BRANCH} is set, then run script: `./test.sh -b ${TRAVIS_BRANCH}`  
    __If__ ${TRAVIS_BRANCH} = "master", then run script: `./test.sh -b all`  
    __Else__ exit 1;  
    
  5. __--valgrind or -v=<full|default|no> [default: default]:__  
         Checks Leaks with Valgrind  
         (the symbole "=" is optionnal).
 --------------
  ## Update/If you want add test:
  1. Write news tests in `$ROOT_BRANCH/tests/tests_bats/$NAME_OF_MODULE.bats`  
  exemple:  
  ```bash
  @test "Lexer: Testing for 'l'" {                            # <= Name of test  
  run ${BATS_TEST_DIRNAME}/../../$name_exec -t lexer "l"      # <= run shell  
  echo "ERROR:"                                               # <= display only when tests fail  
  echo "$name_exec OUTPUT   ->${lines[0]}"  
  echo "$name_exec EXPECTED -><l> = TOKEN_TYPE_WORD"  
  echo  
  [ "${lines[0]}" = "<l> = TOKEN_TYPE_WORD" ]                 # <= test conditon  
}
```
For more information about bats : [Github-bats](https://github.com/sstephenson/bats)  
  __(You can modify variable in `$ROOT_BRANCH/tests/tests_bats/test_helper.bats` exemple: "$name_exec")__

  2. Write line of command in create.txt
  the script tests.sh build tests form `$ROOT_BRANCH/tests/tests_bats/create.txt` for you.
 --------------  
  --------------
  ## Check Leaks with Valgrind :fire: :
  if you use -v or --valgrind command, the valgrind is run.  
    -  by default the tests fail if there is/are some leak(s) "definitely/indirectly lost" (ex: `./tests.sh -v -b A`)  
    -  by full    the tests fail if there is/are some leak(s) even leak(s) is/are still reachable (ex: `./tests.sh -v=full -b A`)  
    
   ### __IF Fail__  
   ```bash
    ✗ AST: Testing [SIMPLE] for NULL
   (from function `check_leaks_function' in file tests/tests_bats/test_helper.bash, line 55,
    in test file tests/tests_bats/ast.bats, line 16)
     `check_leaks_function ast' failed
   ERROR:
   42sh OUTPUT   ->AST NULL
   42sh EXPECTED ->AST NULL
   
   =======================================================================   # ERROR leaks are detected
   **[----- LEAKS DETECTED! -----]
   => check file log: [...]/valgrind_log/ast/TEST-1-MODULE.log               # A log file is create in valgrind_log/$MODULE/TEST-$NUMBER_OF_TESTS-$MODULE.log, you can cat it
   =======================================================================
   [-- STILL REACHABLE!! --]                                                 # The leaks are still reachable

   ```  
 ##### *There is no file.log if test don't fail :)*
 --------------
  ## Display:
  ```
  # = comment
  " = same
  [...] = skip
  ```
  ```bash
  ./tests/tests.sh -b A                                               # <= run script with all tests

##################################   
######## Tests mode: bats ########                                  # <= with option -b it is bats tests
##################################
 info: bin: Minishell find                                           #First check if exec exist

Checking command:                                                   #Second: check dependency
checking for "bats" ... ok                                          #         "
checking for "echo" ... ok                                          #         "
checking for "sh" ... ok                                            #         "
checking for "bash" ... ok                                          #         "
Done.

 ✓ bin exist and works or compil test #tests bats
 ✓ Lexer: Testing for NULL
 ✓ Lexer: Testing for ' '
 ✓ Lexer: Testing for 'l'
 ✓ Lexer: Testing for 'ls'

  [...]

 ✗ Parser: Testing for '<ls'                                          #Test fail
   (in test file tests/tests_bats/parser.bats, line 190)               #line,fle
     `[ "${lines[0]}" = "${okparser}" ]` failed                        #fail condition
   ERROR:                                                              #output error
   Minishell OUTPUT   ->Parser: Syntax error near '< or >'             #shell output
   Minishell EXPECTED ->Parser say OK                                  #test expected

  [...]

 - Parser: Testing TASKMASTER 'ls&' (skipped)                         #  skip test

75 tests, 8 failures, 6 skipped
```

