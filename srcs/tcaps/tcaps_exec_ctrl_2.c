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
	get_windows(0)->cur = input->next;
	get_windows(0)->cur->prompt_type = E_RET_LEXER_PIPE;
	sh_print_prompt(input->next, NULL, E_RET_LEXER_PIPE);
	return (false);
}

BOOL			exec_ctrl_j(const t_key *key, t_input *input)
{
	t_input		*tmp;
	t_window	*wd;

	(void)key;
	if (!(wd = get_windows(0)))
		return (false);
	if ((wd->autocomp && wd->autocomp->active))
		return (exec_ctrl_j_select(input));
	if (get_select()->is)
		return (false);
	if (MAX_NB_INPUT < count_nb_input(input_get_cur_head()))
	{
		tputs(tgetstr("vb", NULL), 0, &ft_putc_in);
		tcaps_bell();
		return (false);
	}
	tmp = input_get_last(input);
	if (tmp->str && tmp->str->len && tmp->str->s[tmp->str->len - 1] == '\\')
		return (exec_ctrl_j2(input));
	while (input->next)
	{
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		input = input->next;
	}
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	tputs("\n", 0, &ft_putc_in);
	tputs(tgetstr("cd", NULL), 0, &ft_putc_in);
	return (true);
}

BOOL			exec_ctrl_r(const t_key *key, t_input *input)
{
	t_window	*wd;
	(void)key;
	(void)input;

	if (!(wd = get_windows(0)))
		return (false);
	if ((wd->autocomp && wd->autocomp->active))
		return (false);
	if (get_select()->is)
		return (false);
	history_research(input);
	return (false);
}

BOOL			exec_ctrl_l(const t_key *key, t_input *input)
{
	t_window	*wd;
	t_cpos		pos;
	t_input		*tmp;

	(void)key;
	if (!(wd = get_windows(0)))
		return (false);
	if ((wd->autocomp && wd->autocomp->active))
		return (false);
	if (get_select()->is)
		return (false);
	pos.cp_col = input->cpos.cp_col;
	pos.cp_line = 0;
	tmp = input;
	input = input_back_to_writable(input);
	get_windows(1);
	get_windows(0)->cur = input;
	tputs(tgetstr("cl", NULL), 0, &ft_putc_in);
	get_select()->is = false;
	reset_insert_pos();
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	sh_print_prompt(input, NULL, E_RET_REDRAW_PROMPT);
	redraw_input(input);
	//TODO refactor using tgoto
	input = goto_input(input, tmp);
	move_cursor_to(&pos, &input->cpos, get_ts());
	get_windows(0)->cur = input;
	return (false);
}
