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
#include <core/color.h>

static void		expand_hist_aff(char *str)
{
	if (str)
	{
		if (get_data(NULL) && get_data(NULL)->opts.color)
			ft_dprintf(STDIN_FILENO, "\n%s%s%s", C_YELLOW, str, C_NONE);
		else
			ft_dprintf(STDIN_FILENO, "\n%s", str);
	}
}

static void		expand_aff_multi(char *hist)
{
	t_input	*disp;

	disp = input_from_history(hist);
	while (disp && disp->next)
	{
		if (disp->str)
			expand_hist_aff(disp->str->s);
		disp = disp->next;
	}
	if (disp && disp->str)
		expand_hist_aff(disp->str->s);
	while(disp && disp->prev)
		disp = disp->prev;
	ft_putc_in('\n');
	if (disp)
		input_destroy(&disp);
}

static BOOL expand_hist_replace_multi(t_input *input, char *hist, size_t index)
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
	input_get_last(input)->next = next_save;
	ft_strdel(&tmp);
	return (true);
}

BOOL expand_hist_replace(t_input *input, char *hist, size_t *index, size_t len)
{
	BOOL	ret;

	if (!hist || !input)
		return (false);
	string_remove(input->str, *index, len);
	if (!ft_strchr(hist, '\\'))
	{
		string_insert(input->str, hist, *index);
		*index += (size_t)ft_strlen(hist);
		expand_hist_aff(hist);
		ft_putc_in('\n');
		return (true);
	}
	ret = expand_hist_replace_multi(input, hist, *index);
	*index += input->str->len;
	expand_aff_multi(hist);
	return (ret);
}
