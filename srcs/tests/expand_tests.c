/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:26:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/06 18:43:44 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/expand_tests.h>

void expand_print_test(t_array *array_exp)
{
  t_exp   *exp;
  size_t  i;

  i = 0;
  if (!array_exp || i >= array_exp->used)
    return ;
  while (i < array_exp->used)
  {
    exp = (t_exp *)array_get_at(array_exp, i);
    if (exp)
      ft_printf("%s", exp->str);
    i++;
  }
}

t_array init_tests_exp(char *input)
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
	{
		if (automaton.stack)
			stack_destroy(&(automaton.stack), NULL);
		return (tokens);
	}
	else
	{
		ft_printf("Fatal testing error : Couldn't Catch the error.");
		exit (1);
	}
}

void sh_testing_expand(char *const *av)
{
	t_array expand_array;
	t_array		tokens;
	//char *input;

	//input = ft_strclean(av[3]);//TODO à faire pour le main ;)
	tokens = init_tests_exp(av[3]);
  if (expand_init(&expand_array) == NULL)
		exit (1);
  if (expand(&tokens, &expand_array))
    expand_print_test(&expand_array);
	array_reset(&tokens, NULL);
	exit (0);
}
