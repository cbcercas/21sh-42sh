/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_arrow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:57:33 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/12 15:51:49 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>
#include <history/history.h>
#include <core/prompt.h>

BOOL	exec_arrow_right(const t_key *key, t_input *input)
{
	struct winsize	*ts;
	t_select		*sel;

	log_dbg1("exec arrow right.");
	ts = get_ts();
	sel = get_select();
	if (((size_t) (input->cpos.cp_col + (input->offset_line  * ts->ws_col) - input->offset_col) + input->offset_len) < input->str->len)
	{
		exec_select_arrows(key, input, "right");
		if (input->cpos.cp_col + 1 == ts->ws_col)
			input->offset_line += 1;
		move_cursor_right(&input->cpos, ts);
		if (sel->is)
			sel->cur_end = pos_in_str(input);
	}
	return (false);
}

BOOL	exec_arrow_left(const t_key *key, t_input *input)
{
	struct winsize	*ts;
	t_select		*sel;

	log_dbg1("exec arrow left.");
	ts = get_ts();
	sel = get_select();
	if (((input->cpos.cp_col + ((input->offset_line ) * ts->ws_col) - input->offset_col)) > 0)
	{
		exec_select_arrows(key, input, "left");
		if (input->cpos.cp_col == 0)
			input->offset_line -= 1;
		move_cursor_left(&input->cpos, ts);
		if (sel->is)
			sel->cur_end = pos_in_str(input);
	}
	return (false);
}

static void cpy_input_data(t_input *cpy, t_input *ori)
{
	cpy->prompt_type = ori->prompt_type;
	cpy->prompt_len = ori->prompt_len;
	cpy->offset_col = (unsigned short)ori->prompt_len;
	ft_memmove(&cpy->cpos, &ori->cpos, sizeof(ori->cpos));
}

t_input	*input_back_to_origin(t_input *input)
{
	t_cpos	cpos;
	ssize_t up;

	cpos.cp_col = input->cpos.cp_col;
	cpos.cp_line = 0;
	while (input)
	{
		up = ((input->prompt_len + input->str->len) / input->ts->ws_col);
		if (input->prev && !input->prev->lock)
		{
			tputs(tgetstr("up", NULL), 0, &ft_putchar2);
			while (up-- > 0)
				tputs(tgetstr("up", NULL), 0, &ft_putchar2);
			input = input->prev;
		}
		else
		{
			move_cursor_to_col(&cpos, get_ts(), input->offset_col);
			ft_memmove(&input->cpos, &cpos, sizeof(cpos));
			break;
		}
	}
	return (input);
}

void	input_goto_line_end(t_input *input)
{
	t_cpos	dest;

	dest.cp_line = (unsigned short)((input->prompt_len + input->str->len)
				   / input->ts->ws_col);
	dest.cp_col = (unsigned short)((input->prompt_len + input->str->len)
								   % input->ts->ws_col);
	while (dest.cp_line > input->cpos.cp_line)
		move_cursor_down(&input->cpos);
	move_cursor_to_col(&input->cpos, input->ts, dest.cp_col);
}

BOOL	exec_arrow_up(const t_key *key, t_input *input)
{
	t_input *tmp;

	(void)key;
	log_dbg1("exec arrow up.");
	if (input->lock)
		return (false);
	//TODO add beep
	//if (!(tmp = input_from_history(history_get_next(input_to_history
	//(input_get_writable(input))))))
	if (!(tmp = input_from_history(history_get_n((get_windows(0)->histlvl)++))))
		return(false);
	input = input_back_to_origin(input);
	cpy_input_data(tmp, input);
	if (get_windows(0)->save == NULL)
		get_windows(0)->save = input;
	else
		input_destroy(&input);
	if (get_windows(0)->save->prev)
		get_windows(0)->save->prev->next = tmp;
	else
		get_windows(0)->cur_head = tmp;
	tmp->prev = get_windows(0)->save->prev;
	get_windows(0)->cur = tmp;
	tmp = input_draw(tmp);
	tmp = input_back_to_origin(tmp);
	input_goto_line_end(tmp);
	return (false);
}

BOOL	exec_arrow_down(const t_key *key, t_input *input)
{
	(void)input;
	(void)key;
	log_dbg1("exec arrow down.");
	//TODO add history
	//tputs(tgetstr(key->key_code, NULL), 0, &ft_putchar2);
	sh_history_down(input);
	//redraw_line(input);
	return (false);
}
