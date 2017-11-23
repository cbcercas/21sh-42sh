/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_is_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 18:20:34 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/08 12:07:48 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

/*
** @brief Checks if the next token is a redirect.
**
** If the next token is a redirection, it will return it's type.\n
** Otherwise, this function will return a E_TOKEN_NONE
**
** @param cnt Contains current position in the token array
** @param expands Contains the token array
**
** @return Returns token's type if next token is a redirect.
*/

static t_token_type	ast_return_type_redir_front(t_array *expands, ssize_t cnt)
{
	t_exp		*exp;

	exp = (t_exp *)array_get_at(expands, (size_t)cnt + 1);
	if (exp && is_redirect(exp->type))
		return (exp->type);
	return (E_TOKEN_NONE);
}

/*
** @brief Checks if the preceding token is a redirect.
**
** If the prededing token is a redirection, it will return it's type.\n
** Otherwise, this function will return a E_TOKEN_NONE
**
** @param cnt Contains current position in the token array
** @param expands Contains the token array
**
** @return Returns token's type if preceding token is a redirect.
*/

static t_token_type	ast_return_type_redir_back(t_array *expands, ssize_t cnt)
{
	t_exp		*exp;

	exp = (t_exp *)array_get_at(expands, (size_t)cnt - 1);
	if (exp && is_redirect(exp->type))
		return (exp->type);
	while (exp && exp->type == E_TOKEN_BLANK)
	{
		cnt--;
		exp = (t_exp *)array_get_at(expands, (size_t)cnt - 1);
		if (exp && is_redirect(exp->type))
			return (exp->type);
	}
	return (E_TOKEN_NONE);
}

/*
** @brief Checks if the current token is a redirect.
**
** If the current token is a redirection, it will return it's type.\n
** Otherwise, this function will return a E_TOKEN_NONE
**
** @param cnt Contains current position in the token array
** @param expands Contains the token array
** @param type Contains the type of the current token
**
** @return Returns type if current token is a redirect.
*/

t_token_type		ast_return_type_redir(t_array *expands, ssize_t cnt,
										  t_token_type type)
{
	t_token_type	ret;
	t_exp			*exp;

	ret = type;
	if (is_redirect(ret))
		return (ret);
	if (type != E_TOKEN_IO_NUMBER && type != E_TOKEN_WORD &&\
			type != E_TOKEN_BLANK)
		return (E_TOKEN_NONE);
	if (type == E_TOKEN_IO_NUMBER &&
			(exp = (t_exp *)array_get_at(expands, (size_t)cnt)) && exp->str->len >= 2)
		return (E_TOKEN_NONE);
	if (type != E_TOKEN_WORD &&
			(ret = ast_return_type_redir_front(expands, cnt)) != E_TOKEN_NONE)
		return (ret);
	if ((ret = ast_return_type_redir_back(expands, cnt)) != E_TOKEN_NONE)
		return (ret);
	return (E_TOKEN_NONE);
}

/*
** @brief Tests if current token is a redirect.
**
** @param cnt Contains current position in the token array
** @param expands Contains the token array
** @param type Contains the type of the current token
**
** @return Returns true if current token is a redirect else will return false.
*/

BOOL				ast_is_redir(t_array *expands, ssize_t cnt,
								 t_token_type type)
{
	if (ast_return_type_redir(expands, cnt, type) == E_TOKEN_NONE)
		return (false);
	return (true);
}
