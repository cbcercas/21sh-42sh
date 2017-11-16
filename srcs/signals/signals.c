/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:16:16 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/11 15:39:25 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals/signals.h>
#include <wait.h>

/*
** @brief Initializes all the signals from 1 to 32
**
** @param handler The handler per signal
*/

void    init_signals(void *handler)
{
	int		i;

	i = 1;
	if (!handler)
		return ;
	while (i++ < 32)
		if(i != 17 && signal(i, handler) == SIG_ERR)
			log_warn("Signal:%d no catch", i);
	log_info("Signal: Init success");
}

/*
** @brief Waits for a process to finish (?TODO)
**
** @param pid TODO
** @param wait_flag TODO
**
** @return Returns the exit status
*/

int sh_wait(pid_t pid, int wait_flag)
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
	if (wait_flag != WUNTRACED)
		remove_pid_child(pid);
	return (status);
}

/*
** @brief TODO
** @return TODO
*/

BOOL	*is_in_pipe(void)
{
	static BOOL		stop = true;
	return (&stop);
}