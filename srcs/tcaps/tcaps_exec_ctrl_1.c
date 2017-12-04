/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:47:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/22 12:14:40 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_ctrl_c(const t_key *key, t_input *input)
{
	(void)key;
	while (input && (input = input->next))
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
	get_windows(72);
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	tputs("\n", 0, &ft_putc_in);
	tputs(tgetstr("cd", NULL), 0, &ft_putc_in);
	get_windows(0) ? get_windows(0)->cur = NULL : 0;
	return (true);
}

BOOL	exec_ctrl_d(const t_key *key, t_input *input)
{
	if (get_select()->is)
		return (false);
	if (input->str->len == 0)
	{
		sh_history_save();
		default_terminal_mode();
		exit(EXIT_SUCCESS);
	}
	else
		exec_delete(key, input);
	return (false);
}

BOOL	exec_ctrl_z(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	if (get_select()->is)
		return (false);
	tcaps_bell();
	tputs(tgetstr("vb", NULL), 0, &ft_putc_in);
	return (false);
}

BOOL	exec_ctrl_a(const t_key *key, t_input *input)
{
	if (get_select()->is)
		return (false);
	exec_start(key, input);
	return (false);
}

BOOL	exec_ctrl_e(const t_key *key, t_input *input)
{
	if (get_select()->is)
		return (false);
	exec_end(key, input);
	return (false);
}
