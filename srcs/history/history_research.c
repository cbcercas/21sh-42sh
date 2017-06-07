/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_research.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:18:13 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/06 11:18:15 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <history/history.h>

/*char	*history_research_delete(char *line, char *result, BOOL fail)
{
	sh_history_clear_len(line, result, fail);
	if (line && ft_strlen(line))
		line[ft_strlen(line) - 1] = 0;
	return (line);
}*/

void		history_research_prompt(char *buff, char *result, BOOL fail)
{
	if (fail)
		ft_putstr("failing ");
	ft_putstr("bck-i-search:");
	if (buff)
		ft_putstr(buff);
	ft_putstr("_");
	ft_printf("  $>%s", result);
}

BOOL	history_research_search(const char *line, char **result)
{
	t_array	*hists;
	t_hist	*h;
	t_hist	*first;

		ft_strdel(result);
		if (!line || !ft_strlen(line))
			return (true);
		hists = sh_history_get();
		if ((first = (t_hist *)array_get_at(hists, 0)))
		{
			if (!hists->used)
				return (true);
			if (first->cur < 0)
				first->cur = hists->used - 1;
			while (first->cur != -1 && (h = (t_hist *)array_get_at(hists, first->cur)) && !ft_strnequ(line, h->cmd, ft_strlen(line)))
				first->cur--;
			if (ft_strnequ(line, h->cmd, ft_strlen(line)))
				*result = ft_strdup(h->cmd);
			else
				return (true);
		}
	return (false);
}

void	history_research(t_input *input)
{
	char		buff[MAX_KEY_STRING_LEN];
	BOOL		fail;
	char		*line;
	char		*result;
	ssize_t		res;

	history_research_start(&line, &result, &fail);
	ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
	while ((res = read(STDIN_FILENO, buff, MAX_KEY_STRING_LEN)) && ft_strcmp(buff, "\n") && !ISCTRL(buff))
	{
		buff[res] = 0;
		if (ISCTRLR(buff) || ISARR(buff))
			break ;
		//else if (buff[0] == 127 && line)
			//line = history_research_delete(line, result, fail);
		else if (ISIMPRC(buff))
		{
			if (line)
				line = ft_strjoincl(line, buff, 1);
			else
				line = ft_strdup(buff);
		}
		sh_history_clear_len(line, result, fail);
		fail = history_research_search((const char *)line, &result);
		history_research_prompt(line, result, fail);
		ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
	}
	if (line)
		ft_strdel(&line);
	history_research_exit(result, input);
}
