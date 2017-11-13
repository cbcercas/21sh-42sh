
#ifndef SIGNALS_H
# define SIGNALS_H

#include <signal.h>
#include <libft.h>

void    init_signals(void *handler);
void    signals_handler(int sig);
int sh_wait(pid_t pid, int wait_flag);
void	signals_sigwinch();

pid_t get_pid_child(pid_t pid_op);
t_array		*get_pids_child(void);
int		kill_childs(int sig);
void	remove_pid_child(int pid_child);
void	remove_useless(void);

BOOL	*get_stop(void);

#endif
