/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/24 22:00:49 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/command.h>

int	ms_command(t_ms_data *data, t_command *command)
{
	t_builtin	fn;
	if ((fn = ms_is_builtin(data->builtins, command->command)))
		return(fn(data, command->args));
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