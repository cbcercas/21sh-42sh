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

size_t			find_last_quote(const char *s)
{
	size_t		i;

	i = 0;
	if (!s || !*s)
		return (0);
	i++;
	while (s[i] && s[i] != '\'')
		i++;
	if (s[i])
		i++;
	return (i);
}

/*
** @brief find '!' and call the good function
** @param i index in str
** @param inp current input
** @return true if everything is ok, false otherwise
*/

static BOOL		expand_hist_loop(size_t *i, t_input *inp)
{
	if (inp->str->s[*i] == '\\')
		*i += 2;
	else if (inp->str->s[*i] == '!' && inp->str->s[*i + 1] == '!')
	{
		if (!expand_hist_replace(inp, (char *)sh_history_get_at(-1), i, 3))
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

/*
** @brief display expand
*/

static void		expand_hist_aff(void)
{
	t_input		*inp;

	inp = input_get_cur_head();
	ft_putc_in('\n');
	while (inp)
	{
		if (inp->str)
		{
			if (get_data(NULL) && get_data(NULL)->opts.color)
				ft_dprintf(STDIN_FILENO, "%s%s%s\n", C_YELLOW, inp->str->s,
						C_NONE);
			else
				ft_dprintf(STDIN_FILENO, "%s\n", inp->str->s);
		}
		inp = inp->next;
	}
}

/*
** @brief the main function to expand history
** @param input current input
** @return true if everything is ok, false otherwise
*/

BOOL			expand_hist(t_input *input)
{
	size_t	i;

	while (input)
	{
		i = 0;
		if (!(input = expand_hist_find(input, &i)))
			break ;
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
