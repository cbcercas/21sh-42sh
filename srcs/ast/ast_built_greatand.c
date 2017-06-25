/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_built_greatand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 18:20:34 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/25 18:23:18 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

BOOL	ast_is_redir(t_array *tokens, size_t cnt, t_token *cur)
{
	t_token *tok;

	if (cur && cur->type == E_TOKEN_GREATAND)
		return (true);
	if (!cur || (cur->type != E_TOKEN_IO_NUMBER && cur->type != E_TOKEN_WORD &&\
		cur->type != E_TOKEN_BLANK && cur->type != E_TOKEN_DQUOTE &&\
		cur->type != E_TOKEN_SQUOTE))
		return (false);
	tok = NULL;
	tok = (t_token *)array_get_at(tokens, cnt + 1);
	if (tok && tok->type == E_TOKEN_GREATAND)
		return (true);
	tok = (t_token *)array_get_at(tokens, cnt - 1);
	if (tok && tok->type == E_TOKEN_GREATAND)
		return (true);
	while (tok && tok->type == E_TOKEN_BLANK)
	{
		cnt--;
		tok = (t_token *)array_get_at(tokens, cnt - 1);
		if (tok && tok->type == E_TOKEN_GREATAND)
			return (true);
	}
	return (false);
}

t_lim ast_built_greatand_plus(t_array *tokens, t_lim lim, size_t *len)
{
		t_token	*tok;

		tok = NULL;
		while (lim.cnt <= lim.lim && lim.cnt <= tokens->used &&\
			(!tok || ast_is_redir(tokens, lim.cnt - 1, tok)))
		{
			if (tok)
				*len = *len + tok->len;
			tok = (t_token *)array_get_at(tokens, lim.cnt);
			lim.cnt++;
		}
		lim.cnt--;
		return (lim);
}

t_btree	*ast_built_greatand(t_btree *ast, t_array *tokens, t_lim lim)
{
	t_token	*tok;
	t_lim lim_left;
	size_t	len;

	lim_left = lim;
	tok = NULL;
	while (lim.cnt < lim.lim && lim.cnt <= tokens->used &&\
 				(!tok || !(ast_is_redir(tokens, lim.cnt - 1, tok))))
	{
		tok = (t_token *)array_get_at(tokens, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt <= tokens->used && tok && lim.cnt < lim.lim)
	{
		len = tok->len;
		lim_left.lim = lim.cnt;
		lim = ast_built_greatand_plus(tokens, lim, &len);
		btree_insert_data(&ast, ast_new_cmd(tok->str, len, tok->type), (int (*)(void*, void*))&ast_cmp);
		ast->left = ast_built6(ast->left, tokens, lim_left);
		ast->right = ast_built_greatand(ast->right, tokens, lim);
	}
	else
		ast = ast_built6(ast, tokens, lim_left);
	return (ast);
}
