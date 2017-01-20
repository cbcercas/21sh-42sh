/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/19 14:44:52 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "input.h"

int	ms_get_command(t_ms_data *data)
{
	t_command	*com_list;
	t_command	*e;
	char		*command;
	int			ret;

	com_list = NULL;
	ret = get_next_line(0, &command);
	if (ret == 1 && ft_strcmp(command, ""))
		com_list = ms_parse_command(command);
	e = com_list;
	while (e)
	{
		if (ms_command(data, e))
			return (1);
		e = e->next;
	}
	// TODO free t_command
	ft_strdel(&command);
	return (0);
}