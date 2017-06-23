/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:59:15 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/23 13:03:53 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/ast_tests.h>

void test_aff(t_cmd *cmd)
{
	static int i = 0;
	ft_printf("[%d]{%s} ", i, cmd->str);
	i++;
}

t_array init_tests_ast(char *input)
{
	t_automaton	automaton;
	t_array		tokens;

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
	else if (lexer_lex(&tokens, &automaton, input))
		return (tokens);
	else
	{
		ft_printf("Fatal testing error : Couldn't Catch the error.");
		exit (1);
	}
}

void sh_testing_ast(char *const *av)
{
	t_btree	*ast;
	t_array		tokens;
	char *input;

	input = ft_strclean(av[3]);//TODO à faire pour le main ;)
	ast = NULL;
	tokens = init_tests_ast(input);
	if (!(ast = ast_create(&tokens)))
		ft_printf("AST NULL\n");
	else if (!av[4] || ft_strequ(av[4], "tree"))
		btree_print(ast, (char * (*)(void*))&ast_aff);
	else if (ft_strequ(av[4], "line"))
		btree_apply_prefix(ast, (void (*)(void*))&test_aff);
	btree_destroy(&ast, (void (*) (void*))&ast_del_cmd);
	free(input);
	exit (0);
}
