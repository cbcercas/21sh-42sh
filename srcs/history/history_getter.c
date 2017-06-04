/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:16:17 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/04 09:42:50 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

int			sh_history_is_space_plus(char const *line)
{
	int		i;

	i = 0;
	while (line && line[i])
	{
		if (!ISBLANC(line[i]))
			return (0);
		i++;
	}
	return (1);
}

t_hist	*sh_history_set_new(char const *cmd)
{
	t_array	*hists;
	t_hist	*h;

		if (sh_history_is_space_plus(cmd))
			return (NULL);
		hists = sh_history_get();
		if ((h = (t_hist *)array_get_at(hists, 0)))
		{
			ft_strdel(&(h->buf));
			h->cur = 0;
			//array_set_at(hists, 0, h);
		}
		if ((h = sh_history_new(ft_strdup(cmd))) != NULL)
		{
			array_push(hists, (void *)h);
			ft_memdel((void**)&h);
		}
	return (NULL);
}
