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

/*
** @brief Gets a variable from its name
** @param vars The t_array containing the vars
** @param name The name you want to get the var
** @return Returns the var
*/

t_env	*get_var(t_array *vars, const char *name)
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

/*
** @brief Gets the value of a var
** @param vars The t_array containing all the vars
** @param name The name you want to get the value from
** @return Returns the value of `name`
*/

char	*get_var_value(t_array *vars, const char *name)
{
	t_env	*e;

	if ((e = get_var(vars, name)) != NULL)
		return (e->value);
	return (NULL);
}
