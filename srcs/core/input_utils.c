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
	input->cpos.cp_col = input->offset_col;
	//ioctl(STDOUT_FILENO, TIOCGWINSZ, &input->ts);
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
	//ioctl(STDOUT_FILENO, TIOCGWINSZ, &input->ts);
	ft_strdel(&input->select->str);
	ft_bzero(input->select, sizeof(t_select));
	//input->inp_save = NULL;
}

size_t	pos_in_str(t_input *input)
{
	size_t			ret;
	size_t			len_prompt;
	struct winsize	*ts;

	ret = 0;
	ts = get_ts();
 	len_prompt = input->prompt_len;
	ret = input->cpos.cp_col + (input->offset_line *  ts->ws_col) - len_prompt;
	return (ret);
}

void	sh_reset_line(t_automaton *automaton, t_array *tokens)
{
	array_reset(tokens, NULL);
	automaton_reset(automaton);
}
