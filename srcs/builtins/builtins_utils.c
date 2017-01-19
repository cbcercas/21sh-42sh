/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:16 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/19 15:24:45 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "builtins_utils.h"

static t_builtin_e	*ms_new_builtin(char *name, t_builtin fn)
{
	t_builtin_e	*e;

	if (!(e = ft_memalloc(sizeof(*e))))
	{
		ft_printf("minishell: Builtin initialisation fail!\n");
		return (NULL);
	}
	(void)name;
	e->name = strdup(name);
	e->fn = fn;
	e->next = NULL;
	return (e);
}

static t_builtin_e	*ms_add_builtin(t_builtin_e	**head, char *name, t_builtin fn)
{
	t_builtin_e	*e;

	if (*head)
	{
		e = *head;
		while (e->next)
			e = e->next;
		if (!(e->next = ms_new_builtin(name, fn)))
			// TODO free head
			*head = NULL;
	}
	else
		*head = ms_new_builtin(name, fn);
	return (*head);
}


t_builtin_e			*ms_builtins_init(void)
{
	t_builtin_e	*head;

	head = NULL;
	if (!(head = ms_add_builtin(&head, "exit", ms_exit)))
		return (head);
	if (!(head = ms_add_builtin(&head, "echo", ms_echo)))
		return (head);
	return (head);
}

t_builtin ms_is_builtin(t_builtin_e *head, char *name)
{
	t_builtin_e	*e;

	e = head;
	while (e)
	{
		if (!ft_strcmp(name, e->name))
			return (e->fn);
		e = e->next;
	}
	return (NULL);
}