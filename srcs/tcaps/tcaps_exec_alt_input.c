/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_alt_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:46:24 by gpouyat           #+#    #+#             */
/*   Updated: 2017/12/12 14:46:28 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

static BOOL		exec_alt_input_init(const t_key *key, t_window *wd)
{
	if ((!wd->cur->prev && is_alt_up_arrow(key->key)) ||
		(!wd->cur->next && is_alt_down_arrow(key->key)))
		return (false);
	return (true);
}

static BOOL		exec_alt_input_end(t_window *wd)
{
	move_cursor_to(&wd->cur->cpos
			, &(t_cpos){wd->cur->cpos.cp_col, wd->cur->cpos.cp_line}, get_ts());
	redraw_input(wd->cur);
	get_windows(0) ? get_windows(0)->cur = wd->cur : 0;
	return (false);
}

BOOL			exec_alt_input(const t_key *key, t_window *wd, unsigned short x,
							t_cpos ts)
{
	BOOL	is_up;

	if (!exec_alt_input_init(key, wd))
		return (false);
	is_up = is_alt_up_arrow(key->key);
	wd->cur->cpos = (is_up ? input_get_first_pos(wd->cur) :
					input_get_last_pos(wd->cur));
	move_cursor_to(&wd->cur->cpos
			, &(t_cpos){wd->cur->cpos.cp_col, wd->cur->cpos.cp_line}, get_ts());
	if (is_up)
	{
		tputs(tgetstr("up", NULL), 0, &ft_putc_in);
		wd->cur = wd->cur->prev;
	}
	else
	{
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		wd->cur = wd->cur->next;
	}
	if ((ts = input_get_last_pos(wd->cur)).cp_col < x && (!ts.cp_line || is_up))
		wd->cur->cpos = input_get_last_pos(wd->cur);
	else
		wd->cur->cpos.cp_col = x;
	return (exec_alt_input_end(wd));
}
