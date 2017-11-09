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
#include <core/input.h>
#include <history/history.h>
#include <core/prompt.h>

BOOL	exec_ctrl_c(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	get_windows(72);
	tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
	tputs("\n", 0, &ft_putchar2);
	tputs(tgetstr("cd", NULL), 0, &ft_putchar2);
	get_windows(0)->cur = NULL;
	//sh_history_insert_buf(input->str->s);
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
	write(1, "User pressed CTRL+Z\n", 20);
	exec_ctrl_c(key, input);
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

BOOL	exec_ctrl_l(const t_key *key, t_input *input)
{
	size_t 	pos;
	//TODO REFACTOR need current input (redraw only the last line with "> "

	(void)key;
	if (get_select()->is)
		return (false);
	pos = pos_in_str(input);
	//input->offset_col = sh_len_prompt();
	//input->offset_line = 0;
	//input->cpos.cp_line = 0;
	//input->select.is = false;
	//input->cpos.cp_col = (unsigned short)input->offset_col;
	tputs(tgetstr("cl", NULL), 0, &ft_putchar2);
	sh_print_prompt(input, NULL, E_RET_REDRAW_PROMPT);
	redraw_line(input);
	while (pos != pos_in_str(input))
		exec_arrow_right(NULL, input);
	return (false);
}
