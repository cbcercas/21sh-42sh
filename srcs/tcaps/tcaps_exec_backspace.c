/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_backspace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:04:39 by jlasne            #+#    #+#             */
/*   Updated: 2017/09/18 21:50:05 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_backspace(const t_key *key, t_input *input)
{
	(void)key;

	log_dbg3("User pressed backspace");
	if (input->cpos.cp_line || (input->cpos.cp_col > input->offset_col))
	{
		exec_arrow_left(key, input);
		exec_delete(key, input);
	}
	else if (input->prev)
	{
		exec_arrow_left(key, input);
		get_windows(0)->cur = input->prev;
		exec_delete(key, input->prev);
	}
	else
		tcaps_bell();
	return (false);
}
