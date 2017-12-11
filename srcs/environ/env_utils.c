/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:03:02 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/04 09:41:24 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/env_utils.h>
#include <environ/modif_env.h>
#include <ftprintf.h>
#include <tools/tools.h>

/*
** @brief Prints all the vars (env or local)
**
** @param vars Vars to be printed (env or local)
** @param color When set to true, the colors are displayed for the vars.
*/

void		print_vars(t_array *vars, BOOL color)
{
	t_env	*e;
	size_t	i;

	i = 0;
	if (!vars || !vars->used)
		return ;
	while (i < vars->used)
	{
		e = (t_env *)array_get_at(vars, i);
		if (color)
			ft_printf("\033[94m%s\033[0m=%s\n", e->name, e->value);
		else
			ft_printf("%s=%s\n", e->name, e->value);
		i++;
	}
}

/*
** @brief Gets the env
**
** @return Returns a t_array containing the env
*/

t_array		*get_envs(void)
{
	static t_array	*e = NULL;

	if (!e && (e = array_create(sizeof(t_env))) == NULL)
		sh_exit_error("Environ: can't initialise environment variables");
	return (e);
}

/*
** @brief Gets the local var
** @return Returns a t_array containing the local vars
*/

t_array		*get_vars(void)
{
	static t_array	*e = NULL;

	if (!e && (e = array_create(sizeof(t_env))) == NULL)
		sh_exit_error("Variables: can't initialise variables");
	return (e);
}

/*
** @brief Clones two t_array vars
** @param vars source
** @param tmp destination
** @return Returns the cloned t_array
*/

t_array		*clone_vars(t_array *vars, t_array *tmp)
{
	t_env	*var;
	size_t	i;

	if (!vars)
		return (tmp);
	i = 0;
	while (i < vars->used)
	{
		var = (t_env *)array_get_at(vars, i);
		if (var)
			set_var(tmp, var->name, var->value, var->is_export);
		i++;
	}
	return (tmp);
}
