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

t_automaton *automaton_init(t_automaton *automaton)
{
	if (!(stack_init(&automaton->stack, sizeof(int))))
	{
		log_fatal("Automaton: Initialization failed");
		return (NULL);
	}
		automaton->cur_state = E_STATE_START;
	log_info("Automaton: Initialization done");
	return (automaton);
}

t_automaton *automaton_reset(t_automaton *automaton)
{
	if ((stack_reset(&automaton->stack) == NULL))
	{
		log_fatal("Automaton: Reset failed");
		return (NULL);
	}
	automaton->cur_state = E_STATE_START;
	log_dbg3("Automaton: Reset done");
	return (automaton);
}

void automaton_destroy(t_automaton **automaton)
{
	if (*automaton)
	{
		if (&(*automaton)->stack)
			stack_destroy(&(*automaton)->stack);
		ft_memdel((void**)automaton);
	}
	log_info("Automaton: Destroy done");
}

void automaton_step(t_automaton	*a, t_stack_state state, t_automaton_step step)
{
	if (step == E_UNKNOWN)
	{
		if (is_empty_stack(&a->stack))
			step = E_PUSH;
		else if (*(t_stack_state *)get_top_stack(&a->stack) == state)
			step = E_POP;
		else
			step = E_PUSH;
	}
	if (step == E_POP)
	{
		stack_pop(&a->stack);
		if (is_empty_stack(&a->stack))
			a->cur_state = E_STATE_START;
		else
			a->cur_state = *(t_stack_state *) get_top_stack(&a->stack);
	}
	else if (step == E_PUSH)
	{
		stack_push(&a->stack, &state);
		a->cur_state = *(t_stack_state *)get_top_stack(&a->stack);
	}
}
