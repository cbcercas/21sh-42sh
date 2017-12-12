/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_built_wr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiforge <guiforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:25:14 by guiforge          #+#    #+#             */
/*   Updated: 2017/11/23 16:25:17 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

/*
** @brief ast_search2 Searches for the next token with priority
**
** @param expands Contains the expanded user input
** @param lim Contains the virtual limits used by the AST.
** @param prio Priority for tokens:\n
** 1 = ";" or "||" or "&&",\n
** 2 = "|",\n
** 3 = redirections,\n
** 4 = "&".
**
** @return Returns a t_exp on success, or it will return NULL.
*/

static t_exp			*ast_search2(t_array *expands, t_lim *lim, int prio)
{
	t_exp		*exp;

	exp = NULL;
	log_dbg1("AST: SEARCH2 cnt: %d lim: %d", lim->cnt, lim->lim);
	while (lim->cnt < lim->lim && lim->cnt <= (ssize_t)expands->used)
	{
		lim->cnt++;
		if (lim->cnt < (ssize_t)expands->used)
			exp = (t_exp *)array_get_at(expands, (size_t)lim->cnt);
		if (exp && ast_associate_prio(exp->type, prio, lim->cnt, expands))
			break ;
	}
	if (exp && exp->str)
		log_dbg1("AST: SEARCH: find: cnt(%d)(%s)", lim->cnt, exp->str->s);
	if (exp && !(ast_associate_prio(exp->type, prio, lim->cnt, expands)))
		return (NULL);
	return (exp);
}

/*
** @brief This function will count the number of tokens in given redirection
** Example:
**
** `>` = one token\n
** `2>` = two tokens,\n
** `2> file` = tree tokens.
**
** @param expands Contains the expanded user input
** @param lim Contains the virtual limits used by the AST
**
** @return Returns a `lim` struct containing the number of tokens in a redir.
*/

static t_lim			ast_built_redir_plus(t_array *expands, t_lim lim)
{
	t_exp	*exp;

	exp = NULL;
	if (!expands)
		return (lim);
	while (lim.cnt <= lim.lim && lim.cnt <= (ssize_t)expands->used &&\
			(!exp || ast_is_redir(expands, lim.cnt, exp->type)))
	{
		lim.cnt++;
		exp = (t_exp *)array_get_at(expands, (size_t)lim.cnt);
		if (exp->type == E_TOKEN_WORD || exp->type == E_TOKEN_IO_NUMBER)
		{
			lim.cnt++;
			break ;
		}
	}
	return (lim);
}

/*
** @brief This function counts the number or `word` token in a given command.
** Example:
**
** `ls` = one token,\n
** `ls -l` = two tokens,\n
** `ls -l /foo/bar` = tree tokens.
**
** @param expands Contains the expanded user input
** @param lim Contains virtual limits used by the AST
**
** @return Returns a `lim` struct, containing the number of tokens in a
** `word` command.
*/

static t_lim			ast_built_word_plus(t_array *expands, t_lim lim)
{
	t_exp	*exp;

	exp = NULL;
	while (lim.cnt <= lim.lim && lim.cnt <= (ssize_t)expands->used &&\
			(!exp || (!is_sepa(exp->type) && exp->type != E_TOKEN_NEWLINE)))
	{
		exp = (t_exp *)array_get_at(expands, (size_t)lim.cnt);
		lim.cnt++;
	}
	if (lim.cnt > lim.lim && lim.cnt <= (ssize_t)expands->used)
		lim.cnt--;
	if (lim.cnt >= (ssize_t)expands->used)
		lim.cnt--;
	return (lim);
}

/*
** @brief ast_built2 Builds the ast recursively for words and redirections
**
** @param ast Contains the abstract syntax tree
** @param expands Contains the expanded user input
** @param lim Contains virtual limits for the AST
** @param prio Priority for tokens:\n
** 1 = ";" or "||" or "&&",\n
** 2 = "|",\n
** 3 = redirections,\n
** 4 = "&".
**
** @return Returns the ast in a `btree` form
*/

t_btree					*ast_built2(t_btree **ast, t_array *expands,
									t_lim lim, int prio)
{
	t_exp	*exp;
	t_lim	lim_left;

	lim_left = lim;
	log_dbg1("AST: BUILT2-START prio:%d cnt:%d lim:%d", prio, lim.cnt, lim.lim);
	exp = ast_search2(expands, &lim, prio);
	if (lim.cnt <= (ssize_t)expands->used && exp && lim.cnt <= lim.lim)
	{
		lim_left.lim = lim.cnt;
		lim = (prio == 3 ? ast_built_redir_plus(expands, lim) : lim);
		lim = (prio == 4 ? ast_built_word_plus(expands, lim) : lim);
		btree_insert_data(ast, ast_new_cmd(expands, lim_left.lim, lim.cnt,\
					return_type(prio, exp->type, expands, lim_left.lim)), \
				(int (*)(void*, void*))&ast_cmp);
		if (lim.cnt < lim.lim && lim.cnt <= (ssize_t)expands->used)
			(*ast)->left = ast_built2(&(*ast)->left, expands, lim, prio);
	}
	log_dbg1("AST: BUILT2-END prio:%d cnt:%d lim:%d", prio, lim.cnt, lim.lim);
	return (*ast);
}
