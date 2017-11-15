/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:53:38 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/15 17:53:40 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>

t_select		*get_select(void)
{
	return (&(get_windows(0))->select);
}

struct winsize	*get_ts(void)
{
	return (&(get_windows(0))->ts);
}

t_input			*input_get_cur_head(void)
{
	t_window	*w;

	w = get_windows(0);
	return (w->cur_head);
}

t_input			*input_get_cur(void)
{
	t_window	*w;

	w = get_windows(0);
	return (w->cur);
}

int				*get_cmd_ret(void)
{
	t_window	*w;

	w = get_windows(0);
	return (&w->cmd_ret);
}
