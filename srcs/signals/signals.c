/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:16:16 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/22 08:05:32 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals/signals.h>

/*
** @brief Initializes all the signals from 1 to 32
**
** @param handler The handler per signal
*/

void	init_signals(void *handler)
{
	int					i;
	struct sigaction	act;

	i = 0;
	if (!handler)
		return ;
	while (++i <= 31)
	{
		if (i == SIGKILL || i == SIGSTOP)
			continue ;
		if (sigaction(i, NULL, &act) < 0)
			log_warn("Signal: can't change handler signal: %d", i);
		if (act.sa_handler == SIG_IGN)
			continue ;
		ft_bzero(&act.sa_mask, sizeof(act.sa_mask));
		act.sa_flags = SA_RESTART;
		if (i == SIGTSTP || i == SIGCONT || i == SIGIO)
			act.sa_handler = SIG_IGN;
		else
			act.sa_handler = handler;
		if (sigaction(i, &act, NULL) == -1)
			log_warn("Signal: can't change handler signal: %d", i);
	}
	log_info("Signal: Init finish");
}

/*
** @brief Waits for a process to finish
**
** @param pid The pid to wait for
** @param wait_flag TODO
**
** @return Returns the exit status
*/

int		sh_wait(pid_t pid, int wait_flag)
{
	int		status;
	pid_t	pid_child;

	status = 0;
	pid_child = waitpid(pid, &status, wait_flag);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			ft_dprintf(STDERR_FILENO, "[1]    %d segmentation fault (core "
					"dumped)  %s\n", pid_child, sh_history_get_at(-1));
		else if (WTERMSIG(status) == SIGBUS)
			ft_dprintf(STDERR_FILENO, "[1]    %d bus error  %s\n", pid_child,
					sh_history_get_at(-1));
		return (status);
	}
	if (wait_flag != WUNTRACED && !WSTOPSIG(status))
		remove_pid_child(pid);
	return (status);
}

/*
** @brief TODO
** @return TODO
*/

BOOL	signals(int sig, void (*handler)(int))
{
	struct sigaction	act;

	if (sigaction(sig, NULL, &act) < 0)
		return (true);
	act.sa_handler = handler;
	if (sigaction(sig, &act, NULL) == -1)
		return (true);
	return (false);
}

BOOL	ignore_sigwinch(void)
{
	return (signals(SIGWINCH, SIG_IGN));
}

BOOL	restore_sigwinch(void)
{
	return (signals(SIGWINCH, &signals_handler));
}
