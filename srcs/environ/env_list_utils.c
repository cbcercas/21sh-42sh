/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:24:48 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/24 16:39:43 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <environ/env_list_utils.h>


char	*split_env_name(char const *env)
{
	char	*sep;
	char	*name;

	sep = ft_strchr(env, '=');
	name = ft_strsub(env, 0, sep - env);
	return (name);
}

char	*split_env_value(char const *env)
{
	char	*sep;
	char	*value;

	sep = ft_strchr(env, '=') + 1;
	value = ft_strsub(sep, 0, ft_strlen(sep));
	return (value);
}

t_env	*env_new(char *name, char *value)
{
	t_env	*e;

	if ((e = ft_memalloc(sizeof(*e))) == NULL)
	{
		log_fatal("Environ: can't create new environment varibles");
		ft_dprintf(STDERR_FILENO,"Environ: can't create new environment varibles");
	}
	else if ((e->name = name) == NULL)
	{
		log_fatal("Environ: can't create new environment varibles");
		ft_dprintf(STDERR_FILENO,"Environ: can't create new environment varibles");
		ft_memdel((void**)&e);
	}
	else
		e->value = value;
	return (e);
}

void	del_env(t_env **e)
{
	ft_strdel(&(*e)->name);
	ft_strdel(&(*e)->value);
	ft_memdel((void**)e);

}

void	sh_lst_env_del(t_env **head)
{
	while ((*head)->next)
		sh_lst_env_del(&(*head)->next);
	del_env(head);
}
