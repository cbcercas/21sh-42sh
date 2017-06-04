/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 21:25:24 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/04 16:32:20 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

void sh_history_insert_buf(char *str)
{
	t_array	*hists;
	t_hist	*h;

	hists = sh_history_get();
	if (!str)
		return ;
		if ((h = (t_hist *)array_get_at(hists, 0)))
		{
			if (h->buf)
				ft_strdel(&(h->buf));
				h->buf = ft_strdup(str);
			h->cur = -1;
		}
}

void	sh_history_reset_cur(void)
{
	t_array	*hists;
	t_hist	*h;

	hists = sh_history_get();
	if ((h = (t_hist *)array_get_at(hists, 0)))
		h->cur = -1;
}

void	sh_history_up(t_input *input)
{
	t_array	*hists;
	t_hist	*h;
	t_hist	*first;

		hists = sh_history_get();
		if (!hists->used)
			return;
		if ((first = (t_hist *)array_get_at(hists, 0)))
		{
			log_dbg3("History: buf=%s", first->buf);
								log_dbg3("History: use=%d", hists->used);
				if (first->cur < 0)
					first->cur = hists->used - 1;
				else if(first->cur)
					first->cur--;
				log_dbg3("History: cur=%zu", first->cur);
				if ((h = (t_hist *)array_get_at(hists, first->cur)))
				{
					log_dbg3("History: %zu=\"%s\" ", first->cur, h->cmd);
					reset_input(input);
					redraw_line(input);
					string_replace(input->str, (char *const)h->cmd);
					redraw_line(input);
				}
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
			if (!hists->used)
				return;
					log_dbg3("History: buf=%s", first->buf);
					log_dbg3("History: use=%d", hists->used);
					log_dbg3("History: cur=%d", first->cur);
				if (!first->cur && !ft_strequ(first->cmd, input->str->s))
					return ;
				else if(hists->used && first->cur <= (hists->used - 1))
					first->cur++;
				if(first->cur == hists->used)
				{
					reset_input(input);
					redraw_line(input);
					if (first->buf)
					{
						string_replace(input->str, (char *const)first->buf);
						redraw_line(input);
					}
					first->cur = -1;
					return ;
				}
				if ((h = (t_hist *)array_get_at(hists, first->cur)))
				{
					log_dbg3("History: %zu=\"%s\" ", first->cur, h->cmd);
					reset_input(input);
					redraw_line(input);
					string_replace(input->str, (char *const)h->cmd);
					redraw_line(input);
				}
		}
}
