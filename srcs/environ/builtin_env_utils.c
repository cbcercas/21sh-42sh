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

void		sh_print_env(void)
{
	t_array	*envs;
	t_env	*e;
	size_t	i;

	envs = sh_get_envs();
	i = 0;
	while (i < envs->used)
	{
		e = (t_env *)array_get_at(envs, i);
		ft_printf("\033[94m%s\033[0m=%s\n", e->name, e->value);
		i++;
	}
}

t_array		*sh_get_envs(void)
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

void		sh_free_elem_env(t_env *env)
{
	if (!env)
		return ;
	if (env->value)
		free(env->value);
	if (env->name)
		free(env->name);
}
