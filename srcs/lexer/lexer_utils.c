/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 01:56:00 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/09 02:50:00 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

/*
** @brief Checks if a given token type is a token type
**
** @param t The token type to check
**
** @return Returns true or false
*/

BOOL			is_token_type(t_token_type t)
{
	if (t > E_TOKEN_NONE && t < E_TOKEN_MAX)
		return (true);
	else
		return (false);
}

/*
** @brief Prints token type for token tok
**
** @param tok The token
*/

static void		lexer_print_token2(t_token *tok)
{
	if (tok->type == E_TOKEN_LESSGREAT)
		ft_putstr("TOKEN_TYPE_LESSGREAT");
	else if (tok->type == E_TOKEN_DGREAT)
		ft_putstr("TOKEN_TYPE_DGREAT");
	else if (tok->type == E_TOKEN_DLESS)
		ft_putstr("TOKEN_TYPE_DLESS");
	else if (tok->type == E_TOKEN_AND)
		ft_putstr("TOKEN_TYPE_AND");
	else if (tok->type == E_TOKEN_AND_IF)
		ft_putstr("TOKEN_TYPE_AND_IF");
	else if (tok->type == E_TOKEN_SEMI)
		ft_putstr("TOKEN_TYPE_SEMI");
	else if (tok->type == E_TOKEN_LESSAND)
		ft_putstr("TOKEN_TYPE_LESSAND");
	else if (tok->type == E_TOKEN_GREATAND)
		ft_putstr("TOKEN_TYPE_GREATAND");
	else if (tok->type == E_TOKEN_IO_NUMBER)
		ft_putstr("TOKEN_TYPE_IO_NUMBER");
}

static void		lexer_print_token(t_token *tok)
{
	if (tok->type == E_TOKEN_BLANK)
		ft_putstr("TOKEN_TYPE_BLANK");
	else if (tok->type == E_TOKEN_NEWLINE)
		ft_putstr("TOKEN_TYPE_NEWLINE");
	else if (tok->type == E_TOKEN_WORD)
		ft_putstr("TOKEN_TYPE_WORD");
	else if (tok->type == E_TOKEN_SQUOTE)
		ft_putstr("TOKEN_TYPE_SQUOTE");
	else if (tok->type == E_CHAR_TYPE_BQUOTE)
		ft_putstr("TOKEN_TYPE_BQUOTE");
	else if (tok->type == E_TOKEN_DQUOTE)
		ft_putstr("TOKEN_TYPE_DQUOTE");
	else if (tok->type == E_TOKEN_PIPE)
		ft_putstr("TOKEN_TYPE_PIPE");
	else if (tok->type == E_TOKEN_OR_IF)
		ft_putstr("TOKEN_TYPE_OR_IF");
	else
		lexer_print_token2(tok);
}

/*
** @brief Prints all the tokens for the given t_array
**
** @param toks t_array to be printed
*/

void			lexer_print_tokens(t_array *toks)
{
	size_t	cnt;
	t_token	*tok;

	cnt = 0;
	while (cnt < toks->used)
	{
		tok = (t_token *)array_get_at(toks, cnt);
		ft_putchar('<');
		ft_putnstr(tok->str, tok->len);
		ft_putstr("> = ");
		lexer_print_token(tok);
		ft_putchar('\n');
		cnt++;
	}
}

/*
** @brief Handles the return values
**
** @param cur_state The current state of the stack
**
** @return Returns a value based on the error or not of the lexer
*/

t_return		lexer_get_incomplete_ret(t_stack_state cur_state)
{
	if (cur_state == E_STATE_SQUOTE)
		return (E_RET_LEXER_SQUOTE);
	else if (cur_state == E_STATE_BQUOTE)
		return (E_RET_LEXER_BQUOTE);
	else if (cur_state == E_STATE_DQUOTE)
		return (E_RET_LEXER_DQUOTE);
	else
		return (E_RET_LEXER_INCOMPLETE);
}
