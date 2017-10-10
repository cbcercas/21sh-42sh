/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:43:58 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/10 17:05:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <autocomplete/autocomplete.h>

void autocomplete_sort_loop(t_string **tmp, t_array *content, size_t *tmp_pos)
{
	t_string	*tmp2;
	size_t		i;

	i = 1;
	while (i < content->used)
	{
		if (ft_strcmp((*tmp)->s,\
			(tmp2 = (t_string *)array_get_at(content, i))->s) > 0)
		{
			*tmp = tmp2;
			*tmp_pos = i;
		}
		i++;
	}
}

t_array	*autocomplete_sort_content(t_array *content)
{
	t_array		*clone;
	size_t		tmp_pos;
	t_string	*tmp;

	tmp_pos = 0;
	tmp = NULL;
	if (!content || content->used <= 1)
		return (content);
	if (!(clone = array_create(content->elem_size)))
		ft_dprintf(STDERR_FILENO, "%s in %s :ERROR malloc", PROGNAME, __FILE__);
	tmp = (t_string *)array_get_at(content, 0);
	while (content->used && tmp)
	{
		autocomplete_sort_loop(&tmp, content, &tmp_pos);
		array_push(clone, (void *)tmp);
		array_remove_at(content, tmp_pos, NULL);
		tmp_pos = 0;
		tmp = (t_string *)array_get_at(content, tmp_pos);
	}
	array_destroy(&content, NULL);
	return (clone);
}
