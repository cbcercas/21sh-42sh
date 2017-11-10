/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:47:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/15 12:33:05 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>
#include <core/prompt.h>
#include <history/history.h>

BOOL	exec_ctrl_j(const t_key *key, t_input *input)
{
	(void)key;
	if (get_select()->is)
		return (false);
	if (pos_in_str(input) == input->str->len && input->str->len
		&& input->str->s[input->str->len - 1] == '\\' && !input->next)
	{
		tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
		tputs("\n", 0, &ft_putchar2);
		tputs(tgetstr("cd", NULL), 0, &ft_putchar2);
		input->lock = true;
		input_add_new(input);
		get_windows(0)->cur = input->next;
		sh_print_prompt(input->next, NULL, E_RET_LEXER_PIPE);
		return (false);
	}
	while (input->next)
	{
		tputs(tgetstr("do", NULL), 0, &ft_putchar2);
		input = input->next;
	}
	tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
	tputs("\n", 0, &ft_putchar2);
	tputs(tgetstr("cd", NULL), 0, &ft_putchar2);
	return (true);
}

BOOL	exec_ctrl_r(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	if (get_select()->is)
		return (false);
	history_research(input);
	return (false);
}
