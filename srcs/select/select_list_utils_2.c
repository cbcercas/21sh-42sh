/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:51:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/03 12:51:43 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/select.h>

void	word_renum(t_sel_word *list)
{
	t_sel_word	*cur;

	list->num = 0;
	cur = list->next;
	while (cur != list)
	{
		cur->num = cur->prev->num + 1;
		cur = cur->next;
	}
	select_get_data()->disp.word_num = cur->prev->num + 1;
}

t_sel_word	*word_get_current(void)
{
	t_sel_data	*data;
	t_sel_word	*word;

	data = select_get_data();
	word = data->words;
	while (word && !word->cursor)
		word = word->next;
	if (!word)
	{
		word = data->words;
		word->cursor = true; // TODO if data->word existe pas ?
	}
	return (word);
}

t_sel_word	*word_get_num(size_t num)
{
	t_sel_data	*data;
	t_sel_word	*word;

	data = select_get_data();
	word = data->words;
	while (word && word->num != num && num < data->disp.word_num)
		word = word->next;
	return (word);
}

void	word_print_list(t_sel_word *list)
{
	t_sel_word	*save;
	BOOL	space;

	if (!list)
		return ;
	space = false;
	if (list->select && list->word)
	{
		ft_putstr_fd(list->word, STDOUT_FILENO);
		space = true;
	}
	save = list;
	list = list->next;
	while (list && list != save)
	{
		if (list->select && list->word)
		{
			if (space)
				ft_putchar_fd('.', STDOUT_FILENO);
			ft_putstr_fd(list->word, STDOUT_FILENO);
			space = true;
		}
		list = list->next;
	}
}
