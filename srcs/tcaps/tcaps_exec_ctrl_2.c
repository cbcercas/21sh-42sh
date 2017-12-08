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

static BOOL		exec_ctrl_j2(t_window *wd)
{
	t_cpos		dest;

	default_terminal_mode();
	if (get_data(NULL) && get_data(NULL)->opts.verbose)
		ft_putchar_fd('\n', STDIN_FILENO);
	print_verb(input_get_last(wd->cur)->str->s);
	raw_terminal_mode();
	while (wd->cur && wd->cur->next)
	{
		dest = input_get_first_pos(wd->cur);
		move_cursor_to(&dest, &wd->cur->cpos, get_ts());
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		wd->cur->lock = true;
		wd->cur = wd->cur->next;
	}
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	if (!get_data(NULL) || !get_data(NULL)->opts.verbose)
		tputs("\n", 0, &ft_putc_in);
	tputs(tgetstr("cd", NULL), 0, &ft_putc_in);
	wd->cur->lock = true;
	input_add_new(wd->cur);
	wd->cur = wd->cur->next;
	input_get_cur()->prompt_type = E_RET_LEXER_PIPE;
	sh_print_prompt(wd->cur, NULL, E_RET_LEXER_PIPE);
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

BOOL			exec_ctrl_j(const t_key *key, t_window *wd)
{
	t_input		*tmp;
	size_t		tmp_i;

	(void)key;
	if ((wd->autocomp && wd->autocomp->active))
		return (exec_ctrl_j_select(wd));
	if (wd->select.is)
		return (false);
	if (expand_hist_find(input_back_to_writable(wd->cur), &tmp_i))
		return (exec_ctr_j_hist(wd->cur));
	if (MAX_NB_INPUT < count_nb_input(input_get_cur_head()))
	{
		tcaps_bell();
		return (false);
	}
	tmp = input_get_last(wd->cur);
	if (tmp && tmp->str && tmp->str->len && tmp->str->s[tmp->str->len - 1] == '\\')
		return (exec_ctrl_j2(wd));
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	tputs("\n", 0, &ft_putc_in);
	tputs(tgetstr("cd", NULL), 0, &ft_putc_in);
	return (true);
}

BOOL			exec_ctrl_r(const t_key *key, t_window *wd)
{
	(void)key;

	if ((wd->autocomp && wd->autocomp->active))
		return (false);
	else if (wd->autocomp)
		get_windows(100);
	if (get_select()->is)
		return (false);
	history_research(wd->cur);
	return (false);
}

BOOL			exec_ctrl_l(const t_key *key, t_window *wd)
{
	t_cpos		pos;
	t_input		*tmp;

	(void)key;
	if ((wd->autocomp && wd->autocomp->active))
		return (false);
	else if (wd->autocomp)
		get_windows(100);
	if (get_select()->is)
		return (false);
	pos.cp_col = wd->cur->cpos.cp_col;
	pos.cp_line = 0;
	tmp = wd->cur;
	wd->cur = input_back_to_writable(wd->cur);
	get_windows(1);
	tputs(tgetstr("cl", NULL), 0, &ft_putc_in);
	get_select()->is = false;
	reset_insert_pos();
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	sh_print_prompt(wd->cur, NULL, E_RET_REDRAW_PROMPT);
	redraw_input(wd->cur);
	//TODO refactor using tgoto
	wd->cur = goto_input(wd->cur, tmp);
	move_cursor_to(&pos, &wd->cur->cpos, get_ts());
	return (false);
}
