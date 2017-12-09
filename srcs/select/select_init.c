/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 22:55:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/30 23:13:04 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/select.h>
#include <autocomplete/autocomplete.h>

void *select_init(t_sel_data *data, t_array *array, char *cur_word)
{
	data->array = array;
	if (!(data->words = word_list_create(array)))
		return (select_exit("Word list initialisation failed."));
	data->cur_word = ft_strlen(cur_word) - autocomplete_len_useless(cur_word);
	return (dsp_init());
}

void			select_deinit(t_sel_data **data)
{
	if (!data || !*data)
		return;
	if ((*data)->words)
		word_list_destroy(&(*data)->words);
	redraw_input(get_windows(0)->cur);
	if ((*data)->array)
		array_destroy(&(*data)->array, (void *(*)(void *))&string_clear);
	ft_memdel((void **)data);
}

void			select_init_opt(int selectable, BOOL color)
{
	t_sel_opt	*opts;

	opts = &select_get_data()->options;
	if (color)
		opts->color = true;
	opts->selectable = selectable;
}
