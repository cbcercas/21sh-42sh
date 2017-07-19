/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:47:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/19 18:06:23 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ast/ast.h>

int	ast_val_cmp(t_token_type type)
{
	if ((type == E_TOKEN_SEMI) ||\
			(type == E_TOKEN_AND_IF) || (type == E_TOKEN_OR_IF))
		return (1);
	if (type == E_TOKEN_LESSGREAT)
		return (2);
	if (type == E_TOKEN_DLESS)
		return (3);
	if (type == E_TOKEN_DGREAT)
		return (4);
	if ((type == E_TOKEN_PIPE) || (type == E_TOKEN_AND))
		return (5);
	if (type == E_TOKEN_WORD || type == E_TOKEN_IO_NUMBER)
		return (6);
	return (7);
}

int	ast_cmp(t_cmd *s1, t_cmd *s2)
{
	if (ast_val_cmp(s1->type) <= ast_val_cmp(s2->type))
		return (0);
	return (1);
}

t_btree	*ast_create(t_array *expands)
{
	t_lim			lim;
	t_btree		*ast;

	ast = NULL;
	lim.cnt = 0;
	lim.lim = 10000;
	ast = ast_built(ast, expands, lim, 1);
	return (ast);
}
