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

#include <history/history.h>

/*
** @brief Transforms the t_input input we get into a char*
**
** @param input The current input
**
** @return Returns a char* containing the current input
*/

char		*input_to_history(t_input *input)
{
	char	*line;

	line = NULL;
	if (input == NULL)
		return (NULL);
	while (input)
	{
		if (!(line = ft_strjoincl(line, input->str->s, 1)))
			return (NULL);
		if ((input->next && input->next->str->len)
				&& !(line = ft_strjoincl(line, "\\\n", 1)))
			return (NULL);
		input = input->next;
	}
	return (line);
}

/*
** @brief Turns a history entry into a t_input
** @param hist The history entry
** @return Returns a t_input containing the history entry
*/

t_input		*input_from_history(const char *hist)
{
	t_input		*input;
	t_input		*save;
	const char	*c;

	if (!hist || !ft_strlen(hist) || !(input = input_new()))
		return (NULL);
	save = input;
	while (((c = ft_strstr(hist, "\\\n")) != NULL))
	{
		if (!ft_strncmp(c, "\\\n", 2))
			string_ninsert(save->str, hist, 0, c - hist);
		else
			string_insert(save->str, hist, 0);
		hist = c + ((ft_strncmp(c, "\\\n", 2)) ? 1 : 2);
		if (!(save = input_add_new(save)))
		{
			input_destroy(&input);
			return (NULL);
		}
	}
	//if (input->str->len && input->str->s[input->str->len - 1] == '\\')
	//	input = input_add_new(input);
	string_insert(save->str, hist, 0);
//	while (input->prev)
//		input = input->prev;
	return (input);
}
