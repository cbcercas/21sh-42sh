/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:40:34 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/15 11:00:22 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/parsing_command.h>

static t_command	*ms_get_command(char *command)
{
	t_command	*e;
	char		*tmp;
	char		*tmp2;

	e = ft_memalloc(sizeof(*e));
	tmp = command;
	while (*tmp && ft_iswhitespace(*tmp))
		tmp++;
	tmp2 = tmp;
	while (*tmp2 && !ft_iswhitespace(*tmp2))
		tmp2++;
	e->command = ft_strsub(tmp, 0, tmp2 - tmp);
	while (*tmp2 && ft_iswhitespace(*tmp2))
		tmp2++;
	if (*tmp2)
		e->args = ft_strtrim(tmp2);
	else
		e->args = NULL;
	e->next = NULL;
	return (e);
}

static t_command	*ms_split_command(char **commands)
{
	t_command	*head;
	t_command	*e;

	head = NULL;
	while (*commands)
	{
		if (!head)
		{
			if (!(head = ms_get_command(*commands)))
				return (NULL);
			e = head;
		}
		else
		{
			if (!(e->next = ms_get_command(*commands)))
			{
				//TODO free list
				return (NULL);
			}
			e = e->next;
		}
		commands++;
	}
	return (head);
}

static char	**ms_split_commands(char *command)
{
	char	**tab;
	char	*com_cleam;

	tab = NULL;
	if (!(com_cleam = ft_strtrim(command)))
		ft_printf("minishell: memory allocation fail!\n");
	else
		if(!(tab = ft_strsplit(com_cleam, ';')))
			ft_printf("minishell: memory allocation fail!\n");
	ft_strdel(&com_cleam);
	return (tab);
}

t_command	*ms_parse_command(char *command)
{
	t_command	*commands;
	char		**tmp;

	commands = NULL;
	if ((tmp = ms_split_commands(command)))
	{
		commands = ms_split_command(tmp);
		ft_freetab(tmp, ft_tablen(tmp));
	}
	return (commands);
}
