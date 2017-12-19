/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiforge <guiforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:27:39 by guiforge          #+#    #+#             */
/*   Updated: 2017/12/05 14:27:40 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>
#include <core/progname.h>
#include <signals/signals.h>

int				g_logger_fd;

void	sh_exit_error(const char *error)
{
	ft_putstr_fd(PROGNAME, STDERR_FILENO);
	if (g_logger_fd)
		ft_putstr_fd(PROGNAME, g_logger_fd);
	ft_putstr_fd(": EXIT-ERROR: ", STDERR_FILENO);
	if (g_logger_fd)
		ft_putstr_fd(": EXIT-ERROR: ", g_logger_fd);
	if (error)
	{
		ft_putendl_fd(error, STDERR_FILENO);
		if (g_logger_fd)
			ft_putendl_fd(error, g_logger_fd);
	}
	else
	{
		ft_putendl_fd("", STDERR_FILENO);
		if (g_logger_fd)
			ft_putendl_fd("", g_logger_fd);
	}
	kill_childs(SIGTERM);
	exit(EXIT_FAILURE);
}

void	sh_exit_printf(const char *fmt, ...)
{
	va_list		list;

	if (fmt)
	{
		va_start(list, fmt);
		ft_dprintf(STDERR_FILENO, "%s: ERROR: ", PROGNAME);
		ft_vdprintf(STDERR_FILENO, fmt, list);
		va_end(list);
		va_start(list, fmt);
		log_fatal(fmt, list);
		va_end(list);
	}
	ft_putendl_fd("", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
