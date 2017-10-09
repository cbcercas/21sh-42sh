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

t_bool	parser_bt(t_array *tokens, size_t tok_num, 	t_grammar_type gram_cur, int parser_lvl)
{
    parser_lvl += 1;
	t_token	*tok_cur;
	uint32_t	g_list;
	uint32_t	g_final;

	tok_cur = (t_token *)array_get_at(tokens, tok_num);
	g_list = 0;
	g_final = 0;
    ft_printf("%d Parsing: tok_num : %d, gram type : %s \n", parser_lvl, tok_num, parser_gram_get_name(gram_cur));
    if (tok_cur && grammar[gram_cur][g_list][g_final])
    {
        if (is_grammar_type(grammar[gram_cur][g_list][g_final]))
        {
            if (parser_bt(tokens, tok_num, grammar[gram_cur][g_list][g_final], parser_lvl))
                return (parser_bt(tokens, tok_num + 1, grammar[gram_cur][g_list][g_final + 1], parser_lvl));
            else
                parser_bt(tokens, tok_num, grammar[gram_cur][g_list + 1][g_final + 1], parser_lvl);
        }
        else
        {
            if (grammar[gram_cur][g_list][g_final] == tok_cur->type)
                return (true);
            else
                return (false);
        }
    }
    else if (!tok_cur)
    {
        ft_dprintf(2, "parse error near %s", ft_strsub_secu(tok_cur->str, 0, tok_cur->len, M_LVL_PARSER));
    }
       return (false);
}

t_bool parser_parse(t_array *tokens)
{
    if (parser_bt(tokens, 0, E_GRAM_PROGRAM, 0))
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