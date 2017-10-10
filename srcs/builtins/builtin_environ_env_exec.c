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

char	**sh_builtin_env_to_tab(t_array *envs)
{
	t_env	*env;
	char	**env_tab;
	size_t	i;

	if (!envs)
		return (NULL);
	env_tab = ft_memalloc(sizeof(*env_tab) * (envs->used + 2));
	i = 0;
	while (i < envs->used)
	{
		if (!(env = (t_env *)array_get_at(envs, i)))
			return (NULL);
		env_tab[i] = ft_strjoin(env->name, "=");
		env_tab[i] = ft_strjoincl(env_tab[i], env->value, 1);
		i++;
	}
	env_tab[i] = NULL;
	return (env_tab);
}

int		sh_builtin_env_exec(char **av, t_array *envs)
{
	char	*cmd;
	char	**envtab;
	pid_t	pid;

	if (!av || !av[0])
		return (0);
	envtab = sh_builtin_env_to_tab(envs);
	cmd = NULL;
	g_ret = 2;
	if ((cmd = get_filename(av[0])))
	{
		pid = sh_fork();
		if (pid == 0)
		{
			execve(cmd, av, envtab);
			exit(0);
		}
		else
			g_ret = sh_ret(wait_sh());
	}
	ft_strdel(&cmd);
	ft_strdblfree(envtab);
	envtab = NULL;
	return (g_ret);
}
