/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/20 17:29:00 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ast/ast.h>

t_btree	*ast_built5(t_btree *ast, t_array *tokens, t_lim lim)
{
	t_token	*tok;
	t_lim lim_left;

	lim_left = lim;
	tok = NULL;
	while (lim.cnt <= lim.lim && lim.cnt <= tokens->used &&\
 				(!tok || !(tok->type == E_TOKEN_WORD)))
	{
		tok = (t_token *)array_get_at(tokens, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= tokens->used && tok && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		btree_insert_data(&ast, ast_new_cmd(tok->str, tok->len, tok->type), (int (*)(void*, void*))&ast_cmp);
		ast->left = ast_built5(ast->left, tokens, lim_left);
	}
	return (ast);
}

t_btree	*ast_built4(t_btree *ast, t_array *tokens, t_lim lim)
{
	t_token	*tok;
	t_lim lim_left;

	lim_left = lim;
	tok = NULL;
	while (lim.cnt < lim.lim && lim.cnt <= tokens->used &&\
 				(!tok || (!(tok->type == E_TOKEN_PIPE) && !(tok->type == E_TOKEN_AND))))
	{
		tok = (t_token *)array_get_at(tokens, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= tokens->used && tok && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		btree_insert_data(&ast, ast_new_cmd(tok->str, tok->len, tok->type), (int (*)(void*, void*))&ast_cmp);
		ast->left = ast_built5(ast->left, tokens, lim_left);
		ast->right = ast_built4(ast->right, tokens, lim);
	}
	else
		ast = ast_built5(ast, tokens, lim_left);
	return (ast);
}

t_btree	*ast_built3(t_btree *ast, t_array *tokens, t_lim lim)
{
	t_token	*tok;
	t_lim lim_left;

	lim_left = lim;
	tok = NULL;
	while (lim.cnt < lim.lim && lim.cnt <= tokens->used &&\
 				(!tok || (!(tok->type == E_TOKEN_DLESS) &&\
				 !(tok->type == E_TOKEN_DGREAT))))
	{
		tok = (t_token *)array_get_at(tokens, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= tokens->used && tok && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		btree_insert_data(&ast, ast_new_cmd(tok->str, tok->len, tok->type), (int (*)(void*, void*))&ast_cmp);
		ast->left = ast_built4(ast->left, tokens, lim_left);
		ast->right = ast_built3(ast->right, tokens, lim);
	}
	else
		ast = ast_built4(ast, tokens, lim_left);
	return (ast);
}

t_btree	*ast_built2(t_btree *ast, t_array *tokens, t_lim lim)
{
	t_token	*tok;
	t_lim lim_left;

	lim_left = lim;
	tok = NULL;
	while (lim.cnt < lim.lim && lim.cnt <= tokens->used &&\
 				(!tok || !(tok->type == E_TOKEN_LESSGREAT)))
	{
		tok = (t_token *)array_get_at(tokens, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= tokens->used && tok && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		btree_insert_data(&ast, ast_new_cmd(tok->str, tok->len, tok->type), (int (*)(void*, void*))&ast_cmp);
		ast->left = ast_built3(ast->left, tokens, lim_left);
		ast->right = ast_built2(ast->right, tokens, lim);
	}
	else
		ast = ast_built3(ast, tokens, lim_left);
	return (ast);
}

t_btree	*ast_built1(t_btree *ast, t_array *tokens, t_lim lim)
{
	t_token	*tok;
	t_lim lim_left;

	lim_left = lim;
	tok = NULL;
	while (lim.cnt < lim.lim && lim.cnt <= tokens->used &&\
 				(!tok || !((tok->type == E_TOKEN_SEMI) ||\
 				(tok->type == E_TOKEN_AND_IF) || (tok->type == E_TOKEN_OR_IF))))
	{
		tok = (t_token *)array_get_at(tokens, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= tokens->used && tok && lim.cnt < lim.lim)
	{
		btree_insert_data(&ast, ast_new_cmd(tok->str, tok->len, tok->type), (int (*)(void*, void*))&ast_cmp);
		lim_left.lim = lim.cnt;
		ast->left = ast_built2(ast->left, tokens, lim_left);
		ast->right = ast_built1(ast->right, tokens, lim);
	}
	else
		ast = ast_built2(ast, tokens, lim_left);
	return (ast);
}
