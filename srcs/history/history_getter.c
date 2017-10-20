/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:16:17 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/10 17:37:34 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tools/tools.h>
#include <history/history.h>
#include <logger.h>
#include <ft_secu_malloc/ft_secu_malloc.h>

int			sh_history_is_space_plus(char const *line)
{
	int		i;

	i = 0;
	if (ft_strequ(line, "\n") || ft_strequ(line, ""))
		return (1);
	while (line && line[i])
	{
		if (!is_white(line[i]))
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

		if (!line || !ft_strlen(line) || !(hists = sh_history_get()) || !hists->used)
			return (NULL);
		if ((first = (t_hist *)array_get_at(hists, 0)))
		{
			log_info("Hist");
			if (!(search = hists->used - 1))
				return (NULL);
			while (search != -1 && (h = (t_hist *)array_get_at(hists, search)) && !ft_strnequ(line, h->cmd, ft_strlen(line)))
				search--;
			if (h && ft_strnequ(line, h->cmd, ft_strlen(line)))
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

		if (sh_history_is_space_plus(cmd) || !is_printstr(cmd))
			return (NULL);
		hists = sh_history_get();
		if ((h = (t_hist *)array_get_at(hists, 0)))
		{
			if (h->buf)
				ft_secu_free(h->buf);
			h->buf = NULL;
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
