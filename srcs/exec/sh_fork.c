/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:22:25 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/29 13:24:09 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

pid_t sh_fork(t_pid_type type)
{
	pid_t	pid;
	t_pids	save_pid;

	if ((pid = fork()) == -1)
		ft_putstr_fd("fork error\n", 2);
	if (pid > 0)
	{
		save_pid.pid = pid;
		log_dbg1("SH_FORK: Save pid_child %d", pid);
		array_push(get_pids_child(), &save_pid);
	}
  return (pid);
}
