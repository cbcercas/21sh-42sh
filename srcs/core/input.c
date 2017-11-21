/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 15:40:24 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>
#include <core/tcaps.h>
#include <tools/tools.h>

/*
** @brief Creates a new t_input
**
** @return Returns the new t_input
*/

t_input			*input_new(void)
{
	t_input	*input;

	if (!(input = ft_memalloc(sizeof(*input))))
		return (NULL);
	input->next = NULL;
	input->prev = NULL;
	input->ts = get_ts();
	input->lock = false;
	input_reset(input);
	return (input);
}

/*
** @brief Resests the input by destroying it and creating a new one
**
** @param input The t_input to be `reseted`
**
** @return Returns the new input
*/

t_input			*input_hard_reset(t_input **input)
{
	input_destroy(input);
	*input = input_new();
	return (*input);
}

/*
** @brief TODO
** @param input TODO
** @return TODO
*/

t_input			*input_add_new(t_input *input)
{
	t_input	*save;

	if (!input)
		return (NULL);
	save = input->next;
	if ((input->next = input_new()) == NULL)
		return (NULL);
	input->next->prev = input;
	input->next->next = save;
	if (save)
		save->prev = input->next;
	return (input->next);
}

/*
** @brief TODO
** @param input TODO
** @param key TODO
** @return TODO
*/

static BOOL		sh_get_line_insert(t_input *input, t_key key)
{
	if (!string_insert(input->str, key.key, pos_in_str(input)))
		return (false);
	get_windows(10)->h_complet = true;
	draw_char(input, key.key);
	return (true);
}

/*
** @brief Gets the line that the user is typing
** @param input The t_input (TODO)
** @param opts The options (?TODO)
** @return Returns The input
*/

char			*sh_get_line(t_input *input, t_sh_opt *opts)
{
	char			buff[MAX_KEY_STRING_LEN + 1];
	t_key			key;
	BOOL			stop;

	stop = false;
	raw_terminal_mode();
	while (stop == false)
	{
		ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
		read(STDIN_FILENO, buff, (opts->tcaps) ? MAX_KEY_STRING_LEN : 1);
		key = key_get(buff, opts->tcaps);
		if (ft_strcmp(key.key_code, KEY_CODE_OTHER))
			stop = key_exec(&key, input);
		else if (MAX_LEN_INPUT <= input->str->len)
			tputs(tgetstr("vb", NULL), 0, &ft_putc_in);
		else if (is_printstr(buff) && !get_select()->is &&
				!ft_strchr(buff, '\n') && !sh_get_line_insert(input, key))
			return (NULL);
		input = get_windows(0)->cur;
		key_del(&key);
	}
	default_terminal_mode();
	(input ? input->lock = true : 0);
	return (NULL);
}
