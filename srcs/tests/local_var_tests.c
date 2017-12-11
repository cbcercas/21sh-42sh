/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_var_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/sh_tests.h>

/*
** @brief Tests the set module for the local vars
**
** @param av Arguments passed to the module
*/

void	testing_local_vars_set(char *const *av)
{
	int		i;

	i = 4;
	while (av[i] && ft_strchr(av[i], '='))
	{
		set_var(get_envs(), split_var_name(av[i]), split_var_value(av[i]),
				true);
		i++;
	}
}

/*
** @brief Tests the del module for the local vars
**
** @param av Arguments passed to the module
*/

void	testing_local_vars_del(char *const *av)
{
	int		i;

	i = 4;
	while (av[i])
	{
		del_var(get_envs(), av[i]);
		i++;
	}
}

/*
** @brief Main function to test the local var module
**
** @param av The arguments passed to the local var testing module
** @param environ The current environ
*/

void	testing_local_vars(char *const *av, char **environ)
{
	init_environ(environ);
	init_local_var();
	if (av[0] && (ft_strequ(av[0], "set")))
		testing_local_vars_set(av);
	else if (av[0] && (ft_strequ(av[0], "del")))
		testing_local_vars_del(av);
	print_vars(get_envs(), false);
	print_vars(get_vars(), false);
	exit(0);
}
