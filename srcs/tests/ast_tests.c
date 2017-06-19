/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:59:15 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/19 14:39:43 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/ast_tests.h>

void sh_testing_ast(char *const *av)
{
	t_btree	*ast;
	t_automaton	automaton;
	t_array		tokens;

	ast = NULL;
	if (lexer_init(&tokens) == NULL)
	{
			ft_printf("Error initialising tokens");
			exit (1);
	}
	else if (automaton_init(&automaton) == NULL)
	{
			ft_printf("Error Initialising automaton");
			exit (1);
	}

	else if (lexer_lex(&tokens, &automaton, av[3]))
	{
			if(parser_parse(&tokens))
			{
				if (!(ast = ast_built(ast, &tokens, 0, 1000000)))
					ft_printf("AST NULL\n");
				else
					btree_print(ast, (char * (*)(void*))&ast_aff);
				exit (0);
			}
			exit (1);
	}
	else
	{
			ft_printf("Fatal testing error : Couldn't Catch the error.");
			exit (1);
	}
}
