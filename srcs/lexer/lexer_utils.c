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

BOOL	is_token_type(t_token_type t)
{
	if (t > E_TOKEN_NONE && t < E_TOKEN_MAX)
		return (true);
	else
		return (false);
};