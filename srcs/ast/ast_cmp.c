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
** @brief Finds and returns the type of given token.\n
** This function will compares priorities and returns the appropriate
** `t_token_type`
**
** @param expands Contains the expanded user input
** @param prio Priority for tokens:\n
** 1 = ";" or "||" or "&&",\n
** 2 = "|",\n
** 3 = redirections,\n
** 4 = "&".
** @param cnt Contains the position of the current token
** @param type Contains the current token's type
**
** @return Returns a token type.\n
** Return values can be any token type defined in lexer.h
*/

t_token_type	return_type(int prio, t_token_type type, t_array *expands,
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
** @brief Associates a given token to a priority.\n
** This function will test the given token and every priority and will return
** `true` if they match.
**
** @param cnt Contains position of the current token
** @param expands Contains the token array
** @param prio Priority for tokens:\n
** 1 = ";" or "||" or "&&",\n
** 2 = "|",\n
** 3 = redirections,\n
** 4 = "&".
** @param type Contains the type of current token
**
** @return The return value is based on the match or not of the token and the
** priority. If `token` and `prio` match, This function will return `true`.\n
** Else, This function will return `false`.
*/

BOOL			ast_associate_prio(t_token_type type, int prio, ssize_t cnt,
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
** @brief Compares and returns the priority for each token.\n
** If the token `type` is a `separator`, then it's priority will be set to 1.\n
** If the token `type` is a `pipe`, then it's priority will be set to 2.\n
** If the token `type` is a `redir`, then it's priority will be set to 3.\n
** If the token `type` is a `word`, then it's priority will be set to 4.\n
**
** @param type Contains the current token's type to be matched with a priority
**
** @return Returns the priority of the given token `type`
*/

static int		ast_get_prio(t_token_type type)
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
** @brief Checks if s1 is under s2 priority wise.
**
** @param s1 First command to compare
** @param s2 Second command to compare
**
** @return Returns 0 if s1 is less than s2, else it will return -1.
*/

int				ast_cmp(t_cmd *s1, t_cmd *s2)
{
	if (ast_get_prio(s1->type) <= ast_get_prio(s2->type))
		return (0);
	return (-1);
}
