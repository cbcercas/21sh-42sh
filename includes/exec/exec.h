/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/20 13:34:11 by guiforge         ###   ########.fr       */
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

#define START 1
#define END 0

/*int	sh_command(t_sh_data *data, char **command);
char **sh_get_command(char *input);
int	sh_exec_command(char **command);*/

int   sh_exec(t_sh_data *data, t_cmd *item);
int   sh_exec_builtin(t_sh_data *data, t_cmd *item);
int   sh_exec_simple(t_sh_data *data, t_cmd *item);
int   sh_exec_pipe(t_sh_data *data, t_btree *ast);

int   sh_process_pipe(t_sh_data *data, t_btree *ast);

int   sh_process_exec(t_sh_data *data, t_btree *ast);

pid_t  sh_fork(void);

#endif
