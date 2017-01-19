/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/17 21:57:33 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "command.h"

int	ms_command(t_ms_data *data, t_command *command)
{
	t_builtin	fn;
	if ((fn = ms_is_builtin(data->builtins, command->command)))
		return(fn(data, command->args));
	return (0);
}