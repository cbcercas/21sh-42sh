/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:26:04 by jlasne            #+#    #+#             */
/*   Updated: 2017/06/19 14:26:46 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/modif_env.h>

t_env *set_var(t_array *vars, char const *name, char const *value)
{
	t_array	*envs;
	t_env	*env;

	if ((env = get_var(vars, name)) != NULL)
	{
		ft_strdel(&env->value);
		env->value = ft_strdup(value);
	}
	else
	{
		envs = get_envs();
		if ((env = var_new(ft_strdup(name), ft_strdup(value))) != NULL)
		{
			array_push(envs, (void *)env);
			ft_memdel((void**)&env);
		}
	}
	return (NULL);
}

t_env *del_var(t_array *vars, char const *name)
{
	t_env		*e;
	size_t		i;

	i = 0;
	while (i < vars->used)
	{
		e = (t_env *)array_get_at(vars, i);
		if (ft_strequ(e->name, name) && e->name)
			break ;
		i++;
	}
	if (i >= vars->used)
		log_warn("Environ: can't find \"%s\" variables ", name);
	else
		vars = array_remove_at(vars, i, NULL);
	return (NULL);
}
