/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/20 16:14:17 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>
#include <core/tcaps.h>

/*
** @brief display char
**
** @param input  current input
** @param c the char to be "draw"
*/

void		draw_char(t_input *input, char *c)
{
	int	len;

	len = 0;
	if (c)
		len = (int)ft_strlen(c);
	redraw_input(input);
	while (len--)
		exec_arrow_right(NULL, input);
}

/*
** TODO add suport of input > ts.ws_line
** draw input from cursor to the end
*/

/*
** @brief display input
**
** @param input start of draw
**
** @return the last input draw
*/

t_input		*input_draw(t_input *input)
{
	while (input)
	{
		redraw_line(input);
		if (input->next)
		{
			input_goto_line_end(input);
			tputs(tgetstr("do", NULL), 0, &ft_putc_in);
			tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
			input = input->next;
		}
		else
			break ;
	}
	return (input);
}

/*
** TODO add suport of input > ts.ws_line
*/

/*
** @brief display input and replace cursor to the origin of input
**
** @param input the current input
*/

void		redraw_input(t_input *input)
{
	t_input	*tmp;
	t_input	*prev;
	t_cpos	cpos;

	prev = input->prev;
	input->prev = NULL;
	ft_memmove(&cpos, &input->cpos, sizeof(cpos));
	tmp = input_draw(input);
	if (tmp != input)
	{
		input_back_to_origin(tmp);
		move_cursor_to(&cpos, &input->cpos, get_ts());
	}
	input->prev = prev;
}
