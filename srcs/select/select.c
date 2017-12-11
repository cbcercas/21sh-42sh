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

static void	select_print_all(t_window *wd)
{
	char	buff[MAX_KEY_STRING_LEN];
	t_cpos	cpos;

	tputs(tgetstr("cr",NULL), 1, &ft_putc_in);
	tputs(tgetstr("do", NULL), 0, &ft_putc_in);
	ft_dprintf(STDIN_FILENO,
			   "%s: do you wish to see all %zu possibilities (%zu lines)? ",
			   PROGNAME, wd->autocomp->disp.word_num,
			   (wd->autocomp->disp.word_num / wd->autocomp->disp.col_num));
	read(STDIN_FILENO, &buff, 1);
	ft_putc_in((int)*buff);
	tputs(tgetstr("cr",NULL), 1, &ft_putc_in);
	tputs(tgetstr("do", NULL), 0, &ft_putc_in);
	if (*buff == 'y' || *buff == 'Y')
	{
		default_terminal_mode();
		display_list_force(wd->autocomp->words, &wd->autocomp->disp);
		raw_terminal_mode();
	}
	select_deinit(&wd->autocomp, false);
	cpos = wd->cur->cpos;
	ft_bzero(&wd->cur->cpos, sizeof(wd->cur->cpos));
	sh_print_prompt(wd->cur, NULL, E_RET_REDRAW_PROMPT);
	redraw_input(wd->cur);
	move_cursor_to(&cpos, &wd->cur->cpos, &wd->ts);
}

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
		select_print_all(wd);
		return;
	}
	tputs(tgetstr("cr",NULL), 1, &ft_putc_in);
	tputs(tgetstr("do", NULL), 0, &ft_putc_in);
	display_list(wd->autocomp->words, &wd->autocomp->disp);
	tputs(tgetstr("up", NULL), 0, &ft_putc_in);
	cpos = wd->cur->cpos;
	cpos.cp_col = 0;
	move_cursor_to(&wd->cur->cpos, &cpos, &wd->ts);
}