/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history_npr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 09:29:56 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/10 18:41:32 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_history.h>

/*
** @brief The option -r reads the contents of the history
** file and uses them as the current history.
**
** @param path Contains the filename/path of the history file
*/

void		sh_history_builtin_r(char *path)
{
	t_array	*hists;
	t_hist	*h;
	int		fd;

	if ((fd = open(history_get_path(path), O_RDWR | O_CREAT, 0644)) == -1)
		return ;
	if ((hists = sh_history_get()) != NULL)
	{
		while (sh_history_init_one(hists, fd))
		{
			h = (t_hist *)array_get_at(hists, hists->used - 1);
			h->session = true;
			if (hists->used >= HISTORY_MAX)
				sh_history_remove_at(0);
		}
	}
	close(fd);
}

/*
** @brief The option -n reads the history lines not already read from the
** history file into the current history list. These are lines appended to the
** history file since the beginning of the current session.
**
** @param path Contains the filename/path of the history file
*/

void		sh_history_builtin_n(char *path)
{
	t_array	*hists;
	t_hist	*h;
	int		fd;
	size_t	i;

	i = 0;
	if ((fd = open(history_get_path(path), O_RDWR | O_CREAT, 0644)) == -1)
		return ;
	if ((hists = sh_history_get()) != NULL)
	{
		while (fd != -1 && i < hists->used)
		{
			h = (t_hist *)array_get_at(hists, i);
			if (h && h->session == true)
				ft_dprintf(fd, "%s\n", h->cmd);
			i++;
		}
	}
	close(fd);
}

/*
** @brief Displays -p option ret
**
** @param result result of history -p
** @param index index in arg
** @param arg passed at history -p
*/

static void	sh_history_builtin_p_helper(int index, char **arg)
{
	index = 2;
	while (arg && arg[index])
	{
		ft_printf("%s\n", arg[index]);
		index++;
	}
}

/*
** @brief The option -p performs a history substitution on the following args
** and displays the result on the standard output.
** It does not store the results in the history list.
** Each arg must be quoted to disable normal history expansion.
**
** @param arg Arguments passed at the `history -p` command
*/

void		sh_history_builtin_p(char **arg)
{
	int		index;

	index = 0;
	if (sh_history_get())
		sh_history_remove_at(sh_history_get()->used - 1);
	while (arg && arg[index])
	{
		if (arg[index][0] == '!' && arg[index][1])
		{
			ft_printf("%s: event not found\n", arg[index]);
			return ;
		}
		index++;
	}
	sh_history_builtin_p_helper(index, arg);
}
