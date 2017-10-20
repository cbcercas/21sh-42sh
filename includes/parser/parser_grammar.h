//
// Created by Jules LASNE on 5/23/17.
//

#ifndef MINISHELL_PARSER_GRAMMAR_H
#define MINISHELL_PARSER_GRAMMAR_H

# include <types/bool.h>
# include <array/array.h>

#define __FILENAME__ (ft_strrchr(__FILE__, '/') ? ft_strrchr(__FILE__, '/') + 1 : __FILE__)

BOOL check_double(t_array *tokens, size_t where);

BOOL check_last(t_array *tokens, size_t where);

BOOL check_first(t_array *tokens, size_t where);

BOOL check_double_semi(t_array *tokens, size_t where);

#endif //MINISHELL_PARSER_GRAMMAR_H
