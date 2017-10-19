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

BOOL		sh_get_input(t_sh_data *data, t_input *input)
{
	char *line;

	line = NULL;
	if (!isatty(0))
	{
		if (!get_next_line(0, &line))
			return (false);
		if (line)
		{
			ft_putendl(line);
			string_insert(input->str, line, 0);
			ft_strdel(&line);
		}
	}
	else
		sh_get_line(input, &(data->opts));
	return (true);
}

/*
**reset les arrays
*/

void		sh_arrays_reset(t_array *tokens, t_array *expands)
{
	//TODO test reset
	array_reset(tokens, NULL);
	array_reset(expands, sh_exp_del);
	//ft_secu_free_lvl(M_LVL_AST);
	ft_secu_free_lvl(M_LVL_EXPA);
}

/*
**lex, pars, expand, et build ast, il retourn l'ast
*/

t_return	sh_process(t_btree **ast, t_array *expands, t_array *tokens,
					   t_input *input)
{
	t_return	ret;
	//static char *save = NULL;

	//save = save ? ft_strjoincl(save, input->str->s, 1) : ft_strdup(input->str->s);
	if (((ret = lexer_lex(tokens, input->str->s)) == E_RET_LEXER_INCOMPLETE)
		|| (tokens->used > 1 &&
		((t_token*)array_get_at(tokens, tokens->used - 1))->type == E_TOKEN_PIPE))
	{
		input->prompt = false;
	}
	else
	{
		input->prompt = true;
		sh_history_set_new(input->str->s);
		if (ret == E_RET_LEXER_OK && (ret = parser_parse(tokens)) ==
									 E_RET_PARSER_OK)
		{
			if ((ret = expand(tokens, expands)) == E_RET_EXPAND_OK)
			{
				if ((ret = ast_create(ast, expands)) == E_RET_AST_ERROR)
				{
					ft_dprintf(STDERR_FILENO, "%s: AST creation failed\n",
							   PROGNAME);
					exit(EXIT_FAILURE);
				}
			}
		}
		//ft_strdel(&save);
	}
	return (ret);
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

struct s_test
{
	t_array		tokens;
	t_array		expand;
	t_btree		*ast;

};

int			main(int ac, char *const *av, char **environ)
{
	t_sh_data	data;
	struct s_test exec_dat;
	t_return	ret;
	//char		*input;
	t_input		input;
	ft_bzero(&input, sizeof(input));
	input.str = NULL;
	input.select.str = NULL;
	input.prompt = true;
	input.len_save = 0;
	g_input = &input;

	exec_dat.ast = NULL;
	sh_arrays_init(&exec_dat.tokens, &exec_dat.expand);
	if (!sh_init(&data, ac, av, environ))
		exit(1);
	reset_input(&input);
	while (42)
	{
		sh_print_prompt();
		if (!sh_get_input(&data, &input))
			break ;
		if (input.str->len > 1 && ft_strequ(input.str->s, "exit"))
			break ;
		ret = sh_process(&exec_dat.ast, &exec_dat.expand, &exec_dat.tokens, &input);
		if (ret == E_RET_AST_OK)
		{
			sh_process_exec(&data, exec_dat.ast);
		}
		if (exec_dat.ast)
			btree_destroy(&exec_dat.ast, (void (*)(void*))&ast_del_cmd);
		sh_arrays_reset(&exec_dat.tokens, &exec_dat.expand);
	}
	sh_arrays_reset(&exec_dat.tokens, &exec_dat.expand);
	sh_exit(&data, NULL);
	return (0);
}
