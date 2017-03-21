/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 10:02:17 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/20 10:32:58 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <lexer/lexer.h>

/*
** @file parser.c
**
** @brief initialize the parser
*/

enum e_grammar_sym
{
	complete_command = 100,
	list,
	separator_op,
	separator,
	and_or,
	pipeline,
	linebreak,
	pipe_sequence,
	newline_list
}

void	parser_init(t_array *tokens, char *input);

#endif
