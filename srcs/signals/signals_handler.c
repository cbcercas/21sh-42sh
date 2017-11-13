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
#include <sys/wait.h>
#include <libft.h>
#include <ftprintf.h>
#include <logger.h>
#include <core/input.h>
#include <term.h>
#include <sys/ioctl.h>
#include <core/prompt.h>
#include <core/tcaps.h>

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
	//TODO REFACTOR
	t_input	*input;

	// TODO need current input
	input = input_get_cur();
	pos = pos_in_str(input);

	// reset term size
	get_windows(1);
	get_select()->is = false;
	reset_select_pos();
	//goto debut ligne
	tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
	sh_print_prompt(input, NULL, E_RET_REDRAW_PROMPT);
	//TODO check when offset prompt
	//input->cpos.cp_line = 0;
	//input->cpos.cp_col = input->offset_col;
	//input->select->is = false;
	redraw_line(input);
	//TODO refactor using tgoto
	while (pos != pos_in_str(input))
		exec_arrow_right(NULL, input);
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
	if (sig == SIGUSR2)
	{
		*get_stop() = false;
		log_dbg3("SIGNAL SIGUSR1 g_stop = %d", *get_stop());
		return ;
	}
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
