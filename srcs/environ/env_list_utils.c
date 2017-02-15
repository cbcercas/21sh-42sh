/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:24:48 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/15 11:02:23 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <environ/env_list_utils.h>

char	*ms_getenv_name(char *env)
{
	char	*sep;
	char	*name;

	sep = ft_strchr(env, '=');
	name = ft_strsub(env, 0, sep - env);
	return (name);
}

char	*ms_getenv_value(char *env)
{
	char	*sep;
	char	*value;

	sep = ft_strchr(env, '=') + 1;
	value = ft_strsub(sep, 0, ft_strlen(sep));
	return (value);
}

t_env	*ms_new_env(char *name, char *value)
{
	t_env	*e;

	e = ft_memalloc(sizeof(*e));
	if (!e)
		return (NULL);
	e->next = NULL;
	if (!(e->name = name))
		ft_memdel((void **)&e);
	else if (!(e->value = value))
	{
		ft_strdel(&e->name);
		ft_memdel((void **)&e);
	}
	return (e);
}

void	ms_env_del(t_env **e)
{
	ft_strdel(&(*e)->name);
	ft_strdel(&(*e)->value);
	ft_memdel((void**)e);

}

void	ms_lst_env_del(t_env **head)
{
	while ((*head)->next)
		ms_lst_env_del(&(*head)->next);
	ms_env_del(head);
}