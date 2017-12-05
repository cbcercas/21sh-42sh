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

#include <secure_memory/secure_memory.h>
#include <tools/tools.h>

/*
** @brief TODO
** @param secu_malloc TODO
** @param mem TODO
*/

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

/*
** @brief Securely mallocs with a level ?TODO
**
** @param size Size to be malloced
** @param lvl TODO
**
** @return Returns a pointer to the malloced area in memory
*/

void			*ft_secu_malloc_lvl(size_t size, size_t lvl)
{
	t_mem			*mem;
	t_secu_malloc	*secu_malloc;
	void			*ptr;

	mem = get_mem();
	if (!mem || !(secu_malloc =
				(t_secu_malloc*)ft_memalloc(sizeof(t_secu_malloc))))
	{
		sh_exit_error("Error Malloc");
		return (NULL);
	}
	ptr = ft_memalloc(size);
	secu_malloc->lvl = lvl;
	secu_malloc->ptr = ptr;
	secu_malloc->next = NULL;
	ft_s_malloc_mouv(secu_malloc, mem);
	return (ptr);
}

/*
** @brief Securely allocates memoy
** @param size Size of malloc
** @return Pointer to the area of memory which has been allocated
*/

void			*secu_malloc(size_t size)
{
	return (ft_secu_malloc_lvl(size, MALLOC_LVL_DEFAULT));
}

/*
** @brief TODO
** @return TODO
*/

t_mem			*get_mem(void)
{
	static t_mem *mem = NULL;

	if (mem == NULL)
	{
		if (!(mem = (t_mem *)malloc(sizeof(t_mem))))
			sh_exit_error("Error Malloc");
		ft_bzero(mem, sizeof(t_mem));
		mem->first = NULL;
		mem->last = NULL;
	}
	return (mem);
}
