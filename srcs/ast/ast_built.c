/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/14 16:57:29 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ast/ast.h>

/*t_lim ast_built6_plus(t_array *expands, t_lim lim, size_t *len)
{
		t_exp	*exp;

		exp = NULL;
		while (lim.cnt <= lim.lim && lim.cnt <= expands->used &&\
			!(ast_is_redir(expands, lim.cnt - 1, exp)) &&
			(!exp || (exp->type == E_TOKEN_WORD) || (exp->type == E_TOKEN_BLANK)\
					 	|| (exp->type == E_TOKEN_DQUOTE) || (exp->type == E_TOKEN_SQUOTE)\
						|| (exp->type == 	E_TOKEN_IO_NUMBER)))
		{
			if (exp)
				*len = *len + exp->len;
			exp = (t_exp *)array_get_at(expands, lim.cnt);
			lim.cnt++;
		}
		lim.cnt--;
		return (lim);
}*/

t_btree	*ast_built6(t_btree *ast, t_array *expands, t_lim lim)
{
	t_exp	*exp;
	t_lim lim_left;
	//size_t	len;

	//lim_left = lim;
	exp = NULL;
	while (lim.cnt <= lim.lim && lim.cnt <= expands->used &&\
 				(!exp || (!(exp->type == E_TOKEN_WORD) &&\
				 !(exp->type == E_TOKEN_SQUOTE) && !(exp->type == E_TOKEN_DQUOTE)\
				  && !(exp->type == E_TOKEN_IO_NUMBER ))))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= expands->used && exp && lim.cnt < lim.lim)
	{
	//	len = exp->len;
	//	lim_left = ast_built6_plus(expands, lim, &len);
		lim_left.lim = lim.cnt;
		btree_insert_data(&ast, ast_new_cmd(exp), (int (*)(void*, void*))&ast_cmp);
//		ft_printf("4 cnt=%ld lim=%ld, str=|%s| len=%ld\n", lim_left.cnt, lim_left.lim, exp->str, len);
		ast->left = ast_built6(ast->left, expands, lim_left);
	}
	return (ast);
}

t_btree	*ast_built4(t_btree *ast, t_array *expands, t_lim lim)
{
	t_exp	*exp;
	t_lim lim_left;

	lim_left = lim;
	exp = NULL;
	while (lim.cnt < lim.lim && lim.cnt <= expands->used &&\
 				(!exp || (!(exp->type == E_TOKEN_PIPE) && !(exp->type == E_TOKEN_AND))))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= expands->used && exp && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		btree_insert_data(&ast, ast_new_cmd(exp), (int (*)(void*, void*))&ast_cmp);
		ast->left = ast_built_greatand(ast->left, expands, lim_left);
		ast->right = ast_built4(ast->right, expands, lim);
	}
	else
		ast = ast_built_greatand(ast, expands, lim_left);
	return (ast);
}

t_btree	*ast_built3(t_btree *ast, t_array *expands, t_lim lim)
{
	t_exp	*exp;
	t_lim lim_left;

	lim_left = lim;
	exp = NULL;
	while (lim.cnt < lim.lim && lim.cnt <= expands->used &&\
 				(!exp || (!(exp->type == E_TOKEN_DLESS) &&\
				 !(exp->type == E_TOKEN_DGREAT))))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= expands->used && exp && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		btree_insert_data(&ast, ast_new_cmd(exp), (int (*)(void*, void*))&ast_cmp);
		ast->left = ast_built4(ast->left, expands, lim_left);
		ast->right = ast_built3(ast->right, expands, lim);
	}
	else
	ast = ast_built4(ast, expands, lim_left);
	return (ast);
}

t_btree	*ast_built2(t_btree *ast, t_array *expands, t_lim lim)
{
	t_exp	*exp;
	t_lim lim_left;

	lim_left = lim;
	exp = NULL;
	while (lim.cnt < lim.lim && lim.cnt <= expands->used &&\
 				(!exp || !(exp->type == E_TOKEN_LESSGREAT)))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= expands->used && exp && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		btree_insert_data(&ast, ast_new_cmd(exp), (int (*)(void*, void*))&ast_cmp);
			ast->left = ast_built3(ast->left, expands, lim_left);
			ast->right = ast_built2(ast->right, expands, lim);
		if (ft_strequ(exp->str, "<"))
			ast_built2_swap(ast);
	}
	else
		ast = ast_built3(ast, expands, lim_left);
	return (ast);
}

t_btree	*ast_built1(t_btree *ast, t_array *expands, t_lim lim)
{
	t_exp	*exp;
	t_lim lim_left;

	lim_left = lim;
	exp = NULL;
	while (lim.cnt < lim.lim && lim.cnt <= expands->used &&\
 				(!exp || !((exp->type == E_TOKEN_SEMI) ||\
 				(exp->type == E_TOKEN_AND_IF) || (exp->type == E_TOKEN_OR_IF))))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= expands->used && exp && lim.cnt < lim.lim)
	{
		btree_insert_data(&ast, ast_new_cmd(exp), (int (*)(void*, void*))&ast_cmp);
		lim_left.lim = lim.cnt;
		ast->left = ast_built2(ast->left, expands, lim_left);
		ast->right = ast_built1(ast->right, expands, lim);
	}
	else
		ast = ast_built2(ast, expands, lim_left);
	return (ast);
}
