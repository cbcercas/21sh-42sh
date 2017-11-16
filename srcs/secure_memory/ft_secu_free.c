/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 20:09:31 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/04 17:38:51 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <secure_memory/secure_memory.h>

/**
 * @brief Searches into memory for a pointer (TODO)
 * @param ptr TOOD
 * @param mem TODO
 * @return TODO
 */

static t_secu_malloc	*ft_malloc_search(void *ptr, t_mem *mem)
{
	t_secu_malloc *tmp;

	tmp = mem->first;
	while (tmp && (tmp->ptr != ptr))
		tmp = tmp->next;
	return (tmp);
}

/**
 * @brief Frees securely the variable passed
 *
 * @param ptr The pointer to the variable you want to free
 */

void					ft_secu_free(void *ptr)
{
	t_mem			*mem;
	t_secu_malloc	*secu_malloc;

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

/**
 * @brief Frees all it can find in memory
 */

void	ft_secu_free_all(void)
{
	t_mem			*mem;
	t_secu_malloc	*secu_malloc;
	t_secu_malloc	*tmp;

	if (!(mem = get_mem()))
		return ;
	secu_malloc = mem->first;
	while (secu_malloc)
	{
		tmp = secu_malloc;
		secu_malloc = secu_malloc->next;
		free(tmp->ptr);
		free(tmp);
	}
	free(mem);
}

/**
 * @brief TODO
 * @param lvl TODO
 */

void	ft_secu_free_lvl(size_t lvl)
{
	t_mem			*mem;
	t_secu_malloc	*secu_malloc;
	t_secu_malloc	*tmp;

	if (!(mem = get_mem()))
		return ;
	secu_malloc = mem->first;
	while (secu_malloc)
	{
		if (secu_malloc->lvl == lvl)
		{
			tmp = secu_malloc;
			ft_secu_free(tmp->ptr);
			if (!(mem = get_mem()))
				return ;
			secu_malloc = mem->first;
		}
		else
			secu_malloc = secu_malloc->next;
	}
}
