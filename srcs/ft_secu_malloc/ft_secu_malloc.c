/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:57:29 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/21 00:54:24 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_secu_malloc/ft_secu_malloc.h>

static void ft_s_malloc_mouv(t_secu_malloc *secu_malloc, t_mem *mem)
{
	if(!mem->first)
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

void *ft_secu_malloc(size_t size)
{
	t_mem         *mem;
	t_secu_malloc *secu_malloc;
	void          *ptr;

	ptr = NULL;
	mem = get_mem();
	if (!mem || !(secu_malloc = (t_secu_malloc*)ft_memalloc(sizeof(t_secu_malloc)))) // 1 malloc pour deux
		return(NULL);
	ptr = ft_memalloc(size);
	secu_malloc->ptr = ptr;
	secu_malloc->next = NULL;
	ft_s_malloc_mouv(secu_malloc, mem);
	return (ptr);
}
