/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_escape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:06:00 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/04 15:06:00 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/bool.h>
#include <core/tcaps.h>

BOOL exec_escape_select(t_window *wd)
{
	t_cpos		cpos;

	if (wd->autocomp && !wd->autocomp->active)
	{
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	}
	tputs(tgetstr("cd", NULL), 0, &ft_putc_in);
	tputs(tgetstr("up", NULL), 0, &ft_putc_in);
	tputs(tgetstr("ve", NULL), 0, &ft_putc_in);
	cpos = wd->cur->cpos;
	cpos.cp_col = 0;
	move_cursor_to(&wd->cur->cpos, &cpos, &wd->ts);
	select_exit(EXIT_SUCCESS, NULL);
	return (false);
}

BOOL exec_escape(const t_key *key, t_window *wd)
{
	(void)key;
	if (wd->autocomp)
		return (exec_escape_select(wd));
	if (wd->select.is)
		exec_insert_off(wd->cur);
	return (false);
}
