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

void			*select_init(t_sel_data *data, t_array *array)
{
	data->array = array;
	if (!(data->words = word_list_create(array)))
		return (select_exit("Word list initialisation failed."));
	return (dsp_init());
}

void			select_deinit(t_sel_data **data)
{
	if (data && *data && (*data)->words)
		word_list_destroy(&(*data)->words);
	//TODO remove t_array
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
