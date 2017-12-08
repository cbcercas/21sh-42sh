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

/*
** @brief Returns the value select
**
** @return Returns the value select
*/

t_select		*get_select(void)
{
	t_window	*w;

	w = get_windows(0);
	if (w)
		return (&(w)->select);
	return (NULL);
}

/*
** @brief Returns the value ts
**
** @return Returns the value ts
*/

struct winsize	*get_ts(void)
{
	t_window	*w;

	w = get_windows(0);
	if (w)
		return (&(w)->ts);
	return (NULL);
}

/*
** @brief Returns the value cur_head
**
** @return Returns the value cur_head
*/

t_input			*input_get_cur_head(void)
{
	t_window	*w;

	w = get_windows(0);
	if (w)
		return (w->cur_head);
	return (NULL);
}

/*
** @brief Returns the value cur
**
** @return Returns the value cur
*/

t_input			*input_get_cur(void)
{
	t_window	*w;

	if ((w = get_windows(0)))
		return (w->cur);
	return (NULL);
}

/*
** @brief Returns the value cmd_ret
**
** @return Returns the value cmd_ret
*/

int				*get_cmd_ret(void)
{
	t_window	*w;

	if ((w = get_windows(0)))
		return (&w->cmd_ret);
	return (NULL);
}
