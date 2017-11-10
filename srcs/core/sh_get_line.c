/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_line.c                                      :+:      :+:    :+:   */
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
			return (NULL);
		input = input->next;
	}
	return (line);
}

/*
 **récupère l'input en fonction d'isatty
 */

static char		*sh_get_input_no_tty(void)
{
	char	*line;
	t_input	*input;

	line = NULL;
	if (!get_next_line(0, &line))
		return (NULL);
	if (line)
	{
		//TODO what append when lexing incomplet
		input = input_get_cur_head();
		string_insert(input->str, line, 0);
		ft_strdel(&line);
	}
	return (str_from_input());
}

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
		sh_print_prompt(input, prompt, ret);
		sh_get_line(input, &(data->opts));
	}
	return (str_from_input());
}