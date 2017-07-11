/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:24:50 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/10 10:06:05 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>

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
	input->ts = get_term_size();
};

size_t	sh_pos_of_insert(t_input input)
{
	size_t	ret;
	size_t	len_prompt;

	ret = 0;
	len_prompt = input.prompt_len;
	ret = input.cpos.cp_col + (input.offset_line * input.ts.ts_cols) - len_prompt;
	return (ret);
}
