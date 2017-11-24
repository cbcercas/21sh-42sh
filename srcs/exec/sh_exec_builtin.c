/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiforge <guiforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:36:49 by guiforge          #+#    #+#             */
/*   Updated: 2017/11/24 14:36:51 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

static BOOL	sh_exex_creat_backup_fd_error(t_list **fds, int cnt)
{
	ft_dprintf(STDERR_FILENO, "%s: Error dup", PROGNAME);
	log_fatal("Error dup dup(%d)", (int)fds[cnt]->content_size);
	return (true);
}

static BOOL	sh_exex_creat_backup_fd(t_list **backup, t_list **fds)
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

static BOOL	sh_exec_restore_fd(t_list **backup)
{
	int		cnt;

	cnt = 0;
	log_info("EXEC: sh_exec_restore_fd");
	while (cnt < FD_SETSIZE)
	{
		if (backup[cnt])
		{
			if (dup2((int)backup[cnt]->content_size, cnt) == -1)
			{
				ft_dprintf(STDERR_FILENO, "%s: Error dup", PROGNAME);
				log_fatal("Error dup dup(%d, %d)",(int)backup[cnt]->content_size, cnt);
				return (true);
			}
			log_info("RESTORE = %d => %d", cnt, (int)backup[cnt]->content_size);
			close((int)backup[cnt]->content_size);
		}
		cnt++;
	}
	return(false);
}
/*
** @brief          exec a builtin command
**
** @param  data    The data of shell
** @param  item    The item in AST
**
** @return         result of builtin
*/

int	sh_exec_builtin(t_sh_data *data, t_cmd *item, t_list **fds)
{
	t_builtin	*builtin;
	t_list	*backup[FD_SETSIZE];
	int		cnt;

	cnt = 0;
	while (cnt < FD_SETSIZE)
		backup[cnt++] = NULL;
	if (sh_exex_creat_backup_fd(backup, fds))
		return (*get_cmd_ret() = 1);
	exec_list_fd_close(fds);
	builtin = get_builtin(item->av[0]);
	set_var(get_envs(), "_", item->av[0], true);
	exec_list_fd_dup(fds);
	if (builtin)
		*get_cmd_ret() = builtin->fn(data, item->av);
	if (sh_exec_restore_fd(backup))
		return (*get_cmd_ret() = 1);
	return (*get_cmd_ret());
}