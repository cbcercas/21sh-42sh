/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:27:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 18:44:57 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <test.h>
#include <ftprintf.h>
#include <environ/environ.h>
void sh_testing_env(void)
{
	t_array	*envs;
	t_env	*e;
	size_t	i;

	ft_printf("----Env Testing-----\n");
	sh_init_environ();
	envs = sh_get_envs();
	i = 0;
	while (i < envs->used)
	{
		e = (t_env *)array_get_at(envs, i);
		ft_printf("%s=%s\n", e->name, e->value);
		i++;
	}
	exit(0);
}