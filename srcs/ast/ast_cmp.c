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

/**
 * \fn t_token_type	return_type(int prio, t_token_type type, t_array *expands,\
 *                             size_t cnt)
 * \brief get type of token.
 *
 * \param expands is token arrays
 * \param prio 1 = ";" or "||" or "&&", 2 = "|", 3 = redirections, 4 = "&"
 * \param cnt is position of the current token
 * \param type is the type of current token
 *
 * \return the token type.
 */
t_token_type	return_type(int prio, t_token_type type, t_array *expands,\
		size_t cnt)
{
	if (type == E_TOKEN_NEWLINE)
		return (E_TOKEN_SEMI);
	if (prio == 5)
		return (E_TOKEN_WORD);
	if (prio != 3)
		return (type);
	if (type == E_TOKEN_GREATAND || type == E_TOKEN_LESSAND)
		return (type);
	if (ast_is_redir(expands, cnt - 1, type))
		return (ast_return_type_redir(expands, cnt - 1, type));
	return (type);
}

/**
 * \fn BOOL	ast_prio(t_token_type type, int prio, size_t cnt, t_array *expands)
 *
 * \brief associate priority and token.
 *
 * \param cnt is position of the current token
 * \param expands is token arrays
 * \param prio 1 = ";" or "||" or "&&", 2 = "|", 3 = redirections, 4 = "&"
 * \param type is the type of current token
 *
 * \return true if token and prio is associate else false.
 */
BOOL		ast_prio(t_token_type type, int prio, size_t cnt, t_array *expands)
{
	if (prio == 1 && (is_sepa(type)))
		return (true);
	if (prio == 2 && type == E_TOKEN_PIPE)
		return (true);
	if (prio == 3 && (ast_is_redir(expands, cnt, type)))
		return (true);
	if (prio == 4 && type == E_TOKEN_AND)
		return (true);
	if (prio == 5 && (type == E_TOKEN_WORD || type == E_TOKEN_IO_NUMBER) &&\
			!ast_is_redir(expands, cnt, type))
		return (true);
	return (false);
}

/**
 * \fn static int		ast_val_cmp(t_token_type type)
 *
 * \brief return number of prio for ast_cmp.
 *
 * \param type is the type of current token
 *
 * \return number of prio for ast_cmp.
 */
static int		ast_val_cmp(t_token_type type)
{
	if (is_sepa(type))
		return (1);
	if (type == E_TOKEN_PIPE)
		return (2);
	if (is_redirect(type))
		return (3);
	if (type == E_TOKEN_AND)
		return (4);
	if (type == E_TOKEN_WORD || type == E_TOKEN_IO_NUMBER)
		return (5);
	return (6);
}

/**
 * \fn static int		ast_val_cmp(t_token_type type)
 *
 * \brief return number of prio for ast_cmp.
 *
 * \param s1 is pointer
 *
 * \return 0 if s1 is less than s2 else -1.
 */
int		ast_cmp(t_cmd *s1, t_cmd *s2)
{
	if (ast_val_cmp(s1->type) <= ast_val_cmp(s2->type))
		return (0);
	return (-1);
}
