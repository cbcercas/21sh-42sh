/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:50:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 13:53:45 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <automaton/automaton.h>

/*
** @brief Initializes the automaton
** Checks if the stack can be created and sets the current state on START
**
** @param automaton the automaton
**
** @return Returns the automaton with the START state if successful. Else
** returns NULL
*/

t_automaton		*automaton_init(t_automaton *automaton)
{
	if (!(automaton->stack = stack_create(sizeof(int))))
	{
		log_fatal("Automaton: Initialization failed");
		ft_dprintf(2, "Automaton: Initialization failed");
		return (NULL);
	}
	automaton->cur_state = E_STATE_START;
	log_info("Automaton: Initialization done");
	return (automaton);
}

/*
** @brief Resets the automaton
** Checks if it can reset the stack.
** Then it places the state back on START
**
** @param automaton The automaton
**
** @return Returns the automaton if successful, Else returns NULL
*/

t_automaton		*automaton_reset(t_automaton *automaton)
{
	if ((stack_reset(automaton->stack, NULL) == NULL))
	{
		log_fatal("Automaton: Reset failed");
		return (NULL);
	}
	automaton->cur_state = E_STATE_START;
	log_dbg3("Automaton: Reset done");
	return (automaton);
}

/*
** @brief Destroys the automaton
** Checks if automaton exists, then if the stack exists. If all is true,
** It destroys the stack and memdels the automaton before returning void
**
** @param automaton automaton to be destroyed
**
** @return void
*/

void			automaton_destroy(t_automaton **automaton)
{
	if (*automaton)
	{
		if ((*automaton)->stack)
			stack_destroy(&(*automaton)->stack, NULL);
		ft_memdel((void**)automaton);
	}
	log_info("Automaton: Destroy done");
}

/*
** @brief Steps the automaton
**
** @param a the automaton
** @param state The current state
** @param step The step
**
** @return void
*/

void			automaton_step(t_automaton *a, t_stack_state state, \
														t_automaton_step step)
{
	if (step == E_UNKNOWN)
	{
		if (is_empty_stack(a->stack))
			step = E_PUSH;
		else if (*(t_stack_state *)get_top_stack(a->stack) == state)
			step = E_POP;
		else
			step = E_PUSH;
	}
	if (step == E_POP)
	{
		stack_pop(a->stack);
		if (is_empty_stack(a->stack))
			a->cur_state = E_STATE_END;
		else
			a->cur_state = *(t_stack_state *)get_top_stack(a->stack);
	}
	else if (step == E_PUSH)
	{
		stack_push(a->stack, &state);
		a->cur_state = *(t_stack_state *)get_top_stack(a->stack);
	}
}
