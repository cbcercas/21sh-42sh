/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_arrows.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:42:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/12 21:44:48 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_ctrl_up(const t_key *key, t_input *input)
{
	size_t    x;
	size_t    y;

	y = input->offset_line - 1;
	x = input->cpos.cp_col;
	if (input->offset_line <= 0 || (input->offset_line == 1 && x < input->prompt_len))
		return (false);
	(void)key;
	while (input->cpos.cp_col != x || input->offset_line != y)
		exec_arrow_left(NULL, input);
	return (false);
}

BOOL	exec_ctrl_down(const t_key *key, t_input *input)
{
	size_t    x;
	size_t    y;
	size_t    nb_of_line;
	size_t    i;

	i = 0;
	nb_of_line = input->str->len / input->ts.ts_cols;
	y = input->offset_line + 1;
	x = input->cpos.cp_col;
	if (nb_of_line == input->offset_line)
		return (false);
	(void)key;
	while ((input->cpos.cp_col != x || input->offset_line != y) && input->str->len != i)
	{
		exec_arrow_right(NULL, input);
		i++;
	}
	return (false);
}

BOOL	exec_ctrl_left(const t_key *key, t_input *input)
{
	exec_arrow_left(key, input);
	while ((sh_pos_of_insert(*input) != 0) &&\
			(sh_pos_of_insert(*input) == input->str->len ||\
			 !(input->str->s[sh_pos_of_insert(*input)] == ' ' &&\
				 input->str->s[sh_pos_of_insert(*input) - 1] != ' ')))
		exec_arrow_left(key, input);
	return (false);
}

BOOL	exec_ctrl_right(const t_key *key, t_input *input)
{
	exec_arrow_right(key, input);
	while ((sh_pos_of_insert(*input) != input->str->len) &&\
			(sh_pos_of_insert(*input) == 0 ||\
			 !(input->str->s[sh_pos_of_insert(*input)] != ' ' &&\
				 input->str->s[sh_pos_of_insert(*input) - 1] == ' ')))
		exec_arrow_right(key, input);
	return (false);
}
