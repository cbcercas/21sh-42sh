/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:11:41 by gpouyat           #+#    #+#             */
/*   Updated: 2017/12/09 19:11:48 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	tcaps_init(t_window *wd)
{
	if (!wd)
		return (false);
	if (wd->autocomp && wd->autocomp->active)
		return (false);
	else if (wd->autocomp)
		get_windows(100);
	return (true);
}
