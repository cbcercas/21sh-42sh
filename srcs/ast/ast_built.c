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
** @brief Counts number of tokens in a redirection.
**
** ">" = one token\n
** "2>" = two tokens,\n
** "2> file" = tree tokens.
**
** @param expands Contains the token arrays
** @param lim Contains the count of tokens in a given redirection
**
** @return Returns struct lim, containing number of tokens in given redirection
*/

static t_lim			ast_built_redir_plus(t_array *expands, t_lim lim)
{
	t_exp	*exp;

	exp = NULL;
	if (!expands)
		return (lim);
	while (lim.cnt <= lim.lim && lim.cnt <= expands->used &&\
			(!exp || ast_is_redir(expands, lim.cnt - 1, exp->type)))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
		if (exp->type == E_TOKEN_WORD)
		{
			lim.cnt++;
			break ;
		}
	}
	lim.cnt--;
	return (lim);
}

/*
** @brief Counts number of tokens in a given 'word' command
**
** "ls" = one token,
**
** "ls -l" = two tokens,
**
** "ls -l /foo/bar" = tree tokens.
**
** @param expands Contains the token array
** @param lim Contains count of tokens
**
** @return Returns struct lim, containing number of tokens in a 'word' command.
*/

static t_lim			ast_built_word_plus(t_array *expands, t_lim lim)
{
	t_exp	*exp;

	exp = NULL;
	while (lim.cnt <= lim.lim && lim.cnt <= expands->used &&\
			(!exp || (!is_sepa(exp->type) && exp->type != E_TOKEN_NEWLINE)))
	{
		exp = (t_exp *)array_get_at(expands, lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt > lim.lim && lim.cnt <= expands->used)
		lim.cnt--;
	lim.cnt--;
	return (lim);
}

/*
** @brief ast_built2 Does the same as ast_built but doesnt push in the ast.
**
** @param ast Contains the abstract syntax tree
** @param expands Contains the token array
** @param lim Contains virtual limit and start pos
** @param prio Priority for tokens
**
** 1 = ";" or "||" or "&&",\n
**
** 2 = "|",\n
**
** 3 = redirections,\n
**
** 4 = "&".
**
** @return Returns the Abstract Syntax Tree
*/

static t_btree			*ast_built2(t_btree **ast, t_array *expands,
						t_lim lim, int prio)
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
		btree_insert_data(ast, ast_new_cmd(expands, lim_left.lim - 1, lim.cnt,\
					return_type(prio, exp->type, expands, lim_left.lim)), \
				(int (*)(void*, void*))&ast_cmp);
		(*ast)->left = ast_built2(&(*ast)->left, expands, lim, prio);
	}
	return (*ast);
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
	t_lim	lim_left;

	lim_left = lim;
	exp = NULL;
	if (prio != 5 && prio != 3)
		exp = ast_search(expands, &lim, prio);
	else
		*ast = ast_built2(ast, expands, lim_left, prio);
	if (lim.cnt <= expands->used && exp && lim.cnt < lim.lim)
	{
		lim_left.lim = lim.cnt;
		btree_insert_data(ast, ast_new_cmd(expands, lim_left.lim - 1, lim.cnt,\
					return_type(prio, exp->type, expands, lim_left.lim)), \
				(int (*)(void*, void*))&ast_cmp);
		if (prio != 5 && prio != 3)
			(*ast)->left = ast_built(&(*ast)->left, expands,
									lim_left, prio + 1);
		if (prio != 5 && prio != 3)
			(*ast)->right = ast_built(&(*ast)->right, expands, lim, prio);
	}
	else if (prio != 5)
		*ast = ast_built(ast, expands, lim_left, prio + 1);
	return (*ast);
}
