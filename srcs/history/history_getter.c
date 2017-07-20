/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:16:17 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/20 10:19:33 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

int			sh_history_is_space_plus(char const *line)
{
	int		i;

	i = 0;
	if (ft_strequ(line, "\n") || ft_strequ(line, ""))
		return (1);
	while (line && line[i])
	{
		if (!ISBLANC(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int			sh_history_is_print(char const *line)
{
	int		i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_isprint(line[i]))
			return (0);
		i++;
	}
	return (1);
}

const char	*sh_history_get_search(const char *line)
{
	t_array	*hists;
	t_hist	*h;
	t_hist	*first;
	int			search;

		if (!line || !ft_strlen(line))
			return (NULL);
		hists = sh_history_get();
		if ((first = (t_hist *)array_get_at(hists, 0)))
		{
			if (!(search = hists->used - 1))
				return (NULL);
			while (search != -1 && (h = (t_hist *)array_get_at(hists, search)) && !ft_strnequ(line, h->cmd, ft_strlen(line)))
				search--;
			if (ft_strnequ(line, h->cmd, ft_strlen(line)))
				return ((const char *)h->cmd);
		}
	return (NULL);
}

const char	*sh_history_get_at(ssize_t nb)
{
	t_array	*hists;
	t_hist	*h;

	if (nb == 0)
		return (NULL);
		hists = sh_history_get();
		if (nb < 0)
		{
			if ((h = (t_hist *)array_get_at(hists, hists->used + nb)))
				return ((const char *)h->cmd);
		}
		else if ((h = (t_hist *)array_get_at(hists, nb - 1)))
			return ((const char *)h->cmd);
	return (NULL);
}

t_hist	*sh_history_set_new(char const *cmd)
{
	t_array	*hists;
	t_hist	*h;

		if (sh_history_is_space_plus(cmd) || !sh_history_is_print(cmd))
			return (NULL);
		hists = sh_history_get();
		if ((h = (t_hist *)array_get_at(hists, 0)))
		{
			ft_strdel(&(h->buf));
			h->cur = -1;
		}
		if ((hists->used < 1 || ft_strcmp(cmd, sh_history_get_at(-1))) &&\
		 ((h = sh_history_new(ft_strdup(cmd))) != NULL))
		{
			h->session = true;
			array_push(hists, (void *)h);
			ft_memdel((void**)&h);
		}
	return (NULL);
}
