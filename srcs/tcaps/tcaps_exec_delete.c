/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:04:39 by chbravo-          #+#    #+#             */
/*   Updated: 2017/09/18 21:49:58 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

static BOOL		exec_delete2(void)
{
	tcaps_bell();
	return (false);
}

BOOL			exec_delete(const t_key *key, t_window *wd)
{
	size_t		pos;
	t_input		*del;

	if (!key || !tcaps_init(wd) || wd->select.is
		|| (wd->autocomp && wd->autocomp->active))
		return (false);
	else if (wd->autocomp && !wd->autocomp->active)
		get_windows(100);
	pos = pos_in_str(wd->cur);
	if (wd->cur->str->len > pos)
		string_remove_char(wd->cur->str, pos);
	else if (wd->cur->str->len == pos && wd->cur->next)
	{
		wd->cur->str = string_join_cl(&wd->cur->str, &wd->cur->next->str, true);
		del = wd->cur->next;
		wd->cur->next = del->next;
		if (wd->cur->next)
			wd->cur->next->prev = wd->cur;
		del->next = NULL;
		input_destroy(&del);
	}
	else
		return (exec_delete2());
	redraw_input(wd->cur);
	return (false);
}
