/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_grammar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SSG <SSG@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:15:33 by SSG               #+#    #+#             */
/*   Updated: 2017/06/12 15:15:33 by SSG              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/enum.h>
#include <parser/parser.h>
#include <stdint.h>

uint32_t    grammar[224][6][4]=
{
	[E_PROGRAM] =
	{
		{E_LINEBREAK, E_COMPLETE_COMMANDS, E_LINEBREAK},
		{E_LINEBREAK}
	},
	[E_COMPLETE_COMMANDS] =
	{
		{E_COMPLETE_COMMANDS, E_NEWLINE_LIST, E_COMPLETE_COMMAND},
		{E_COMPLETE_COMMAND}
	},
	[E_COMPLETE_COMMAND] =
	{
		{E_LIST, E_SEPARATOR_OP},
		{E_LIST}
	},
	[E_LIST] =
	{
		{E_LIST, E_SEPARATOR_OP, E_AND_OR},
		{E_AND_OR}
	},
	[E_AND_OR] =
	{
		{E_PIPELINE}
	},
	[E_PIPELINE] =
	{
		{E_PIPE_SEQUENCE}
	},
	[E_PIPE_SEQUENCE] =
	{
		{E_COMMAND},
		{E_PIPE_SEQUENCE, '|', E_LINEBREAK, E_COMMAND}
	},
	[E_COMMAND] =
	{
		{E_SIMPLE_COMMAND}
	},
	[E_SIMPLE_COMMAND] =
	{
		{E_CMD_PREFIX, E_CMD_WORD, E_CMD_SUFFIX},
		{E_CMD_PREFIX, E_CMD_WORD},
		{E_CMD_PREFIX},
		{E_CMD_NAME, E_CMD_SUFFIX},
		{E_CMD_NAME}
	},
	[E_CMD_NAME] =
	{
		{E_TOKEN_WORD}
	},
	[E_CMD_WORD] =
	{
		{E_TOKEN_WORD}
	},
	[E_CMD_PREFIX] =
	{
		{E_IO_REDIRECT},
		{E_CMD_PREFIX, E_IO_REDIRECT}
	},
	[E_CMD_SUFFIX] =
	{
		{E_IO_REDIRECT},
		{E_CMD_SUFFIX, E_IO_REDIRECT},
		{E_TOKEN_WORD},
		{E_CMD_SUFFIX, E_TOKEN_WORD}
	},
	[E_IO_REDIRECT] =
	{
		{E_IO_FILE},
		{E_TOKEN_IO_NUMBER, E_IO_FILE},
		{E_IO_HERE},
		{E_TOKEN_IO_NUMBER, E_IO_HERE}
	},
	[E_IO_FILE] =
	{
		{'<', E_FILENAME},
		{E_TOKEN_LESSAND, E_FILENAME},
		{'>', E_FILENAME},
		{E_TOKEN_GREATAND, E_FILENAME},
		{E_TOKEN_DGREAT, E_FILENAME},
		{E_TOKEN_LESSGREAT, E_FILENAME}
	},
	[E_FILENAME] =
	{
		{E_TOKEN_WORD}
	},
	[E_IO_HERE] =
	{
		{E_TOKEN_DLESS, E_HERE_END}
	},
	[E_HERE_END] =
	{
		{E_TOKEN_WORD}
	},
	[E_NEWLINE_LIST] =
	{
		{E_TOKEN_NEWLINE},
		{E_NEWLINE_LIST, E_TOKEN_NEWLINE}
	},
	[E_LINEBREAK] =
	{
		{E_NEWLINE_LIST}
	},
	[E_SEPARATOR_OP] =
	{
		{';'}
	},
	[E_SEPARATOR] =
	{
		{E_SEPARATOR_OP, E_LINEBREAK},
		{E_COMPLETE_COMMANDS}
	},
	[E_SEQUENTIAL_SEP] =
	{
		{';', E_LINEBREAK},
		{E_COMPLETE_COMMANDS}
	}
};
