/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 10:02:17 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/21 10:22:54 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <lexer/lexer.h>
# include <parser/parser_grammar.h>
# include <stdint.h>

typedef	uint32_t t_grammar_type;

enum e_grammar_type
{
	PROGRAM = 200,
	COMPLETE_COMMANDS = 201,
	COMPLETE_COMMAND = 202,
	LIST = 203,
	AND_OR = 204,
	PIPELINE = 205,
	PIPE_SEQUENCE = 206,
	COMMAND = 207,
	SIMPLE_COMMAND = 208,
	CMD_NAME = 209,
	CMD_WORD = 210,
	CMD_PREFIX = 211,
	CMD_SUFFIX = 212,
	IO_REDIRECT = 213,
	IO_FILE = 214,
	FILENAME = 215,
	IO_HERE = 216,
	HERE_END = 217,
	NEWLINE_LIST = 218,
	LINEBREAK = 219,
	SEPARATOR_OP = 220,
	SEPARATOR = 221,
	SEQUENTIAL_SEP =222
};

t_bool	parser_parse(t_array *tokens);

#endif
