#!/bin/sh

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for NULL ******]"
echo
./Minishell -t lexer ""
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for ' ' *******]"
echo
./Minishell -t lexer " "
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'l' *******]"
echo
./Minishell -t lexer "l"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls' ******]"
echo
./Minishell -t lexer "ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[** Testing for '    ls    ' **]"
echo
./Minishell -t lexer "    ls    "
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[** Testing for '        ls' **]"
echo
./Minishell -t lexer "        ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[** Testing for 'ls        ' **]"
echo
./Minishell -t lexer "ls        "
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls -l' ***]"
echo
./Minishell -t lexer "ls -l"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[**** Testing for '    ls -l' *]"
echo
./Minishell -t lexer "    ls -l"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[**** Testing for 'ls -l    ' *]"
echo
./Minishell -t lexer "ls -l    "
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls-l' *******]"
echo
./Minishell -t lexer "ls-l"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls - l' **]"
echo
./Minishell -t lexer "ls - l"
echo
echo "[******* End of testing *******]"
echo "\n\n"


echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[ Testing for 'ls -l | cat -e' ]"
echo
./Minishell -t lexer "ls -l | cat -e"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[* Testing for 'ls -l|cat -e' *]"
echo
./Minishell -t lexer "ls -l|cat -e"
echo
echo "[******* End of testing *******]"
echo "\n\n"


echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[* Testing for 'ls -l| cat -e' ]"
echo
./Minishell -t lexer "ls -l| cat -e"
echo
echo "[******* End of testing *******]"
echo "\n\n"


echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[* Testing for 'ls -l |cat -e' ]"
echo
./Minishell -t lexer "ls -l |cat -e"
echo
echo "[******* End of testing *******]"
echo "\n\n"


echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls ; ls' *]"
echo
./Minishell -t lexer "ls ; ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"


echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls;ls' ***]"
echo
./Minishell -t lexer "ls;ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls ;ls' **]"
echo
./Minishell -t lexer "ls ;ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls; ls' **]"
echo
./Minishell -t lexer "ls; ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[***** Testing for 'ls || ls' *]"
echo
./Minishell -t lexer "ls || ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls||ls' **]"
echo
./Minishell -t lexer "ls||ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls ||ls' *]"
echo
./Minishell -t lexer "ls ||ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls|| ls' *]"
echo
./Minishell -t lexer "ls|| ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[*** Testing for 'ls && ls' ***]"
echo
./Minishell -t lexer "ls && ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls&&ls' **]"
echo
./Minishell -t lexer "ls&&ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls &&ls' *]"
echo
./Minishell -t lexer "ls &&ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls&& ls' *]"
echo
./Minishell -t lexer "ls&& ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls & ls' *]"
echo
./Minishell -t lexer "ls & ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls&ls' ***]"
echo
./Minishell -t lexer "ls& ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"

echo "[******************************]"
echo "[**** Testing lexer module ****]"
echo "[****** Testing for 'ls &ls' **]"
echo
./Minishell -t lexer "ls &ls"
echo
echo "[******* End of testing *******]"
echo "\n\n"