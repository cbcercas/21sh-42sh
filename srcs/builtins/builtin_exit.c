/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:49:07 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 14:46:46 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/data.h>
#include <history/history.h>
#include <core/deinit.h>
#include <core/tcaps.h>

int	sh_exit(t_sh_data *data, char **arg)
{
	int		status;

	status = 0;
	sh_history_save();
	sh_deinit(data);
	default_terminal_mode();
	ft_printf("exit\n");
	if (arg && arg[1] && ft_isdigit(arg[1][0]))
		status = ft_atoi(arg[1]);
	exit(status);
}

/*
**ft_putstr("\033[?1049l");
*/
