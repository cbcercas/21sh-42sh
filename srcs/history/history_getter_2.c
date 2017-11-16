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

#include <history/history.h>

/*
** @brief Searches the history for `str` and returns the previous one (TODO?)
**
** @param str The string to search
**
** @return Returns the history entry previous to `str`
*/

const char *history_get_prev(char *str)
{
	t_array	*hists;
	t_hist	*h;
	ssize_t	lvl;
	size_t	len;

	lvl = get_windows(0)->h_lvl;
	if (!str || !(hists = sh_history_get()) || lvl < -1)
		return (NULL);
	if (!get_windows(0)->h_complet)
		h = (t_hist *)array_get_at(hists,
								   ((hists->used - 1) - (size_t)++lvl));
	else
	{
		len = ft_strlen(str);
		while (hists->used > (size_t)++lvl &&
										(h = (t_hist *)array_get_at(hists,
											((hists->used - 1) - (size_t)lvl))))
			if (ft_strnequ(h->cmd, str, len))
				break;
	}
	if ((ssize_t)hists->used <= lvl || !h)
		return (NULL);
	get_windows(0)->h_lvl = lvl;
	return (h->cmd);
}

/*
** @brief Searches the history for `str` and returns the next one (TODO?)
**
** @param str The string to search
**
** @return Returns the history entry next to `str`
*/

const char *history_get_next(char *str)
{
	t_array	*hists;
	t_hist	*h;
	ssize_t	lvl;
	size_t	len;

	lvl = get_windows(0)->h_lvl;
	if (!str || !(hists = sh_history_get()) || lvl < 0)
		return (NULL);
	if (!get_windows(0)->h_complet)
		h = (t_hist *)array_get_at(hists, (size_t)((hists->used - 1) - --lvl));
	else
	{
		len = ft_strlen(str);
		while ((h = (t_hist *)array_get_at(hists,
										(size_t)((hists->used - 1) - --lvl))))
			if (ft_strnequ(h->cmd, str, len))
				break;
	}
	if (lvl >= 0 && h)
	{
		get_windows(0)->h_lvl = lvl;
		return (h->cmd);
	}
	return (NULL);
}