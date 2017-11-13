/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/14 17:54:33 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <core/data.h>
# include <libft.h>
# include <btree/ft_btree.h>
# include <lexer/lexer.h>
# include <ast/ast.h>
# include <array/array.h>

#define START 1
#define END 0
#define CLOSE 3
#define PIPE_OUT 4
#define PIPE_IN 5

void	exec_list_push(t_list **head, size_t fd);
void	exec_list_nothing(void *no, size_t thing);
int		exec_exec(t_sh_data *data, t_btree *ast);
void	exec_list_pop(t_list **head);
int sh_exec_simple(t_sh_data *data, t_cmd *item, t_list **fds);
int sh_exec_pipe(t_sh_data *data, t_btree *ast, t_list **fds);

int
sh_exec_greatand(t_sh_data *data, t_btree *ast, t_list **fds);
int sh_exec_redir(t_sh_data *data, t_btree *ast, t_list **fds);

int
sh_process_exec(t_sh_data *data, t_btree *ast, t_list **fds);

int sh_heredoc(t_sh_data *data, t_btree *ast, t_list **fds);

BOOL	manage_create_pipe(int pipe[3][2], t_list *fds[5]);
BOOL	manage_dup2(int pipe[3][2], t_list *fds[5]);
void	manage_fds(int pipe[3][2], t_list *fds[5]);
BOOL	multi_close(int pipe[3][2], t_list *fds[5], BOOL pos);
void	manage_close(t_list *fds[5]);

void	exec_list_mouv(t_list **dest, t_list **src);
int		sh_exec_local_var(t_sh_data *data, t_cmd *item, t_list **fds);


#endif
