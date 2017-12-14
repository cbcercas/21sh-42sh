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

void	sh_exec_new_redir_fd(t_array *fds, int old, int new, BOOL close)
{
	t_redir_fd	fd;

	if (!fds)
		return ;
	fd.new_fd = new;
	fd.old_fd = old;
	fd.close = close;
	fd.backup = -1;
	array_push(fds, (void *)&fd);
}

/*
** @brief manage fd from list, do dup
** @param fds list of fd
** @return true if everything is ok, false otherwise
*/

BOOL sh_exec_manage_fd(t_array *fds, BOOL is_close)
{
	size_t		cnt;
	t_redir_fd	*fd;

	cnt = 0;
	while (cnt < fds->used)
	{
		fd = (t_redir_fd *)array_get_at(fds, cnt);
		if (fd->close)
			close(fd->old_fd);
		else if (!is_close && (dup2(fd->new_fd, fd->old_fd) == -1))
		{
			log_fatal("ERROR: file: %s dup2(%d, %d)", __FILE__, fd->new_fd, fd->old_fd);
			return (false);
		}
		cnt++;
	}
	return (true);
}

/*
** @brief close all fd from list
** @param fds list of fd
** @return
*/

void	exec_array_fd_all_close(t_array *fds)
{
	size_t		cnt;
	t_redir_fd	*fd;

	cnt = 0;
	while (cnt < fds->used)
	{
		fd = (t_redir_fd *)array_get_at(fds, cnt);
		if (!fd->close && fd->new_fd > STDERR_FILENO)
		{
			log_dbg1("CLOSE = %d", fd->old_fd);
			close(fd->new_fd);
		}
		cnt++;
	}
}
