/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_environ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:04:48 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/02 14:31:58 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_env.h>
#include <builtins/help.h>

int		sh_builtin_setenv(t_sh_data *data, char **args)
{
	int i;

	(void)data;
	if (!args || !args[0] || !args[1] || !ft_strchr(args[1], '='))
	{
		sh_help_setenv();
		return (1);
	}
	i = 1;
	while (args[i] && ft_strchr(args[i], '='))
	{
		sh_setenv(split_env_name(args[i]), split_env_value(args[i]));
		i++;
	}
	return (0);
}

int		sh_builtin_unsetenv(t_sh_data *data, char **args)
{
	int		i;

	(void)data;
	if (!args || !args[0] || !args[1])
	{
		sh_help_unsetenv();
		return (1);
	}
	i = 1;
	while (args[i])
	{
		sh_delenv(args[i]);
		i++;
	}
	return (0);
}
