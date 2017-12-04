/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 18:22:15 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/22 17:26:24 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>
#include <core/color.h>

/*
** @brief Prints the history entries and their number
*/

void	sh_history_print(void)
{
	t_array	*hists;
	t_hist	*h;
	size_t	i;

	hists = sh_history_get();
	i = 0;
	if (!hists || !hists->used)
		ft_dprintf(STDERR_FILENO, "%s: history: no history (yet)", PROGNAME);
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		if (get_data(NULL) && get_data(NULL)->opts.color)
			ft_printf("%s %zu %s %s\n", C_MAGENTA, i + 1, C_NONE, h->cmd);
		else
			ft_printf("%zu %s\n", i + 1, h->cmd);
		i++;
	}
}

/*
** @brief Prints the history in the log
*/

void	sh_history_print_in_log(void)
{
	t_array	*hists;
	t_hist	*h;
	size_t	i;
	int		ses;

	hists = sh_history_get();
	i = 0;
	log_dbg3("***********HISTORY PRINT**************");
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		ses = (h->session == true ? 1 : 0);
		log_dbg3("%zu %s | %d", i, h->cmd, ses);
		i++;
	}
	log_dbg3("**************************************");
}
