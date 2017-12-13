/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

/*
** @brief Inserts a string contained in `tm2` before `tmp1`
** @param tmp1 t_string to instert into
** @param tmp2 t_string to insert
** @param array_exp t_array of token
** @param i index of tmp2
*/

void	expand_merge_now(t_exp *tmp1, t_exp *tmp2, t_array *array_exp,
																	size_t *i)
{
	tmp1->str->len = ft_strlen(tmp1->str->s);
	tmp2->str->len = ft_strlen(tmp2->str->s);
	string_insert_back(tmp1->str, tmp2->str->s);
	string_del(&tmp2->str);
	array_remove_at(array_exp, *i + 1, NULL);
	*i = 0;
}

/*
** @brief Merges 2 WORD tokens togethers
** @param array_exp array of token
*/

void	expand_merge_tokens_word(t_array *array_exp)
{
	t_exp	*tmp1;
	t_exp	*tmp2;
	size_t	i;

	i = 0;
	while (array_exp && (i + 1 < array_exp->used))
	{
		tmp1 = (t_exp *)array_get_at(array_exp, i);
		if (tmp1->type == E_TOKEN_WORD)
		{
			tmp2 = (t_exp *)array_get_at(array_exp, i + 1);
			if (tmp2->type == E_TOKEN_WORD)
				expand_merge_now(tmp1, tmp2, array_exp, &i);
			else
				i++;
		}
		else
			i++;
	}
}
