/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_alt_arrows.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:42:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/13 14:44:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>


BOOL		exec_alt_up(const t_key *key, t_window *wd)
{
	unsigned short		x;
	t_cpos				ts;

	if (!tcaps_init(wd) || wd->select.is)
		return (false);
	ts.cp_col = 0;
	ts.cp_line = 0;
	log_dbg1("exec alt arrow up.");
	x = wd->cur->cpos.cp_col;
	if (!(wd->cur->cpos.cp_line <= 0 || (wd->cur->cpos.cp_line == 1 &&
			x < wd->cur->offset_col)))
	{
		move_cursor_up(&wd->cur->cpos);
		move_cursor_to(&wd->cur->cpos,
			&(t_cpos){wd->cur->cpos.cp_col, wd->cur->cpos.cp_line}, get_ts());
		return (false);
	}
	if (!wd->cur->prev || wd->cur->prev->lock)
		return (false);
	if (!wd->cur->prev->prev && x <= wd->cur->prev->prompt_len &&
		input_get_last_pos(wd->cur->prev).cp_line == 0)
		x = x + (unsigned short)wd->cur->prev->prompt_len;
	return (exec_alt_input(key, wd, x, ts));
}

BOOL		exec_alt_down(const t_key *key, t_window *wd)
{
	unsigned short		x;
	t_cpos				ts;

	if (!tcaps_init(wd) || wd->select.is)
		return (false);
	ts.cp_col = 0;
	ts.cp_line = 0;
	log_dbg1("exec alt arrow down.");
	x = wd->cur->cpos.cp_col;
	if (wd->cur->cpos.cp_line != input_get_last_pos(wd->cur).cp_line)
	{
		if (wd->cur->cpos.cp_line == input_get_last_pos(wd->cur).cp_line - 1)
		{
			move_cursor_right(&(wd->cur->cpos), get_ts());
			while (x != wd->cur->cpos.cp_col &&
				pos_in_str(wd->cur) < wd->cur->str->len)
				move_cursor_right(&(wd->cur->cpos), get_ts());
			return (false);
		}
		move_cursor_down(&wd->cur->cpos);
		move_cursor_to(&wd->cur->cpos,
			&(t_cpos){wd->cur->cpos.cp_col, wd->cur->cpos.cp_line}, get_ts());
		return (false);
	}
	return (exec_alt_input(key, wd, x, ts));
}

BOOL		exec_alt_left(const t_key *key, t_window *wd)
{
	if (!tcaps_init(wd))
		return (false);
	log_dbg1("exec alt arrow left.");
	exec_arrow_left_normal(wd);
	while ((pos_in_str(wd->cur) != 0) &&\
			(pos_in_str(wd->cur) == wd->cur->str->len ||\
			!(wd->cur->str->s[pos_in_str(wd->cur)] == ' ' &&\
				wd->cur->str->s[pos_in_str(wd->cur) - 1] != ' ')))
		exec_arrow_left(key, wd);
	return (false);
}

BOOL		exec_alt_right(const t_key *key, t_window *wd)
{
	if (!tcaps_init(wd))
		return (false);
	log_dbg1("exec alt arrow right.");
	exec_arrow_right(key, wd);
	while ((pos_in_str(wd->cur) != wd->cur->str->len) &&\
			(pos_in_str(wd->cur) == 0 ||\
			!(wd->cur->str->s[pos_in_str(wd->cur)] != ' ' &&\
				wd->cur->str->s[pos_in_str(wd->cur) - 1] == ' ')))
		exec_arrow_right(key, wd);
	return (false);
}
