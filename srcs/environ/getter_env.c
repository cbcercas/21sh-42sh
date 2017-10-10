/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/19 14:24:31 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/getter_env.h>

t_env *get_var(t_array *vars, const char *name)
{
	t_env	*e;
	size_t	i;

	i = 0;
	while (i < vars->used)
	{
		e = (t_env *)array_get_at(vars, i);
		if (ft_strequ(e->name, name) && e->name)
			return (e);
		i++;
	}
	return (NULL);
}

char *get_var_value(t_array *vars, const char *name)
{
	t_env	*e;

	if ((e = get_var(vars, name)) != NULL)
		return (e->value);
	return (NULL);
}
