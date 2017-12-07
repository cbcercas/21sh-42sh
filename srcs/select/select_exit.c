/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 22:55:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/30 23:13:04 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>
#include <core/select.h>
#include <core/progname.h>
#include <core/input.h>
#include <tools/tools.h>


void	*select_exit(const char *fmt, ...)
{
	va_list		list;
	t_window	*wd;

	if (fmt)
	{
		va_start(list, fmt);
		ft_dprintf(STDERR_FILENO, "%s: select", PROGNAME);
		ft_vdprintf(STDERR_FILENO, fmt, list);
		va_end(list);
		va_start(list, fmt);
		log_fatal(fmt, list);
		va_end(list);
	}
	if (!(wd = get_windows(0)) && wd->autocomp)
		get_windows(100);
	return (NULL);
}

