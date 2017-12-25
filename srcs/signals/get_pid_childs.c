/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pid_childs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:16:16 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 14:33:52 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals/signals.h>

/*
** @brief Will get a pid's child
** @param pid_op The father's pid
** @return Returns the child's pid
*/

pid_t		get_pid_child(pid_t pid_op)
{
	static	pid_t		pid = 0;

	if (pid_op > 0)
		pid = pid_op;
	return (pid);
}

/*
** @brief Gets the pid t_array
**
** @return Returns the t_array containing the pids
*/

t_array		*get_pids_child(void)
{
	static t_array	*e = NULL;

	if (!e && (e = array_create(sizeof(t_pids))) == NULL)
		return (NULL);
	return (e);
}

/*
** @brief Kills all the child processes
**
** @param sig The signal
**
** @return Returns `EXIT_SUCCESS` if they are killed and `EXIT_FAILURE` if no
** childs to kill
*/

int			kill_childs(int sig)
{
	t_array		*e;

	e = get_pids_child();
	if (!e)
		return (EXIT_FAILURE);
	while (0 < e->used)
	{
		kill(((t_pids*)array_get_at(e, 0))->pid, sig);
		array_remove_at(e, 0, NULL);
	}
	return (EXIT_SUCCESS);
}

/*
** @brief Will remove the pid from the pid list
**
** @param pid_child Child's pid
*/

void		remove_pid_child(int pid_child)
{
	size_t		i;
	t_array		*e;

	i = 0;
	e = get_pids_child();
	if (!e)
		return ;
	while (i < e->used)
	{
		if (((t_pids*)array_get_at(e, 0))->pid == pid_child)
			break ;
		i++;
	}
	if (i >= e->used)
		log_warn("PID: can't find \"%d\" variables ", pid_child);
	else
	{
		log_dbg3("PID: remove pid : %d", pid_child);
		array_remove_at(e, i, NULL);
	}
}

/*
** @brief Kills all the useless pids
*/

void		remove_useless(void)
{
	size_t		i;
	t_array		*e;

	i = 0;
	e = get_pids_child();
	if (!e)
		return ;
	while (i < e->used)
	{
		if (kill(((t_pids*)array_get_at(e, 0))->pid, 0) == -1)
			array_remove_at(e, i, NULL);
		else
			i++;
	}
}
