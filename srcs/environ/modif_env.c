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
#include <environ/getter_env.h>
#include <logger.h>

/*
** @brief Changes or creates a var with name `name` and value `value`
**
** @param vars The t_array containing the vars
** @param name The name to create/modify
** @param value The value to add/modify
** @param is_export if is tmp var is_export is false, true otherwise
**
** @return Returns the new t_env
*/

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

/*
** @brief Deletes a var from the given t_env
** @param vars The t_array to delete from
** @param name The name to be removed
** @return The new t_env without the var
*/

t_env	*del_var(t_array *vars, char const *name)
{
	t_env		*e;
	size_t		i;

	i = 0;
	e = NULL;
	if (!vars)
		return (NULL);
	while (i < vars->used)
	{
		e = (t_env *)array_get_at(vars, i);
		if (ft_strequ(e->name, name) && e->name)
			break ;
		i++;
	}
	if (i >= vars->used)
		log_warn("Environ: can't find \"%s\" variables ", name);
	else if (e)
	{
		ft_strdel(&e->name);
		ft_strdel(&e->value);
		array_remove_at(vars, i, NULL);
	}
	return (NULL);
}
