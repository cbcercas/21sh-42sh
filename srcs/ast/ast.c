/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:47:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/19 16:26:35 by gpouyat          ###   ########.fr       */
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
	if (type == E_TOKEN_WORD)
		return (6);
	return (7);
}

int	ast_cmp(t_cmd *s1, t_cmd *s2)
{
	if (ast_val_cmp(s1->type) <= ast_val_cmp(s2->type))
		return (1);
	return (0);
	//return (ast_val_cmp(s2->type) - ast_val_cmp(s1->type));
}

char *ast_aff(t_cmd *cmd)
{
	return ((char *)cmd->str);
}

t_cmd	*ast_new_cmd(const char *str, size_t len, t_token_type type)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		return (NULL);
	cmd->type = type;
	cmd->str = ft_strsub(str, 0, len);
	return (cmd);
}

t_token		*tok_sch_type(t_array *tokens, t_token_type type)
{
	t_token	*tok;
	size_t	cnt;

	cnt = 0;
	while (cnt < tokens->used && !(tok->type == type))
	{
		tok = (t_token *)array_get_at(tokens, cnt);
		cnt++;
	}
	if (cnt < tokens->used)
		return (tok);
	return (NULL);
}

t_btree	*ast_built(t_btree *ast, t_array *tokens, size_t cnt, size_t lim)
{
	t_token	*tok;
	size_t	cnt_left;

	cnt_left = cnt;
	tok = NULL;
	ft_printf("cnt=%ld, lim=%ld\n", cnt, lim);
	while (cnt < lim && cnt < tokens->used &&\
 				(!tok || !((tok->type == E_TOKEN_SEMI) ||\
 				(tok->type == E_TOKEN_AND_IF) || (tok->type == E_TOKEN_OR_IF))))
	{
		tok = (t_token *)array_get_at(tokens, cnt);
		cnt++;
	}
	if (cnt < tokens->used && tok && cnt < lim)
	{
		btree_insert_data(&ast, ast_new_cmd(tok->str, tok->len, tok->type), (int (*)(void*, void*))&ast_cmp);
		ast->right = ast_built(ast->right, tokens, cnt, lim);
		//ast->left = ast_built(ast->left, tokens, cnt_left, cnt);
	}
	/*cnt = cnt_left;
	while (cnt < lim && cnt < tokens->used && (tok->type == E_TOKEN_LESSGREAT))
	{
		tok = (t_token *)array_get_at(tokens, cnt);
		cnt++;
	}
	if (cnt < tokens->used && tok && cnt < lim)
	{
		btree_insert_data(&ast, ast_new_cmd(tok->str, tok->len, tok->type), (int (*)(void*, void*))&ast_cmp);
		//ast->right = ast_built(ast->right, tokens, cnt, lim);
		//ast->left = ast_built(ast->left, tokens, cnt_left, cnt);
	}*/
//	else
	//	return (NULL);
//	else
//	{
//		cnt = 0;

	//}
	return (ast);
}
