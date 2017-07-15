/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:24:50 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/15 18:38:03 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>
#include <sys/ioctl.h>

void reset_input(t_input *input)
{
	if (input->str)
		string_reset(input->str);
	else
		input->str = string_create();
	input->prompt_len = sh_len_prompt();
	input->offset_col = input->prompt_len;
	input->offset_line = 0;
	input->cpos.cp_line = 0;
	input->cpos.cp_col = (unsigned short)input->offset_col ;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &input->ts);
	ft_strdel(&input->select.str);
	ft_bzero(&input->select, sizeof(t_select));
};

size_t	pos_in_str(t_input input)
{
	size_t	ret;
	size_t	len_prompt;

	ret = 0;
	len_prompt = input.prompt_len;
	ret = input.cpos.cp_col + (input.offset_line * input.ts.ws_col) - len_prompt;
	return (ret);
}
