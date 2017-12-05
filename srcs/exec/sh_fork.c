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

/*
** @brief   call fork and store pid in pid list
** @param  type     the type of fork
**
** @return same return of fork
*/

pid_t	sh_fork(t_pid_type type)
{
	pid_t	pid;
	t_pids	save_pid;

	if ((pid = fork()) == -1)
		sh_exit_error("Fork error");
	if (pid > 0)
	{
		save_pid.pid = pid;
		save_pid.type = type;
		log_dbg1("SH_FORK: Save pid_child %d", pid);
		array_push(get_pids_child(), &save_pid);
	}
	return (pid);
}
