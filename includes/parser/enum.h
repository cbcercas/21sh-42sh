/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SSG <SSG@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:52:55 by SSG               #+#    #+#             */
/*   Updated: 2017/10/11 15:52:55 by SSG              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H
# include <stdint.h>

typedef uint32_t	t_token_type;

enum	e_token_type
{
	E_TOKEN_NONE,
	E_TOKEN_BLANK,
	E_TOKEN_NEWLINE,
	E_TOKEN_WORD,
	E_TOKEN_SQUOTE,
	E_TOKEN_BQUOTE,
	E_TOKEN_DQUOTE,
	E_TOKEN_PIPE,
	E_TOKEN_LESSGREAT,
	E_TOKEN_AND,
	E_TOKEN_SEMI,
	E_TOKEN_IO_NUMBER,
	E_TOKEN_DLESS,
	E_TOKEN_DGREAT,
	E_TOKEN_OR_IF,
	E_TOKEN_AND_IF,
	E_TOKEN_LESSAND,
	E_TOKEN_GREATAND,
	E_TOKEN_MAX
};

typedef	uint32_t	t_grammar_type;

enum	e_grammar_type
{
	E_GRAM_NONE = 200,
	E_GRAM_PROGRAM = 201,
	E_GRAM_COMPLETE_COMMANDS = 202,
	E_GRAM_COMPLETE_COMMAND = 203,
	E_GRAM_LIST = 204,
	E_GRAM_AND_OR = 205,
	E_GRAM_PIPELINE = 206,
	E_GRAM_PIPE_SEQUENCE = 207,
	E_GRAM_COMMAND = 208,
	E_GRAM_SIMPLE_COMMAND = 209,
	E_GRAM_CMD_NAME = 210,
	E_GRAM_CMD_WORD = 211,
	E_GRAM_CMD_PREFIX = 212,
	E_GRAM_CMD_SUFFIX = 213,
	E_GRAM_IO_REDIRECT = 214,
	E_GRAM_IO_FILE = 215,
	E_GRAM_FILENAME = 216,
	E_GRAM_IO_HERE = 217,
	E_GRAM_HERE_END = 218,
	E_GRAM_NEWLINE_LIST = 219,
	E_GRAM_LINEBREAK = 220,
	E_GRAM_SEPARATOR_OP = 221,
	E_GRAM_SEPARATOR = 222,
	E_GRAM_SEQUENTIAL_SEP = 223,
	E_GRAM_EMPTY = 224,
	E_GRAM_END = 225
};

#endif
