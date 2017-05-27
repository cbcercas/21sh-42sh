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
	log_dbg1("exec arrow right.");
	if (input->cpos.cp_col < input->offset + input->str->len + 1)
	{
		tputs(tgetstr(key->key_code, NULL), 0, &ft_putchar2);
		input->cpos = get_cursor_pos();
	}
	else
		write(1, "\a", 1);
	return (false);
}

BOOL	exec_arrow_left(const t_key *key, t_input *input)
{
	log_dbg1("exec arrow right.");
	if (input->cpos.cp_col > input->offset + 1)
	{
		tputs(tgetstr(key->key_code, NULL), 0, &ft_putchar2);
		input->cpos = get_cursor_pos();
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
