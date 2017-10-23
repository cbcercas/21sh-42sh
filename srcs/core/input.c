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

t_input	*input_new(void)
{
	t_input	*input;

	if (!(input = ft_memalloc(sizeof(*input))))
		return (NULL);
	input->next = NULL;
	input->prev = NULL;
	input->ts = get_ts();
	input->select = get_select();
	input->lock = false;
	input_reset(input);
	return (input);
}

t_input *input_hard_reset(t_input **input)
{
	input_destroy(input);
	*input = input_new();
	return (*input);
}

t_input *input_get_last(t_input *input)
{
	while (input && input->next)
		input = input->next;
	return (input);
}

t_input	*input_add_new(t_input *input)
{
	t_input	*save;

	if (!input)
		return (NULL);
	save = input->next;
	if((input->next = input_new()) == NULL)
		return (NULL);
	input->next->prev = input;
	input->next->next = save;
	if (save)
		save->prev = input->next;
	return (input->next);
}

char *sh_get_line(t_input *input, t_sh_opt *opts)
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
		if (ft_strcmp(key.key_code, KEY_CODE_NONE))
			stop = key_exec(&key, input);
		else if (is_printstr(buff) && !input->select->is)
		{
			if (!string_insert(input->str, key.key, pos_in_str(input)))
				return (NULL);
			get_windows(12);
			draw_char(input, key.key);
		}
		input = get_windows(0)->cur;
		key_del(&key);
	}
	default_terminal_mode();
	input->lock = true;
	return (NULL);
}
