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
	t_window	*wd;
	t_cpos		cpos;

	if (!(wd = get_windows(0)))
		return ;
	if (!(wd->autocomp = select_get_data()))
		return ;
	if (!select_init(wd->autocomp , arr, current))
		return ((void)exec_escape_select(get_windows(0)));
	select_init_opt(selectable, color);
	if ((wd->autocomp ->disp.word_num / wd->autocomp ->disp.col_num)
		> wd->autocomp ->disp.ts.ws_row)
	{
		//add display all?
		select_exit(EXIT_SUCCESS, NULL);
		return;
	}
	tputs(tgetstr("cr",NULL), 1, &ft_putc_in);
	tputs(tgetstr("do", NULL), 0, &ft_putc_in);
	display_list(wd->autocomp ->words, &wd->autocomp ->disp);
	tputs(tgetstr("up", NULL), 0, &ft_putc_in);
	cpos = get_windows(0)->cur->cpos;
	cpos.cp_col = 0;
	move_cursor_to(&get_windows(0)->cur->cpos, &cpos, &get_windows(0)->ts);

}