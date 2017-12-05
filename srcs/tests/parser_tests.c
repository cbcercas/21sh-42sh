/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:31:14 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/30 22:47:06 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/sh_tests.h>

/*
** @brief Main function to test the parser.
**
** @param av The input sent to the testing module
*/

void			sh_testing_parser(char *const *av)
{
	t_automaton	automaton;
	t_array		tokens;

	if (lexer_init(&tokens) == NULL)
		sh_exit_error("Error initialising tokens");
	else if (automaton_init(&automaton) == NULL)
		sh_exit_error("Error initialising automaton");
	else if (lexer_lex(&tokens, av[0]) == E_RET_LEXER_OK)
	{
		if (parser_parse(&tokens) == E_RET_PARSER_OK)
		{
			ft_printf("Parser say OK\n");
			exit(0);
		}
		sh_exit_error("Parser");
	}
	else
		sh_exit_error("Fatal testing error: Couldn't catch the error.");
}
