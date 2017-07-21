/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_free_lvl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 21:26:25 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/21 12:54:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_secu_malloc/ft_secu_malloc.h>

void ft_secu_free_lvl(size_t lvl)
{
	t_mem         *mem;
	t_secu_malloc *secu_malloc;
	t_secu_malloc *tmp;

	if(!(mem = get_mem()))
		return ;
	secu_malloc = mem->first;
	while(secu_malloc)
	{
		if (secu_malloc->lvl == lvl)
		{
			tmp = secu_malloc;
			secu_malloc = secu_malloc->next;
			ft_secu_free(tmp->ptr);
		}
		else
			secu_malloc = secu_malloc->next;
	}
}