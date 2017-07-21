/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:16:16 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/19 16:12:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals/signals.h>

void	signals_quit(int sig)
{
	if(sig == SIGSEGV)
		ft_putstr("\nShell Segfault\n");
	else if(sig == SIGABRT)
		ft_putstr("Shell Abort");
	else
		ft_printf("\nShell quit with signal: %d\nGoodbye, see-you! :)\n", sig);
	log_fatal("Signals: Shell quit with signal: %d", sig);
	//sh_deinit(&data);//TODO si on veut gérer il faut une global dsl mr_chapeau
	exit(128 + (sig % 32));
}

void	signals_sigwinch(void)
{
	size_t 	pos;

	pos = pos_in_str(*g_input);
	g_input->offset_col = sh_len_prompt();
	g_input->offset_line = 0;
	g_input->cpos.cp_line = 0;
	g_input->select.is = false;
	g_input->cpos.cp_col = (unsigned short)g_input->offset_col;
	tputs(tgetstr("cl", NULL), 0, &ft_putchar2);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &g_input->ts);
	sh_print_prompt();
	redraw_line(g_input);
	while (pos != pos_in_str(*g_input))
		exec_arrow_right(NULL, g_input);
}

void    signals_handler(int sig)
{
	if(sig == SIGINT)
	{
		log_info("Signal: User pressed Ctrl+C.");
		ft_putstr("\n");
		//sh_print_prompt();
		return;
	}
	if(sig == SIGWINCH)
		signals_sigwinch();
	if(ISSIGQUIT(sig) && sig != 28)
		signals_quit(sig);
	log_info("Signals:Shell cath signal:%d", sig);
}
