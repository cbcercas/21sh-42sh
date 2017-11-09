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
#include <core/input.h>
#include <history/history.h>

void	reset_select_pos(void)
{
	t_input		*input;

	input = get_windows(0)->cur_head;
	while (input)
	{
		input->select_pos.cur_start = 0;
		input->select_pos.cur_end = 0;
		input->select_pos.is_set = false;
		input = input->next;
	}
}

static void		exec_select_off(t_input *input)
{
	size_t		pos_str;

	input = input_back_to_origin(input);
	while (input && !input->select_pos.is_set)
	{

		input_goto_line_end(input);
		tputs(tgetstr("do", NULL), 1, &ft_putchar2);
		input = input->next;
	}
	redraw_input(input);
	pos_str = (input->select_pos.cur_start > input->select_pos.cur_end) ?
			  input->select_pos.cur_end : input->select_pos.cur_start;
	input_goto_line_end(input);
	while (pos_in_str(input) != pos_str && pos_in_str(input))
		move_cursor_left(&input->cpos, get_ts());
	get_select()->is = false;
	get_windows(0)->cur = input;
	reset_select_pos();
}

BOOL	exec_select(const t_key *key, t_input *input)
{
	(void)key;
	if (!get_select()->is)
	{
		get_select()->is = true;
		get_select()->start_abs = input;
		reset_select_pos();
		input->select_pos.is_set = true;
		input->select_pos.cur_start = pos_in_str(input);
		input->select_pos.cur_end = input->select_pos.cur_start;
	}
	else
		exec_select_off(input);
	return (false);
}

BOOL exec_select_arrows(const t_key *key, t_input *input)
{
	struct winsize	*ts;
	size_t			start;
	size_t			end;

	if (!get_select()->is || !key)
		return (false);
	ts = get_ts();
	if (input && input->str->s && input->str
		&& input->str->s[pos_in_str(input)])
	{
		start = input->select_pos.cur_start;
		end = input->select_pos.cur_end;
		log_dbg3("star = %d, end = %d", start, end);
		if ( (start < end && is_right_arrow(key->key)) ||
			 (start > end && is_left_arrow(key->key)) ||
			 (start == end && start == 0 && is_right_arrow(key->key)) ||
			 (get_select()->start_abs == input && start == end) )
			tputs(tgetstr("mr", NULL), 1, &ft_putchar2);
		ft_putchar(input->str->s[pos_in_str(input)]);
		if (input->cpos.cp_col + 1 != ts->ws_col)
			tputs(tgetstr("le", NULL), 0, &ft_putchar2);
		tputs(tgetstr("me", NULL), 1, &ft_putchar2);
	}
	return (false);
}