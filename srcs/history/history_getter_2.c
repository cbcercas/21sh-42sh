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

const char *history_get_prev(char *str)
{
	t_array		*hists;
	t_hist		*h;
	ssize_t		lvl;
	size_t		len;

	lvl = get_windows(0)->histlvl;
	if (!str || !(hists = sh_history_get()) || lvl < -1)
		return (NULL);
	len = ft_strlen(str);
	if (!get_windows(0)->histlock)
		h = (t_hist *)array_get_at(hists, ((hists->used - 1) - (size_t)++lvl));
	else
	{
		while (hists->used > (size_t)++lvl && (h = (t_hist *)array_get_at(hists, ((hists->used - 1) - (size_t)lvl))))
			if (ft_strnequ(h->cmd, str, len))
				break;
	}
	ft_strdel(&str);
	if ((ssize_t)hists->used <= lvl || !h)
		return (NULL);
	get_windows(0)->histlvl = lvl;
	return (h->cmd);
}

const char *history_get_next(char *str)
{
	t_array		*hists;
	t_hist		*h;
	ssize_t		lvl;
	size_t		len;

	lvl = get_windows(0)->histlvl;
	if (!str || !(hists = sh_history_get()) || lvl < 0)
		return (NULL);
	len = ft_strlen(str);
	if (!get_windows(0)->histlock)
		h = (t_hist *)array_get_at(hists, (size_t)((hists->used - 1) - --lvl));
	else
	{
		while ((h = (t_hist *)array_get_at(hists, (size_t)((hists->used - 1) - --lvl))))
			   if (ft_strnequ(h->cmd, str, len))
				   break;
	}
	ft_strdel(&str);
	if (lvl >= 0 && h)
	{
		get_windows(0)->histlvl = lvl;
		return (h->cmd);
	}
	return (NULL);
}