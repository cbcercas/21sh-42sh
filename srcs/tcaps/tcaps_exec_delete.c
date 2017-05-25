/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:04:39 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 13:41:30 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_delete(const t_key *key, t_input *input)
{
	size_t	pos;

	(void)key;
	log_dbg1("exec delete.");
	pos = (input->cpos.cp_col + 1 - (input->offset_col + 1)) +
		  (input->ts.ts_cols * input->offset_line);
	if (input->str->len >= pos)
	{
		string_remove_char(input->str, pos);
		tputs(tgetstr("dm", NULL), 0, &ft_putchar2);
		tputs(tgetstr("dc", NULL), 0, &ft_putchar2);
		tputs(tgetstr("de", NULL), 0, &ft_putchar2);
		redraw_line(input);
	}
	else
		write(1, "\a", 1);
	return (false);
}
