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

#include <tests/parser_tests.h>

void	sh_testing_parser(char *const *av)
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
	else if (lexer_lex(&tokens, &automaton, av[3]))
	{
			if(parser_parse(&tokens))
			{
				ft_printf("Parser say OK\n");
				exit (0);
			}
			exit (1);
	}
	else
	{
			ft_dprintf(2, "Fatal testing error : Couldn't Catch the error.");
			exit (1);
	}
}
