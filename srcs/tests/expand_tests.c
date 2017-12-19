/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:26:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/30 22:46:33 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/sh_tests.h>

/*
** @brief Prints the expanded input
** @param array_exp The t_array
*/

void		expand_print_test(t_array *array_exp)
{
	t_exp	*exp;
	size_t	i;

	i = 0;
	if (!array_exp || i >= array_exp->used)
		return ;
	while (i < array_exp->used)
	{
		exp = (t_exp *)array_get_at(array_exp, i);
		if (exp)
			ft_printf("%s", exp->str->s);
		i++;
	}
}

/*
** @brief Initializes the lexer and automaton for the test and tokenizes the
** input
** @param input The input sent to the test module
**
** @return Returns the lexed input in a t_array form
*/

t_array		init_tests_exp(char *input)
{
	t_automaton	automaton;
	t_array		tokens;

	if (lexer_init(&tokens) == NULL)
		sh_exit_error("Error initialising tokens");
	else if (automaton_init(&automaton) == NULL)
		sh_exit_error("Error Initialising automaton");
	else if (lexer_lex(&tokens, input) == E_RET_LEXER_OK)
	{
		if (automaton.stack)
			stack_destroy(&(automaton.stack), NULL);
		return (tokens);
	}
	else
		sh_exit_error("Fatal testing error: Couldn't catch the error.");
	return (tokens);
}

/*
** @brief Main function to test the expand module
**
** @param av The arguments passed to the test module
** @param environ The current environ
*/

void		sh_testing_expand(char *const *av, char **environ)
{
	t_array		expand_array;
	t_array		tokens;

	if (ft_strlen(av[0]) >= MAX_LEN_INPUT)
		sh_exit_printf("line is too long: %zu, MAX is %zu", ft_strlen(av[0]),
					MAX_LEN_INPUT);
	else if (ft_strlen(av[0]) && !is_printstr(av[0]))
		sh_exit_printf("line: contains non-ascii characters.");
	init_environ(environ);
	set_var(get_envs(), "HOME", "/tmp", true);
	sh_history_init(sh_history_get());
	tokens = init_tests_exp(av[0]);
	if (expand_init(&expand_array) == NULL)
		sh_exit_error("Expand init fail");
	if (expand(&tokens, &expand_array) == E_RET_EXPAND_OK)
		expand_print_test(&expand_array);
	sh_history_save();
	exit(0);
}
