/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:20:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/20 12:51:49 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>

t_array	*sh_init_environ(char **environ)
{
	t_array	*envs;
	t_env	*env;

	if ((envs = sh_get_envs()) != NULL)
	{
		while (*environ)
		{
			if ((env = env_new(split_env_name(*environ), \
							split_env_value(*environ))) != NULL)
			{
				array_push(envs, (void *)env);
				ft_memdel((void **)&env);
			}
			environ++;
		}
	}
	return (envs);
}

char	**sh_tenv_to_tab(void)
{
	t_array	*envs;
	t_env	*env;
	char	**env_tab;
	size_t	i;

	envs = sh_get_envs();
	if (!envs)
		return (NULL);
	env_tab = ft_memalloc(sizeof(*env_tab) * (envs->used + 2));
	i = 0;
	while (i < envs->used)
	{
		if (!(env = (t_env *)array_get_at(envs, i)))
			return (NULL);
		env_tab[i] = ft_strjoin(env->name, "=");
		env_tab[i] = ft_strjoincl(env_tab[i], env->value, 1);
		i++;
	}
	env_tab[i] = NULL;
	return (env_tab);
}
