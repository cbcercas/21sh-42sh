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
	(void)key;
	log_dbg1("exec delete.");
	if (input->str->len >= input->cpos.cp_col - input->offset)
	{
		string_remove_char(input->str, input->cpos.cp_col - input->offset - 1);
		tputs(tgetstr("dm", NULL), 0, &ft_putchar2);
		tputs(tgetstr("dc", NULL), 0, &ft_putchar2);
		tputs(tgetstr("de", NULL), 0, &ft_putchar2);
	}
	else
		write(1, "\a", 1);
	return (false);
}

