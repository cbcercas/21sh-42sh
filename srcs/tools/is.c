/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 11:43:17 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/11 12:42:10 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>

BOOL  is_white(int c)
{
	if (c == '\t' || c == '\v' || c == ' ')
		return (true);
	return (false);
}

BOOL  is_str_car(const char *buff)
{
  if (buff[0] > 31 && buff[0] < 127 && buff[1] == 0)
    return (true);
  return (false);
}
