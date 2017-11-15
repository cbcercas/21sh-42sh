/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_arrow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:57:33 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/12 15:51:49 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

/*
 BOOL	exec_arrow_right(const t_key *key, t_input *input)
 {
 	struct winsize	*ts;
 	t_select		*sel;

 	log_dbg1("exec arrow right.");
 	ts = get_ts();
 	sel = get_select();
 	if (((size_t) (input->cpos.cp_col + (input->offset_line  * ts->ws_col) - input->offset_col) + input->offset_len) < input->str->len)
 	{
 		exec_select_arrows(key, input, "right");
 		if (input->cpos.cp_col + 1 == ts->ws_col)
 			input->offset_line += 1;
 		move_cursor_right(&input->cpos, ts);
 		if (sel->is)
 			sel->cur_end = pos_in_str(input);
 	}
 	return (false);
 }
*/

BOOL	exec_arrow_right(const t_key *key, t_input *input)
{
	struct winsize	*ts;

	(void)key;
	log_dbg1("exec arrow right.");
	ts = get_ts();
	exec_select_arrows(key, input);
	if (pos_in_str(input) == input->str->len && input->next)
	{
		input = input->next;
		tputs(tgetstr("do", NULL), 0, &ft_putchar2);
		input->cpos = input_get_first_pos(input);
		move_cursor_to(&input->cpos, &(t_cpos){input->prev->cpos.cp_col, 0}, ts);
		get_windows(0)->cur = input;
		if (!input->select_pos.is_set)
		{
			input->select_pos.is_set = true;
			input->select_pos.cur_start = pos_in_str(input);
		}
	}
	else if ((unsigned)(input->cpos.cp_col + (input->cpos.cp_line  * ts->ws_col) - input->offset_col) < input->str->len)
			move_cursor_right(&input->cpos, ts);
	input->select_pos.cur_end = pos_in_str(input);
	return (false);
}
/*
**BOOL	exec_arrow_left(const t_key *key, t_input *input)
**{
**	struct winsize	*ts;
**	t_select		*sel;
**
**	log_dbg1("exec arrow left.");
**	ts = get_ts();
**	sel = get_select();
**	if (((input->cpos.cp_col + ((input->offset_line ) * ts->ws_col) - input->offset_col)) > 0)
**	{
**		exec_select_arrows(key, input, "left");
**		if (input->cpos.cp_col == 0)
**			input->offset_line -= 1;
**		move_cursor_left(&input->cpos, ts);
**		if (sel->is)
**			sel->cur_end = pos_in_str(input);
**	}
**	return (false);
**}
*/

BOOL	exec_arrow_left(const t_key *key, t_input *input)
{
	struct winsize	*ts;

	(void)key;
	log_dbg1("exec arrow left.");
	ts = get_ts();
	exec_select_arrows(key, input);
	if (pos_in_str(input) == 0 && input->prev)
	{
		input = input->prev;
		tputs(tgetstr("up", NULL), 0, &ft_putchar2);
		input->cpos = input_get_last_pos(input);
		move_cursor_to(&input->cpos, &(t_cpos){input->next->cpos.cp_col, input->cpos.cp_line}, get_ts());
		get_windows(0)->cur = input;
		if (!input->select_pos.is_set)
		{
			input->select_pos.is_set = true;
			input->select_pos.cur_start = pos_in_str(input);
		}
	}
	else if (((input->cpos.cp_col + (input->cpos.cp_line * ts->ws_col) - input->offset_col)) > 0)
		move_cursor_left(&input->cpos, ts);
	input->select_pos.cur_end = pos_in_str(input);
	return (false);
}

BOOL	exec_arrow_up(const t_key *key, t_input *input)
{
	t_input		*new_inp;

	(void)key;
	log_dbg1("exec arrow up.");
	if (!(new_inp = sh_history_up(input)))
		return (false);
	input = input_back_to_writable(input);
	input_to_save(&input, new_inp);
	input = new_inp;
	input = input_draw(input);
	input = input_back_to_writable(input);
	input_goto_line_end(input);
	get_windows(0)->cur = input;
	return (false);
}

BOOL	exec_arrow_down(const t_key *key, t_input *input)
{
	t_input *new_inp;

	(void)key;
	log_dbg1("exec arrow down.");
	if (!(new_inp = sh_history_down(input)))
		return (false);
	new_inp = input_draw(new_inp);
	new_inp = new_inp->prev ? input_back_to_writable(new_inp) : new_inp;
	input_goto_line_end(new_inp);
	return (false);
}
