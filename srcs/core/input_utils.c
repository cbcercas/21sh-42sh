/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:24:50 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 15:43:55 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>
#include <sys/ioctl.h>
#include <automaton/automaton.h>

void	reset_input(t_input *input)
{
	if (input->str)
		string_reset(input->str);
	else
		input->str = string_create();
	input->prompt_len = 0;
	input->offset_col = 0;
	input->offset_line = 0;
	input->cpos.cp_line = 0;
	input->offset_len = 0;
	input->cpos.cp_col = input->offset_col;
	ft_strdel(&input->select->str);
	ft_bzero(input->select, sizeof(t_select));
	input->next = NULL;
}

void	input_destroy(t_input **input)
{
	if (*input)
	{
		if ((*input)->next)
			input_destroy(&(*input)->next);
		string_del(&((*input)->str));
		ft_strdel(&(*input)->select->str);
		ft_memdel((void **) input);
	}
}

void	input_reset(t_input *input)
{
	if (input->str)
		string_reset(input->str);
	else
		input->str = string_create();
	input->prompt_len = 0;
	input->offset_col = 0;
	input->offset_line = 0;
	input->cpos.cp_line = 0;
	input->cpos.cp_col = input->offset_col;
	input->offset_len = 0;
	input->lock = false;
	ft_strdel(&input->select->str);
	ft_bzero(input->select, sizeof(t_select));
}

size_t	pos_in_str(t_input *input)
{
	size_t			ret;
	size_t			len_prompt;
	struct winsize	*ts;

	ret = 0;
	ts = get_ts();
 	len_prompt = input->prompt_len;
	ret = input->cpos.cp_col + (input->cpos.cp_line * ts->ws_col) - len_prompt;
	return (ret);
}

t_input *input_get_writable(t_input *input)
{
	while(input && input->prev && !input->prev->lock)
		input = input->prev;
	return (input);
}