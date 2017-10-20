/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 18:42:01 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/31 18:42:15 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

BOOL  ft_isdigit_str(char *str)
{
  int i;

  i = 0;
  if (!str)
    return (false);
  while(str[i])
  {
    if(!ft_isdigit(str[i]))
      return (false);
    i++;
  }
  return (true);
}
