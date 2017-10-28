/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/20 16:14:17 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>

char	*input_to_history(t_input *input)
{
	char	*line;

	line = NULL;
	if (input == NULL)
		return (NULL);
	while (input)
	{
		if(!(line = ft_strjoincl(line, input->str->s, 1)))
			return (NULL);
		if((input->next && input->next->str->len)
				&& !(line = ft_strjoincl(line, "\\\n", 1)))
			return (NULL);
		input = input->next;
	}
	return (line);
}

t_input *input_from_history(const char *hist)
{
	t_input		*input;
	const char	*c;

	if (!hist || !ft_strlen(hist) || !(input = input_new()))
		return (NULL);
	while ((c = ft_strstr(hist, "\\\n")) != NULL)
	{
		string_ninsert(input->str, hist, 0, c - hist);
		hist = c + 2;
		input = input_add_new(input);
	}
	if (input->str->len && input->str->s[input->str->len - 1] == '\\')
		input = input_add_new(input);
	string_ninsert(input->str, hist, 0, hist - c);
	while (input->prev)
		input = input->prev;
	return (input);
}