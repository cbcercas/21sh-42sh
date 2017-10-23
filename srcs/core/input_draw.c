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

void		draw_char(t_input *input, char *c)
{
	int		len;

	len = 0;
	if (c)
		len = (int)ft_strlen(c);
	redraw_line(input);
	while (len--)
		exec_arrow_right(NULL, input);
}

void	redraw_input(t_input *inp)
{
	t_input	*inpcpy;
	int 	line;

	inpcpy = inp;
	line = 0;
	//TODO prompt_len in history????
	tputs(tgoto(tgetstr("cm", NULL) , tgetnum("li"), (int)inp->prompt_len), 1, &ft_putchar2);
	//clear
	tputs(tgetstr("ce", NULL), 0, ft_putchar2);
	while (inpcpy)
	{
		//TODO check if line is multiline all char are drawed
		tputs(inpcpy->str->s, (int)inpcpy->str->len, &ft_putchar2);
		//TODO increment col pos, offset line...
		inpcpy = inpcpy->next;
		line += 1;
	}
	//TODO refactor to support multiline
	tputs(tgoto(tgetstr("cm", NULL) , tgetnum("li") - line, (int)inp->prompt_len + (int)inp->str->len), 1, &ft_putchar2);
}