/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 20:30:58 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/14 12:33:20 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/sh_tests.h>

/*
** @brief Initialized the exec test module
**
** @param input The input sent by the user
**
** @return Returns the input once lexed by the lexer
*/

t_array		init_tests_exec(char *input)
{
	t_automaton	automaton;
	t_array		tokens;

	if (lexer_init(&tokens) == NULL)
	{
		ft_dprintf(2, "Error initialising tokens");
		exit(1);
	}
	else if (automaton_init(&automaton) == NULL)
	{
		ft_dprintf(2, "Error Initialising automaton");
		exit(1);
	}
	else if (lexer_lex(&tokens, input))
	{
		if (automaton.stack)
			stack_destroy(&(automaton.stack), NULL);
		return (tokens);
	}
	else
	{
		ft_dprintf(2, "Fatal -c error : Couldn't Catch the error.\n");
		ft_dprintf(2, "Maybe arg is NULL\n");
		exit(1);
	}
}

/*
** @brief Main function to test the exec module
**
** @param av The arguments passed to the test module
** @param __p__environ The current environ
*/

void		sh_testing_exec(char *const *av, char **environ)
{
	t_array		expands;
	t_array		tokens;
	t_btree		*ast;

	ast = NULL;
	init_environ(environ);
	init_local_var();
	sh_builtins_init();
	sh_history_init(sh_history_get());
	sh_check_env(environ);
	tokens = init_tests_exec(av[0]);
	if (expand_init(&expands) == NULL)
		exit(1);
	expand(&tokens, &expands);
	ast_create(&ast, &expands);
	exec_exec(NULL, ast);
	array_reset(&expands, NULL);
	ft_secu_free_all();
	exit(0);
}
