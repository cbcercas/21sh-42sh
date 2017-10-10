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
	if (input->offset_line || input->cpos.cp_col > (unsigned short)input->offset_col)
	{
		exec_arrow_left(key, input);
		exec_delete(key, input);
	}
	else
		write(1, "\a", 1);
	//TODO change to termcaps
	return (false);
}
