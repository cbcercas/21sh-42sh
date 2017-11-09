/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:04:39 by chbravo-          #+#    #+#             */
/*   Updated: 2017/09/18 21:49:58 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>
#include <core/input.h>
#include <history/history.h>

BOOL	exec_delete(const t_key *key, t_input *input)
{
	size_t	pos;
	t_input	*del;

	(void)key;
	if (get_select()->is)
		return (false);
	log_dbg1("exec delete.");
	pos = pos_in_str(input);
	if (input->str->len > pos)
		string_remove_char(input->str, pos);
	else if (input->str->len == pos && input->next)
	{
		input->str = string_join_cl(&input->str, &input->next->str, true);
		del = input->next;
		input->next = del->next;
		if (input->next)
			input->next->prev = input;
		del->next = NULL;
		input_destroy(&del);
	}
	else
	{
		write(1, "\a", 1);
		return (false);
	}
	input_draw(input);
	//TODO WTF really you save the history on delete? why?
	//sh_history_insert_buf(input->str->s);
	return (false);
}
