/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_grammar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SSG <SSG@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:30:39 by SSG               #+#    #+#             */
/*   Updated: 2017/10/09 13:30:39 by SSG              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/enum.h>
#include <parser/parser.h>
#include <stdint.h>

uint32_t    grammar[224][6][4]=
{
	[E_GRAM_PROGRAM] =
	{
		{E_GRAM_LINEBREAK, E_GRAM_COMPLETE_COMMANDS, E_GRAM_LINEBREAK},
		{E_GRAM_LINEBREAK}
	},
	[E_GRAM_COMPLETE_COMMANDS] =
	{
		{E_GRAM_COMPLETE_COMMANDS, E_GRAM_NEWLINE_LIST, E_GRAM_COMPLETE_COMMAND},
		{E_GRAM_COMPLETE_COMMAND}
	},
	[E_GRAM_COMPLETE_COMMAND] =
	{
		{E_GRAM_LIST, E_GRAM_SEPARATOR_OP},
		{E_GRAM_LIST}
	},
	[E_GRAM_LIST] =
	{
		{E_GRAM_LIST, E_GRAM_SEPARATOR_OP, E_GRAM_AND_OR},
		{E_GRAM_AND_OR}
	},
	[E_GRAM_AND_OR] =
	{
		{E_GRAM_PIPELINE}
	},
	[E_GRAM_PIPELINE] =
	{
		{E_GRAM_PIPE_SEQUENCE}
	},
	[E_GRAM_PIPE_SEQUENCE] =
	{
		{E_GRAM_COMMAND},
		{E_GRAM_PIPE_SEQUENCE, E_TOKEN_PIPE, E_GRAM_LINEBREAK, E_GRAM_COMMAND}
	},
	[E_GRAM_COMMAND] =
	{
		{E_GRAM_SIMPLE_COMMAND}
	},
	[E_GRAM_SIMPLE_COMMAND] =
	{
		{E_GRAM_CMD_PREFIX, E_GRAM_CMD_WORD, E_GRAM_CMD_SUFFIX},
		{E_GRAM_CMD_PREFIX, E_GRAM_CMD_WORD},
		{E_GRAM_CMD_PREFIX},
		{E_GRAM_CMD_NAME, E_GRAM_CMD_SUFFIX},
		{E_GRAM_CMD_NAME}
	},
	[E_GRAM_CMD_NAME] =
	{
		{E_TOKEN_WORD}
	},
	[E_GRAM_CMD_WORD] =
	{
		{E_TOKEN_WORD}
	},
	[E_GRAM_CMD_PREFIX] =
	{
		{E_GRAM_IO_REDIRECT},
		{E_GRAM_CMD_PREFIX, E_GRAM_IO_REDIRECT}
	},
	[E_GRAM_CMD_SUFFIX] =
	{
		{E_GRAM_IO_REDIRECT},
		{E_GRAM_CMD_SUFFIX, E_GRAM_IO_REDIRECT},
		{E_TOKEN_WORD},
		{E_GRAM_CMD_SUFFIX, E_TOKEN_WORD}
	},
	[E_GRAM_IO_REDIRECT] =
	{
		{E_GRAM_IO_FILE},
		{E_TOKEN_IO_NUMBER, E_GRAM_IO_FILE},
		{E_GRAM_IO_HERE},
		{E_TOKEN_IO_NUMBER, E_GRAM_IO_HERE}
	},
	[E_GRAM_IO_FILE] =
	{
		{E_TOKEN_LESSGREAT, E_GRAM_FILENAME},
		{E_TOKEN_LESSAND, E_GRAM_FILENAME},
		{E_TOKEN_LESSGREAT, E_GRAM_FILENAME},
		{E_TOKEN_GREATAND, E_GRAM_FILENAME},
		{E_TOKEN_DGREAT, E_GRAM_FILENAME},
		{E_TOKEN_LESSGREAT, E_GRAM_FILENAME}
	},
	[E_GRAM_FILENAME] =
	{
		{E_TOKEN_WORD}
	},
	[E_GRAM_IO_HERE] =
	{
		{E_TOKEN_DLESS, E_GRAM_HERE_END}
	},
	[E_GRAM_HERE_END] =
	{
		{E_TOKEN_WORD}
	},
	[E_GRAM_NEWLINE_LIST] =
	{
		{E_TOKEN_NEWLINE},
		{E_GRAM_NEWLINE_LIST, E_TOKEN_NEWLINE}
	},
	[E_GRAM_LINEBREAK] =
	{
		{E_GRAM_NEWLINE_LIST}
	},
	[E_GRAM_SEPARATOR_OP] =
	{
		{E_TOKEN_SEMI}
	},
	[E_GRAM_SEPARATOR] =
	{
		{E_GRAM_SEPARATOR_OP, E_GRAM_LINEBREAK},
		{E_GRAM_COMPLETE_COMMANDS}
	},
	[E_GRAM_SEQUENTIAL_SEP] =
	{
		{E_TOKEN_SEMI, E_GRAM_LINEBREAK},
		{E_GRAM_COMPLETE_COMMANDS}
	}
};
