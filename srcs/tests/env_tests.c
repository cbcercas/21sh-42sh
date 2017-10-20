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

#include <libft.h>
#include <environ/modif_env.h>
#include <environ/builtin_env_utils.h>
#include <environ/environ.h>


void	sh_testing_env_set(char *const *av)
{
	int		i;

	i = 4;
	while(av[i] && ft_strchr(av[i], '='))
	{
		set_var(get_envs(), split_var_name(av[i]), split_var_value(av[i]));
		i++;
	}
}

void	sh_testing_env_del(char *const *av)
{
	int		i;

	i = 4;
	while(av[i])
	{
		del_var(get_envs(), av[i]);
		i++;
	}
}

void sh_testing_env(char *const *av, char **environ)
{
	init_environ(environ);
	if (av[3] && (ft_strequ(av[3], "set")))
		sh_testing_env_set(av);
	else if (av[3] && (ft_strequ(av[3], "del")))
		sh_testing_env_del(av);
	print_vars(get_envs());
	exit(0);
}
