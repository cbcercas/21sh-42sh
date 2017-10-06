/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_is_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 18:20:34 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/02 13:40:53 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

static t_token_type	ast_return_type_redir_front(t_array *expands, size_t cnt)
{
	t_exp		*exp;

	exp = (t_exp *)array_get_at(expands, cnt + 1);
	if (exp && ISRED(exp->type))
		return (exp->type);
	return (E_TOKEN_NONE);
}

static t_token_type	ast_return_type_redir_back(t_array *expands, size_t cnt)
{
	t_exp		*exp;

	exp = (t_exp *)array_get_at(expands, cnt - 1);
	if (exp && ISRED(exp->type))
		return (exp->type);
	while (exp && exp->type == E_TOKEN_BLANK)
	{
		cnt--;
		exp = (t_exp *)array_get_at(expands, cnt - 1);
		if (exp && ISRED(exp->type))
			return (exp->type);
	}
	return (E_TOKEN_NONE);
}

t_token_type	ast_return_type_redir(t_array *expands, size_t cnt, t_token_type type)
{
	t_token_type	ret;

	ret = type;
	if (ISRED(ret))
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

BOOL ast_is_redir(t_array *expands, size_t cnt, t_token_type type)
{
	if (ast_return_type_redir(expands, cnt, type) == E_TOKEN_NONE)
		return (false);
	return (true);
}
