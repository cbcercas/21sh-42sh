/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_free_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 21:26:25 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/21 13:22:25 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_secu_malloc/ft_secu_malloc.h>

void ft_secu_free_all(void)
{
	t_mem         *mem;
	t_secu_malloc *secu_malloc;
	t_secu_malloc *tmp;

	if(!(mem = get_mem()))
		return ;
	secu_malloc = mem->first;
	while(secu_malloc)
	{
		tmp = secu_malloc;
		secu_malloc = secu_malloc->next;
		free(tmp->ptr);
		free(tmp);
	}
	free(mem);
}
