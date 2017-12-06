/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 22:55:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/30 23:13:04 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/select.h>
#include <core/tcaps.h>

void	select_select(int selectable, BOOL color, t_array *arr, char *current)
{
	t_sel_data	*data;
	t_cpos		cpos;

	data = select_get_data();

	if (!select_init(data, arr, current))
		return ;
	select_init_opt(selectable, color);
	if ((data->disp.word_num / data->disp.col_num) > data->disp.ts.ws_row)
	{
		//add display all?
		select_exit(EXIT_SUCCESS, NULL);
		return;
	}
	tputs(tgetstr("cr",NULL), 1, &ft_putc_in);
	tputs(tgetstr("do", NULL), 0, &ft_putc_in);
	display_list(data->words, &data->disp);
	tputs(tgetstr("up", NULL), 0, &ft_putc_in);
	cpos = get_windows(0)->cur->cpos;
	cpos.cp_col = 0;
	move_cursor_to(&get_windows(0)->cur->cpos, &cpos, &get_windows(0)->ts);

}