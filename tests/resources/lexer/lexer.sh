#!/bin/sh

name_of_exec=$1

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for NULL ******]"
echo
./$name_of_exec -t lexer ""
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for ' ' *******]"
echo
./$name_of_exec -t lexer " "
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'l' *******]"
echo
./$name_of_exec -t lexer "l"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls' ******]"
echo
./$name_of_exec -t lexer "ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[** Testing for '    ls    ' **]"
echo
./$name_of_exec -t lexer "    ls    "
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[** Testing for '        ls' **]"
echo
./$name_of_exec -t lexer "        ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[** Testing for 'ls        ' **]"
echo
./$name_of_exec -t lexer "ls        "
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls -l' ***]"
echo
./$name_of_exec -t lexer "ls -l"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[**** Testing for '    ls -l' *]"
echo
./$name_of_exec -t lexer "    ls -l"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[**** Testing for 'ls -l    ' *]"
echo
./$name_of_exec -t lexer "ls -l    "
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls-l' *******]"
echo
./$name_of_exec -t lexer "ls-l"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls - l' **]"
echo
./$name_of_exec -t lexer "ls - l"
echo
echo "[******* End of testing *******]"
echo "\n\n"


echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[ Testing for 'ls -l | cat -e' ]"
echo
./$name_of_exec -t lexer "ls -l | cat -e"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[* Testing for 'ls -l|cat -e' *]"
echo
./$name_of_exec -t lexer "ls -l|cat -e"
echo
echo "[******* End of testing *******]"
echo "\n\n"


echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[* Testing for 'ls -l| cat -e' ]"
echo
./$name_of_exec -t lexer "ls -l| cat -e"
echo
echo "[******* End of testing *******]"
echo "\n\n"


echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[* Testing for 'ls -l |cat -e' ]"
echo
./$name_of_exec -t lexer "ls -l |cat -e"
echo
echo "[******* End of testing *******]"
echo "\n\n"


echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls ; ls' *]"
echo
./$name_of_exec -t lexer "ls ; ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"


echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls;ls' ***]"
echo
./$name_of_exec -t lexer "ls;ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls ;ls' **]"
echo
./$name_of_exec -t lexer "ls ;ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls; ls' **]"
echo
./$name_of_exec -t lexer "ls; ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[***** Testing for 'ls || ls' *]"
echo
./$name_of_exec -t lexer "ls || ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls||ls' **]"
echo
./$name_of_exec -t lexer "ls||ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls ||ls' *]"
echo
./$name_of_exec -t lexer "ls ||ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls|| ls' *]"
echo
./$name_of_exec -t lexer "ls|| ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[*** Testing for 'ls && ls' ***]"
echo
./$name_of_exec -t lexer "ls && ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls&&ls' **]"
echo
./$name_of_exec -t lexer "ls&&ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls &&ls' *]"
echo
./$name_of_exec -t lexer "ls &&ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls&& ls' *]"
echo
./$name_of_exec -t lexer "ls&& ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls & ls' *]"
echo
./$name_of_exec -t lexer "ls & ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls&ls' ***]"
echo
./$name_of_exec -t lexer "ls& ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls &ls' **]"
echo
./$name_of_exec -t lexer "ls &ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"
