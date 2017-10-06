/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 18:18:09 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/06 18:59:10 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

t_token_type	return_type(int prio, t_token_type type, t_array *expands,\
                            size_t cnt)
{
	if (prio == 5)
		return (E_TOKEN_WORD);
	if (prio != 3)
		return (type);
	if (ISLGAND(type))
		return (type);
	if (ast_is_redir(expands, cnt - 1, type))
		return (ast_return_type_redir(expands, cnt - 1, type));
	return (type);
}

BOOL		ast_prio(t_token_type type, int prio, size_t cnt, t_array *expands)
{
	if (prio == 1 && (ISSEP(type)))
		return (true);
	if (prio == 2 && ISPIPE(type))
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

static int		ast_val_cmp(t_token_type type)
{
	if (ISSEP(type))
		return (1);
	if (ISPIPE(type))
		return (2);
	if (ISRED(type))
		return (3);
	if (type == E_TOKEN_AND)
		return (4);
	if (type == E_TOKEN_WORD || type == E_TOKEN_IO_NUMBER)
		return (5);
	return (6);
}

int		ast_cmp(t_cmd *s1, t_cmd *s2)
{
	if (ast_val_cmp(s1->type) <= ast_val_cmp(s2->type))
		return (0);
	return (-1);
}
