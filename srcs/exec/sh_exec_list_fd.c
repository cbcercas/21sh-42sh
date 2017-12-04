/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 14:01:25 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/15 18:31:43 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

/*
** @brief manage fd from list, do dup
** @param fds list of fd
** @return true if everything is ok, false otherwise
*/

BOOL	exec_list_fd_dup(t_list **fds)
{
	int		cnt;

	cnt = 0;
	while (cnt < FD_SETSIZE)
	{
		if (fds[cnt] && (dup2((int)fds[cnt]->content_size, cnt) == -1))
		{
			log_fatal("ERROR: file: %s dup2 cnt %d", __FILE__, cnt);
			return (false);
		}
		cnt++;
	}
	return (true);
}

/*
** @brief destroy all list
** @param fds list of fd
** @return
*/

void	exec_list_fd_destroy(t_list **fds)
{
	int		cnt;

	cnt = 0;
	while (cnt < FD_SETSIZE + 1)
	{
		if (fds[cnt])
			ft_lstdel(&fds[cnt], &exec_list_nothing);
		cnt++;
	}
}

/*
** @brief manage fd from list, do close
** @param fds list of fd
** @return
*/

void	exec_list_fd_close(t_list **fds)
{
	t_list		*tmp;

	tmp = fds[CLOSE];
	log_info("EXEC exec_list_fd_close");
	while (tmp)
	{
		log_dbg1("close = %d", tmp->content_size);
		close((int)tmp->content_size);
		tmp = tmp->next;
	}
}

/*
** @brief close all fd from list
** @param fds list of fd
** @return
*/

void	exec_list_fd_all_close(t_list **fds)
{
	int		cnt;

	cnt = 0;
	log_info("EXEC exec_list_fd_all_close");
	while (cnt < FD_SETSIZE)
	{
		if (fds[cnt] && (int)fds[cnt]->content_size > STDERR_FILENO)
		{
			close((int)fds[cnt]->content_size);
			log_info("close %d", (int)fds[cnt]->content_size);
		}
		cnt++;
	}
}
