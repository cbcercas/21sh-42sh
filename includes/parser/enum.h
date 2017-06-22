/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SSG <SSG@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 21:18:12 by SSG               #+#    #+#             */
/*   Updated: 2017/06/22 21:18:12 by SSG              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

# include <inttypes.h>

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

#endif
