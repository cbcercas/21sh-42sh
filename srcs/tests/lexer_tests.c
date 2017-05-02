//
// Created by Jules LASNE on 4/29/17.
//

#include <tests/lexer_tests.h>

void sh_testing_lexer(void)
{
    t_automaton	automaton;
    t_array		tokens;
    char		input[15] = "ls -l | cat -e";

    if (lexer_init(&tokens) == NULL)
        ft_printf("Error initialising tokens");
    if (automaton_init(&automaton) == NULL)
        ft_printf("Error Initialising automaton");
    if (lexer_lex(&tokens, &automaton, input))
        lexer_print_tokens(&tokens);
}