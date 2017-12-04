/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_arrow_select.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:57:33 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/17 18:50:10 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL exec_arrow_right_select(t_sel_data *data)
{
	t_sel_word	*cur;

	log_dbg1("exec arrow right select.");
	if (!(cur = word_get_current()))
		return (true);
	if (cur == cur->next)
	{
		tcaps_bell();
		return (false);
	}
	cur->cursor = false;
	display_word(cur, &data->disp);
	cur = cur->next;
	cur->cursor = true;
	if ((cur->num - data->disp.first->num) >= (size_t)((data->disp.ts.ws_row - 1) * data->disp.col_num))
	{
		data->disp.first = word_get_num(data->disp.first->num + data->disp.col_num);
		tputs(tparm(tgetstr("cm", NULL), data->disp.ts.ws_row, 0), 0,
			  &ft_putc_in);
		tputs(tgetstr("sf", NULL), 1, &ft_putc_in);
		tputs(tparm(tgetstr("cm", NULL), 1, 0), 0, &ft_putc_in);
		display_line(cur, &data->disp);
	}
	else
		display_word(cur, &data->disp);
	return (false);
}

BOOL exec_arrow_left_select(t_sel_data *data)
{
	t_sel_word	*cur;

	log_dbg1("exec arrow left select.");
	if (!(cur = word_get_current()))
		return (true);
	if (cur == cur->prev)
	{
		tcaps_bell();
		return (false);
	}
	cur->cursor = false;
	display_word(cur, &data->disp);
	cur = cur->prev;
	cur->cursor = true;
	if (cur->num < data->disp.first->num)
	{
		data->disp.first = word_get_num(cur->num - (cur->num % data->disp.col_num));
		tputs(tgetstr("sr", NULL), 0, &ft_putc_in);
	}
	display_line(cur, &data->disp);
	return (false);
}

BOOL exec_arrow_up_select(t_sel_data *data)
{
	t_sel_word	*cur;

	log_dbg1("exec arrow up select.");
	if (!(cur = word_get_current()))
		return (true);
	if ((cur->num < data->disp.col_num))
	{
		tcaps_bell();
		return (false);
	}
	cur->cursor = false;
	display_word(cur, &data->disp);
	cur = word_get_num(cur->num - data->disp.col_num);
	cur->cursor = true;
	if (cur->num < data->disp.first->num)
	{
		data->disp.first = word_get_num(data->disp.first->num - data->disp.col_num);
		tputs(tgetstr("sr", NULL), 0, &ft_putc_in);
	}
	display_line(cur, &data->disp);
	return (false);
}

BOOL exec_arrow_down_select(t_sel_data *data)
{
	t_sel_word	*cur;

	log_dbg1("exec arrow down select.");
	if (!(cur = word_get_current()))
		return (true);
	if ((cur->num + data->disp.col_num) >= (data->disp.word_num))
	{
		tcaps_bell();
		return (false);
	}
	cur->cursor = false;
	display_word(cur, &data->disp);
	cur = word_get_num(cur->num + data->disp.col_num);
	cur->cursor = true;
	if (data->disp.ts.ws_row - 1 <= (USHRT)(((cur->num - data->disp.first->num) / data->disp.col_num)))
	{
		data->disp.first = word_get_num(data->disp.first->num + data->disp.col_num);
		tputs(tparm(tgetstr("cm", NULL), data->disp.ts.ws_row, 0), 0,
			  &ft_putc_in);
		tputs(tgetstr("sf", NULL), 1, &ft_putc_in);
		tputs(tparm(tgetstr("cm", NULL), 1, 0), 0, &ft_putc_in);
	}
	display_line(cur, &data->disp);
	return (false);
}