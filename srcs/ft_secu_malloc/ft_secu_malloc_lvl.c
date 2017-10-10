/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_malloc_lvl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:57:29 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/04 17:43:52 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_secu_malloc/ft_secu_malloc.h>

static void		ft_s_malloc_mouv(t_secu_malloc *secu_malloc, t_mem *mem)
{
	if (!mem->first)
	{
		mem->first = secu_malloc;
		mem->last = secu_malloc;
		secu_malloc->prev = NULL;
		secu_malloc->next = NULL;
	}
	else
	{
		secu_malloc->prev = mem->last;
		mem->last->next = secu_malloc;
		mem->last = secu_malloc;
	}
}

void			*ft_secu_malloc_lvl(size_t size, size_t lvl)
{
	t_mem			*mem;
	t_secu_malloc	*secu_malloc;
	void			*ptr;

	ptr = NULL;
	mem = get_mem();
	if (!mem || !(secu_malloc = (t_secu_malloc*)malloc(sizeof(t_secu_malloc))))
		return (NULL);
	ft_bzero(secu_malloc, sizeof(t_secu_malloc));
	ptr = malloc(size);
	ft_bzero(ptr, size);
	secu_malloc->lvl = lvl;
	secu_malloc->ptr = ptr;
	secu_malloc->next = NULL;
	ft_s_malloc_mouv(secu_malloc, mem);
	return (ptr);
}
