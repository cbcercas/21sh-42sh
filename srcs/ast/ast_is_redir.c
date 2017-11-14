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

/**
 * \fn static t_token_type ast_return_type_redir_front(t_array *expands,\
 *																											size_t cnt)
 *
 * \brief looks at the next token and returns its type if it's a redirect.
 *
 * \param cnt is position of the current token
 * \param expands is token arrays
 *
 * \return type if next token is redirect else return E_TOKEN_NONE.
 */
static t_token_type	ast_return_type_redir_front(t_array *expands, size_t cnt)
{
	t_exp		*exp;

	exp = (t_exp *)array_get_at(expands, cnt + 1);
	if (exp && is_redirect(exp->type))
		return (exp->type);
	return (E_TOKEN_NONE);
}

/**
 * \fn static t_token_type	ast_return_type_redir_back(t_array *expands,\
 *																											size_t cnt)
 *
 * \brief looks at the before tokens and returns its type if it's a redirect.
 *
 * \param cnt is position of the current token
 * \param expands is token arrays
 *
 * \return type if before tokenss is redirect else return E_TOKEN_NONE.
 */
static t_token_type	ast_return_type_redir_back(t_array *expands, size_t cnt)
{
	t_exp		*exp;

	exp = (t_exp *)array_get_at(expands, cnt - 1);
	if (exp && is_redirect(exp->type))
		return (exp->type);
	while (exp && exp->type == E_TOKEN_BLANK)
	{
		cnt--;
		exp = (t_exp *)array_get_at(expands, cnt - 1);
		if (exp && is_redirect(exp->type))
			return (exp->type);
	}
	return (E_TOKEN_NONE);
}

/**
 * \fn t_token_type	ast_return_type_redir(t_array *expands, size_t cnt,\
 * 																									t_token_type type)
 *
 * \brief return type if current token is redirect else E_TOKEN_NONE.
 *
 * \param cnt is position of the current token
 * \param expands is token arrays
 * \param type is the type of current token
 *
 * \return return type if current token is redirect, else E_TOKEN_NONE.
 */
t_token_type	ast_return_type_redir(t_array *expands, size_t cnt, t_token_type type)
{
	t_token_type	ret;

	ret = type;
	if (is_redirect(ret))
		return (ret);
	if (type != E_TOKEN_IO_NUMBER && type != E_TOKEN_WORD &&\
			type != E_TOKEN_BLANK)
		return (E_TOKEN_NONE);
	if (type != E_TOKEN_WORD && (ret = ast_return_type_redir_front(expands, cnt)) != E_TOKEN_NONE)
		return (ret);
	if ((ret = ast_return_type_redir_back(expands, cnt)) != E_TOKEN_NONE)
		return (ret);
	return (E_TOKEN_NONE);
}

/**
 * \fn t_token_type	ast_is_redir(t_array *expands, size_t cnt,\
 * 																									t_token_type type)
 *
 * \brief test if current token is redirect.
 *
 * \param cnt is position of the current token
 * \param expands is token arrays
 * \param type is the type of current token
 *
 * \return return true if current token is redirect else flase.
 */
BOOL ast_is_redir(t_array *expands, size_t cnt, t_token_type type)
{
	if (ast_return_type_redir(expands, cnt, type) == E_TOKEN_NONE)
		return (false);
	return (true);
}
