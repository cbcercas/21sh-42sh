/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/06 18:23:56 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

static t_lim			ast_built_redir_plus(t_array *expands, t_lim lim)
{
	t_exp	*exp;

	exp = NULL;
	while (lim.cnt <= lim.lim && lim.cnt <= expands->used &&\
			(!exp || ast_is_redir(expands, lim.cnt - 1, exp->type)))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
		if (exp->type == E_TOKEN_WORD)
			{
				lim.cnt++;
				break;
			}
	}
	lim.cnt--;
	return (lim);
}

static t_lim			ast_built_word_plus(t_array *expands, t_lim lim)
{
	t_exp	*exp;

	exp = NULL;
	while (lim.cnt <= lim.lim && lim.cnt <= expands->used &&\
			(!exp || (!ISSEP(exp->type))))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt > lim.lim && lim.cnt <= expands->used)
		lim.cnt--;
	lim.cnt--;
	return (lim);
}

t_btree			*ast_built2(t_btree *ast, t_array *expands, t_lim lim, int prio)
{
	t_exp	*exp;
	t_lim	lim_left;

	lim_left = lim;
	exp = NULL;
	exp = ast_search(expands, &lim, prio);
	if (lim.cnt <= expands->used && exp && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		lim = (prio == 3 ? ast_built_redir_plus(expands, lim) : lim);
		lim = (prio == 5 ? ast_built_word_plus(expands, lim) : lim);
		btree_insert_data(&ast, ast_new_cmd(expands, lim_left.lim - 1, lim.cnt,\
					return_type(prio, exp->type, expands, lim_left.lim)), \
				(int (*)(void*, void*))&ast_cmp);
		ast->left = ast_built2(ast->left, expands, lim, prio);
	}
	return (ast);
}

t_btree			*ast_built(t_btree *ast, t_array *expands, t_lim lim, int prio)
{
	t_exp	*exp;
	t_lim	lim_left;

	lim_left = lim;
	exp = NULL;
	if (prio != 5 && prio != 3)
		exp = ast_search(expands, &lim, prio);
	else
		ast = ast_built2(ast, expands, lim_left, prio);
	if (lim.cnt <= expands->used && exp && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		btree_insert_data(&ast, ast_new_cmd(expands, lim_left.lim - 1, lim.cnt,\
					return_type(prio, exp->type, expands, lim_left.lim)), \
				(int (*)(void*, void*))&ast_cmp);
		if (prio != 5 && prio != 3)
			ast->left = ast_built(ast->left, expands, lim_left, prio + 1);
		if (prio != 5 && prio != 3)
			ast->right = ast_built(ast->right, expands, lim, prio);
	}
	else if (prio != 5)
		ast = ast_built(ast, expands, lim_left, prio + 1);
	return (ast);
}
