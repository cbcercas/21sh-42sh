/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_backup_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiforge <guiforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:43:55 by guiforge          #+#    #+#             */
/*   Updated: 2017/11/24 16:43:57 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

/*
** @brief          create list of backup fd
**
** @param  fds     the list of fd
** @param  backup  the list of fd backup
**
** @return         false if everything is ok, false otherwise
*/

BOOL		sh_exec_create_backup_fd(t_array *fds, BOOL close)
{
	size_t		cnt;
	t_redir_fd	*fd;
	struct stat buff;

	cnt = 0;
	log_info("EXEC: sh_exec_create_backup");
	while (cnt < fds->used)
	{
		fd = (t_redir_fd *)array_get_at(fds, cnt);
		if (fd->close == close && fstat(fd->old_fd, &buff))
			fd->backup = -2;
		else if (fd->close == close && ((fd->backup = dup(fd->old_fd)) == -1))
		{
			ft_dprintf(STDERR_FILENO, "%s: Error dup(%d)\n", PROGNAME, fd->old_fd);
			return (false);
		}
		else if (fd->close == close)
			log_dbg1("%d : backup = dup(%d)", fd->old_fd, fd->backup);
		cnt++;
	}
	return (true);
}

/*
** @brief          restore fd from fd backup
**
** @param  backup  the list of fd backup
**
** @return         false if everything is ok, false otherwise
*/

BOOL		sh_exec_restore_fd(t_array *fds)
{
	size_t		cnt;
	t_redir_fd	*fd;

	cnt = 0;
	log_info("EXEC: sh_exec_restore_fd");
	while (cnt < fds->used)
	{
		fd = (t_redir_fd *)array_get_at(fds, cnt);
		if (fd && fd->backup >= 0)
		{
			if (dup2(fd->backup, fd->old_fd) == -1)
			{
				ft_dprintf(STDERR_FILENO, "%s: Error dup2\n", PROGNAME);
				log_fatal("Error dup2(%d, %d)",fd->backup, fd->old_fd);
				return (false);
			}
			log_info("RESTORE = %d => %d", fd->old_fd, fd->backup);
			close(fd->backup);
		}
		else if (fd && fd->backup == -2)
			close(fd->old_fd);
		cnt++;
	}
	return (true);
}