/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/30 13:34:00 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/getter_env.h>

t_env	*sh_getenv(const char *name)
{
	t_array	*envs;
	t_env	*e;

	size_t i = 0;
	envs = sh_get_envs();
	while (i < envs->used)
	{
		e = (t_env *)array_get_at(envs, i);
		if (ft_strequ(e->name, name) && e->name)
			return (e);
		i++;
	}
	return (NULL);
}

char	*sh_getenv_value(const char *name)
{
	t_env	*e;
	if ((e = sh_getenv(name)) != NULL)
		return (e->value);
	return (NULL);
}