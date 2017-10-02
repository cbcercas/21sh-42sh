/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:35 by jlasne            #+#    #+#             */
/*   Updated: 2017/09/18 16:49:31 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <autocomplete/autocomplete.h>


static t_array *tri_content(t_array *content)
{
	size_t		i;

	i = 0;
	while (content && content->used && i < (content->used - 1) )
	{
		if (ft_strcmp(((t_string *)array_get_at(content, i))->s,\
		 			((t_string *)array_get_at(content, i + 1))->s ) > 0)
		{
			array_swap(content, i, i + 1);
			i = 0;
		}
		else
			i++;
	}
	return (content);
}

static t_array *filter_autocomplete(t_array *content, t_input *input)
{
	size_t		i;
	t_string	*string;
	char *current;

	i = 0;
	if (!content || !(current = find_word_cur(input)))
		return (content);
	while(i < content->used)
	{
		string = (t_string *)array_get_at(content, i);
		if (string && !ft_strnequ(string->s, current, ft_strlen(current)))
		{
			content = array_remove_at(content, i, NULL);
			i = 0;
		}
		else
			i++;
	}
	return (content);
}

t_input *autocomplete(t_array *content, t_input *input)
{
	t_string *string;
	size_t pos;

	if (content && content->used <= 300)
		content = filter_autocomplete(content, input);
	if (content && content->used == 1)
	{
		pos = get_index_cur(input);
		string = (t_string *)array_get_at(content, 0);
		string_remove(input->str, pos, 100000);
		string_insert_back(input->str, string->s);
		redraw_line(input);
		while (input->str->s[pos_in_str(*input)])
			exec_arrow_right(NULL, input);
		array_destroy(&content, NULL);
		return (input);
	}
	if (content && content->used <= 300)
		content = tri_content(content);
	aff(content);
	array_destroy(&content, NULL);
	return (input);
}
