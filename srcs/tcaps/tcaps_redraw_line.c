/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_redraw_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:41:47 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 06:00:26 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

void	redraw_line(t_input *input)
{
	char	*tmp;
	int		len;
	int		line;
	int		col;

	line = 0;
	col = 0;
	tputs(tgetstr("cd", NULL), 0, &ft_putc_in);
	if (input->str->len == 0)
		return ;
	tmp = input->str->s + pos_in_str(input);
	len = (int)ft_strlen(tmp);
	tputs(tmp, len, &ft_putc_in);
	if (len > (input->ts->ws_col - input->cpos.cp_col))
		line = (len - (input->ts->ws_col - input->cpos.cp_col))
						/ input->ts->ws_col + ((len - (input->ts->ws_col
							- input->cpos.cp_col)) % input->ts->ws_col ? 1 : 0);
	while (line--)
		tputs(tgetstr("up", NULL), 0, &ft_putc_in);
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	while (col++ < input->cpos.cp_col)
		tputs(tgetstr("nd", NULL), 0, &ft_putc_in);
}
