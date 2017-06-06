/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_research_start_end.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:42:12 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/06 11:42:15 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

void	history_mess_quit(int sig)
{
	(void)sig;
	ft_putstr("quit: Ctrl-R or press ENTER");
}

void	history_research_exit(char *line, t_input *input)
{
	sh_history_clear_line();
	reset_input(input);
	sh_print_prompt();
	if(line)
	{
		string_replace(input->str, line);
		ft_strdel(&line);
	}
	//signal(SIGINT, signals_handler); // comme avant
	redraw_line(input);
}

void	history_research_start(char **line, char **result, BOOL *fail)
{
	*line = NULL;
	*result = NULL;
	*fail = false;
	//signal(SIGINT, history_mess_quit);
	history_research_prompt(*line, "" ,*fail);
}
