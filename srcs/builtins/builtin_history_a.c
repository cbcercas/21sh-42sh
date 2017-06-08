/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:53:12 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/08 17:50:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_history.h>

void sh_history_builtin_a(char *str)
{
	t_array	*hists;
	t_hist	*h;
	int			fd;
	size_t	i;

	i = 0;
	if ((fd = sh_history_open_fd(str,  O_RDWR | O_CREAT | O_APPEND)) == -1)
	{
		log_warn("History: History is not save no open");
		ft_putstr_fd("History is not save", 2);
		return ;
	}
	if ((hists = sh_history_get()) == NULL)
		return ;
		while (i < hists->used)
		{
			h = (t_hist *)array_get_at(hists, i);
			if(h->session == true)
				ft_dprintf(fd, "%s\n", h->cmd);
			i++;
		}
	sh_history_var_session_reset();
}
