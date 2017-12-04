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

/*
** @brief The function called when setenv is executed
** @param data The shell data used throughout the program
** @param argv The args passed to echo
**
** @return Returns the ret value of echo
*/

int		sh_builtin_setenv(t_sh_data *data, char **args)
{
	int		i;
	char	*name;
	char	*value;

	(void)data;
	if (!args || !args[0] || !args[1] || !ft_strchr(args[1], '='))
	{
		sh_help_setenv();
		return (1);
	}
	i = 1;
	while (args[i] && ft_strchr(args[i], '='))
	{
		name = split_var_name(args[i]);
		set_var(get_envs(), name, (value = split_var_value(args[i])),
				true);
		ft_strdel(&name);
		ft_strdel(&value);
		log_dbg1("Environ set for %s", args[i]);
		i++;
	}
	return (0);
}

/*
** @brief The function called when unsetenv is executed
** @param data The shell data used throughout the program
** @param argv The args passed to echo
**
** @return Returns the ret value of echo
*/

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
		del_var(get_envs(), args[i]);
		log_dbg1("Deleted env entry for %s", args[i]);
		i++;
	}
	return (0);
}
