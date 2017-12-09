/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_backspace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:04:39 by jlasne            #+#    #+#             */
/*   Updated: 2017/09/18 21:50:05 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_backspace(const t_key *key, t_window *wd)
{
	(void)key;
	log_dbg3("User pressed backspace");
	if (wd->autocomp && wd->autocomp->active)
		return (false);
	else if (wd->autocomp)
		get_windows(100);
	if (wd->cur->cpos.cp_line || (wd->cur->cpos.cp_col > wd->cur->offset_col))
	{
		exec_arrow_left_normal(wd);
		exec_delete(key, wd);
	}
	else if (wd->cur->prev && !wd->cur->prev->lock)
	{
		exec_arrow_left_normal(wd);
		exec_delete(key, wd);
	}
	else
		tcaps_bell();
	return (false);
}
