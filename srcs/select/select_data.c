/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 23:55:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/02 23:55:43 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/select.h>
#include <core/input.h>

t_sel_data	*select_get_data(void)
{
	t_window		*wd;

	wd = get_windows(0);
	if (wd->autocomp)
		return (wd->autocomp);
	if (!(wd->autocomp = ft_memalloc(sizeof(*wd->autocomp))))
		select_exit("Malloc failed... Exiting!");
	return (wd->autocomp);
}
