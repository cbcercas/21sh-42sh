/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:16:16 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/11 15:39:25 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals/signals.h>
# include <builtins/exit.h>

void	signals_quit(int sig)
{
	default_terminal_mode();
	if(sig == SIGSEGV)
		ft_putstr_fd("\nShell Segfault !\n", 2);
	else if(sig == SIGABRT)
		ft_putstr_fd("Shell Abort", 2);
	else
		ft_dprintf(STDERR_FILENO, "\nShell quit with signal: %d\nGoodbye, "
				"see-you! :)\n", sig);
	log_fatal("Signals: Shell quit with signal: %d", sig);
	kill_childs(SIGTERM);
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
	if (sig == SIGUSR1 || sig == SIGTERM)
		sh_exit(NULL, NULL);
	if (sig == 13)
	{
		if (get_pid_child(-1))
			kill(get_pid_child(-1), SIGKILL);
		exit(EXIT_SUCCESS);
	}
	else if (((sig >= 1 && sig <= 17) || sig == 23 || sig == 24 ||\
					(sig >= 26 && sig <= 31)) && sig != SIGWINCH && sig != 28)
		signals_quit(sig);
	log_info("Signals:Shell cath signal:%d", sig);
}
