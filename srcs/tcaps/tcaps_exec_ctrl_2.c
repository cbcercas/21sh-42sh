/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:47:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 21:18:05 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/tcaps.h>

BOOL	exec_ctrl_j(const t_key *key, t_input *input)
{
	//exec_ctrl_c(key, input);
	(void)key;
	(void)input;
	tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
	tputs("\n", 0, &ft_putchar2);
	tputs(tgetstr("cd", NULL), 0, &ft_putchar2);
	return (true);
}