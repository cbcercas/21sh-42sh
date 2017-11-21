/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>

/*
** @brief Helper for get_windows
** @param wd TODO
** @param rst TODO
** @return TODO
*/

static t_window		*get_windows2(t_window *wd, int rst)
{
	if ((rst %= 10) && rst >= 4)
	{
		ft_strdel(&wd->select.str);
		ft_bzero((void *)&wd->select, sizeof(wd->select));
	}
	if ((rst %= 4) && rst >= 2)
		wd->h_lvl = -1;
	if ((rst %= 2) && rst == 1)
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &wd->ts);
	return (wd);
}

/*
** @brief		Create and manage windows data
** @param[in]	rst		the reset byte
** @details		rst can be a byte or an addition of byte like that
**				40	reset h_complet
** 				20	hard reset current input
** 				10	destroy saved input
** 				4	reset the selection data
** 				2	reset history level
** 				1	reset windows size
** 				example:
** 				to reset current and save input and history level:
** 				rst = 32 = 20 + 10 + 2
** 				to reset everything:
** 				rst = 37 = 20 + 10 + 4 + 2 + 1
** @return
*/

t_window			*get_windows(int rst)
{
	static	t_window	*wd = NULL;

	if (wd && !rst)
		return (wd);
	if (!(wd))
	{
		if (!(wd = ft_memalloc(sizeof(*wd))))
			exit(1);
		rst = 77;
	}
	if (rst >= 40)
		wd->h_complet = false;
	if ((rst %= 40) && rst >= 20)
	{
		get_select()->is = false;
		if (!(input_hard_reset(&wd->cur_head)))
			return (NULL);
	}
	if ((rst %= 20) && rst >= 10)
		input_destroy(&wd->save);
	return (get_windows2(wd, rst));
}

t_input				*goto_input(t_input *input, t_input *dest_inp)
{
	t_cpos	dest;

	while (input && input != dest_inp)
	{
		dest = input_get_first_pos(input);
		move_cursor_to(&dest, &input->cpos, get_ts());
		if (input->next)
			tputs(tgetstr("do", NULL), 0, &ft_putchar2);
		else
			break ;
		input = input->next;
	}
	return (input);
}
