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
#include <environ/env_list_utils.h>
#include <environ/env_utils.h>
#include <logger.h>
#include <environ/getter_env.h>
#include <environ/modif_env.h>

t_array		*init_environ(char **environ)
{
	t_array	*envs;
	t_env	*env;

	if ((envs = get_envs()) != NULL)
	{
		while (*environ)
		{
			if ((env = var_new(split_var_name(*environ),
							split_var_value(*environ), true)) != NULL)
			{
				array_push(envs, (void *)env);
				ft_memdel((void **)&env);
			}
			environ++;
		}
	}
	log_info("Environ initialized");
	return (envs);
}

t_array		*init_local_var(void)
{
	t_array	*vars;

	if ((vars = get_vars()) != NULL)
	{
		if (!get_var_value(get_envs(), "PATH"))
		{
			set_var(get_vars(), "PATH",
					"/sbin:/bin:</usr/sbin:/usr/bin:/usr/local/sbin:/usr/local"
							"/bin", true);
		}
	}
	log_info("Local variables initialized");
	return (vars);
}

char		**var_to_tab(t_array *vars)
{
	t_env	*env;
	char	**env_tab;
	size_t	i;

	if (!vars)
		return (NULL);
	env_tab = ft_memalloc(sizeof(*env_tab) * (vars->used + 2));
	i = 0;
	while (i < vars->used)
	{
		if (!(env = (t_env *)array_get_at(vars, i)))
			return (NULL);
		env_tab[i] = ft_strjoin(env->name, "=");
		env_tab[i] = ft_strjoincl(env_tab[i], env->value, 1);
		i++;
	}
	env_tab[i] = NULL;
	return (env_tab);
}
