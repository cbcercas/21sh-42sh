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
#include <ast/ast.h>

int		sh_builtin_env_exec(char **av, t_array *envs)
{
	char	*cmd;
	char	**envtab;
	pid_t	pid;

	if (!av || !av[0])
		return (0);
	envtab = var_to_tab(envs);
	cmd = NULL;
	g_ret = 2;
	if ((cmd = get_filename(av[0])))
	{
		signal(SIGWINCH, SIG_IGN);
		pid = sh_fork();
		if (pid == 0)
		{
			execve(cmd, av, envtab);
			exit(0);
		}
		else
			g_ret = sh_ret(sh_wait(0, 0));
	}
	signal(SIGWINCH, signals_handler);
	ft_strdel(&cmd);
	ft_freetab(envtab, ft_tablen(envtab));
	return (g_ret);
}
