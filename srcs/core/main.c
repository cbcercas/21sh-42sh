/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 16:10:41 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/main.h>

/*
**init tout les arrays qu'on a besoins
*/

void		sh_arrays_init(t_array *tokens, t_array *expand)
{
	if (lexer_init(tokens) == NULL)
		exit(EXIT_FAILURE);
	if (expand_init(expand) == NULL)
		exit(EXIT_FAILURE);
}

/*
**récupère l'input en fonction d'isatty
*/

BOOL		sh_get_input(t_sh_data *data, char **input)
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

/*
**reset les arrays
*/

void		sh_arrays_reset(t_array *tokens, t_array *expands, char *input)
{
	array_reset(tokens, NULL);
	array_reset(expands, sh_exp_del);
	input ? ft_strdel(&input) : 0;
	string_del(&g_input->str);
	ft_secu_free_lvl(M_LVL_AST);
	ft_secu_free_lvl(M_LVL_EXPA);
}

/*
**lex, pars, expand, et build ast, il retourn l'ast
*/

t_btree		*sh_process(t_btree **ast, t_array *expands, t_array *tokens, char *input)
{
	if (lexer_lex(tokens, input))
	{
		if (parser_parse(tokens))
		{
			if (expand(tokens, expands))
			{
				sh_history_set_new(input);
				if (!(ast_create(ast, expands)))
				{
					ft_printf("AST NULL\n");
					exit(EXIT_FAILURE);
				}
				else
					return (*ast);
			}
		}
	}
	return (NULL);
}

/*
**j'ai beaucoup de mal à diminuer le nombre de variables
*/


/*! @mainpage 21-42sh Documentation
 *
 * @section intro_sec Introduction
 *
 * Welcome to the (doxygen-generated) documentation for 21-42sh \n
 * You'll find in here all the documentation, man pages and info about
 * our wonderful project started on Jan 15 2017 by *Christopher Bravo Cercas* \n and later joined
 * by *Jules Lasne*, *Guillaume Pouyat* and *Mathieu Leroy*
 *
 * @section install_sec Installation
 *
 * First, you'll need to clone the repository with all the submodules
 *
 * `git clone --recursive https://github.com/cbcercas/21-42sh.git 21-42sh`
 *
 * Then just `cd` in the directory and `make`
 *
 * @subsection step1 Step 1: Opening the box
 *
 * WIP *Need to add all the instructions here and add them on README.md to*
 */

int			main(int ac, char *const *av, char **environ)
{
	t_sh_data	data;
	t_array		tokens;
	t_array		expand;
	t_btree		*ast;
	char		*input;

	ast = NULL;
	sh_arrays_init(&tokens, &expand);
	if (!sh_init(&data, ac, av, environ))
		exit(1);
	while (42)
	{
		sh_print_prompt();
		if (!sh_get_input(&data, &input))
			break ;
		if (input && ft_strequ(input, "exit"))
			break ;
		if (sh_process(&ast, &expand, &tokens, input))
			sh_process_exec(&data, ast);
		sh_arrays_reset(&tokens, &expand, input);
	}
	sh_arrays_reset(&tokens, &expand, input);
	sh_exit(&data, NULL);
	return (0);
}
