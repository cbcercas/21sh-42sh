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

BOOL	exec_alt_input(const t_key *key, t_input *input, unsigned short x)
{
	if ((!input->prev && is_alt_up_arrow(key->key)) ||
			(!input->next && is_alt_down_arrow(key->key)))
		return (false);
	input->cpos = (is_alt_up_arrow(key->key) ? input_get_first_pos(input) :
				input_get_last_pos(input));
	move_cursor_to(&input->cpos
			, &(t_cpos){input->cpos.cp_col, input->cpos.cp_line}, get_ts());
	if (is_alt_up_arrow(key->key))
	{
		exec_arrow_left(NULL, input);
		input = input->prev;
	}
	else
	{
		exec_arrow_right(NULL, input);
		input = input->next;
	}
	if (input_get_last_pos(input).cp_col < x)
		input->cpos = input_get_last_pos(input);
	else
		input->cpos.cp_col = x;
	move_cursor_to(&input->cpos
			, &(t_cpos){input->cpos.cp_col, input->cpos.cp_line}, get_ts());
	get_windows(0)->cur = input;
	return (false);
}

BOOL	exec_alt_up(const t_key *key, t_input *input)
{
	unsigned short		x;
	t_sel_data			*sdata;

	if ((sdata = select_get_data()) && sdata->active)
		return (false);
	if (get_select()->is)
		return (false);
	log_dbg1("exec alt arrow up.");
	x = input->cpos.cp_col;
	if (!(input->cpos.cp_line <= 0 || (input->cpos.cp_line == 1 &&
													x < input->offset_col)))
	{
		move_cursor_up(&input->cpos);
		move_cursor_to(&input->cpos,
				&(t_cpos){input->cpos.cp_col, input->cpos.cp_line}, get_ts());
		return (false);
	}
	if (!input->prev || input->prev->lock)
		return (false);
	if (!input->prev->prev && x <= input->prev->prompt_len &&
			input_get_last_pos(input->prev).cp_line == 0)
		x = x + (unsigned short)input->prev->prompt_len;
	return (exec_alt_input(key, input, x));
}

BOOL	exec_alt_down(const t_key *key, t_input *input)
{
	unsigned short		x;
	t_sel_data			*sdata;

	if ((sdata = select_get_data()) && sdata->active)
		return (false);
	if (get_select()->is)
		return (false);
	log_dbg1("exec alt arrow down.");
	if (get_select()->is || !input->next || input->next->lock)
		return (false);
	x = input->cpos.cp_col;
	if (input->cpos.cp_line != input_get_last_pos(input).cp_line)
	{
		if (input->cpos.cp_line == input_get_last_pos(input).cp_line - 1)
		{
			move_cursor_right(&(input->cpos), get_ts());
			while (x != input->cpos.cp_col &&
					pos_in_str(input) < input->str->len)
				move_cursor_right(&(input->cpos), get_ts());
			return (false);
		}
		move_cursor_down(&input->cpos);
		move_cursor_to(&input->cpos,
				&(t_cpos){input->cpos.cp_col, input->cpos.cp_line}, get_ts());
		return (false);
	}
	return (exec_alt_input(key, input, x));
}

BOOL	exec_alt_left(const t_key *key, t_input *input)
{
	t_sel_data			*sdata;

	if ((sdata = select_get_data()) && sdata->active)
		return (false);
	get_windows(100);
	log_dbg1("exec alt arrow left.");
	exec_arrow_left_normal(input);
	while ((pos_in_str(input) != 0) &&\
			(pos_in_str(input) == input->str->len ||\
			!(input->str->s[pos_in_str(input)] == ' ' &&\
				input->str->s[pos_in_str(input) - 1] != ' ')))
		exec_arrow_left(key, input);
	return (false);
}

BOOL	exec_alt_right(const t_key *key, t_input *input)
{
	t_sel_data			*sdata;

	if ((sdata = select_get_data()) && sdata->active)
		return (false);
	log_dbg1("exec alt arrow right.");
	get_windows(100);
	exec_arrow_right(key, input);
	while ((pos_in_str(input) != input->str->len) &&\
			(pos_in_str(input) == 0 ||\
			!(input->str->s[pos_in_str(input)] != ' ' &&\
				input->str->s[pos_in_str(input) - 1] == ' ')))
		exec_arrow_right(key, input);
	return (false);
}
