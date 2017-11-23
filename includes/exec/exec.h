/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/21 14:21:21 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <signals/signals.h>
# include <ast/ast.h>
# include <environ/environ.h>
# include <builtins/builtin_utils.h>
# include <environ/modif_env.h>

# define START 1
# define END 0
# define CLOSE FD_SETSIZE
# define PIPE_OUT CLOSE + 1
# define PIPE_IN PIPE_OUT + 1

/*
** @file   exec.h
**
** @brief  Function prototypes for the exec
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file   exec_tlist.c
**
** @brief  Functions to execute the tlist (?TODO)
*/

void	exec_list_push(t_list **head, size_t fd);
void	exec_list_nothing(void *no, size_t thing);

/*
** @file   sh_process_exec.c
**
** @brief  Functions to process the exec
*/

int		exec_exec(t_sh_data *data, t_btree *ast);
int		sh_process_exec(t_sh_data *data, t_btree *ast, t_list **fds);

/*
** @file   sh_exec.c
**
** @brief  Functions for main exec handling
*/

int		sh_exec_simple(t_sh_data *data, t_cmd *item, t_list **fds);

/*
** @file sh_exec_pipe.c
**
** @brief Functions to exec pipes
*/

int		sh_exec_pipe(t_sh_data *data, t_btree *ast, t_list **fds);

/*
** @file   sh_exec_redir.c
**
** @brief  Functions to execute redirections
*/

int		sh_exec_redir(t_sh_data *data, t_btree *ast, t_list **fds);

/*
** @file   sh_exec_redir2.c
**
** @brief  Functions to execute greatand
*/

int		sh_exec_greatand(t_sh_data *data, t_btree *ast, t_list **fds);

/*
** @file   sh_exec_redir3.c
**
** @brief  Functions to execute greatand and dup (TODO)
*/

void	sh_exec_greatand_push_dup(int fd1, int fd2, t_cmd *item,
																t_list **fds);

/*
** @file   sh_heradoc.c
**
** @brief  Functions to execute heradoc
*/

int		sh_heredoc(t_sh_data *data, t_btree *ast, t_list **fds);

/*
** @file   sh_heredoc_input.c
**
** @brief  Functions to execute the input from heradoc
*/

void	mini_input(char *end, int pipe_fd);

/*
** @file   manage.c
**
** @brief  Functions to manage FDs etc
*/

BOOL	manage_create_pipe(int pipe[FD_SETSIZE + 3][2], t_list **fds);
BOOL	manage_dup2(int pipe[FD_SETSIZE + 3][2], t_list **fds);
void	manage_fds(int pipe[FD_SETSIZE + 3][2], t_list **fds);
BOOL	multi_close(int pipe[FD_SETSIZE + 3][2], t_list **fds, BOOL pos);
void	manage_close(t_list **fds);

//void	exec_list_mouv(t_list **dest, t_list **src);

/*
** @file   sh_exec_local_var.c
**
** @brief  Functions to execute the local vars
*/

int		sh_exec_local_var(t_sh_data *data, t_cmd *item, t_list **fds);

/*
** @file   sh_fork.c
**
** @brief  Functions to forks
*/

pid_t	sh_fork(t_pid_type type);

/*
** @file   sh_pipe.c
**
** @brief  Functions to execute pipes
*/

int		sh_pipe(int tube[2]);

/*
** @file   sh_open.c
**
** @brief  TODO
*/

int		sh_open_exec(t_btree *ast);
BOOL	check_fd(int fd);;

/*
** @file   sh_ret.c
**
** @brief  Functions to handle ret values
*/

int		sh_return_cmd(int status);

#endif
