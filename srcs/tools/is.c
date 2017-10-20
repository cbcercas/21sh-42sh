/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 11:43:17 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/11 15:15:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/bool.h>
#include <parser/enum.h>

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

BOOL  is_redirect(int c)
{
	if (c == E_TOKEN_LESSGREAT || c == E_TOKEN_DLESS || c == E_TOKEN_DGREAT ||\
				c == E_TOKEN_DGREAT || c == E_TOKEN_GREATAND || c == E_TOKEN_LESSAND)
		return (true);
	return (false);
}

BOOL  is_sepa(int c)
{
	if (c == E_TOKEN_SEMI || c == E_TOKEN_AND_IF || c == E_TOKEN_OR_IF)
	return (true);
return (false);
}
