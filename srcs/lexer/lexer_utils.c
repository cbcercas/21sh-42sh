/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 01:56:00 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/09 02:50:00 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

/*
** @brief Checks if a given token type is a token type
**
** @param t The token type to check
**
** @return Returns true or false
*/

BOOL	is_token_type(t_token_type t)
{
	if (t > E_TOKEN_NONE && t < E_TOKEN_MAX)
		return (true);
	else
		return (false);
};