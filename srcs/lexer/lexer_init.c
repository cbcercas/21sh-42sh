/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 09:44:00 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/24 09:44:00 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>
#include <lexer/lexer.h>
#include <logger.h>
#include <ftprintf.h>

t_array	*lexer_init(t_array *tokens)
{
	tokens = array_init(tokens, sizeof(t_token));
	if (tokens)
	{
		log_info("Lexer: Initialization done");
		return (tokens);
	}
	log_fatal("Lexer: Initialization failed");
	ft_dprintf(2, "Lexer: Initialization failed");
	return (NULL);
}