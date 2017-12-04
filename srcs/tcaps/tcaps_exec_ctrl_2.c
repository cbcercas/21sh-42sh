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
#include <expand/expand.h>

static BOOL		exec_ctrl_j2(t_input *input)
{
	t_cpos		dest;

	default_terminal_mode();
	if (get_data(NULL) && get_data(NULL)->opts.verbose)
		ft_putchar_fd('\n', STDIN_FILENO);
	print_verb(input_get_last(input)->str->s);
	raw_terminal_mode();
	while (input && input->next)
	{
		dest = input_get_first_pos(input);
		move_cursor_to(&dest, &input->cpos, get_ts());
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		input->lock = true;
		input = input->next;
	}
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	if (!get_data(NULL) || !get_data(NULL)->opts.verbose)
		tputs("\n", 0, &ft_putc_in);
	tputs(tgetstr("cd", NULL), 0, &ft_putc_in);
	input->lock = true;
	input_add_new(input);
	get_windows(0) ? get_windows(0)->cur = input->next : 0;
	input_get_cur()->prompt_type = E_RET_LEXER_PIPE;
	sh_print_prompt(input->next, NULL, E_RET_LEXER_PIPE);
	return (false);
}

static BOOL			exec_ctr_j_hist(t_input *input)
{
	while (input->prev && !input->prev->lock)
		input = input->prev;
	default_terminal_mode();
	if (!expand_hist(input))
		get_windows(72);
	return (true);
}

BOOL			exec_ctrl_j(const t_key *key, t_input *input)
{
	t_input		*tmp;
	size_t		tmp_i;

	(void)key;
	if (get_select()->is)
		return (false);
	input = input_get_cur();
	if (expand_hist_find(input_back_to_writable(input), &tmp_i))
		return (exec_ctr_j_hist(input));
	if (MAX_NB_INPUT < count_nb_input(input_get_cur_head()))
	{
		tcaps_bell();
		return (false);
	}
	tmp = input_get_last(input);
	if (tmp && tmp->str && tmp->str->len && tmp->str->s[tmp->str->len - 1] == '\\')
		return (exec_ctrl_j2(input));
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	tputs("\n", 0, &ft_putc_in);
	tputs(tgetstr("cd", NULL), 0, &ft_putc_in);
	return (true);
}

BOOL			exec_ctrl_r(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	if (get_select()->is)
		return (false);
	history_research(input);
	return (false);
}

BOOL			exec_ctrl_l(const t_key *key, t_input *input)
{
	t_cpos		pos;
	t_input		*tmp;

	(void)key;
	if (get_select()->is)
		return (false);
	pos.cp_col = input->cpos.cp_col;
	pos.cp_line = 0;
	tmp = input;
	input = input_back_to_writable(input);
	get_windows(1);
	get_windows(0) ? get_windows(0)->cur = input : 0;
	tputs(tgetstr("cl", NULL), 0, &ft_putc_in);
	get_select()->is = false;
	reset_select_pos();
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	sh_print_prompt(input, NULL, E_RET_REDRAW_PROMPT);
	redraw_input(input);
	//TODO refactor using tgoto
	input = goto_input(input, tmp);
	move_cursor_to(&pos, &input->cpos, get_ts());
	get_windows(0) ? get_windows(0)->cur = input : 0;
	return (false);
}
