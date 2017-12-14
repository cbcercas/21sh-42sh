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
** @param  fds     The list of opened fds
**
** @return         result of builtin
*/

int	sh_exec_builtin(t_sh_data *data, t_cmd *item, t_array *fds)
{
	t_builtin	*builtin;

	if (!sh_exec_create_backup_fd(fds, false))
		return (*get_cmd_ret() = 1);
	builtin = get_builtin(item->av[0]);
	set_var(get_envs(), "_", item->av[0], true);
	sh_exec_manage_fd(fds, false);
	if (builtin)
		*get_cmd_ret() = builtin->fn(data, item->av);
	return (*get_cmd_ret());
}
