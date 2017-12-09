/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_arrow_normal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:57:33 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/12 15:51:49 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_arrow_right_normal(t_window *wd)
{
	log_dbg1("exec arrow right normal.");
	if (pos_in_str(wd->cur) == wd->cur->str->len && wd->cur->next)
	{
		wd->cur = wd->cur->next;
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		wd->cur->cpos = input_get_first_pos(wd->cur);
		move_cursor_to(&wd->cur->cpos,
					&(t_cpos){wd->cur->prev->cpos.cp_col, 0}, &wd->ts);
		if (!wd->cur->select_pos.is_set)
		{
			wd->cur->select_pos.is_set = true;
			wd->cur->select_pos.cur_start = pos_in_str(wd->cur);
		}
	}
	else if ((unsigned)(wd->cur->cpos.cp_col + (wd->cur->cpos.cp_line * wd->ts.ws_col)
						- wd->cur->offset_col) < wd->cur->str->len)
		move_cursor_right(&wd->cur->cpos, &wd->ts);
	wd->cur->select_pos.cur_end = pos_in_str(wd->cur);
	return (false);
}

BOOL	exec_arrow_left_normal(t_window *wd)
{
	log_dbg1("exec arrow left normal.");
	if (pos_in_str(wd->cur) == 0 && wd->cur->prev && !wd->cur->prev->lock)
	{
		log_dbg1("COUCOU*************************************");
		wd->cur = wd->cur->prev;
		tputs(tgetstr("up", NULL), 0, &ft_putc_in);
		wd->cur->cpos = input_get_last_pos(wd->cur);
		move_cursor_to(&wd->cur->cpos, &(t_cpos){wd->cur->next->cpos.cp_col,
											wd->cur->cpos.cp_line}, &wd->ts);
		if (!wd->cur->select_pos.is_set)
		{
			wd->cur->select_pos.is_set = true;
			wd->cur->select_pos.cur_start = pos_in_str(wd->cur);
		}
	}
	else if (((wd->cur->cpos.cp_col + (wd->cur->cpos.cp_line * wd->ts.ws_col)
			- wd->cur->offset_col)) > 0)
		move_cursor_left(&wd->cur->cpos, &wd->ts);
	wd->cur->select_pos.cur_end = pos_in_str(wd->cur);
	return (false);
}

