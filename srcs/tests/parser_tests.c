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

static void		print_exit_error(char *str, int nb_exit)
{
	ft_dprintf(2, str);
	exit(nb_exit);
}

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
		print_exit_error("Error initialising tokens", 1);
	else if (automaton_init(&automaton) == NULL)
		print_exit_error("Error initialising automaton", 1);
	else if (lexer_lex(&tokens, av[0]) == E_RET_LEXER_OK)
	{
		if (parser_parse(&tokens) == E_RET_PARSER_OK)
		{
			ft_printf("Parser say OK\n");
			exit(0);
		}
		exit(EXIT_FAILURE);
	}
	else
		print_exit_error("Fatal testing error: Couldn't catch the error.", 1);
}
