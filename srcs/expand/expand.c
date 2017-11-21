/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

/*
** @brief Expands a E_TOKEN_WORD/DQUOTE
**
** @param exp X to be expanded (TODO)
**
** @return Returns the expanded X
*/

t_exp		*expand_exp(t_exp *exp)
{
	if (exp->type == E_TOKEN_WORD || exp->type == E_TOKEN_DQUOTE)
	{
		expand_dol(exp->str);
		if (expand_hist(exp) == NULL)
		{
			ft_dprintf(2, "event not found\n");
			return (NULL);
		}
	}
	return (exp);
}

/*
** @brief Main expand function.
**
** @param tokens t_array contaning the tokens used by the expand to expand
** @param expand The t_array used to store the expanded tokens/str
**
** @return Returns a E_RET_EXPAND_OK If the expand is successful
*/

t_return	expand(t_array *tokens, t_array *expand)
{
	t_exp	*exp;
	size_t	i;

	i = 0;
	if (tokens->used == 0)
		return (E_RET_EXPAND_ERROR);
	while (i < tokens->used)
	{
		if (!(exp = exp_create_new((t_token *)array_get_at(tokens, i))))
			return (E_RET_EXPAND_ERROR);
		if (!expand_exp(exp))
			return (E_RET_EXPAND_ERROR);
		expand_remove_quote(exp);
		array_push(expand, (void *)exp);
		i++;
	}
	expand_merge_tokens_word(expand);
	return (E_RET_EXPAND_OK);
}
