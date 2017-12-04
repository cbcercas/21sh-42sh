/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_research_start_end.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:42:12 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/15 17:02:00 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

/*
** @brief TODO
** @param result TODO
** @param line TODO
** @param fail TODO
** @param input TODO
*/

void	history_research_exit(t_input *result, char *line, t_input *input)
{
	if (line)
		ft_strdel(&line);
	default_terminal_mode();
	if (!result)
		ft_putendl_fd("", STDIN_FILENO);
	raw_terminal_mode();
	sh_print_prompt(input, NULL, E_RET_REDRAW_PROMPT);
	if (result)
	{
		input = input_back_to_writable(input);
		input_to_save(&input, result);
		input = result;
		input = input_draw(input);
		input = input_back_to_writable(input);
		input_goto_line_end(input);
		if (get_windows(0))
			get_windows(0)->cur = input;
	}
}

/*
** @brief TODO
** @param line TODO
** @param result TODO
** @param fail TODO
*/

void	history_research_start(char **line, t_input **result, BOOL *fail)
{
	*line = NULL;
	*result = NULL;
	*fail = false;
	history_research_prompt(*line, *result, *fail);
}
