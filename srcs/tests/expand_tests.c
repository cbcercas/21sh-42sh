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

#include <array/array.h>
#include <expand/expand.h>
#include <ftprintf.h>
#include <automaton/automaton.h>
#include <environ/environ.h>
#include <history/history.h>

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
      ft_printf("%s", exp->str->s);
    i++;
  }
}

t_array init_tests_exp(char *input)
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
	else if (lexer_lex(&tokens, input))
	{
		if (automaton.stack)
			stack_destroy(&(automaton.stack), NULL);
		return (tokens);
	}
	else
	{
		ft_dprintf(2, "Fatal testing error : Couldn't Catch the error.");
		exit (1);
	}
}

void sh_testing_expand(char *const *av, char **environ)
{
	t_array expand_array;
	t_array		tokens;

  init_environ(environ);
	sh_history_init(sh_history_get());
	tokens = init_tests_exp(av[3]);
  if (expand_init(&expand_array) == NULL)
		exit (1);
  if (expand(&tokens, &expand_array))
    expand_print_test(&expand_array);
	array_reset(&tokens, NULL);
  sh_history_save();
	exit (0);
}
