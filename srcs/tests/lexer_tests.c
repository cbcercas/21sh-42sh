/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:31:20 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 12:31:44 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/sh_tests.h>

/*
** @brief Function used to test the lexer
**
** @param av The arguments passed to the test module
*/

void	sh_testing_lexer(char *const *av)
{
	t_automaton	automaton;
	t_array		tokens;

	if (lexer_init(&tokens) == NULL)
	{
		ft_dprintf(2, "Error initialising tokens");
		exit(EXIT_FAILURE);
	}
	else if (automaton_init(&automaton) == NULL)
	{
		ft_dprintf(2, "Error Initialising automaton");
		exit(EXIT_FAILURE);
	}
	else if (lexer_lex(&tokens, av[0]) == E_RET_LEXER_OK)
	{
		lexer_print_tokens(&tokens);
		exit(0);
	}
	else
	{
		ft_dprintf(2, "Fatal testing error: Couldn't catch the error.");
		exit(EXIT_FAILURE);
	}
}
