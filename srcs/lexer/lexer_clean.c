/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 01:56:00 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/09 02:50:00 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

void	lexer_clean_tokens(t_array *tokens)
{
	size_t	cnt;
	t_token	*tok;

	cnt = 0;
	if (tokens == NULL)
		return;
	while ((tok = (t_token *)array_get_first(tokens)) && tok->type == E_TOKEN_BLANK)
		array_remove_at(tokens, 0, NULL);
	while (cnt < tokens->used)
	{
		tok = (t_token *)array_get_at(tokens, cnt);
		if (tok->type == E_TOKEN_BLANK && cnt + 1 < tokens->used)
		{
			tok = (t_token *)array_get_at(tokens, cnt + 1);
			if (tok->type == E_TOKEN_BLANK)
				array_remove_at(tokens, cnt, NULL);
			else
				cnt += 1;
		}
		else if (tok->type == E_TOKEN_BLANK && cnt + 1 == tokens->used)
			array_remove_at(tokens, cnt, NULL);
		else
			cnt += 1;
	}
}
