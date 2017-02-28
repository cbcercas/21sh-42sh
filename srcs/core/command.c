/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/26 15:07:45 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/command.h>

int	ms_command(t_ms_data *data, char **command)
{
	t_builtin_e	*e;
	char		**cmd;

	while (*command)
	{
		if ((e = ms_is_builtin(data->builtins, *command)))
		{
			if (e->fn(data, *command + e->len + 1))
				return (1);
		}
		else
		{
			if ((cmd = ms_get_command(*command)))
				ms_exec_command(cmd, data->env);
		}
		command++;
	}
	return (0);
}

char **ms_get_command(char *input)
{
	return (ft_strsplit(input, ' '));
}

int	ms_exec_command(char **command, const t_env *env)
{
	char	*cmd;
	char	**envtab;
	pid_t	pid;
	int		status;

	status = 0;
	envtab = ms_tenv_to_tab(env);
	if ((cmd = ms_check_path(command[0], env)))
	{
		if ((pid = fork()) == -1)
			ft_printf("fork error");
		else if (pid == 0)
		{
			execve(cmd, command, envtab);
			exit(0);
		}
		else
			wait(&status);
	}
	return (0);
}