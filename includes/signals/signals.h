/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

#include <ftprintf.h>
#include <logger.h>
#include <signal.h>
#include <history/history.h>
#include <stdio.h>
#include <environ/env_utils.h>
#include <environ/getter_env.h>
#include <core/tcaps.h>
#include <core/prompt.h>
#include <builtins/builtin_exit.h>

typedef enum e_pid_type		t_pid_type;


/*
** @file   signals.h
**
** @brief  Function prototypes for the signal handler
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @enum e_pid_type
**
** @brief TODO
*/

enum	e_pid_type
{
	E_PID_NONE = 100,
	E_PID_SHELL = 101,
	E_PID_CMD = 102,
	E_PID_HERE = 103,
	E_PID_PIPE = 104,
	E_PID_REDIR = 105
};

/*
** @struct s_pids
**
** @brief TODO
*/

typedef struct		s_pids
{
	t_pid_type		type;
	pid_t			pid;
}					t_pids;

/*
** @file signals.c
**
** @brief Functions to initialize the signals
*/

void init_signals(void *handler);
int sh_wait(pid_t pid, int wait_flag);
BOOL	*is_in_pipe(void);

/*
** @file signals_handler.c
**
** @brief Functions to handle the signals
*/

void    signals_handler(int sig);
void signals_sigwinch(void);

BOOL signals(int sig, void (*handler)(int));
BOOL restore_sigwinch(void);
BOOL ignore_sigwinch(void);

/*
** @file get_pid_childs.c
**
** @brief Functions to handle the pids and the child processes
*/

pid_t get_pid_child(pid_t pid_op);
t_array		*get_pids_child(void);
void	remove_pid_child(int pid_child);
void	remove_useless(void);
int		kill_childs(int sig);

//void	send_kill_except(int sig, t_pid_type except);
//void	send_kill_only(int sig, t_pid_type only);
//BOOL	exist_pid_type(t_pid_type type);

#endif
