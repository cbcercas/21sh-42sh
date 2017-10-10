#include <parser/parser.h>
#include <lexer/lexer.h>
#include <types/bool.h>
#include <array/array.h>
#include <tools/tools.h>

extern uint32_t    grammar[224][6][4];

t_bool	is_grammar_type(t_grammar_type g)
{
	if (g > E_GRAM_NONE && g < E_GRAM_END)
		return (true);
	else
		return (false);
};

char *parser_gram_get_name(t_grammar_type gram)
{
	static char	*grammar[225] =
    {
            [E_TOKEN_NONE] = "E_TOKEN_NONE",
            [E_TOKEN_BLANK] = "E_TOKEN_BLANK",
            [E_TOKEN_NEWLINE] = "E_TOKEN_NEWLINE",
            [E_TOKEN_WORD] = "E_TOKEN_WORD",
            [E_TOKEN_SQUOTE] = "E_TOKEN_SQUOTE",
            [E_TOKEN_BQUOTE] = "E_TOKEN_BQUOTE",
            [E_TOKEN_DQUOTE] = "E_TOKEN_DQUOTE",
            [E_TOKEN_PIPE] = "E_TOKEN_PIPE",
            [E_TOKEN_LESSGREAT] = "E_TOKEN_LESSGREAT",
            [E_TOKEN_AND] = "E_TOKEN_AND",
            [E_TOKEN_SEMI] = "E_TOKEN_SEMI",
            [E_TOKEN_IO_NUMBER] = "E_TOKEN_IO_NUMBER",
            [E_TOKEN_DLESS] = "E_TOKEN_DLESS",
            [E_TOKEN_DGREAT] = "E_TOKEN_DGREAT",
            [E_TOKEN_OR_IF] = "E_TOKEN_OR_IF",
            [E_TOKEN_AND_IF] = "E_TOKEN_AND_IF",
            [E_TOKEN_LESSAND] = "E_TOKEN_LESSAND",
            [E_TOKEN_GREATAND] = "E_TOKEN_GREATAND",
            [E_TOKEN_MAX] = "E_TOKEN_MAX",
            [E_GRAM_NONE] = "E_GRAM_NONE",
            [E_GRAM_PROGRAM] = "E_GRAM_PROGRAM",
            [E_GRAM_COMPLETE_COMMANDS] = "E_GRAM_COMPLETE_COMMANDS",
            [E_GRAM_COMPLETE_COMMAND] = "E_GRAM_COMPLETE_COMMAND",
            [E_GRAM_LIST] = "E_GRAM_LIST",
            [E_GRAM_AND_OR] ="E_GRAM_AND_OR",
            [E_GRAM_PIPELINE] = "E_GRAM_PIPELINE,",
            [E_GRAM_PIPE_SEQUENCE] = "E_GRAM_PIPE_SEQUENCE",
            [E_GRAM_COMMAND] = "E_GRAM_COMMAND",
            [E_GRAM_SIMPLE_COMMAND] = "E_GRAM_SIMPLE_COMMAND",
            [E_GRAM_CMD_NAME] = "E_GRAM_CMD_NAME",
            [E_GRAM_CMD_WORD] = "E_GRAM_CMD_WORD",
            [E_GRAM_CMD_PREFIX] = "E_GRAM_CMD_PREFIX",
            [E_GRAM_CMD_SUFFIX] = "E_GRAM_CMD_SUFFIX",
            [E_GRAM_IO_REDIRECT] = "E_GRAM_IO_REDIRECT",
            [E_GRAM_IO_FILE] = "E_GRAM_IO_FILE",
            [E_GRAM_FILENAME] = "E_GRAM_FILENAME",
            [E_GRAM_IO_HERE] = "E_GRAM_IO_HERE",
            [E_GRAM_HERE_END] = "E_GRAM_END",
            [E_GRAM_NEWLINE_LIST] = "E_GRAM_NEWLINE_LIST",
            [E_GRAM_LINEBREAK] = "E_GRAM_LINEBREAK",
            [E_GRAM_SEPARATOR_OP] = "E_GRAM_SEPARATOR_OP",
            [E_GRAM_SEPARATOR] = "E_GRAM_SEPARATOR",
            [E_GRAM_SEQUENTIAL_SEP] = "E_GRAM_SEQUENTIAL_SEP",
            [E_GRAM_END] = "E_GRAM_END",
    };
	return (grammar[gram]);
};

enum e_parse_ret
{
    E_PARSE_RET_TRUE,
    E_PARSE_RET_FALSE,
    E_PARSE_RET_ERROR
};

enum e_parse_ret	parser_bt(t_array *tokens, size_t tok_num, 	t_grammar_type gram_cur, int parser_lvl)
{
	t_token	*tok_cur;
	uint32_t	g_list;
	uint32_t	g_final;
    enum e_parse_ret ret;

	tok_cur = (t_token *)array_get_at(tokens, tok_num);
	g_list = 0;
	g_final = 0;
    ft_printf("%d Parsing: tok_num : %d, tok_type: %s gram type : %s \n", parser_lvl, tok_num, parser_gram_get_name(tok_cur->type), parser_gram_get_name(gram_cur));
    if (tok_cur && grammar[gram_cur][g_list][g_final])
    {
        if (is_grammar_type(grammar[gram_cur][g_list][g_final]))
        {
            ret = parser_bt(tokens, tok_num, grammar[gram_cur][g_list][g_final], parser_lvl + 1);
            if (ret == E_PARSE_RET_TRUE)
                return (parser_bt(tokens, tok_num + 1, grammar[gram_cur][g_list][g_final + 1], parser_lvl + 1));
            else if (ret == E_PARSE_RET_FALSE)
                return(parser_bt(tokens, tok_num, grammar[gram_cur][g_list + 1][0], parser_lvl + 1));
            return (ret);
        }
        else
        {
            ft_printf("%d token : %s\n", parser_lvl, parser_gram_get_name(grammar[gram_cur][g_list][g_final]));
            if (grammar[gram_cur][g_list][g_final] == tok_cur->type)
                return (E_PARSE_RET_TRUE);
            else
                return (E_PARSE_RET_FALSE);
        }
    }
    else if (!tok_num && gram_cur)
    {
        ft_dprintf(2, "parse error near \"%s\" \n", ft_strsub_secu(tok_cur->str, 0, tok_cur->len, M_LVL_PARSER));
        return (E_PARSE_RET_ERROR);
    }
    return (E_PARSE_RET_TRUE);
}

t_bool parser_parse(t_array *tokens)
{
    enum e_parse_ret ret;

    ret = parser_bt(tokens, 0, E_GRAM_PROGRAM, 0);
    if (ret == E_PARSE_RET_TRUE)
    {
        ft_printf("Parser Ok/n");
        ft_secu_free_lvl(M_LVL_PARSER);
        return (true);
    }
    else
    {
        ft_printf("Parser Error/n");
        ft_secu_free_lvl(M_LVL_PARSER);
        return (false);
    }

}