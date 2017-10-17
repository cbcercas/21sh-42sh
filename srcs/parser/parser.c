/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:00:25 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/13 16:19:07 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <parser/enum.h>
#include <types/bool.h>
#include <array/array.h>
#include <tools/tools.h>
#include <core/progname.h>

static t_token_type	g_grammar2[19][19][1] =
{
	[E_TOKEN_NONE] =
	{
		[E_TOKEN_BLANK] = {1},
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
		[E_TOKEN_NONE] = {1}
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

BOOL						ret_parser(t_token *toknext)
{
	ft_printf("%s: parse error near `%s' : %s\n", PROGNAME,\
		g_grammar[toknext->type], toknext->str);
	return (false);
}

static BOOL					parser_end(t_array *tokens, size_t i, t_token *tok)
{
	t_token *toknext;

	toknext = array_get_at(tokens, i);
	if (tokens->used <= i + 1 && toknext->type == E_TOKEN_NEWLINE)
		return (true);
	return (ret_parser(tok));
}

BOOL						parser_parse(t_array *tokens)
{
	size_t	i;
	t_token	*tok;
	t_token	*toknext;

	i = 0;
	if (!tokens || !tokens->used)
		return (true);
	tok = (t_token*)array_get_at(tokens, 0);
	if (!g_grammar2[0][tok->type][0])
		return (ret_parser(tok));
	while (tokens->used > i + 1)
	{
		toknext = (t_token*)array_get_at(tokens, i + 1);
		while (tokens->used > i + 1 && toknext->type == E_TOKEN_BLANK)
			toknext = (t_token *)array_get_at(tokens, ++i);
		if (tokens->used == i + 1)
			return (ret_parser(toknext));
		if (g_grammar2[tok->type][toknext->type][0])
			i += 1;
		else
			return (ret_parser(toknext));
		tok = toknext;
	}
	return (parser_end(tokens, i, tok));
}
