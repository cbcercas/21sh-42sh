/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:00:25 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 14:56:59 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

/*
** @brief TODO
*/

static t_token_type	g_grammar2[19][19][1] =
{
	[E_TOKEN_NONE] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_SEMI] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_BLANK] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_PIPE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_SEMI] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_OR_IF] = {1},
		[E_TOKEN_AND_IF] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_NEWLINE] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_SEMI] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_OR_IF] = {1},
		[E_TOKEN_AND_IF] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_WORD] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_PIPE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_SEMI] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_OR_IF] = {1},
		[E_TOKEN_AND_IF] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_SQUOTE] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_PIPE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_SEMI] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_OR_IF] = {1},
		[E_TOKEN_AND_IF] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_BQUOTE] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_PIPE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_SEMI] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_OR_IF] = {1},
		[E_TOKEN_AND_IF] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_DQUOTE] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_PIPE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_SEMI] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_OR_IF] = {1},
		[E_TOKEN_AND_IF] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_PIPE] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_LESSGREAT] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_IO_NUMBER] = {1}
	},
	[E_TOKEN_SEMI] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_IO_NUMBER] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_PIPE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_SEMI] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_OR_IF] = {1},
		[E_TOKEN_AND_IF] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_DLESS] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_IO_NUMBER] = {1}
	},
	[E_TOKEN_DGREAT] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_IO_NUMBER] = {1}
	},
	[E_TOKEN_OR_IF] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_AND_IF] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_LESSGREAT] = {1},
		[E_TOKEN_IO_NUMBER] = {1},
		[E_TOKEN_DLESS] = {1},
		[E_TOKEN_DGREAT] = {1},
		[E_TOKEN_LESSAND] = {1},
		[E_TOKEN_GREATAND] = {1}
	},
	[E_TOKEN_LESSAND] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_IO_NUMBER] = {1}
	},
	[E_TOKEN_GREATAND] =
	{
		[E_TOKEN_BLANK] = {1},
		[E_TOKEN_NEWLINE] = {1},
		[E_TOKEN_WORD] = {1},
		[E_TOKEN_SQUOTE] = {1},
		[E_TOKEN_BQUOTE] = {1},
		[E_TOKEN_DQUOTE] = {1},
		[E_TOKEN_IO_NUMBER] = {1}
	}
};

/*
** @brief TODO
*/

static const char	*g_grammar[226] =
{
	[E_TOKEN_BLANK] = " ",
	[E_TOKEN_NEWLINE] = "\\n",
	[E_TOKEN_WORD] = "WORD",
	[E_TOKEN_SQUOTE] = "\'",
	[E_TOKEN_BQUOTE] = "`",
	[E_TOKEN_DQUOTE] = "\"",
	[E_TOKEN_PIPE] = "|",
	[E_TOKEN_LESSGREAT] = "< or >",
	[E_TOKEN_AND] = "&",
	[E_TOKEN_SEMI] = ";",
	[E_TOKEN_IO_NUMBER] = "IO_NUMBER",
	[E_TOKEN_DLESS] = "<<",
	[E_TOKEN_DGREAT] = ">>",
	[E_TOKEN_OR_IF] = "||",
	[E_TOKEN_AND_IF] = "&&",
	[E_TOKEN_LESSAND] = "<&",
	[E_TOKEN_GREATAND] = ">&"
};

/*
** @brief Returns an error and prints the appropriate message
**
** @param toknext The next token when the error occured
**
** @return Returns an error `E_RET_PARSER_ERROR`
*/

t_return						ret_parser(t_token *toknext)
{
	ft_dprintf(STDERR_FILENO, "%s: Parse error near `%s'\n", PROGNAME,
			g_grammar[toknext->type]);
	return (E_RET_PARSER_ERROR);
}

/*
** @brief Main function for the parser
** @param tokens The t_array containing tokens from the lexer
** @return Returns an error (`E_RET_PARSER_ERROR`) or a success
** (`E_RET_PARSER_OK`)
*/

t_return						parser_parse(t_array *tokens)
{
	size_t	i;
	t_token	*tok;
	t_token	*toknext;

	i = 0;
	if (!tokens->used)
		return (E_RET_PARSER_OK);
	tok = (t_token*)array_get_at(tokens, 0);
	if (!g_grammar2[0][tok->type][0])
		return (ret_parser(tok));
	while (tokens->used > i + 1)
	{
		while (tokens->used > i + 1 &&
				(toknext = ((t_token*)array_get_at(tokens, i + 1)))->type
				== E_TOKEN_BLANK)
			i += 1;
		if (g_grammar2[tok->type][toknext->type][0])
			i += 1;
		else
			return (ret_parser(toknext));
		tok = toknext;
	}
	if (g_grammar2[tok->type][E_TOKEN_NEWLINE][0])
		return (E_RET_PARSER_OK);
	return (ret_parser(tok));
}
