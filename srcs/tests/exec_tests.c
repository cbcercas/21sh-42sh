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
		sh_exit_error("Error initialising tokens");
	else if (automaton_init(&automaton) == NULL)
		sh_exit_error("Error Initialising automaton");
	else if (lexer_lex(&tokens, input))
	{
		if (automaton.stack)
			stack_destroy(&(automaton.stack), NULL);
		return (tokens);
	}
	else
		sh_exit_error("Fatal -c error : Couldn't Catch the error.\n"
							" Maybe arg is NULL");
	return (tokens);
}

/*
** @brief Main function to test the exec module
**
** @param av The arguments passed to the test module
** @param environ The current environ
*/

void		sh_testing_exec(char *const *av, char **environ)
{
	t_array		expands;
	t_array		tokens;
	t_btree		*ast;

	ast = NULL;
	if (ft_strlen(av[0]) >= MAX_LEN_INPUT)
		sh_exit_printf("line is too long: %zu, MAX is %zu", ft_strlen(av[0]),
					MAX_LEN_INPUT);
	else if (ft_strlen(av[0]) && !is_printstr(av[0]))
		sh_exit_printf("line: contains non-ascii characters.");
	init_environ(environ);
	init_local_var();
	sh_builtins_init();
	sh_history_init(sh_history_get());
	sh_check_env(environ);
	print_verb(av[0]);
	tokens = init_tests_exec(av[0]);
	if (expand_init(&expands) == NULL)
		sh_exit_error("Expand init fail");
	expand(&tokens, &expands);
	ast_create(&ast, &expands);
	exec_exec(get_data(NULL), ast);
	exit(*get_cmd_ret() % 256);
}
