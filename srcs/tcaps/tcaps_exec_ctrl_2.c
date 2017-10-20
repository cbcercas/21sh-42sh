/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:47:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/05 15:10:47 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>
#include <core/input.h>
#include <core/prompt.h>
#include <history/history.h>

BOOL	exec_ctrl_j(const t_key *key, t_input *input)
{
	//exec_ctrl_c(key, input);
	//TODO REFACTOR
	(void)key;
	(void)input;
	//string_insert(input->str, key->key, pos_in_str(input));
	tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
	tputs("\n", 0, &ft_putchar2);
	tputs(tgetstr("cd", NULL), 0, &ft_putchar2);
	return (true);
}

BOOL	exec_ctrl_r(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	history_research(input);
	return (false);
}
