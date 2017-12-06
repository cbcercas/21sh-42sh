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

BOOL	exec_arrow_right(const t_key *key, t_input *input)
{
	t_window	*window;

	log_dbg1("dispatch arrow right.");
	if (!(window = get_windows(0)))
		return (false);
	if (window->autocomp)
	{
		if (window->autocomp->active)
			return (exec_arrow_right_select(window->autocomp));
		get_windows(100);
	}
	if (window->select.is)
		exec_insert_arrows(key, input);
	return (exec_arrow_right_normal(input));
}

BOOL	exec_arrow_left(const t_key *key, t_input *input)
{
	t_window	*window;

	log_dbg1("dispatch arrow left.");
	if (!(window = get_windows(0)))
		return (false);
	if (window->autocomp)
	{
		if (window->autocomp->active)
			return (exec_arrow_left_select(window->autocomp));
		get_windows(100);
	}
	if (window->select.is)
		exec_insert_arrows(key, input);
	return (exec_arrow_left_normal(input));
}

BOOL	exec_arrow_up(const t_key *key, t_input *input)
{
	t_sel_data	*sdata;
	t_input		*new_inp;

	(void)key;
	log_dbg1("exec arrow up.");
	if ((sdata = select_get_data()) && sdata->active)
		return (false); // TODO add exec_arrow_up_select
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
	t_sel_data	*sdata;
	t_input *new_inp;

	(void)key;
	log_dbg1("exec arrow down.");
	if (((sdata = select_get_data()) && sdata->active))
		return (false); // TODO add exec_arrow_down_select
	if (!(new_inp = sh_history_down(input)))
		return (false);
	new_inp = input_draw(new_inp);
	new_inp = new_inp->prev ? input_back_to_writable(new_inp) : new_inp;
	input_goto_line_end(new_inp);
	return (false);
}
