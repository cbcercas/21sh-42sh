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

#include <environ/builtin_env_utils.h>

void print_vars(t_array *vars)
{
	t_env	*e;
	size_t	i;

	i = 0;
	if (!vars || !vars->used)
		return ;
	while (i < vars->used)
	{
		e = (t_env *) array_get_at(vars, i);
		ft_printf("\033[94m%s\033[0m=%s\n", e->name, e->value);
		i++;
	}
}

t_array		*get_envs(void)
{
	static t_array	*e = NULL;

	if (e == NULL)
	{
		if ((e = array_create(sizeof(t_env))) == NULL)
		{
			log_fatal("Environ: can't initialise environment array");
			ft_dprintf(STDERR_FILENO, "Environ: can't initialise environment\
					variables\n");
			exit(1);
		}
	}
	return (e);
}

t_array		*get_vars(void)
{
	static t_array	*e = NULL;

	if (e == NULL)
	{
		if ((e = array_create(sizeof(t_env))) == NULL)
		{
			log_fatal("Variables: can't initialise variable array");
			ft_dprintf(STDERR_FILENO, "Variables: can't initialise variables\n");
			exit(1);
		}
	}
	return (e);
}

// TODO Check usage and remove it
void		sh_free_elem_env(t_env *env)
{
	if (!env)
		return ;
	if (env->value)
		free(env->value);
	if (env->name)
		free(env->name);
}

t_array			*clone_vars(t_array *vars, t_array *tmp)
{
	t_env	*var;
	size_t	i;

	if (!vars)
		return (tmp);
	i = 0;
	while (i < vars->used)
	{
		var = (t_env *)array_get_at(vars, i);
		if ((var = var_new(ft_strdup(var->name), ft_strdup(var->value), true))
				   != NULL)
		{
			array_push(tmp, (void *)var);
			ft_memdel((void **)&var);
		}
		i++;
	}
	return (tmp);
}
