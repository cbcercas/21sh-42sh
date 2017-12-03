/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_history_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

static size_t strlen_alpha_after(const char *str)
{
	size_t		i;

	i = 0;
	if (*str != '!')
		return (0);
	while (str[i] && (str[i] != ' ' || ( i != 0 && str[i - 1] == '\\')))
		i++;
	return (i);
}

/*
** @brief Calculates the lenght of a number
** Example: `10` = 2 or `1970` = 4
**
** @param str The number in string form
**
** @return Returns the number's lenght
*/

size_t			ft_numlen(const char *str)
{
	size_t		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

/*
** @brief TODO
** @param exp TODO
** @param i TODO
** @param len TODO
** @return TODO
*/

BOOL expand_hist_digit(t_input *inp, size_t *i)
{
	int			nb;
	size_t		size;

	size = ft_numlen(&inp->str->s[*i + 1]);
	if ((nb = ft_atoi(&inp->str->s[*i + 1])) != 0)
	{
		if (expand_hist_replace(inp, (char *)sh_history_get_at(nb), i, size + 1))
			return (true);
		ft_dprintf(STDERR_FILENO, "\n%s: !%d: event not found\n", PROGNAME, nb);
	}
	return (false);
}

/*
** @brief TODO
** @param exp TODO
** @param i TODO
** @param len TODO
** @return TODO
*/

BOOL expand_hist_alpha(t_input *inp, size_t *i)
{
	size_t		len;
	char		*search;

	len = strlen_alpha_after(&inp->str->s[*i]);
	if ((search = ft_strsub(&inp->str->s[*i], 1, len)))
	{
		if (expand_hist_replace(inp, (char *) sh_history_get_search(search), i,
								len + 1))
		{
			ft_strdel(&search);
			return (true);
		}
		ft_dprintf(STDERR_FILENO, "\n%s: !%s: event not found\n", PROGNAME,
				search);
	}
	ft_strdel(&search);
	return (false);
}

t_input *expand_hist_find(t_input *input, size_t *i)
{
	while (input)
	{
		if (!input->str)
		{
			input = input->next;
			continue ;
		}
		*i = 0;
		while (input->str->s[*i] && (input->str->s[*i] != '!' ||
				(*i != 0 && input->str->s[(*i - 1)] == '\\') ||
				!input->str->s[*i + 1]))
		{
			if (input->str->s[*i] == '\'')
				*i = find_last_quote(&input->str->s[*i]) + *i;
			else
				*i = *i + 1;
		}
		if (*i != input->str->len)
			return (input);
		input = input->next;
	}
	*i = 0;
	return (NULL);
}