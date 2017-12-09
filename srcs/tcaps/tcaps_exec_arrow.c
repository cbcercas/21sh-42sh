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

BOOL	exec_arrow_right(const t_key *key, t_window *wd)
{
	log_dbg1("dispatch arrow right.");
	if (wd->autocomp && wd->autocomp->active)
		return (exec_arrow_right_select(wd->autocomp));
	else if (wd->autocomp)
		get_windows(100);
	if (wd->select.is)
		exec_insert_arrows(key, wd);
	return (exec_arrow_right_normal(wd));
}

BOOL	exec_arrow_left(const t_key *key, t_window *wd)
{
	log_dbg1("dispatch arrow left.");
	if (wd->autocomp && wd->autocomp->active)
		return (exec_arrow_left_select(wd->autocomp));
	else if (wd->autocomp)
		get_windows(100);
	if (wd->select.is)
		exec_insert_arrows(key, wd);
	return (exec_arrow_left_normal(wd));
}

BOOL	exec_arrow_up(const t_key *key, t_window *wd)
{
	t_input		*new_inp;

	(void)key;
	log_dbg1("exec arrow up.");
	if (wd->autocomp && wd->autocomp->active)
		return (exec_arrow_up_select(wd->autocomp));
	else if (wd->autocomp)
		get_windows(100);
	if (!(new_inp = sh_history_up(wd->cur)))
		return (false);
	wd->cur = input_back_to_writable(wd->cur);
	input_to_save(&wd->cur, new_inp);
	wd->cur = new_inp;
	wd->cur = input_draw(wd->cur);
	wd->cur = input_back_to_writable(wd->cur);
	input_goto_line_end(wd->cur);
	return (false);
}

BOOL	exec_arrow_down(const t_key *key, t_window *wd)
{
	t_input *new_inp;

	(void)key;
	log_dbg1("exec arrow down.");
	if (wd->autocomp && wd->autocomp->active)
		return (exec_arrow_down_select(wd->autocomp));
	else if (wd->autocomp)
		get_windows(100);
	if (!(new_inp = sh_history_down(wd->cur)))
		return (false);
	new_inp = input_draw(new_inp);
	new_inp = new_inp->prev ? input_back_to_writable(new_inp) : new_inp;
	input_goto_line_end(new_inp);
	return (false);
}
