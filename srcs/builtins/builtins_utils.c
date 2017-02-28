/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:16 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/26 14:06:16 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <builtins/builtins_utils.h>

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
	e->len = ft_strlen(name);
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
	if (!(head = ms_add_builtin(&head, "cd", ms_chdir)))
		return (head);
	if (!(head = ms_add_builtin(&head, "chdir", ms_chdir)))
		return (head);
	return (head);
}

t_builtin_e *ms_is_builtin(t_builtin_e *head, char *name)
{
	t_builtin_e	*e;

	e = head;
	while (e)
	{
		if (!ft_strncmp(name, e->name, e->len))
			return (e);
		e = e->next;
	}
	return (NULL);
}

static char	*ms_find_quote_end(char *arg)
{
	int	lvl;
	char cur_q;

	lvl = 1;
	cur_q = *arg;
	arg++;
	while (*arg)
	{
		if (cur_q == *arg && lvl)
		{
			lvl -= 1;
			if (lvl)
				cur_q = (cur_q == '"') ? '`' : '"';
		}
		else if ((*arg == '"' || *arg == '`') && lvl)
		{
			cur_q = *arg;
			lvl += 1;
		}
		if (*arg == cur_q && lvl == 0)
			return (arg);
		arg++;
	}
	return ((*arg) ? arg : NULL);
}

char	*ms_extract_str(char *arg)
{
	char	*str;
	char	*q_end;

	q_end = ms_find_quote_end(arg);
	str = ft_strsub(arg, 1, q_end - arg - 1);
	return (str);
}