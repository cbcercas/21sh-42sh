/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:26:58 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/10 13:27:00 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <core/input.h>
#include <core/prompt.h>
#include <tools/tools.h>
#include <core/progname.h>

/*
** @brief Gets the str from input
**
** @return Returns the input
*/

static char		*str_from_input(void)
{
	t_input	*input;
	char	*line;

	input = input_get_cur_head();
	line = NULL;
	if (input == NULL)
		return (NULL);
	while (input && input->str)
	{
		if (!(line = ft_strjoincl(line, input->str->s, 1)))
			sh_exit_error("Error Malloc");
		if (line && input->str && input->str->len && ft_strlen(line) &&
				input->str->s[input->str->len - 1] == '\\')
			line[ft_strlen(line) - 1] = '\0';
		if (input->next && input->str->s[input->str->len - 1] != '\\'
			&& !(line = ft_strjoincl(line, "\n", 1)))
			sh_exit_error("Error Malloc");
		input = input->next;
	}
	return (line);
}

/*
** @brief Gets the input from isatty
**
** @return Returns the input
*/

static char		*sh_get_input_no_tty(void)
{
	char	*line;
	t_input	*input;
	size_t	len;

	line = NULL;
	if (get_next_line(STDIN_FILENO, &line) <= 0)
		return (NULL);
	if ((len = ft_strlen(line)) >= MAX_LEN_INPUT || !is_printstr(line))
	{
		if (len >= MAX_LEN_INPUT)
			ft_dprintf(STDERR_FILENO, "%s: line is too long: %zu, MAX is %zu "
					"\n", PROGNAME, ft_strlen(line), MAX_LEN_INPUT);
		else
			ft_dprintf(STDERR_FILENO, "%s: line: contains non-ascii"
				" characters.\n", PROGNAME);
		ft_strdel(&line);
		return (NULL);
	}
	if (line)
	{
		input = input_get_cur_head();
		string_insert(input->str, line, 0);
		ft_strdel(&line);
	}
	return (str_from_input());
}

/*
** @brief Gets the input
**
** @param data The shell's data used across the program
** @param prompt The prompt string
** @param ret The last return value
**
** @return Returns the input string
*/

char			*sh_get_input(t_sh_data *data, char *prompt, t_return ret)
{
	t_input *input;

	if (!isatty(STDIN_FILENO))
		return (sh_get_input_no_tty());
	else
	{
		if (ret >= E_RET_LEXER_INCOMPLETE && ret <= E_RET_LEXER_PIPE)
		{
			if ((input = input_add_new(input_get_last(input_get_cur_head())))
				== NULL)
				return (NULL);
		}
		else if (!(input = input_get_last(input_get_cur_head())))
			return (NULL);
		(get_windows(0))->cur = input;
		input->prompt_type = ret;
		sh_print_prompt(input, prompt, ret);
		sh_get_line(input, &(data->opts));
	}
	return (str_from_input());
}
