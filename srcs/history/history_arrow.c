/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 21:25:24 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/13 14:19:20 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

BOOL	history_exec_arrow_right(t_input *input)
{
	(void)input;
	if (((input->cpos.cp_col + (input->offset_line  * input->ts.ts_cols) - input->offset_col)) < input->str->len)
	{
		if (input->cpos.cp_col + 1 == input->ts.ts_cols)
			input->offset_line += 1;
		move_cursor_right(&input->cpos, &input->ts);
	}
	else
		write(1, "\a", 1);
	return (false);
}

void	sh_history_draw_line(t_input *input, const char *line)
{
	unsigned int len;

	log_dbg3("History: draw=\"%s\" ", line);
	sh_history_clear_line(input->str->len + 3);
	reset_input(input);
	sh_print_prompt();
	if(line)
		string_replace(input->str, line);
	len = input->str->len;
	redraw_line(input);
	while(len--)
		history_exec_arrow_right(input);
}

void	sh_history_up(t_input *input)
{
	t_array	*hists;
	t_hist	*h;
	t_hist	*first;

		hists = sh_history_get();
		if ((first = (t_hist *)array_get_at(hists, 0)))
		{
			if (!hists->used)
				return;
			log_dbg3("History: buf=%s", first->buf);
			log_dbg3("History: use=%d", hists->used);
			log_dbg3("History: cur=%d", first->cur);
			if (first->cur < 0)
				first->cur = hists->used - 1;
			else if(first->cur)
				first->cur--;
			if ((h = (t_hist *)array_get_at(hists, first->cur)))
				sh_history_draw_line(input, (const char *)h->cmd);
		}
}

void	sh_history_down(t_input *input)
{
	t_array	*hists;
	t_hist	*h;
	t_hist	*first;

		hists = sh_history_get();
		if ((first = (t_hist *)array_get_at(hists, 0)))
		{
				if (!first->cur && !ft_strequ(first->cmd, input->str->s))
					return ;
				log_dbg3("History: buf=%s", first->buf);
				log_dbg3("History: use=%d", hists->used);
				log_dbg3("History: cur=%d", first->cur);
				if(hists->used && (size_t)first->cur <= (hists->used - 1))
					first->cur++;
				if(first->cur == (int)hists->used)
				{
					sh_history_draw_line(input, (char *const)first->buf);
					first->cur = -1;
					return ;
				}
				if ((h = (t_hist *)array_get_at(hists, first->cur)))
					sh_history_draw_line(input, (const char *)h->cmd);
		}
}
