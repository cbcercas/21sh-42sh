/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 20:09:31 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/21 13:21:45 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_secu_malloc/ft_secu_malloc.h>

static t_secu_malloc *ft_malloc_search(void *ptr, t_mem *mem)
{
	t_secu_malloc *tmp;

	tmp = mem->first;
	while (tmp && (tmp->ptr != ptr))
		tmp = tmp->next;
	return (tmp);
}

void ft_secu_free(void *ptr)
{
	t_mem         *mem;
	t_secu_malloc *secu_malloc;

	if (!(mem = get_mem()))
		return ;
	if (!(secu_malloc = ft_malloc_search(ptr, mem)))
		return ;
	if (!secu_malloc->prev)
		mem->first = secu_malloc->next;
	else
		secu_malloc->prev->next = secu_malloc->next;
	if (!secu_malloc->next)
		mem->last = secu_malloc->prev;
	else
		secu_malloc->next->prev = secu_malloc->prev;
	free(secu_malloc->ptr);
	free(secu_malloc);
}
