/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_arrow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:57:33 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/17 18:50:10 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/tcaps.h>

BOOL	exec_arrow_right(const t_key *key, t_input *input)
{
	(void)input;
	(void)key;

	log_dbg1("exec arrow right.");
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

BOOL	exec_arrow_left(const t_key *key, t_input *input)
{
	(void)key;
	log_dbg1("exec arrow left.");
	if (((input->cpos.cp_col + ((input->offset_line ) * input->ts.ts_cols) - input->offset_col)) > 0)
	{
		if (input->cpos.cp_col == 0)
			input->offset_line -= 1;
		move_cursor_left(&input->cpos, &input->ts);
	}
	else
		write(1, "\a", 1);
	return (false);
}

BOOL	exec_arrow_up(const t_key *key, t_input *input)
{
	(void)input;
	(void)key;
	log_dbg1("exec arrow up.");
	//TODO add history
	//tputs(tgetstr(key->key_code, NULL), 0, &ft_putchar2);
	return (false);
}

BOOL	exec_arrow_down(const t_key *key, t_input *input)
{
	(void)input;
	(void)key;
	log_dbg1("exec arrow down.");
	//TODO add history
	//tputs(tgetstr(key->key_code, NULL), 0, &ft_putchar2);
	return (false);
}
