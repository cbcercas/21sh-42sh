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
	const char	*c;

	if (!hist || !ft_strlen(hist) || !(input = input_new()))
		return (NULL);
	while ((c = ft_strstr(hist, "\\\n")) != NULL)
	{
		if (!string_ninsert(input->str, hist, 0, c - hist));
			sh_exit_error("ERROR Malloc");
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
