/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/15 13:30:01 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>

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

t_env	*sh_setenv(char const *name, char const *value)
{
	t_array	*envs;
	t_env	*env;

	if ((env = sh_getenv(name)) != NULL)
	{
		ft_strdel(&env->value);
		env->value = ft_strdup(value);
	}
	else
	{
		envs = sh_get_envs();
		if ((env = env_new(ft_strdup(name), ft_strdup(value))) != NULL)
		{
			array_push(envs, (void *)env);
			ft_memdel((void**)&env);
		}
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
