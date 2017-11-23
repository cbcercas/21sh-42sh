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

t_exp			*ast_search2(t_array *expands, t_lim *lim, int prio)
{
	t_exp		*exp;

	exp = NULL;
	//ft_printf("SEARCH: cnt: %d lim: %d\n", lim->cnt, lim->lim);
	while (lim->cnt < lim->lim && lim->cnt <= (ssize_t)expands->used)
	{
		lim->cnt++;
		//ft_printf("SEARCH: loop cnt: %d/%d\n", lim->cnt, expands->used);
		if (lim->cnt < (ssize_t)expands->used)
			exp = (t_exp *)array_get_at(expands, (size_t)lim->cnt);
		if (exp && ast_prio(exp->type, prio, lim->cnt, expands))
			break ;
	}
	//if (exp && exp->str)
		//ft_printf("SEARCH: find = (%d)(%s)\n", lim->cnt, exp->str->s);
	if (exp && !(ast_prio(exp->type, prio, lim->cnt, expands)))
		return (NULL);
	return (exp);
}

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
	//ft_printf("REDIR +: cnt: %d lim: %d\n", lim.cnt, lim.lim);
	while (lim.cnt <= lim.lim && lim.cnt <= (ssize_t)expands->used &&\
			(!exp || ast_is_redir(expands, lim.cnt, exp->type)))
	{
		//ft_printf("LOOP cnt: %d lim: %d\n", lim.cnt, lim.lim);
		lim.cnt++;
		exp = (t_exp *)array_get_at(expands, (size_t)lim.cnt);
		if (exp->type == E_TOKEN_WORD)
		{
			lim.cnt++;
			break ;
		}
		//ft_printf("LOOP IS REDIR: cnt = (%d) [%d]\n", lim.cnt, ast_is_redir(expands, lim.cnt, exp->type));
	}
	//lim.cnt--;
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
	//ft_printf("WORD: cnt = (%d) lim = (%d)\n", lim.cnt, lim.lim );
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

t_btree			*ast_built2(t_btree **ast, t_array *expands,
									  t_lim lim, int prio)
{
	t_exp	*exp;
	t_lim	lim_left;

	lim_left = lim;
	exp = NULL;
	//ft_printf("\nBUILT: prio = (%d) cnt = (%d) lim = (%d)\n", prio, lim.cnt, lim.lim);
	exp = ast_search2(expands, &lim, prio);
	//ft_printf("BUILT: CONDI (%d) cnt = (%d) lim = (%d)\n", (lim.cnt <= (ssize_t)expands->used && exp && lim.cnt <= lim.lim), lim.cnt, lim.lim );
	if (lim.cnt <= (ssize_t)expands->used && exp && lim.cnt <= lim.lim)
	{
		lim_left.lim = lim.cnt;
		lim = (prio == 3 ? ast_built_redir_plus(expands, lim) : lim);
		lim = (prio == 4 ? ast_built_word_plus(expands, lim) : lim);
		//ft_printf("LIM: cnt = (%d), lim = (%d)| cnt_lef (%d) lim_left (%d)\n", lim.cnt, lim.lim, lim_left.cnt, lim_left.lim);
		//ft_printf("CREATE: start (%d), end (%d)\n",  lim_left.lim, lim.cnt);
		btree_insert_data(ast, ast_new_cmd(expands, lim_left.lim, lim.cnt,\
					return_type(prio, exp->type, expands, lim_left.lim)), \
				(int (*)(void*, void*))&ast_cmp);
		//getchar();
		if (lim.cnt < lim.lim && lim.cnt <= (ssize_t)expands->used)
			(*ast)->left = ast_built2(&(*ast)->left, expands, lim, prio);
	}
	//ft_printf("***********RET\n");
	return (*ast);
}