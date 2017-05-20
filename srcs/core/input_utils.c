/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:24:50 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 22:26:07 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>

void reset_input(t_input *input)
{
	if (input->str)
		string_reset(input->str);
	else
		input->str = string_create();
	//TODO add prompt len
	input->offset_col = 3;
	input->offset_line = 0;
	input->cpos = get_cursor_pos();
	input->ts = get_term_size();
};
