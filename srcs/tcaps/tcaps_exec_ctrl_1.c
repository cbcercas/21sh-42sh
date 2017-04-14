/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:47:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 14:30:38 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <tcaps_test.h>

BOOL	exec_ctrl_c(const t_key *key)
{
	(void)key;
	tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
	tputs("\n", 0, &ft_putchar2);
	tputs(tgetstr("cd", NULL), 0, &ft_putchar2);
	return (false);
}

BOOL	exec_ctrl_d(const t_key *key)
{
	(void)key;
	return (true);
}

BOOL	exec_ctrl_z(const t_key *key)
{
	(void)key;
	write(1, "User pressed CTRL+Z\n", 20);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_ctrl_a(const t_key *key)
{
	(void)key;
	write(1, "User pressed CTRL+A\n", 20);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_ctrl_e(const t_key *key)
{
	(void)key;
	write(1, "User pressed CTRL+E\n", 20);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_ctrl_l(const t_key *key)
{
	(void)key;
	write(1, "User pressed CTRL+L\n", 20);
	exec_ctrl_c(key);
	return (false);
}
