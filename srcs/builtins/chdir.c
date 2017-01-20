/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:34:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/20 07:41:13 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "chdir.h"

int	ms_chdir(t_ms_data *data, char *arg)
{
	char	*dir;
	(void)data;

	dir = ms_extract_str(arg);
	ft_printf("%s\n", dir);
	return (0);
}