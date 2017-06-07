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

void	history_research_exit(char *result, char *line, BOOL fail, t_input *input)
{

	if (line)
		ft_strdel(&line);
	reset_input(input);
	sh_print_prompt();
	if(result)
	{
		string_replace(input->str, result);
		ft_strdel(&result);
	}
	redraw_line(input);
}

void	history_research_start(char **line, char **result, BOOL *fail)
{
	*line = NULL;
	*result = NULL;
	*fail = false;
	history_research_prompt(*line, "" ,*fail);
}
