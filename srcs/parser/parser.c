/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:43:16 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/20 10:41:34 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

/*
** @brief Initializes the parser for the program
**
** @param tokens  The tokens sent by the lexer
** @param input   The input the user sent
** @return Returns nothing for now
**/

void	parser_init(t_array *tokens, char *input)
{
	ft_printf("User input: %s\n", input);
}
