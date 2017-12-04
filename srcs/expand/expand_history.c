/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>
#include <core/color.h>

size_t		find_last_quote(char *s)
{
	size_t		i;

	i = 0;
	if (!s || !*s)
		return (0);
	i++;
	while(s[i] && s[i] != '\'')
		i++;
	if (s[i])
		i++;
	return (i);
}

/*
** @brief Expands the history
** @param exp TODO
** @return TODO
*/

static BOOL expand_hist_loop(size_t *i, t_input *inp)
{
	if (inp->str->s[*i] == '\\')
		*i += 2;
	else if (inp->str->s[*i] == '!' && inp->str->s[*i + 1] == '!')
	{
		if (!expand_hist_replace(inp, (char *)sh_history_get_at(-1), i, 2))
			return (false);
	}
	else if (inp->str->s[*i] == '!' && (ft_atoi(&inp->str->s[*i + 1]) != 0))
	{
		if (!expand_hist_digit(inp, i))
			return (false);
	}
	else if (inp->str->s[*i] == '!' && ft_isalpha(inp->str->s[*i + 1]))
	{
		if (!expand_hist_alpha(inp, i))
			return (false);
	}
	else
		*i += 1;
	return (true);
}

static void		expand_hist_aff(void)
{
	t_input		*inp;

	inp = input_get_cur_head();
	while (inp)
	{
		if (inp->str)
		{
			if (get_data(NULL) && get_data(NULL)->opts.color)
				ft_dprintf(STDIN_FILENO, "%s%s%s\n", C_YELLOW, inp->str->s, C_NONE);
			else
				ft_dprintf(STDIN_FILENO, "%s\n", inp->str->s);
		}
		inp = inp->next;
	}
}

BOOL	expand_hist(t_input *input)
{
	size_t	i;

	while (input)
	{
		i = 0;
		if (!(input = expand_hist_find(input, &i)))
			break;
		while (input->str->s[i])
		{
			if (input->str->s[i] == '\'')
				i = find_last_quote(&input->str->s[i]) + i;
			else if (input->str && !expand_hist_loop(&i, input))
				return (false);
		}
		input = input->next;
	}
	expand_hist_aff();
	return (true);
}