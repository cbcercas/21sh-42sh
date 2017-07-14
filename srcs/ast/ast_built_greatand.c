/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_built_greatand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 18:20:34 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/14 16:57:56 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

/*BOOL	ast_is_redir(t_array *expands, size_t cnt, t_exp *cur)
{
	t_exp *exp;

	if (cur && cur->type == E_TOKEN_GREATAND)
		return (true);
	if (!cur || (cur->type != E_TOKEN_IO_NUMBER && cur->type != E_TOKEN_WORD &&\
		cur->type != E_TOKEN_BLANK && cur->type != E_TOKEN_DQUOTE &&\
		cur->type != E_TOKEN_SQUOTE))
		return (false);
	exp = NULL;
	exp = (t_exp *)array_get_at(expands, cnt + 1);
	if (exp && exp->type == E_TOKEN_GREATAND)
		return (true);
	exp = (t_exp *)array_get_at(expands, cnt - 1);
	if (exp && exp->type == E_TOKEN_GREATAND)
		return (true);
	while (exp && exp->type == E_TOKEN_BLANK)
	{
		cnt--;
		exp = (t_exp *)array_get_at(expands, cnt - 1);
		if (exp && exp->type == E_TOKEN_GREATAND)
			return (true);
	}
	return (false);
}

t_lim ast_built_greatand_plus(t_array *expands, t_lim lim, size_t *len)
{
		t_exp	*exp;

		exp = NULL;
		while (lim.cnt <= lim.lim && lim.cnt <= expands->used &&\
			(!exp || ast_is_redir(expands, lim.cnt - 1, exp)))
		{
			if (exp)
				*len = *len + exp->len;
			exp = (t_exp *)array_get_at(expands, lim.cnt);
			lim.cnt++;
		}
		lim.cnt--;
		return (lim);
}*/

t_btree	*ast_built_greatand(t_btree *ast, t_array *expands, t_lim lim)
{
	t_exp	*exp;
	t_lim lim_left;

	lim_left = lim;
	exp = NULL;
	while (lim.cnt < lim.lim && lim.cnt <= expands->used &&\
 				(!exp || exp->type != E_TOKEN_GREATAND))//!(ast_is_redir(expands, lim.cnt - 1, exp))))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= expands->used && exp && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		//lim = ast_built_greatand_plus(expands, lim, &len);
		btree_insert_data(&ast, ast_new_cmd(exp), (int (*)(void*, void*))&ast_cmp);
		ast->left = ast_built6(ast->left, expands, lim_left);
		ast->right = ast_built_greatand(ast->right, expands, lim);
	}
	else
		ast = ast_built6(ast, expands, lim_left);
	return (ast);
}
