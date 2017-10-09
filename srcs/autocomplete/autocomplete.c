/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:35 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/09 19:25:53 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

static size_t	autocomplete_len_cur_word(size_t start, t_input *input)
{
	size_t	i;
	size_t	pos;

	i = 0;
	if (!input || !input->str || start > input->str->len)
		return (i);
	pos = pos_in_str(*input);
	if (input->str->s[pos] == '/')
		pos++;
	while (start + i < pos && start + i < input->str->len &&\
				input->str->s[start + i] != ' ')
		i++;
	return (i);
}

static t_array	*autocomplete_filter(t_array *content, t_input *input)
{
	size_t		i;
	t_string	*string;
	char		*current;

	i = 0;
	if (!content || !(current = find_word_cur(input)))
		return (content);
	while (i < content->used)
	{
		string = (t_string *)array_get_at(content, i);
		if (string && !autocomplete_strnequ(string->s, current,\
				ft_strlen(current)))
		{
			content = array_remove_at(content, i, NULL);
			i = 0;
		}
		else
			i++;
	}
	return (content);
}

t_input			*autocomplete(t_array *content, t_input *input)
{
	t_string	*string;
	size_t		pos;
	size_t		len;

	if (content && content->used <= 3000)
		content = autocomplete_filter(content, input);
	if (content && content->used == 1)
	{
		pos = get_index_cur(input);
		len = autocomplete_len_cur_word(pos, input);
		if ((string = (t_string *)array_get_at(content, 0)))
		{
			string_remove(input->str, pos, len);
			string_insert(input->str, string->s, pos);
			autocomplete_display_line(input, ft_strlen(string->s) - len);
		}
	}
	if (content && content->used <= 0)
		return (input);
	if (content && content->used <= 3000 && content->used != 1) //TODO : voir si on baisse la limit
		content = autocomplete_sort_content(content);
	autocomplete_display(content);
	array_destroy(&content, NULL);
	return (input);
}
