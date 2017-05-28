#include <parser/parser.h>
#include <stdint.h>

uint32_t	grammar[230][6][4]=
{
	[PROGRAM] =
		{
			{LINEBREAK, COMPLETE_COMMANDS, LINEBREAK},
			{LINEBREAK}
		},
	[COMPLETE_COMMANDS] =
		{
			{COMPLETE_COMMANDS, NEWLINE_LIST, COMPLETE_COMMAND},
			{COMPLETE_COMMAND}
		},
	[COMPLETE_COMMAND] =
		{
			{LIST, SEPARATOR_OP},
			{LIST}
		},
	[LIST] =
		{
			{LIST, SEPARATOR_OP, AND_OR},
			{AND_OR}
		},
	[AND_OR] =
		{
			{PIPELINE}
		},
	[PIPELINE] =
		{
			{PIPE_SEQUENCE}
		},
	[PIPE_SEQUENCE] =
		{
			{COMMAND},
			{PIPE_SEQUENCE, '|', LINEBREAK, COMMAND}
		},
	[COMMAND] =
		{
			{SIMPLE_COMMAND}
		},
	[SIMPLE_COMMAND] =
		{
			{CMD_PREFIX, CMD_WORD, CMD_SUFFIX},
			{CMD_PREFIX, CMD_WORD},
			{CMD_PREFIX},
			{CMD_NAME, CMD_SUFFIX},
			{CMD_NAME}
		},
	[CMD_NAME] =
		{
			{E_TOKEN_WORD}
		},
	[CMD_WORD] =
		{
			{E_TOKEN_WORD}
		},
	[CMD_PREFIX] =
		{
			{IO_REDIRECT},
			{CMD_PREFIX, IO_REDIRECT}
		},
	[CMD_SUFFIX] =
		{
			{IO_REDIRECT},
			{CMD_SUFFIX, IO_REDIRECT},
			{E_TOKEN_WORD},
			{CMD_SUFFIX, E_TOKEN_WORD}
		},
	[IO_REDIRECT] =
		{
			{IO_FILE},
			{E_TOKEN_IO_NUMBER, IO_FILE},
			{IO_HERE},
			{E_TOKEN_IO_NUMBER, IO_HERE}
		},
	[IO_FILE] =
		{
			{'<', FILENAME},
			{E_TOKEN_LESSAND, FILENAME},
			{'>', FILENAME},
			{E_TOKEN_GREATAND, FILENAME},
			{E_TOKEN_DGREAT, FILENAME},
			{E_TOKEN_LESSGREAT, FILENAME}
		},
	[FILENAME] =
		{
			{E_TOKEN_WORD}
		},
	[IO_HERE] =
		{
			{E_TOKEN_DLESS, HERE_END}
		},
	[HERE_END] =
		{
			{E_TOKEN_WORD}
		},
	[NEWLINE_LIST] =
		{
			{E_TOKEN_NEWLINE},
			{NEWLINE_LIST, E_TOKEN_NEWLINE}
		},
	[LINEBREAK] =
		{
			{NEWLINE_LIST}
//			[] TODO nead "| /* empty */"
		},
	[SEPARATOR_OP] =
		{
			{';'}
		},
	[SEPARATOR] =
		{
			{SEPARATOR_OP, LINEBREAK},
			{NEWLINE_LIST}
		},
	[SEQUENTIAL_SEP] =
		{
			{';', LINEBREAK},
			{NEWLINE_LIST}
		}
};