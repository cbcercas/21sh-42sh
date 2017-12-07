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

BOOL	exec_arrow_right_normal(t_input *input)
{
	struct winsize	*ts;

	log_dbg1("exec arrow right normal.");
	ts = get_ts();
	if (pos_in_str(input) == input->str->len && input->next)
	{
		input = input->next;
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		input->cpos = input_get_first_pos(input);
		move_cursor_to(&input->cpos,
					&(t_cpos){input->prev->cpos.cp_col, 0}, ts);
		get_windows(0)->cur = input;
		if (!input->select_pos.is_set)
		{
			input->select_pos.is_set = true;
			input->select_pos.cur_start = pos_in_str(input);
		}
	}
	else if ((unsigned)(input->cpos.cp_col + (input->cpos.cp_line * ts->ws_col)
						- input->offset_col) < input->str->len)
		move_cursor_right(&input->cpos, ts);
	input->select_pos.cur_end = pos_in_str(input);
	return (false);
}

BOOL	exec_arrow_left_normal(t_input *input)
{
	struct winsize	*ts;

	log_dbg1("exec arrow left normal.");
	ts = get_ts();
	if (pos_in_str(input) == 0 && input->prev)
	{
		input = input->prev;
		tputs(tgetstr("up", NULL), 0, &ft_putc_in);
		input->cpos = input_get_last_pos(input);
		move_cursor_to(&input->cpos, &(t_cpos){input->next->cpos.cp_col,
											input->cpos.cp_line}, get_ts());
		get_windows(0)->cur = input;
		if (!input->select_pos.is_set)
		{
			input->select_pos.is_set = true;
			input->select_pos.cur_start = pos_in_str(input);
		}
	}
	else if (((input->cpos.cp_col + (input->cpos.cp_line * ts->ws_col)
			- input->offset_col)) > 0)
		move_cursor_left(&input->cpos, ts);
	input->select_pos.cur_end = pos_in_str(input);
	return (false);
}

