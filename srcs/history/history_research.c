/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_research.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:18:13 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 16:48:59 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

/*
** @brief Prints the search/fail messages
**
** @param buff Buffer containing the cmd entered by the user
**
** @param result The result got by the history
**
** @param fail Is the research failing (true/false)
*/

void		history_research_prompt(char *buff, t_input *result, BOOL fail)
{
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	tputs(tgetstr("cd", NULL), 0, &ft_putc_in);
	if (fail)
		ft_putstr_fd("failing ", STDIN_FILENO);
	ft_putstr_fd("bck-i-search:", STDIN_FILENO);
	if (buff)
		ft_putstr_fd(buff, STDIN_FILENO);
	ft_putstr_fd("_", STDIN_FILENO);
	ft_dprintf(STDIN_FILENO, "  $>%s");
	if (result)
		redraw_input(result);
}

/*
** @brief Researches in the history
**
** @param line The line entered by the user
**
** @param result The results
**
** @return Returns true if found. False otherwise
*/

BOOL		history_research_search(const char *line, t_input **result)
{
	t_array	*hists;
	t_hist	*h;
	t_hist	*first;

	input_destroy(result);
	*result = NULL;
	if (!line || !ft_strlen(line))
		return (true);
	hists = sh_history_get();
	if ((first = (t_hist *)array_get_at(hists, 0)))
	{
		if (!hists->used)
			return (true);
		if (first->cur < 0)
			first->cur = hists->used - 1;
		while (first->cur != -1 &&\
				(h = (t_hist *)array_get_at(hists, first->cur)) &&\
				!ft_strnequ(line, h->cmd, ft_strlen(line)))
			first->cur--;
		if (ft_strnequ(line, h->cmd, ft_strlen(line)))
			*result = input_from_history((char *)h->cmd);
		else
			return (true);
	}
	return (false);
}

/*
** @brief TODO
** @param buff TODO
** @param line TODO
** @return TODO
*/

static char	*apply_buff(char *buff, char *line)
{
	if (buff[0] == 127 && line && ft_strlen(line))
		line[ft_strlen(line) - 1] = 0;
	else if (is_str_car(buff))
	{
		if (line)
			line = ft_strjoincl(line, buff, 1);
		else
			line = ft_strdup(buff);
	}
	return (line);
}

/*
** @brief TODO
** @param input TODO
*/

void		history_research(t_input *input)
{
	char		buff[MAX_KEY_STRING_LEN];
	BOOL		fail;
	char		*line;
	t_input		*result;

	history_research_start(&line, &result, &fail);
	ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
	while (read(STDIN_FILENO, buff, MAX_KEY_STRING_LEN) &&
			ft_strcmp(buff, "\n") && (is_str_car(buff) || buff[0] == 127))
	{
		line = apply_buff(buff, line);
		fail = history_research_search((const char *)line, &result);
		history_research_prompt(line, result, fail);
		ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
	}
	history_research_exit(result, line, input);
}
