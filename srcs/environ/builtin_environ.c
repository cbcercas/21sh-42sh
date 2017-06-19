/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_environ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:04:48 by jlasne            #+#    #+#             */
/*   Updated: 2017/06/19 14:05:44 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/builtin_env.h>

int		sh_builtin_setenv(t_sh_data *data, char **args)
{
	int i;

	(void)data;
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
	i = 1;
	while (args[i])
	{
		sh_delenv(args[i]);
		i++;
	}
	return (0);
}

int		sh_builtin_env(t_sh_data *data, char **args)
{
	(void)data;
	(void)args;
	return (0);
}
