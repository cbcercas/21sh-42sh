/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/14 11:10:24 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/input.h>

int	ms_get_command(t_ms_data *data)
{
	t_command	*com_list;
	t_command	*e;
	char		*command;
	int			ret;

	com_list = NULL;
	ret = get_next_line(0, &command);
	if (ret == 1 && ft_strcmp(command, ""))
		com_list = ms_parse_command(command);
	e = com_list;
	while (e)
	{
		if (ms_command(data, e))
			return (1);
		e = e->next;
	}
	// TODO free t_command
	ft_strdel(&command);
	return (0);
}

BOOL remove_escaped_newline(char **input)
{
	size_t	len;

	len = ft_strlen(*input);
	if (*(*input + len - 1) == '\\')
	{
		*(*input + len - 1) = '\0';
		return true;
	}
	return (false);
}

/**
** @brief      Read the input on standard entry
**
** @return     A pointer to the input string
*/
char	*ms_get_line(void)
{
	char	*line;
	char	*input;
	int		ret;

	input = NULL;
	ret = get_next_line(0, &line);
	input = ft_strjoincl(input, line, 3);
	while (remove_escaped_newline(&input))
	{
		ft_printf(">");
		ret = get_next_line(0, &line);
		input = ft_strjoincl(input, line, 3);
	}
	if (*input != '\0')
		return (input);
	ft_strdel(&input);
	return (NULL);
}