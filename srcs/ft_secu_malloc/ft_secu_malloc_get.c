/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_malloc_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:49:44 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/04 17:39:45 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_secu_malloc/ft_secu_malloc.h>

t_mem	*get_mem(void)
{
	static t_mem *mem = NULL;

	if (mem == NULL)
	{
		if (!(mem = (t_mem *)malloc(sizeof(t_mem))))
		{
			ft_putstr_fd("ERROR: Malloc\n", 2);
			return (NULL);
		}
		ft_bzero(mem, sizeof(t_mem));
		mem->first = NULL;
		mem->last = NULL;
	}
	return (mem);
}
