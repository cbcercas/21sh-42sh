/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:49:07 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/12 11:22:00 by gpouyat          ###   ########.fr       */
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
	exit(status);
}
