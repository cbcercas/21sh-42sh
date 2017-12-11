/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:27:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/30 14:26:11 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/sh_tests.h>

/*
** @brief Function to test the set module for the env
**
** @param av The arguments passsed to the test module
*/

void	sh_testing_env_set(char *const *av)
{
	int		i;

	i = 1;
	while (av[i] && ft_strchr(av[i], '='))
	{
		set_var(get_envs(), split_var_name(av[i]), split_var_value(av[i]),
				true);
		i++;
	}
}

/*
** @brief Function to test the del function for the env
**
** @param av The arguments passsed to the test module
*/

void	sh_testing_env_del(char *const *av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		del_var(get_envs(), av[i]);
		i++;
	}
}

/*
** @brief Main funtion used to test the env module
**
** @param av The arguments passed to the test module
** @param environ The current environ
*/

void	sh_testing_env(char *const *av, char **environ)
{
	init_environ(environ);
	if (av[0] && (ft_strequ(av[0], "set")))
		sh_testing_env_set(av);
	else if (av[0] && (ft_strequ(av[0], "del")))
		sh_testing_env_del(av);
	print_vars(get_envs(), true);
	exit(0);
}
