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
	static char	*grammar[226] =
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
			[E_GRAM_EMPTY] = "E_GRAM_EMPTY",
			[E_GRAM_END] = "E_GRAM_END"
    };
	return (grammar[gram]);
};

enum e_parse_ret
{
    E_PARSE_RET_TRUE,
    E_PARSE_RET_FALSE,
	E_PARSE_RET_END,
    E_PARSE_RET_ERROR
};

#include <stdio.h>
enum e_parse_ret	parser_bt(t_array *tokens, size_t tok_num, t_grammar_type gram_cur, uint32_t g_list, uint32_t g_final, int parser_lvl)
{
	t_token	*tok_cur;
    enum e_parse_ret ret;

	tok_cur = (t_token *)array_get_at(tokens, tok_num);
    printf("%d%*sParsing: tok_num : %zu, tok_type: %s gram type : %s \n", parser_lvl, parser_lvl, " ", tok_num, parser_gram_get_name(tok_cur->type), parser_gram_get_name(gram_cur));
    if (tok_cur->type != 0 && gram_cur != 0)
    {
        if (is_grammar_type(gram_cur))
        {
			//printf("%*s parser_bt(tokens, %d, grammar[%s][%d][%s], %d + 1);", " ", tok_num, parser_gram_get_name(gram_cur), g_list, parser_gram_get_name())
            ret = parser_bt(tokens, tok_num, grammar[gram_cur][g_list][g_final], 0, g_final, parser_lvl + 1);
            if (ret == E_PARSE_RET_TRUE)
                return (parser_bt(tokens, tok_num + 1, gram_cur, 0, g_final + 1, parser_lvl + 1));
            else if (ret == E_PARSE_RET_FALSE)
                return(parser_bt(tokens, tok_num, gram_cur, g_list + 1, 0, parser_lvl + 1)); // <--
			else if (ret == E_PARSE_RET_END)
				return (E_PARSE_RET_FALSE);
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
    else if (tok_cur->type == E_TOKEN_NONE && gram_cur != 0)
    {
        ft_dprintf(2, "parse error near \"%s\" \n", ft_strsub_secu(tok_cur->str, 0, tok_cur->len, M_LVL_PARSER));
        return (E_PARSE_RET_ERROR);
    }
    else if (gram_cur == 0)
        return (E_PARSE_RET_END);
    return (E_PARSE_RET_TRUE);
}

enum e_parse_ret parser_test(t_array *tokens, size_t tok_num, t_grammar_type gram_cur, uint32_t glist, uint32_t gfinal, int parser_lvl)
{
	t_token	*tok_cur;
	enum e_parse_ret	ret;

	tok_cur = (t_token *)array_get_at(tokens, tok_num);
	while (tok_cur->type == E_TOKEN_BLANK)
	{
		tok_num += 1;
		tok_cur = (t_token *) array_get_at(tokens, tok_num);
	}
	if (is_grammar_type(gram_cur))
	{
		while (grammar[gram_cur][glist][0])
		{
			while (grammar[gram_cur][glist][gfinal])
			{
				printf("%d%*sParsing: tok_num : %zu, tok_type: %s gram type : %s \n", parser_lvl, parser_lvl, " ", tok_num, parser_gram_get_name(tok_cur->type), parser_gram_get_name(gram_cur));
				ret = parser_test(tokens, tok_num, grammar[gram_cur][glist][gfinal], 0, 0, parser_lvl + 1);
				if (ret == E_PARSE_RET_TRUE && tok_num < tokens->used)
					return (parser_test(tokens, tok_num + 1, gram_cur, glist, gfinal + 1, parser_lvl + 1));
				else if (tok_num >= tokens->used && !grammar[gram_cur][glist][gfinal + 1])
					return (E_PARSE_RET_TRUE);
				gfinal += 1;
			}
			gfinal = 0;
			glist += 1;
		}
	}
	else if (is_token_type(gram_cur))
	{
	 ft_printf("token\n");
		if (tok_cur->type == gram_cur)
		{
			ft_printf("ok\n");
				return (E_PARSE_RET_TRUE);
		}
	}
	return (E_PARSE_RET_FALSE);
}

t_bool parser_parse(t_array *tokens)
{
    enum e_parse_ret ret;

//	ret = parser_bt(tokens, 0, E_GRAM_PROGRAM, 0, 0, 1);
	ret = parser_test(tokens, 0, E_GRAM_PROGRAM, 0, 0, 1);
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