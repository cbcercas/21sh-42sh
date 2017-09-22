/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:47:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/21 12:28:56 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ast/ast.h>

int	ast_val_cmp(t_token_type type)
{
	if ((type == E_TOKEN_SEMI) ||\
			(type == E_TOKEN_AND_IF) || (type == E_TOKEN_OR_IF))
		return (1);
	if ((type == E_TOKEN_PIPE) || (type == E_TOKEN_AND))
		return (2);
	if (type == E_TOKEN_LESSGREAT ||  type == E_TOKEN_DLESS ||\
		 		type == E_TOKEN_DGREAT || type == E_TOKEN_GREATAND ||\
				 	type == E_TOKEN_LESSAND)
		return (3);
	if (type == E_TOKEN_WORD || type == E_TOKEN_IO_NUMBER)
		return (4);
	return (5);
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
