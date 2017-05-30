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

#include <tests/test.h>
#include <ftprintf.h>
#include <environ/environ.h>

void	sh_print_env()
{
	t_array	*envs;
	t_env	*e;
	size_t	i;

	envs = sh_get_envs();
	i = 0;
	while (i < envs->used)
	{
		e = (t_env *)array_get_at(envs, i);
		ft_printf("%s=%s\n", e->name, e->value);
		i++;
	}
}

void	sh_testing_env_set(char *const *av)
{
	int		i;

	i = 4;
	while(av[i] && ft_strchr(av[i], '='))
	{
		sh_setenv(split_env_name(av[i]), split_env_value(av[i]));
		i++;
	}
}

void	sh_testing_env_del(char *const *av)
{
	int		i;

	i = 4;
	while(av[i])
	{
		sh_delenv(av[i]);
		i++;
	}
}

void sh_testing_env(char *const *av)
{
	sh_init_environ();
	if (av[3] && (ft_strequ(av[3], "set")))
		sh_testing_env_set(av);
	else if (av[3] && (ft_strequ(av[3], "del")))
		sh_testing_env_del(av);
	sh_print_env();
	exit(0);
}
