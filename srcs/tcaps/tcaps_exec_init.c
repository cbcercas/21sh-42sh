/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:11:41 by gpouyat           #+#    #+#             */
/*   Updated: 2017/12/09 19:11:48 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

static char *g_tcaps_needed[] = {
	KEY_CODE_RARROW,
	KEY_CODE_LARROW,
	KEY_CODE_DARROW,
	KEY_CODE_UARROW,
	KEY_CODE_DELETE,
	KEY_CODE_INSERT,
	"cl",
	"cr",
	"cd",
	"up",
	"do",
	"cs",
	"cm",
	"ve",
	"sf",
	"sr",
	"mr",
	"le",
	"me",
	"vi",
	"nd",
	"bl",
	"us",
	"ue",
	NULL
};

void tcaps_check_needed(void)
{
	int	i;

	i = 0;
	while (g_tcaps_needed[i])
		if (!(tgetstr(g_tcaps_needed[i++], NULL)))
			sh_exit_error("Failed to get needed terminal capabilities");
}


BOOL	tcaps_init(t_window *wd)
{
	if (!wd)
		return (false);
	if (wd->autocomp && wd->autocomp->active)
		return (false);
	else if (wd->autocomp)
		get_windows(100);
	return (true);
}
