//
// Created by Jules LASNE on 4/3/17.
//

#ifndef MINISHELL_GRAMMAR_H
#define MINISHELL_GRAMMAR_H

t_bool gr_complete_cmd(t_array *tokens, size_t where);

t_bool gr_list(t_array *tokens, size_t where);

t_bool gr_separator(t_array *tokens, size_t where);

t_bool gr_separator_op(t_array *tokens, size_t where);

t_bool gr_and_or(t_array *tokens, size_t where);

//t_bool gr_(t_array *tokens, size_t where);


#endif //MINISHELL_GRAMMAR_H
