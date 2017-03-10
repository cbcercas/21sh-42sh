/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:50:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/05 10:02:58 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <automaton/automaton.h>

t_automaton *automaton_init(void)
{
	t_automaton		*automaton;

	if(!(automaton = ft_memalloc(sizeof(*automaton))))
		return (NULL);
	if (!(automaton->stack = stack_create(sizeof(int))))
		return (NULL);
	automaton->cur_state = E_STATE_START;
	return (automaton);
}

void automaton_destroy(t_automaton **automaton)
{
	if (*automaton)
	{
		if ((*automaton)->stack)
			stack_destroy(&(*automaton)->stack);
		ft_memdel((void**)automaton);
	}
}
