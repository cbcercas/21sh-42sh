/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 15:40:24 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>

/*
** @brief Moves the cursor and input at the beginning
**
** @param input The input
**
** @return Returns the new input state
*/

t_input	*input_back_to_origin(t_input *input)
{
	t_cpos	*save;
	t_cpos	dest;

	save = NULL;
	while (input)
	{
		if (save)
		{
			input->cpos.cp_col = save->cp_col;
			input->cpos.cp_line = (unsigned short)(
				(input->offset_col + input->str->len) / input->ts->ws_col);
		}
		dest = input_get_first_pos(input);
		move_cursor_to(&dest, &input->cpos, get_ts());
		if (input->prev)
			tputs(tgetstr("up", NULL), 0, &ft_putc_in);
		else
			break ;
		save = &input->cpos;
		input = input->prev;
	}
	return (input);
}

/*
** @brief Moves the cursor to line end
** @param input The current input
*/

void	input_goto_line_end(t_input *input)
{
	t_cpos	dest;

	dest = input_get_last_pos(input);
	move_cursor_to(&dest, &input->cpos, input->ts);
}

/*
** @brief Gets the first position
**
** @param input The current input
**
** @return Returns the pos
*/

t_cpos	input_get_first_pos(t_input *input)
{
	t_cpos cpos;

	cpos.cp_col = input->offset_col;
	cpos.cp_line = 0;
	return (cpos);
}

/*
** @brief Gets the last position
**
** @param input The current input
**
** @return Returns the pos
*/

t_cpos	input_get_last_pos(t_input *input)
{
	t_cpos cpos;

	cpos.cp_line = (unsigned short)((input->offset_col + input->str->len)
									/ input->ts->ws_col);
	cpos.cp_col = (unsigned short)((input->offset_col + input->str->len)
								% input->ts->ws_col);
	return (cpos);
}

/*
** @brief Moves the input to the writable area (?TODO)
** @param input The current input
** @return Returns the input
*/

t_input	*input_back_to_writable(t_input *input)
{
	t_cpos	*save;
	t_cpos	dest;

	save = NULL;
	while (input && !input->lock)
	{
		dest = input_get_first_pos(input);
		move_cursor_to(&dest, &input->cpos, get_ts());
		if (save)
		{
			input->cpos.cp_col = save->cp_col;
			input->cpos.cp_line = (unsigned short)(
					(input->offset_col + input->str->len) / input->ts->ws_col);
		}
		dest = input_get_first_pos(input);
		move_cursor_to(&dest, &input->cpos, get_ts());
		if (input->prev && !input->prev->lock)
			tputs(tgetstr("up", NULL), 0, &ft_putc_in);
		else
			break ;
		save = &input->cpos;
		input = input->prev;
	}
	return (input);
}
