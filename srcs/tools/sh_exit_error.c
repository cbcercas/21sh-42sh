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
	exit(EXIT_FAILURE);
}
