/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 18:22:15 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/03 18:25:20 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

void sh_history_print(void)
{
	t_array	*hists;
	t_hist	*h;
	size_t	i;

	hists = sh_history_get();
	i = 0;
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		ft_printf("%zu %s\n", i, h->cmd);
		i++;
	}
}

void sh_history_print_in_log(void)
{
	t_array	*hists;
	t_hist	*h;
	size_t	i;

	hists = sh_history_get();
	i = 0;
	log_dbg1("***********HISTORY PRINT**************");
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		log_dbg1("%zu %s", i, h->cmd);
		i++;
	}
	log_dbg1("**************************************");
}
