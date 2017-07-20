/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_malloc_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:49:44 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/21 00:54:17 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_secu_malloc/ft_secu_malloc.h>

t_mem *get_mem(void)
{
	static t_mem *mem = NULL;

	if (mem == NULL)
	{
		if (!(mem = (t_mem *)ft_memalloc(sizeof(t_mem))))
			ft_putstr_fd("ERROR: Malloc\n", 2);
	}
	return (mem);
}
