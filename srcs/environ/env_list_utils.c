/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:24:48 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/04 09:40:42 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/env_list_utils.h>
#include <libft.h>
#include <logger.h>
#include <ftprintf.h>

char	*split_var_name(char const *env)
{
	char	*sep;
	char	*name;

	sep = ft_strchr(env, '=');
	name = ft_strsub(env, 0, sep - env);
	return (name);
}

char	*split_var_value(char const *env)
{
	char	*sep;
	char	*value;

	sep = ft_strchr(env, '=') + 1;
	value = ft_strsub(sep, 0, ft_strlen(sep));
	return (value);
}

t_env	*var_new(char *name, char *value, BOOL is_export)
{
	t_env	*e;

	if ((e = ft_memalloc(sizeof(*e))) == NULL)
	{
		log_fatal("Environ: can't create new environment varibles");
		ft_dprintf(STDERR_FILENO, "Environ: can't create new environment \
				varibles");
	}
	else if ((e->name = name) == NULL)
	{
		log_fatal("Environ: can't create new environment varibles");
		ft_dprintf(STDERR_FILENO, "Environ: can't create new environment \
				varibles");
		ft_memdel((void**)&e);
	}
	else
	{
		e->value = value;
		e->is_export = is_export;
	}
	return (e);
}

void	del_env(void *e)
{
	ft_strdel(&((t_env *)e)->name);
	ft_strdel(&((t_env *)e)->value);
	ft_memdel((void**)e);
}
