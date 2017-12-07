/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/14 15:02:58 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

/*
** @brief Swap limits
**
** @param lim Contains virtual limit and start pos
**
** @return Returns the Abstract Syntax Tree
*/

static t_lim			swap_lim(t_lim lim)
{
	t_lim	ret;

	ret.lim = lim.cnt;
	ret.cnt = lim.lim;
	return (ret);
}

/*
** @brief ast_built Builds the ast recursively
**
** @param ast Contains the abstract syntax tree
** @param expands Contains the token array
** @param lim Contains virtual limit and start pos
** @param prio Priority for tokens
**
** 1 = ";" or "||" or "&&",\n
** 2 = "|",\n
** 3 = redirections,\n
** 4 = "&".
**
** @return Returns the Abstract Syntax Tree
*/

t_btree					*ast_built(t_btree **ast,
						t_array *expands, t_lim lim, int prio)
{
	t_exp	*exp;
	t_lim	lim_right;

	lim_right = lim;
	exp = NULL;
	log_dbg1("AST: BUILT-START prio:%d cnt:%d lim:%d", prio, lim.cnt, lim.lim);
	if (prio != 4 && prio != 3)
		exp = ast_search(expands, &lim, prio);
	else
		*ast = ast_built2(ast, expands, swap_lim(lim_right), prio);
	if (lim.cnt >= 0 && exp && lim.cnt > lim.lim)
	{
		lim_right.lim = lim.cnt;
		btree_insert_data(ast, ast_new_cmd(expands, lim.cnt, lim_right.lim + 1,\
					return_type(prio, exp->type, expands, lim_right.lim)), \
				(int (*)(void*, void*))&ast_cmp);
		(*ast)->left = ast_built(&(*ast)->left, expands, lim, prio);
		if (lim.cnt >= 0)
			(*ast)->right = ast_built(&(*ast)->right, expands,
									lim_right, prio + 1);
	}
	else if (prio != 4)
		*ast = ast_built(ast, expands, lim_right, prio + 1);
	log_dbg1("AST: BUILT-END prio:%d cnt:%d lim:%d", prio, lim.cnt, lim.lim);
	return (*ast);
}
