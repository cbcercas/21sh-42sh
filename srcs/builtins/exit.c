/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:49:07 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/12 20:06:04 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/exit.h>

int	sh_exit(t_sh_data *data, char **arg)
{
	int		status;

	status = 0;
	sh_history_save();
	sh_deinit(data);
	ft_putstr("\033[?1049l");
	default_terminal_mode();
	ft_printf("exit\n");
	if (arg && arg[1] && ft_isdigit(arg[1][0]))
		status = ft_atoi(arg[1]);
	exit(status);
}
