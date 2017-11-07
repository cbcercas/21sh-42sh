/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_arrows.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:42:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/13 14:44:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_alt_up(const t_key *key, t_input *input)
{
	struct winsize	*ts;
	size_t    x;

	(void)key;
	log_dbg1("exec alt arrow up.");
	ts = get_ts();
	x = input->cpos.cp_col;
	if (!(input->cpos.cp_line <= 0 || (input->cpos.cp_line == 1 &&
													x < input->offset_col)))
	{
		move_cursor_up(&input->cpos);
		return (false);
	}
	if (!input->prev)
		return (false);
	input = input->prev;
	tputs(tgetstr("up", NULL), 0, &ft_putchar2);
	input->cpos = input_get_last_pos(input);
	move_cursor_to(&input->cpos, &(t_cpos){input->next->cpos.cp_col,
										   input->cpos.cp_line}, get_ts());
	if (pos_in_str(input->next) < input->str->len)
		while (input->cpos.cp_col != input->next->cpos.cp_col)
			move_cursor_left(&input->cpos, ts);
	get_windows(0)->cur = input;
	return (false);
}

static	BOOL	alt_down_simple(t_input *input, struct winsize	*ts)
{
	size_t			save_col;

	save_col = input->cpos.cp_col;
	if (((input->str->len + input->prompt_len) / ts->ws_col) - 1 != (input->cpos.cp_line))
	{
		move_cursor_down(&input->cpos);
		return (false);
	}
	move_cursor_right(&(input->cpos), ts);
	while (input->cpos.cp_col != save_col && pos_in_str(input) < input->str->len)
		move_cursor_right(&(input->cpos), ts);
	return (false);
}

BOOL	exec_alt_down(const t_key *key, t_input *input)
{
	struct winsize	*ts;

	(void) key;
	log_dbg1("exec alt arrow down.");
	ts = get_ts();
	if ((input->str->len + input->prompt_len) / ts->ws_col != input->cpos.cp_line)
		return (alt_down_simple(input, ts));
	if (!input->next)
		return (false);
	input = input->next;
	tputs(tgetstr("do", NULL), 0, &ft_putchar2);
	input->cpos = input_get_last_pos(input);
	move_cursor_to(&input->cpos, &(t_cpos){input->prev->cpos.cp_col,
										   input->cpos.cp_line}, get_ts());
	if (pos_in_str(input->prev) < input->str->len)
		while (input->cpos.cp_col != input->prev->cpos.cp_col)
			move_cursor_right(&input->cpos, ts);
	get_windows(0)->cur = input;
	return (false);
}

BOOL	exec_alt_left(const t_key *key, t_input *input)
{
	exec_arrow_left(key, input);
	while ((pos_in_str(input) != 0) &&\
			(pos_in_str(input) == input->str->len ||\
			 !(input->str->s[pos_in_str(input)] == ' ' &&\
				 input->str->s[pos_in_str(input) - 1] != ' ')))
		exec_arrow_left(key, input);
	return (false);
}

BOOL	exec_alt_right(const t_key *key, t_input *input)
{
	exec_arrow_right(key, input);
	while ((pos_in_str(input) != input->str->len) &&\
			(pos_in_str(input) == 0 ||\
			 !(input->str->s[pos_in_str(input)] != ' ' &&\
				 input->str->s[pos_in_str(input) - 1] == ' ')))
		exec_arrow_right(key, input);
	return (false);
}
