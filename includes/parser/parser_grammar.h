//
// Created by Jules LASNE on 5/23/17.
//

#ifndef MINISHELL_PARSER_GRAMMAR_H
#define MINISHELL_PARSER_GRAMMAR_H

# include <lexer/lexer.h>
# include <logger/logger.h>

t_bool check_double(t_array *tokens, size_t where);

t_bool check_last(t_array *tokens, size_t where);

t_bool check_first(t_array *tokens, size_t where);

t_bool check_double_semi(t_array *tokens, size_t where);

#endif //MINISHELL_PARSER_GRAMMAR_H
