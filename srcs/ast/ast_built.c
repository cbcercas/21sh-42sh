/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/31 09:13:59 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ast/ast.h>

t_token_type return_type(int prio, t_token_type type)
{
	if ( prio != 5 )
		return (type);
	return (E_TOKEN_GREATAND);
}

t_lim ast_built_greatand_plus(t_array *expands, t_lim lim)
{
	t_exp	*exp;

	exp = NULL;
	while (lim.cnt <= lim.lim && lim.cnt <= expands->used &&\
			(!exp || ast_is_greatand(expands, lim.cnt - 1, exp->type)))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
	}
	lim.cnt--;
	return (lim);
}

t_lim ast_built_word_plus(t_array *expands, t_lim lim)
{
	t_exp	*exp;

	exp = NULL;
	while (lim.cnt <= lim.lim && lim.cnt <= expands->used &&\
			(!exp || (exp->type == E_TOKEN_WORD) || (exp->type == E_TOKEN_BLANK) ||\
			 ((exp->type == E_TOKEN_IO_NUMBER) &&\
			  	!ast_is_greatand(expands, lim.cnt - 1, exp->type))))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
	}
	lim.cnt--;
	return (lim);
}

t_exp		*ast_search(t_array *expands, t_lim *lim, int prio)
{
	t_exp		*exp;

	exp = NULL;
	while (lim->cnt < lim->lim && lim->cnt <= expands->used &&\
			(!exp || !(ast_prio(exp->type, prio, lim->cnt - 1, expands))))
	{
		exp = (t_exp *)array_get_at(expands, lim->cnt);
		lim->cnt++;
	}
	return (exp);
}

t_btree	*ast_built(t_btree *ast, t_array *expands, t_lim lim, int prio)
{
	t_exp	*exp;
	t_lim lim_left;

	lim_left = lim;
	exp = ast_search(expands, &lim, prio);
	if (lim.cnt <= expands->used && exp && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		lim = (prio == 5 ? ast_built_greatand_plus(expands, lim) : lim);
		lim = (prio == 6 ? ast_built_word_plus(expands, lim) : lim);
		btree_insert_data(&ast, ast_new_cmd(expands, lim_left.lim - 1, lim.cnt,\
					return_type(prio, exp->type)), (int (*)(void*, void*))&ast_cmp);
		if (prio != 6)
			ast->left = ast_built(ast->left, expands, lim_left, prio + 1);
		ast->right = ast_built(ast->right, expands, lim, prio);
	}
	else if (prio != 6)
		ast = ast_built(ast, expands, lim_left, prio + 1);
	return (ast);
}
