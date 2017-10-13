/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/13 19:45:13 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

/*# include <unistd.h>
# include <core/init.h>
# include <core/data.h>
# include <sys/wait.h>*/
# include <libft.h>
# include <btree/ft_btree.h>
# include <lexer/lexer.h>
# include <ast/ast.h>
# include <builtins/builtins_utils.h>
# include <exec/check_path.h>
# include <signals/signals.h>
# include <tools/tools.h>
# include <ft_secu_malloc/ft_secu_malloc.h>
# include <core/prompt.h>

#define START 1
#define END 0

void	exec_list_push(t_list **head, size_t fd);
int		exec_exec(t_sh_data *data, t_btree *ast);
int   sh_exec(t_sh_data *data, t_cmd *item, t_list *fds[4]);
int   sh_exec_builtin(t_sh_data *data, t_cmd *item);
int   sh_exec_simple(t_sh_data *data, t_cmd *item, t_list *fds[4]);
int   sh_exec_pipe(t_sh_data *data, t_btree *ast, int *fd, BOOL isout);
int   sh_process_pipe(t_sh_data *data, t_btree *ast);

int   sh_exec_greatand(t_sh_data *data, t_btree *ast, t_cmd *item);
int   sh_exec_redir(t_sh_data *data, t_btree *ast, t_cmd *item);

int   sh_process_exec(t_sh_data *data, t_btree *ast, t_list *fds[4]);

int   sh_heradoc(t_btree *ast, t_cmd *item, int fd);

#endif
