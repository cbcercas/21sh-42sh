#!/bin/sh

cd ..
sh tests/resources/lexer/lexer.sh > tests/resources/lexer/lexer_tobetested.out
cd tests
diff -U3 ./resources/lexer/lexer_ok.out ./resources/lexer/lexer_tobetested.out