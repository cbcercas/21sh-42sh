/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_free_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 22:55:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/30 23:13:04 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

void	string_clear(void *string)
{
	if (!string)
		return ;
	if (((t_string*)string)->s)
		ft_strdel(&((t_string*)string)->s);
	return ;
}