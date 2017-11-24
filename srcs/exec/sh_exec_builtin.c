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
	builtin = get_builtin(item->av[0]);
	set_var(get_envs(), "_", item->av[0], true);
	exec_list_fd_dup(fds);
	if (builtin)
		*get_cmd_ret() = builtin->fn(data, item->av);
	if (sh_exec_restore_fd(backup))
		return (*get_cmd_ret() = 1);
	return (*get_cmd_ret());
}