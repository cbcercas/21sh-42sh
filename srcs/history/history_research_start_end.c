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

void	history_research_exit(char *result, char *line, BOOL fail, t_input *input)
{
	unsigned int len;
	//TODO REFACTOR

	len = (fail == true ? 32 : 18);
	sh_history_clear_line(len + ft_strlen(line) + ft_strlen(result));
	if (line)
		ft_strdel(&line);
	reset_input(input);
	sh_print_prompt(input, NULL, 0);
	if(result)
	{
		string_replace(input->str, result);
		ft_strdel(&result);
	}
	redraw_line(input);
	while (pos_in_str(input) < input->str->len)
		exec_arrow_right(NULL, input);
}

/*
** @brief TODO
** @param line TODO
** @param result TODO
** @param fail TODO
*/

void	history_research_start(char **line, char **result, BOOL *fail)
{
	*line = NULL;
	*result = NULL;
	*fail = false;
	sh_history_clear_len(*line, *result, *fail);
	history_research_prompt(*line, "" ,*fail);
}
