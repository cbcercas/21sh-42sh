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
#include <history/history.h>
#include <core/prompt.h>

/*
**BOOL	exec_arrow_right(const t_key *key, t_input *input)
**{
**	struct winsize	*ts;
**	t_select		*sel;
**
**	log_dbg1("exec arrow right.");
**	ts = get_ts();
**	sel = get_select();
**	if (((size_t) (input->cpos.cp_col + (input->offset_line  * ts->ws_col) - input->offset_col) + input->offset_len) < input->str->len)
**	{
**		exec_select_arrows(key, input, "right");
**		if (input->cpos.cp_col + 1 == ts->ws_col)
**			input->offset_line += 1;
**		move_cursor_right(&input->cpos, ts);
**		if (sel->is)
**			sel->cur_end = pos_in_str(input);
**	}
**	return (false);
**}
*/

BOOL	exec_arrow_right(const t_key *key, t_input *input)
{
	struct winsize	*ts;

	log_dbg1("exec arrow right.");
	ts = get_ts();
	if (pos_in_str(input) == input->str->len && input->next)
	{
		input = input->next;
		tputs(tgetstr("do", NULL), 0, &ft_putchar2);
		input->cpos = input_get_first_pos(input);
		move_cursor_to(&input->cpos, &(t_cpos){input->prev->cpos.cp_col, 0}, get_ts());
		get_windows(0)->cur = input;
	}
	else if (((size_t) (input->cpos.cp_col + (input->cpos.cp_line  * ts->ws_col) - input->prompt_len)) < input->str->len)
	{

			if (input->cpos.cp_col + 1 == ts->ws_col)
				input->offset_line += 1;
			move_cursor_right(&input->cpos, ts);
	}
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

	log_dbg1("exec arrow left.");
	ts = get_ts();
	if (pos_in_str(input) == 0 && input->prev)
	{
		input = input->prev;
		tputs(tgetstr("up", NULL), 0, &ft_putchar2);
		input->cpos = input_get_last_pos(input);
		move_cursor_to(&input->cpos, &(t_cpos){input->next->cpos.cp_col, input->cpos.cp_line}, get_ts());
		get_windows(0)->cur = input;
	}
	else if (((input->cpos.cp_col + (input->cpos.cp_line * ts->ws_col) - input->offset_col)) > 0)
	{
		if (input->cpos.cp_col == 0)
			input->offset_line -= 1;
		move_cursor_left(&input->cpos, ts);
	}
	return (false);
}

static void cpy_input_data(t_input *cpy, t_input *ori)
{
	cpy->prompt_type = ori->prompt_type;
	cpy->prompt_len = ori->prompt_len;
	cpy->offset_col = (unsigned short)ori->prompt_len;
	ft_memmove(&cpy->cpos, &ori->cpos, sizeof(ori->cpos));
}

BOOL	exec_arrow_up(const t_key *key, t_input *input)
{
	t_input *tmp;

	(void)key;
	log_dbg1("exec arrow up.");
	//TODO really need this?
	if (input->lock)
		return (false);
	//TODO add beep
	//if (!(tmp = input_from_history(history_get_next(input_to_history
	//(input_get_writable(input))))))
	if (!(tmp = input_from_history(history_get_prev(input_to_history(input_get_writable(input->lock ? get_windows(0)->save : input))))))
		return(false);
	input = input_back_to_origin(input);
	cpy_input_data(tmp, input);
	if (get_windows(0)->save == NULL)
		get_windows(0)->save = input;
	else
		input_destroy(&input);
	if (get_windows(0)->save->prev)
		get_windows(0)->save->prev->next = tmp;
	else
		get_windows(0)->cur_head = tmp;
	tmp->prev = get_windows(0)->save->prev;
	get_windows(0)->cur = tmp;
	tmp = input_draw(tmp);
	if (tmp->prev)
		tmp = input_back_to_origin(tmp);
	input_goto_line_end(tmp);
	return (false);
}

BOOL	exec_arrow_down(const t_key *key, t_input *input)
{
	t_input *tmp;
	t_input	*remove;

	(void)key;
	remove = NULL;
	tmp = NULL;
	log_dbg1("exec arrow down.");
	//TODO really need this?
	if (input->lock)
		return (false);
	//TODO add beep
	if (get_windows(0)->histlvl >= 1 && (tmp = input_from_history(history_get_next(input_to_history(input_get_writable(get_windows(0)->histlock ? get_windows(0)->save : input))))))
	{
		input = input_back_to_origin(input);
		cpy_input_data(tmp, input);
		if (get_windows(0)->save == NULL)
			get_windows(0)->save = input;
		else
			remove = input;
		if (get_windows(0)->save->prev)
			get_windows(0)->save->prev->next = tmp;
		else
			get_windows(0)->cur_head = tmp;
		tmp->prev = get_windows(0)->save->prev;
	}
	else if (get_windows(0)->save && !tmp)
	{
		get_windows(0)->histlvl -= 1;
		input = input_back_to_origin(input);
		if (input->prev)
		{
			get_windows(0)->save->prev = input->prev;
			input->prev->next = get_windows(0)->save;
		}
		else
			get_windows(0)->cur_head = get_windows(0)->save;
		remove = input;
		tmp = get_windows(0)->save;
		get_windows(0)->save = NULL;
	}
	else
		return(false);
	get_windows(0)->cur = tmp;
	tputs(tgetstr("ce", NULL), 0, &ft_putchar2);
	tmp = input_draw(tmp);
	if (tmp->prev)
		tmp = input_back_to_origin(tmp);
	input_goto_line_end(tmp);
	input_destroy(&remove);
	return (false);
}
