/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:43:58 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/09 19:24:38 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <autocomplete/autocomplete.h>

t_array	*autocomplete_sort_content(t_array *content)
{
	t_array		*clone;
	size_t		tmp_pos;
	t_string	*tmp;
	size_t		i;

	t_string *tmp2;

	tmp_pos = 0;
	i = 1;
	tmp = NULL;
	if (!content || content->used <= 1)
		return (content);
	clone = array_create(content->elem_size);
	if (!clone)
		ft_dprintf(STDERR_FILENO, "%s in %s :ERROR malloc", PROGNAME, __FILE__);
	tmp = (t_string *)array_get_at(content, 0);
	while (content->used && tmp)
	{
		log_info("** used = %zu, tmp = |%s|", content->used, tmp->s);
		while (i < content->used)
		{
			log_info("++ i = %zu, tmp = |%s|", i, tmp->s);
			if (ft_strcmp(tmp->s,\
 				(tmp2 = (t_string *)array_get_at(content, i))->s) > 0)
			{
				tmp = tmp2;
				tmp_pos = i;
			}
			i++;
		}
		array_push(clone, (void *)tmp);
		log_info("REMOVE i = %zu tmp = %s", i, tmp->s);
		array_remove_at(content, tmp_pos, NULL);
		tmp_pos = 0;
		tmp = (t_string *)array_get_at(content, tmp_pos);
		i = 1;
	}
	return (clone);
}
