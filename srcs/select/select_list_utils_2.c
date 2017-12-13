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
		word->cursor = true;
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
