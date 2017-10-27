/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_getter_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:52:34 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/26 14:52:40 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <history/history.h>
//#include <logger.h>

const char *history_get_next(char *str)
{
	t_array		*hists;
	t_hist		*h;
	size_t		lvl;
	size_t		len;

	if (!str || !(hists = sh_history_get()))
		return (NULL);
	len = ft_strlen(str);
	lvl = ((t_window*)get_windows(0))->histlvl;
	while ((h = (t_hist *)array_get_at(hists, lvl)) && hists->used > lvl &&
			ft_strncmp(h->cmd, str, len))
		lvl++;
		ft_strdel(&str);
	if (hists->used <= lvl)
		return (NULL);
	((t_window*)get_windows(0))->histlvl = lvl;
	return (h->cmd);
}

const char *history_get_prev(char *str)
{
	t_array		*hists;
	t_hist		*h;
	size_t		lvl;
	size_t		len;

	if (!str || !(hists = sh_history_get()))
		return (NULL);
	len = ft_strlen(str);
	lvl = ((t_window*)get_windows(0))->histlvl;
	while ((h = (t_hist *)array_get_at(hists, lvl)) && lvl &&
		   ft_strncmp(h->cmd, str, len))
		lvl--;
	if (ft_strnequ(h->cmd, str, len))
	{
		ft_strdel(&str);
		((t_window*)get_windows(0))->histlvl = lvl;
		return (h->cmd);
	}
	ft_strdel(&str);
	return (NULL);
}