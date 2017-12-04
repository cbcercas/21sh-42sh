/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:35 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/10 15:47:14 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

static t_array	*autocomplete_filter(t_array *content, t_input *input)
{
	size_t		i;
	t_string	*string;
	char		*current;
	t_string	remove;

	i = 0;
	if (!content || !(current = find_word_cur(input)))
		return (content);
	while (i < content->used)
	{
		string = (t_string *)array_get_at(content, i);
		if (string && !autocomplete_strnequ(string->s, current,\
				ft_strlen(current)))
		{
			content = array_remove_at(content, i, &remove);
			string_clear(&remove);
		}
		else
			i++;
	}
	return (content);
}

t_array			*autocomplete(t_array *content, t_input *input)
{
	if (content && content->used <= 3000)
		content = autocomplete_filter(content, input);
	if (content && content->used == 0)
		array_destroy(&content, &string_clear);
	if (content && content->used <= 3000 && content->used != 1) //TODO : voir si on baisse la limit
		content = autocomplete_sort_content(content);
	ft_secu_free_lvl(M_LVL_AUTOC);
	return (content);
}
