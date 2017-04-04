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

t_bool gr_linebreak(t_array *tokens, size_t where);

t_bool gr_newline_list(t_array *tokens, size_t where);

t_bool gr_pipeline(t_array *tokens, size_t where);

t_bool gr_check_or_if(t_array *tokens, size_t where);

t_bool gr_check_and_if(t_array *tokens, size_t where);

t_bool gr_pipe_sequence(t_array *tokens, size_t where);

t_bool gr_simple_command(t_array *tokens, size_t where);

t_bool	gr_command(t_array *tokens, size_t where);

t_bool gr_cmd_suffix(t_array *tokens, size_t where);

t_bool gr_cmd_prefix(t_array *tokens, size_t where);

t_bool gr_cmd_word(t_array *tokens, size_t where);

t_bool gr_cmd_name(t_array *tokens, size_t where);

t_bool gr_io_redirect(t_array *tokens, size_t where);

t_bool gr_io_file(t_array *tokens, size_t where);

t_bool gr_io_here(t_array *tokens, size_t where);

t_bool gr_filename(t_array *tokens, size_t where);

t_bool gr_here_end(t_array *tokens, size_t where);
//t_bool gr_(t_array *tokens, size_t where);


#endif //MINISHELL_GRAMMAR_H
