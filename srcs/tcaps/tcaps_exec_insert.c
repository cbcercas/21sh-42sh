/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_select.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:17:48 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/18 17:22:56 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

void			reset_insert_pos(void)
{
	t_input		*input;

	input = input_get_cur_head();
	while (input)
	{
		input->select_pos.cur_start = 0;
		input->select_pos.cur_end = 0;
		input->select_pos.is_set = false;
		input = input->next;
	}
}

void		exec_insert_off(t_input *input)
{
	size_t		pos_str;
	t_cpos		dest;

	input = input_back_to_origin(input);
	redraw_input(input);
	while (input && !input->select_pos.is_set)
	{
		dest = input_get_first_pos(input);
		move_cursor_to(&dest, &input->cpos, get_ts());
		tputs(tgetstr("do", NULL), 1, &ft_putc_in);
		dest = input_get_first_pos(input);
		move_cursor_to(&dest, &input->cpos, get_ts());
		input = input->next;
	}
	if (!input)
		return ;
	pos_str = (input->select_pos.cur_start > input->select_pos.cur_end) ?
			input->select_pos.cur_end : input->select_pos.cur_start;
	input_goto_line_end(input);
	while (pos_in_str(input) != pos_str && pos_in_str(input))
		move_cursor_left(&input->cpos, get_ts());
	reset_insert_pos();
	get_select()->is = false;
	get_windows(0) ? get_windows(0)->cur = input : 0;
}

BOOL			exec_insert(const t_key *key, t_window *wd)
{
	(void)key;
	if (wd->autocomp && wd->autocomp->active)
		return (false);
	else if (wd->autocomp)
		exec_escape_select(wd);
	if (!wd->select.is)
	{
		get_select()->is = true;
		get_select()->start_abs = wd->cur;
		reset_insert_pos();
		wd->cur->select_pos.is_set = true;
		wd->cur->select_pos.cur_start = pos_in_str(wd->cur);
		wd->cur->select_pos.cur_end = wd->cur->select_pos.cur_start;
	}
	else
		exec_insert_off(wd->cur);
	return (false);
}

//TODO rename
BOOL			exec_insert_arrows(const t_key *key, t_window *wd)
{
	size_t			start;
	size_t			end;

	if (!wd->select.is || !key)
		return (false);
	if (wd->cur && wd->cur->str->s && wd->cur->str
		&& wd->cur->str->s[pos_in_str(wd->cur)])
	{
		start = wd->cur->select_pos.cur_start;
		end = wd->cur->select_pos.cur_end;
		log_dbg3("star = %d, end = %d", start, end);
		if ((start < end && is_right_arrow(key->key)) ||
			(start > end && is_left_arrow(key->key)) ||
			(start == end && start == 0 && is_right_arrow(key->key)) ||
			(get_select()->start_abs == wd->cur && start == end))
			tputs(tgetstr("mr", NULL), 1, &ft_putc_in);
		ft_putchar_fd(wd->cur->str->s[pos_in_str(wd->cur)], STDIN_FILENO);
		if (wd->cur->cpos.cp_col + 1 != wd->ts.ws_col)
			tputs(tgetstr("le", NULL), 0, &ft_putc_in);
		tputs(tgetstr("me", NULL), 1, &ft_putc_in);
	}
	return (false);
}
