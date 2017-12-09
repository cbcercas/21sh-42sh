/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:26:48 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/10 13:26:50 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/sh_loop.h>

/*
** @brief Resets the given arrays
**
** @param tokens Token array to be reset
** @param expands Expand array to be reset
*/

void				sh_arrays_reset(t_array *tokens, t_array *expands)
{
	array_reset(tokens, NULL);
	array_reset(expands, (void *(*)(void *))&sh_exp_del);
	ft_secu_free_lvl(M_LVL_EXPA);
}

/*
** TODO test reset
*/

/*
** @brief Lexes, parses, expands then builds the ast and returns it
**
** @param ast The ast to be returned
** @param expands The expand
** @param tokens The lexer tokens
** @param line The line to process
**
** @return Returns the ast once built
*/

static t_return		sh_process(t_btree **ast, t_array *expands, t_array *tokens,
	char *line)
{
	t_return	ret;
	char		*hline;

	if ((ret = lexer_lex(tokens, line)) == E_RET_LEXER_OK && tokens->used
	&& ((t_token*)array_get_at(tokens, tokens->used - 1))->type != E_TOKEN_PIPE)
	{
		hline = input_to_history(input_get_cur_head());
		sh_history_set_new(&hline);
		if (ret == E_RET_LEXER_OK && (ret = parser_parse(tokens)) ==
									E_RET_PARSER_OK)
		{
			if ((ret = expand(tokens, expands)) == E_RET_EXPAND_OK)
			{
				if ((ret = ast_create(ast, expands)) == E_RET_AST_ERROR)
				{
					ft_dprintf(2, "%s: AST creation failed\n", PROGNAME);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	else if (ret == E_RET_LEXER_OK && tokens->used)
		ret = E_RET_LEXER_PIPE;
	return (ret);
}

/*
** @brief Processes each line of input and executes it
**
** @param data Shell's data used and accessed throughout the program
** @param exec_dat is struc contains all arrays we need for exec
** @param ret The return value
**
** @return false if everthing is ok, false otherwise (false for stop shell)
*/

BOOL				sh_loop(t_sh_data data, struct s_exec_data *exec_dat,
							t_return *ret)
{
	char	*line;

	if (!(line = sh_get_input(&data, NULL, *ret)))
		return (true);
	print_verb(line);
	if (input_get_cur())
		input_get_cur()->prompt_type = *ret;
	*ret = sh_process(&exec_dat->ast, &exec_dat->expand,
					&exec_dat->tokens, line);
	if (*ret == E_RET_AST_OK)
	{
		exec_exec(&data, exec_dat->ast);
		get_windows(72);
	}
	if (!(*ret >= E_RET_LEXER_INCOMPLETE && *ret <= E_RET_LEXER_PIPE))
	{
		input_destroy(&(input_get_cur_head())->next);
		input_reset(input_get_cur_head());
		*ret = E_RET_NEW_PROMPT;
	}
	if (exec_dat->ast)
		btree_destroy(&exec_dat->ast, (void (*)(void*))&ast_del_cmd);
	sh_arrays_reset(&exec_dat->tokens, &exec_dat->expand);
	ft_strdel(&line);
	return (false);
}
