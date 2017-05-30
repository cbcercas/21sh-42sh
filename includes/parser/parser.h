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
	E_GM_NONE = 200,
	E_PROGRAM = 201,
	E_COMPLETE_COMMANDS = 202,
	E_COMPLETE_COMMAND = 203,
	E_LIST = 204,
	E_AND_OR = 205,
	E_PIPELINE = 206,
	E_PIPE_SEQUENCE = 207,
	E_COMMAND = 208,
	E_SIMPLE_COMMAND = 209,
	E_CMD_NAME = 210,
	E_CMD_WORD = 211,
	E_CMD_PREFIX = 212,
	E_CMD_SUFFIX = 213,
	E_IO_REDIRECT = 214,
	E_IO_FILE = 215,
	E_FILENAME = 216,
	E_IO_HERE = 217,
	E_HERE_END = 218,
	E_NEWLINE_LIST = 219,
	E_LINEBREAK = 220,
	E_SEPARATOR_OP = 221,
	E_SEPARATOR = 222,
	E_SEQUENTIAL_SEP = 223,
	E_GM_END = 224
};

t_bool	parser_parse(t_array *tokens);

#endif
