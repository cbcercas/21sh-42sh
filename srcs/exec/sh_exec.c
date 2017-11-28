/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:12:03 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/15 13:02:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

/*
** @brief Executes the parent process (?TODO)
**
** @param fds TODO
** @param path TODO
** @param pipe TODO
** @param pid TODO
**
** @return Returns the ret value based on success or not
*/

static int	sh_exec_parent(char *path, int pid)
{
	if (path && !*is_in_pipe())
		*get_cmd_ret() = sh_return_cmd(sh_wait(pid, 0));
	else if (path)
		*get_cmd_ret() = sh_return_cmd(sh_wait(pid, WUNTRACED));
	ft_strdel(&path);
	restore_sigwinch();
	return (*get_cmd_ret());
}

/*
** @brief          exec a system command
**
** @param  data    The data of shell
** @param  item    The item in AST
**
** @return         status set by wait
*/

static int	sh_exec(t_cmd *item, t_list **fds)
{
	char	*path;
	pid_t	pid;

	pid = -1;
	if ((path = get_filename(item->av[0])))
	{
		if ((pid = sh_fork(E_PID_CMD)) == -1)
			return (EXIT_FAILURE);
		ignore_sigwinch();
		set_var(get_envs(), "_", path, true);
		if (!pid)
		{
			signal_restore();
			exec_list_fd_dup(fds);
			execve(path, item->av, var_to_tab(get_envs()));
			ft_dprintf(2, "%s: error exec(): %s\n", PROGNAME, path);
			exit(EXIT_FAILURE);
		}
	}
	get_pid_child(pid);
	return (sh_exec_parent(path, pid));
}

/*
** @brief          call sh_exec_builtin or sh_exec
**
** @param  data    The data of shell
** @param  item    The item in AST
**
** @return         result of sh_exec_builtin or sh_exec
*/

int			sh_exec_simple(t_sh_data *data, t_cmd *item, t_list **fds)
{
	int		ret;
	t_list	*backup[FD_SETSIZE];
	int		cnt;

	cnt = 0;
	while (cnt < FD_SETSIZE)
		backup[cnt++] = NULL;
	ret = 1;
	log_info("EXEC: %s", item->av[0]);
	sh_exex_creat_backup_fd_close(backup, fds);
	exec_list_fd_close(fds);
	if (item && item->av && ft_strchr(item->av[0], '=') &&
			ft_strlen(item->av[0]) != 1)
		sh_exec_local_var(data, item, fds);
	else if (sh_is_builtin(item->av[0]))
		ret = sh_exec_builtin(data, item, fds);
	else
		ret = sh_exec(item, fds);
	exec_list_fd_all_close(fds);
	exec_list_fd_destroy(fds);
	sh_exec_restore_fd(backup);
	log_dbg3("EXEC: %s ret = %d", item->av[0], ret);
	return (ret);
}
