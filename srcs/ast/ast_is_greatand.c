/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_is_lgand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 18:20:34 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/02 13:40:53 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

BOOL	is_greatand_front(t_array *expands, size_t cnt)
{
	t_exp		*exp;

	exp = (t_exp *)array_get_at(expands, cnt + 1);
	if (exp && ISLGAND(exp->type))
		return (true);
	return (false);
}

BOOL	is_greatand_back(t_array *expands, size_t cnt)
{
	t_exp		*exp;

	exp = (t_exp *)array_get_at(expands, cnt - 1);
	if (exp && ISLGAND(exp->type))
		return (true);
	while (exp && exp->type == E_TOKEN_BLANK)
	{
		cnt--;
		exp = (t_exp *)array_get_at(expands, cnt - 1);
		if (exp && ISLGAND(exp->type))
			return (true);
	}
	return (false);
}

BOOL	ast_is_lgand(t_array *expands, size_t cnt, t_token_type type)
{
	if (ISLGAND(type))
		return (true);
	if ((type != E_TOKEN_IO_NUMBER && type != E_TOKEN_WORD &&\
				type != E_TOKEN_BLANK && type != E_TOKEN_DQUOTE &&\
				type != E_TOKEN_SQUOTE))
		return (false);
	if (is_greatand_front(expands, cnt))
		return (true);
	if (is_greatand_back(expands, cnt))
		return (true);
	return (false);
}
