/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:47:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/04 13:05:53 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_ctrl_c(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	reset_input(input);
	tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
	tputs("\n", 0, &ft_putchar2);
	tputs(tgetstr("cd", NULL), 0, &ft_putchar2);
	sh_history_reset_cur();
	return (true);
}

BOOL	exec_ctrl_d(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	if (input->str->len == 0)
	{
		sh_history_save();
		default_terminal_mode();
		exit(EXIT_SUCCESS);
	}
	return (false);
}

BOOL	exec_ctrl_z(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	write(1, "User pressed CTRL+Z\n", 20);
	exec_ctrl_c(key, input);
	return (false);
}

BOOL	exec_ctrl_a(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	write(1, "User pressed CTRL+A\n", 20);
	exec_ctrl_c(key, input);
	return (false);
}

BOOL	exec_ctrl_e(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	write(1, "User pressed CTRL+E\n", 20);
	exec_ctrl_c(key, input);
	return (false);
}

BOOL	exec_ctrl_l(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	write(1, "User pressed CTRL+L\n", 20);
	exec_ctrl_c(key, input);
	return (false);
}
