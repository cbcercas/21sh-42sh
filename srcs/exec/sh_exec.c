/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:12:03 by gpouyat           #+#    #+#             */
/*   Updated: 2017/12/07 17:54:26 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

/*
** @brief Executes the parent process
**
** @param path is the absolute path of bin or NULL otherwise
** @param pid the pid of command or -1 otherwise
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
** @param  item    the struct of commande
** @param  fds     the list of fd
**
** @return         status set by wait
*/

static int	sh_exec(t_cmd *item, t_array *fds)
{
	char	*path;
	pid_t	pid;
	char	**vartab;

	pid = -1;
	if ((path = get_filename(item->av[0])))
	{
		if ((pid = sh_fork(E_PID_CMD)) == -1)
			return (EXIT_FAILURE);
		ignore_sigwinch();
		if (!pid)
		{
			set_var(get_envs(), "_", path, true);
			sh_exec_manage_fd(fds, false);
			execve(path, item->av, (vartab = var_to_tab(get_envs())));
			ft_dprintf(2, "%s: error exec(): %s\n", PROGNAME, path);
			if (vartab)
				ft_freetab(vartab, ft_tablen(vartab));
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
** @param  fds     The list of opened fds
**
** @return         result of sh_exec_builtin or sh_exec
*/

int			sh_exec_simple(t_sh_data *data, t_cmd *item, t_array *fds)
{
	int		ret;

	log_info("EXEC: %s", item->av[0]);
	sh_exec_create_backup_fd(fds, true);
	sh_exec_manage_fd(fds, true);
	if (item->av && item->av[0] && ft_strchr(item->av[0], '=') &&
			ft_strlen(item->av[0]) != 1)
		ret = sh_exec_local_var(data, item, fds);
	else if (sh_is_builtin(item->av[0]))
		ret = sh_exec_builtin(data, item, fds);
	else
		ret = sh_exec(item, fds);
	exec_array_fd_all_close(fds);
	sh_exec_restore_fd(fds);
	keep_status_fd_tty(false);
	array_reset(fds, NULL);
	log_dbg3("EXEC: %s ret = %d", item->av[0], ret);
	return (ret);
}
