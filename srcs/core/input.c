/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 23:04:31 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/input.h>
#include <core/tcaps.h>

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
char	*sh_get_line_old(void)
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

char	*sh_get_line(void)
{
	char		buff[MAX_KEY_STRING_LEN];
	ssize_t		res;
	t_key		key;
	BOOL		stop;
	static t_input		input;
	char *ret;

	ft_bzero(&input, sizeof(input));
	stop = false;
	raw_terminal_mode();
	reset_input(&input);
	while (stop == false)
	{
		ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
		res = read(STDIN_FILENO, buff, MAX_KEY_STRING_LEN);
		buff[res] = '\0';
		key = key_get(buff);
		if (ft_strcmp(key.key_code, KEY_CODE_NONE))
			stop = key_exec(&key, &input);
		else
		{
			if (input.offset_line)
			{
				if (!string_insert(input.str, key.key,
								   (input.ts.ts_cols * input.offset_line) +
								   input.cpos.cp_col - input.offset_col - 1))
					return (NULL);
			}
			else
				if (!string_insert(input.str, key.key, input.cpos.cp_col - input.offset_col - 1))
					return (NULL);
			// insert mode
			tputs(tgetstr("im", NULL), 0, &ft_putchar2);
			ft_putchar(key.key[0]);
			tputs(tgetstr("ie", NULL), 0, &ft_putchar2);
			if (input.cpos.cp_col == input.ts.ts_cols)
			{
				input.cpos.cp_col = 1;
				input.offset_line += 1;
			}
			else
				input.cpos.cp_col += 1;
		}
		key_del(&key);
	}
	default_terminal_mode();
	ret = input.str->len > 0 ? ft_strdup(input.str->s) : NULL;
	return (ret);
}
