/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 20:30:58 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/30 22:49:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/exec_tests.h>

t_array init_tests_exec(char *input)
{
	t_automaton	automaton;
	t_array		tokens;

	if (lexer_init(&tokens) == NULL)
	{
		ft_dprintf(2, "Error initialising tokens");
		exit (1);
	}
	else if (automaton_init(&automaton) == NULL)
	{
		ft_dprintf(2, "Error Initialising automaton");
		exit (1);
	}
	else if (lexer_lex(&tokens, &automaton, input))
	{
		if (automaton.stack)
			stack_destroy(&(automaton.stack), NULL);
		return (tokens);
	}
	else
	{
		ft_dprintf(2, "Fatal -c error : Couldn't Catch the error.\n");
    ft_dprintf(2, "Maybe arg is NULL\n");
		exit (1);
	}
}

void sh_testing_exec(char *const *av, char **environ)
{
	t_array		expands;
	t_array		tokens;

	sh_init_environ(environ);
  sh_builtins_init();
	sh_history_init(NULL);
	tokens = init_tests_exec(av[2]);
	if (expand_init(&expands) == NULL)
		exit (1);
	expand(&tokens, &expands);
	sh_process_exec(NULL, ast_create(&expands));
	array_reset(&expands, NULL);
  ft_secu_free_all();
	exit (0);
}
