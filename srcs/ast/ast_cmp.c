/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 18:18:09 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/11 15:06:56 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

/*
** @brief Finds and returns the type of given token
**
** Compares priorities and returns appropriate type
**
** @param expands Contains the token array
** @param prio Priority for tokens
**
** 1 = ";" or "||" or "&&",\n
** 2 = "|",\n
** 3 = redirections,\n
** 4 = "&".
**
** @param cnt Contains the position of the current token
** @param type Contains the current token's type
**
** @return Returns the token type
**
** Return values can be any token type defined in lexer.h
*/

t_token_type	return_type(int prio, t_token_type type, t_array *expands, \
								ssize_t cnt)
{
	if (type == E_TOKEN_NEWLINE)
		return (E_TOKEN_SEMI);
	if (prio == 4)
		return (E_TOKEN_WORD);
	if (prio != 3)
		return (type);
	if (type == E_TOKEN_GREATAND || type == E_TOKEN_LESSAND)
		return (type);
	if (ast_is_redir(expands, cnt, type))
		return (ast_return_type_redir(expands, cnt, type));
	return (type);
}

/*
** @brief Associates priorities and tokens
**
** This will test possible matches between priorities and tokens, and will
** then return true if they match
**
** @param cnt Contains position of the current token
** @param expands Contains the token array
** @param prio Priority for tokens
**
** 1 = ";" or "||" or "&&",\n
** 2 = "|",\n
** 3 = redirections,\n
** 4 = "&".
**
** @param type Contains the type of current token
**
** @return Returns true if token and priority match, else returns false
*/

BOOL			ast_prio(t_token_type type, int prio, ssize_t cnt,
						t_array *expands)
{
	if (prio == 1 && (is_sepa(type)))
		return (true);
	if (prio == 2 && type == E_TOKEN_PIPE)
		return (true);
	if (prio == 3 && (ast_is_redir(expands, cnt, type)))
		return (true);
	if (prio == 4 && (type == E_TOKEN_WORD || type == E_TOKEN_IO_NUMBER) &&\
			!ast_is_redir(expands, cnt, type))
		return (true);
	return (false);
}

/*
** @brief Compares given token type and returns appropriate priority for the ast
**
** @param type Contains current token's type
**
** @return Returns the priority
*/

static int		ast_val_cmp(t_token_type type)
{
	if (is_sepa(type))
		return (1);
	if (type == E_TOKEN_PIPE)
		return (2);
	if (is_redirect(type))
		return (3);
	if (type == E_TOKEN_WORD || type == E_TOKEN_IO_NUMBER)
		return (4);
	return (5);
}

/*
** @brief Returns priority between two commands
**
** @param s1 First command to compare
** @param s2 Second command to compare
**
** @return Returns 0 if s1 is less than s2, else it will return -1.
*/

int				ast_cmp(t_cmd *s1, t_cmd *s2)
{
	if (ast_val_cmp(s1->type) <= ast_val_cmp(s2->type))
		return (0);
	return (-1);
}
