/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 21:25:24 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/15 16:57:00 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

/*
** @brief Called when a user presses up. Will parse the input and find
** similar commands
**
** @param input The current input
**
** @return Returns the input once modified
*/

t_input	*sh_history_up(t_input *input)
{
	t_input		*new_inp;
	t_input		*hist_inp;
	t_window	*w;
	char		*tmp;

	w = get_windows(0);
	hist_inp = (w->h_complet && w->save) ? w->save : input;
	tmp = input_to_history(input_get_writable(hist_inp));
	if (!(new_inp = input_from_history(history_get_prev(tmp))))
	{
		ft_strdel(&tmp);
		tcaps_bell();
		return(NULL);
	}
	ft_strdel(&tmp);
	return (new_inp);
}

/*
** @brief Called when a user presses down. Will parse the input and find
** similar commands
**
** @param input The current input
**
** @return Returns the input once modified
*/


t_input	*sh_history_down(t_input *input)
{
	t_input		*new_inp;
	t_input		*hist_inp;
	char		*tmp;
	t_window	*w;

	w = get_windows(0);
	new_inp = NULL;
	hist_inp = (w->h_complet && w->save) ? w->save : input;
	tmp = input_to_history(input_get_writable(hist_inp));
	if (get_windows(0)->h_lvl >= 1
			&& (new_inp = input_from_history(history_get_next(tmp))))
	{
		input = input_back_to_writable(input);
		input_to_save(&input, new_inp);
	}
	else if (get_windows(0)->save && !new_inp)
	{
		get_windows(0)->h_lvl -= 1;
		input = input_back_to_writable(input);
		new_inp = input_from_save(&input);
	}
	if (!new_inp)
		tcaps_bell();
	ft_strdel(&tmp);
	return (new_inp);
}
