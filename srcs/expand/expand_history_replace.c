/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_history_replace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiforge <guiforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:39:45 by guiforge          #+#    #+#             */
/*   Updated: 2017/12/03 16:39:46 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

/*
** @brief replace the '!' occurence by history in multi input
** @param input current input
** @param hist the replacement str
** @param index is where the replacement is
** @return true if everything is ok, false otherwise
*/

static BOOL		expand_hist_replace_multi(t_input *input, char *hist,
											size_t index)
{
	char		*tmp;
	t_input		*next_save;
	size_t		len;

	len = 0;
	if (!(hist = ft_strjoincl(hist, &input->str->s[index], 0)))
		return (false);
	string_remove(input->str, index, input->str->len);
	while (hist[len] && hist[len] != '\\')
		len++;
	if (!string_insert_back(input->str, tmp = ft_strsub(hist, 0, len)))
		return (false);
	ft_strdel(&tmp);
	tmp = hist;
	hist = ft_strchr(hist, '\n') + 1;
	next_save = input->next;
	input->next = input_from_history(hist);
	if (next_save)
		next_save->prev = input_get_last(input);
	if (input->next)
		input->next->prev = input;
	if (input_get_last(input))
		input_get_last(input)->next = next_save;
	ft_strdel(&tmp);
	return (true);
}

/*
** @brief replace the '!' occurence by history
** @param input current input
** @param hist the replacement str
** @param index is where the replacement is
** @param len the len of occurence
** @return true if everything is ok, false otherwise
*/

BOOL			expand_hist_replace(t_input *input, char *hist, size_t *index,
									size_t len)
{
	BOOL	ret;

	if (!hist || !input)
	{
		ft_dprintf(STDERR_FILENO, "\n%s: !!: event not found\n", PROGNAME);
		get_windows(0)->cur = NULL;
		return (false);
	}
	string_remove(input->str, *index, len - 1);
	if (!ft_strchr(hist, '\\'))
	{
		string_insert(input->str, hist, *index);
		*index += (size_t)ft_strlen(hist);
		ft_putc_in('\n');
		return (true);
	}
	ret = expand_hist_replace_multi(input, hist, *index);
	*index += input->str->len;
	return (ret);
}
