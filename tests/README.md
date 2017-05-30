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
  1. __-s [module]:__  
    It is option for "normal" tests with shell script, based on diff command. tests.sh call the scripts `$ROOT_BRANCH/tests/tests_module/test_$NAME_OF_MODULE.sh`. In `$ROOT_BRANCH/tests/ressouces/parser/`, there are three directories:
        * tests: with `tests[1-19].sh` script tests
        * expected: with `tests[1-19].expected` output expected
        * output: with `tests[1-19].output` output result of script tests    
__*(This option is no longer updated. By default, use the -b option)*__

  2. __-b [module]:__  
      -*lexer*  
      -*parser*  
      -*env* (it doesn't test the builtin env)  
  "-b" is option for tests with frameworks: bats.  
  __(You should install bats before)__ [Github-bats](https://github.com/sstephenson/bats)

  3. __-h :__  
   Display help.

  4. __without option__  
    __If__ ${TRAVIS_BRANCH} is set, then run script: `./test.sh -b ${TRAVIS_BRANCH}`  
    __If__ ${TRAVIS_BRANCH} = "master", then run script: `./test.sh -b all`  
    __Else__ exit 1;
 --------------
  ## Update/If you want add test:
  Write news tests in `$ROOT_BRANCH/tests/tests_bats/$NAME_OF_MODULE.bats`  
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

 --------------
  ## Display:
  ```
  # = comment
  " = same
  [...] = skip
  ```
  ```bash
  ./tests/tests.sh -b A                                               # <= run script

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
