/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_environ_env_exec.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:21:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/02 14:35:12 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_env.h>

/*
** @brief Executes what is passed through env -i
** @param av The command to be executed and its args
** @param envs The env
** @return Returns the return value of the executed command
*/

int		sh_builtin_env_exec(char **av, t_array *envs)
{
	char	*cmd;
	char	**envtab;
	pid_t	pid;

	if (!av || !av[0])
		return (0);
	envtab = var_to_tab(envs);
	*get_cmd_ret() = 2;
	if ((cmd = get_filename(av[0])))
	{
		ignore_sigwinch();
		pid = sh_fork(E_PID_CMD);
		if (pid == 0)
		{
			execve(cmd, av, envtab);
			ft_dprintf(2, "%s: error exec(): %s\n", PROGNAME, cmd);
			exit(EXIT_FAILURE);
		}
		else
			*get_cmd_ret() = sh_return_cmd(sh_wait(0, 0));
	}
	restore_sigwinch();
	ft_strdel(&cmd);
	ft_freetab(envtab, ft_tablen(envtab));
	return (*get_cmd_ret());
}
