/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/25 20:15:46 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/input.h>

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
char	*sh_get_line(void)
{
	char	*line;
	char	*input;

	input = NULL;
	(void)get_next_line(0, &line);
	input = ft_strjoincl(input, line, 3);
	while (remove_escaped_newline(&input))
	{
		ft_printf(">");
		(void)get_next_line(0, &line);
		input = ft_strjoincl(input, line, 3);
	}
	if (*input != '\0')
		return (input);
	ft_strdel(&input);
	return (NULL);
}

char	*sh_get_line2(void)
{
	char		buff[MAX_KEY_STRING_LEN];
	ssize_t		res;
	t_key		key;
	BOOL		stop;
	t_string	*input;
	char 		*ret;

	input = string_create();
	stop = false;
	while (stop == false)
	{
		raw_terminal_mode();
		(void) ft_bzero((void *) buff, MAX_KEY_STRING_LEN);
		res = read(STDIN_FILENO, buff, MAX_KEY_STRING_LEN);
		buff[res] = '\0';
		key = key_get(buff);
		if (ft_strcmp(key.key_code, KEY_CODE_NONE))
			stop = key_exec(&key);
		else if (ft_isprint(key.key[0]))
		{
			string_insert_back(input, key.key);
			ft_printf("%c", key.key[0]);
		}
		key_del(&key);
		default_terminal_mode();
	}
	ret = ft_strdup(input->s);
	//ft_printf("\n\nret =\"%s\"", ret);
	string_del(&input);
	return (ret);
}