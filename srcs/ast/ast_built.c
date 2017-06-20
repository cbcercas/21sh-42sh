/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/20 22:01:44 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ast/ast.h>

t_lim ast_built5_plus(t_array *tokens, t_lim lim, size_t *len)
{
		t_token	*tok;

		tok = NULL;
		while (lim.cnt <= lim.lim && lim.cnt <= tokens->used &&\
	 				(!tok || (tok->type == E_TOKEN_WORD) || (tok->type == E_TOKEN_BLANK)))
		{
			if (tok)
				*len = *len + tok->len;
			tok = (t_token *)array_get_at(tokens, lim.cnt);
			lim.cnt++;
		}
		lim.cnt--;
		return (lim);
}

t_btree	*ast_built5(t_btree *ast, t_array *tokens, t_lim lim)
{
	t_token	*tok;
	t_lim lim_left;
	size_t	len;

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
		len = tok->len;
		lim_left = ast_built5_plus(tokens, lim, &len);
		lim_left.lim = lim.cnt;
		btree_insert_data(&ast, ast_new_cmd(tok->str, len, tok->type), (int (*)(void*, void*))&ast_cmp);
//		ft_printf("4 cnt=%ld lim=%ld, str=|%s| len=%ld\n", lim_left.cnt, lim_left.lim, tok->str, len);
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
