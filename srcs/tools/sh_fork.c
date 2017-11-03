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

# include <tools/tools.h>
# include <signals/signals.h>

pid_t  sh_fork(void)
{
	pid_t	pid;

	if ((pid = fork()) == -1)
		ft_putstr_fd("fork error\n", 2);
	if (pid > 0)
	{
		log_dbg1("SH_FORK: Save pid_child %d", pid);
		array_push(get_pids_child(), &pid);
	}
  return (pid);
}
