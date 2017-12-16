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

/*
** @brief Exits the program and displays a message
**
** @param sig The signal you want the program to exit with
*/
extern int				g_logger_fd;

void	signals_quit(int sig)
{
	default_terminal_mode();
	if (sig == SIGSEGV)
		ft_putstr_fd("\nShell Segfault !\n", 2);
	else if (sig == SIGABRT)
		ft_putstr_fd("Shell Abort", 2);
	else
	{
		ft_putstr_fd("The Shell Quit suddenly cause signal : ", 2);
		ft_putnbr_fd(sig, 2);
		ft_putchar('\n');
	}
	if (g_logger_fd != -1)
	{
		ft_putstr_fd("Signals: Shell quit with signal:", g_logger_fd);
		ft_putnbr_fd(sig, g_logger_fd);
		ft_putendl_fd("", g_logger_fd);
	}
	kill_childs(SIGTERM);
	exit(128 + (sig % 32));
}

/*
** @brief SIGWINCH signal handler
*/

void	signals_sigwinch(void)
{
	size_t	pos;
	t_input	*input;
	t_input	*tmp;

	if (!isatty(STDIN_FILENO))
		return ;
	input = input_get_cur();
	pos = pos_in_str(input);
	tmp = input;
	input = input_back_to_writable(input);
	get_windows(101);
	if (get_windows(0))
		get_windows(0)->cur = input;
	get_select()->is = false;
	reset_insert_pos();
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	sh_print_prompt(input, NULL, E_RET_REDRAW_PROMPT);
	redraw_input(input);
	input = goto_input(input, tmp);
	while (pos != pos_in_str(input) && pos_in_str(input) < input->str->len)
		move_cursor_right(&input->cpos, get_ts());
	if (get_windows(0))
		get_windows(0)->cur = input;
}

/*
** @brief Signal handler for each `sig`
** @param sig signal
*/

void	signals_handler(int sig)
{
	if (sig == SIGTSTP)
		tcaps_bell();
	else if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDIN_FILENO);
		log_info("Signal: User pressed Ctrl+C.");
	}
	else if (sig == SIGWINCH)
		signals_sigwinch();
	else if (sig == SIGUSR1 || sig == SIGTERM)
		sh_exit(NULL, NULL);
	else if (sig == 13)
	{
		if (get_pid_child(-1))
			kill(get_pid_child(-1), SIGKILL);
		exit(EXIT_SUCCESS);
	}
	else if ((sig >= 1 && sig < 17) || sig == 23 || sig == 24 ||\
					(sig >= 26 && sig <= 31))
		signals_quit(sig);
}

BOOL	*is_in_pipe(void)
{
	static BOOL		stop = true;

	return (&stop);
}
