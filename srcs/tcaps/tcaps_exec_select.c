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

void	reset_select_pos()
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

BOOL	exec_select(const t_key *key, t_input *input)
{
	(void)key;
	if (!get_select()->is)
	{
		get_select()->is = true;
		reset_select_pos();
		input->select_pos.is_set = true;
		input->select_pos.cur_start = pos_in_str(input);
		input->select_pos.cur_end = input->select_pos.cur_start;
	}
	else
	{
		get_select()->is = false;
		reset_select_pos();
		//TODO Refactor
		reset_line(input);
	}
	return (false);
}

void	draw_reverse_char(char c, BOOL is_reverse)
{
	if (is_reverse)
		tputs(tgetstr("mr", NULL), 1, &ft_putchar2);
	ft_putchar(c);
	tputs(tgetstr("me", NULL), 1, &ft_putchar2);

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
		if (((start <= end && is_right_arrow(key->key))
					|| (start >= end && is_left_arrow(key->key))))
			tputs(tgetstr("mr", NULL), 1, &ft_putchar2);
		ft_putchar(input->str->s[pos_in_str(input)]);
		if (input->cpos.cp_col + 1 != ts->ws_col)
			tputs(tgetstr("le", NULL), 0, &ft_putchar2);
		tputs(tgetstr("me", NULL), 1, &ft_putchar2);
	}
	return (false);
}

BOOL	exec_alt_c(const t_key *key, t_input *input)
{
	size_t  start;
	size_t  end;

	(void)key;
	start = input->select_pos.cur_start;
	end = input->select_pos.cur_end;
	if (!get_select()->is)
		return (false);
	log_dbg3("start = %d end = %d", start, end);
	/*ft_strdel(&input->select->str);
	if (start < end)
		input->select->str = ft_strsub(input->str->s, start, end - start);
	else if (start > end)
		input->select->str = ft_strsub(input->str->s, end, start - end);
	else
		input->select->str = ft_strsub(input->str->s, start, 1);
	log_info("copie str =[%s]", input->select->str);*/
	return (false);
}

BOOL	exec_alt_v(const t_key *key, t_input *input)
{
	(void)key;
	if (get_select()->is)
		return (false);
	input->str = string_insert(input->str, get_select()->str, pos_in_str(input));
	redraw_line(input);
	return (false);
}

/*BOOL	exec_alt_x(const t_key *key, t_input *input)
{
	size_t  start;
	size_t  end;

	(void)key;
	start = input->select_pos.cur_start;
	end = input->select_pos.cur_end;
	if (!get_select()->is)
		return (false);
	exec_alt_c(key, input);
	if (start < end)
		string_remove(input->str, start, end - start);
	else if (start > end)
		string_remove(input->str, end, start - end);
	else
		string_remove(input->str, start, 1);
	redraw_line(input);
	return (false);
}*/
