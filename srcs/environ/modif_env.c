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

#include <environ/env_list_utils.h>
#include <array/array.h>
#include <environ/getter_env.h>
#include <logger.h>

t_env	*set_var(t_array *vars, char const *name, char const *value,
				BOOL is_export)
{
	t_env	*env;

	if ((env = get_var(vars, name)) != NULL)
	{
		ft_strdel(&env->value);
		env->value = ft_strdup(value);
	}
	else
	{
		if ((env = var_new(ft_strdup(name), ft_strdup(value),
						is_export)) != NULL)
		{
			array_push(vars, (void *)env);
			ft_memdel((void**)&env);
		}
	}
	return (NULL);
}

t_env	*del_var(t_array *vars, char const *name)
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
	{
		ft_strdel(&e->name);
		ft_strdel(&e->value);
		array_remove_at(vars, i, NULL);
	}
	return (NULL);
}
