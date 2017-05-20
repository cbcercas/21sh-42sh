/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_backspace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:04:39 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/30 13:41:30 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_backspace(const t_key *key, t_input *input)
{
	(void)key;
	log_dbg3("User pressed backspace");
	if (input->offset_line)
		string_remove_char(input->str,
						   (input->ts.ts_cols * input->offset_line) +
						   input->cpos.cp_col - input->offset_col - 2);
	else if (!input->offset_line && input->cpos.cp_col > input->offset_col + 1)
	{
		string_remove_char(input->str,
						   input->cpos.cp_col - input->offset_col - 2);
	}
	else
	{
		tputs(tgetstr("vb", NULL), 0, &ft_putchar2);
		return (false);
	}
		if (input->cpos.cp_col == 1)
	{
		input->cpos = get_cursor_pos();
		input->offset_line -=1;
		tputs(tgoto(tgetstr("cm", NULL), input->ts.ts_cols, input->cpos.cp_line - 2), 1, &ft_putchar2);
		tputs(tgetstr("dm", NULL), 0, &ft_putchar2);
		tputs(tgetstr("dc", NULL), 0, &ft_putchar2);
		tputs(tgetstr("de", NULL), 0, &ft_putchar2);
		input->cpos = get_cursor_pos();
	}
	else
	{
		tputs(tgetstr("le", NULL), 0, &ft_putchar2);
		input->cpos = get_cursor_pos();
		tputs(tgetstr("dm", NULL), 0, &ft_putchar2);
		tputs(tgetstr("dc", NULL), 0, &ft_putchar2);
		tputs(tgetstr("de", NULL), 0, &ft_putchar2);
	}
	return (false);
}