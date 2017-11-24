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

static BOOL	sh_exex_creat_backup_fd_error(t_list **fds, int cnt)
{
	ft_dprintf(STDERR_FILENO, "%s: Error dup", PROGNAME);
	if (fds[cnt])
		log_fatal("Error dup dup(%d)", (int)fds[cnt]->content_size);
	return (true);
}

BOOL	sh_exex_creat_backup_fd(t_list **backup, t_list **fds)
{
	int		cnt;
	int		fd_back;

	cnt = 0;
	log_info("EXEC: sh_exex_creat_backup_fd");
	while (cnt < FD_SETSIZE)
	{
		if (fds[cnt] && (fd_back = dup(cnt)) != -1)
		{
			exec_list_push(&backup[cnt], (size_t)fd_back);
			if((fd_back = dup(cnt)) != -1)
				exec_list_push(&backup[(int)fds[cnt]->content_size], (size_t)fd_back);
			else
				return (sh_exex_creat_backup_fd_error(fds, cnt));
		}
		else if (fds[cnt] && fd_back == -1)
			return (sh_exex_creat_backup_fd_error(fds, cnt));
		cnt++;
	}
	return (false);
}

BOOL	sh_exec_restore_fd(t_list **backup)
{
	int		cnt;
	t_list	*tmp;

	cnt = 0;
	log_info("EXEC: sh_exec_restore_fd");
	while (cnt < FD_SETSIZE)
	{
		if ((tmp = backup[cnt]))
			while (tmp)
			{
				if (dup2((int)tmp->content_size, cnt) == -1)
				{
					ft_dprintf(STDERR_FILENO, "%s: Error dup", PROGNAME);
					log_fatal("Error dup dup(%d, %d)",(int)tmp->content_size, cnt);
					return (true);
				}
				log_info("RESTORE = %d => %d", cnt, (int)tmp->content_size);
				close((int)tmp->content_size);
				tmp = tmp->next;
			}
		if (backup[cnt])
			ft_lstdel(&backup[cnt], &exec_list_nothing);
		cnt++;
	}
	return(false);
}

BOOL	sh_exex_creat_backup_fd_close(t_list **backup, t_list **fds)
{
	int		fd_back;
	t_list	*tmp;

	log_info("EXEC: sh_exex_creat_backup_fd_close");
	tmp = fds[CLOSE];
	while (tmp)
	{
		if ((fd_back = dup((int)tmp->content_size)) != -1)
			exec_list_push(&backup[(int)tmp->content_size], (size_t)fd_back);
		else
			return (sh_exex_creat_backup_fd_error(fds, (int)tmp->content_size));
		tmp = tmp->next;
	}
	return (false);
}