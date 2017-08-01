/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/21 16:14:28 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/main.h>

// permet de destroy, de print un messages, et d'exit
void sh_over(char *mess, t_automaton *automat, t_array *array, void fn(void *elem))
{
	if (mess)
		ft_putendl_fd(mess, 2);
	if (automat)
		automaton_destroy(&automat);
	if (array)
		array_destroy(&array, fn);
	exit (EXIT_FAILURE);
}

// init tout les arrays qu'on a besoins
void sh_arrays_init(t_automaton *automat, t_array *tokens, t_array *expands)
{
	if (lexer_init(tokens) == NULL)
		sh_over("ERROR: Initialisation tokens", automat, tokens, NULL);
	if (automaton_init(automat) == NULL)
		sh_over("ERROR: Initialisation automaton", automat, NULL, NULL);
	if (expand_init(expands) == NULL)
		sh_over("ERROR: Initialisation expand", automat, expands, sh_exp_del);
}

//récupère l'input en fonction d'isatty
BOOL sh_get_input(t_sh_data *data, char **input)
{
	if (!isatty(0))
	{
		if (!get_next_line(0, input))
			return (false);
		if (input)
			ft_putendl(*input);
	}
	else
		*input = sh_get_line(&(data->opts));
	return (true);
}

//reset les arrays
void sh_arrays_reset(t_automaton *automat, t_array *tokens, t_array *expands,\
	 										char *input)
{
	array_reset(tokens, NULL);
	array_reset(expands, sh_exp_del);
	automaton_reset(automat);
	input ? ft_strdel(&input) : 0;
	ft_secu_free_lvl(M_LVL_AST);
	ft_secu_free_lvl(M_LVL_EXPA);
}

//lex, pars, expand, et build ast, il retourn l'ast
t_btree	*sh_process(t_automaton *automat, t_array *tokens, t_array *expands,\
	 										char *input)
{
	t_btree		*ast;

	ast = NULL;
	if (lexer_lex(tokens, automat, input))
		if (parser_parse(tokens))
		{
			//lexer_print_tokens(tokens);
			if (expand(tokens, expands))
			{
					sh_history_set_new(input);
				if (!(ast = ast_create(expands)))
					;//ft_printf("AST NULL\n");
				//else
					//btree_print(ast, (char * (*)(void*))&ast_aff);
				return (ast);
			}
		}
		return (NULL);
}

//j'ai beaucoup de mal à diminuer le nombre de variables
int main(int ac, char *const *av, char **environ)
{
	t_sh_data	data;
	t_automaton	automaton;
	t_array		tokens;
	t_array		expand_array;
	char		*input;

	sh_arrays_init(&automaton, &tokens, &expand_array);
	if (!sh_init(&data, ac, av, environ))
		exit(1);
	while (42)
	{
		sh_print_prompt();
		if (!sh_get_input(&data, &input))
			break;
		if (input && ft_strequ(input, "exit"))
			break;
		sh_process_exec(&data, sh_process(&automaton, &tokens, &expand_array, input));
		sh_arrays_reset(&automaton, &tokens, &expand_array, input);
	}
	sh_arrays_reset(&automaton, &tokens, &expand_array, input);
	sh_exit(&data, NULL);
	return (0);
}
