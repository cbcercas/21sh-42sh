/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_end_home.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:42:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/11 15:32:56 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_end(const t_key *key, t_input *input)
{
  size_t    i;

  i = 0;
	(void)key;
  while (input->str->len > i++)
    exec_arrow_right(NULL, input);
	return (false);
}

BOOL	exec_start(const t_key *key, t_input *input)
{
  size_t    i;

  i = 0;
	(void)key;
  while (input->str->len > i++)
    exec_arrow_left(NULL, input);
	return (false);
}
