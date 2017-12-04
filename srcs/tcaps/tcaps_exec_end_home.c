/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_end_home.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:42:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/11 15:32:56 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

// TODO rewrite using tgoto and prompt len/offset col
BOOL	exec_end(const t_key *key, t_input *input)
{
	t_window	*wd;
	t_cpos	dest;

	(void)key;
	if (!(wd = get_windows(0)))
		return (false);
	if ((wd->autocomp && wd->autocomp->active))
		return (false);
	if (get_select()->is)
		return (false);
	dest = input_get_last_pos(input);
	move_cursor_to(&dest, &input->cpos, input->ts);
	return (false);
}

// TODO rewrite using tgoto and prompt len/offset col
BOOL	exec_start(const t_key *key, t_input *input)
{
	t_window	*wd;
	t_cpos	dest;

	(void)key;
	if (!(wd = get_windows(0)))
		return (false);
	if ((wd->autocomp && wd->autocomp->active))
		return (false);
	if (get_select()->is)
		return (false);
	dest = input_get_first_pos(input);
	move_cursor_to(&dest, &input->cpos, input->ts);
	return (false);
}
