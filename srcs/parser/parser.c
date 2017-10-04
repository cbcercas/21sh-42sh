#include <parser/parser.h>
#include <lexer/lexer.h>
#include <types/bool.h>
#include <array/array.h>

extern uint32_t    grammar[224][6][4];

t_bool	is_grammar_type(t_grammar_type g)
{
	if (g > E_GRAM_NONE && g < E_GRAM_END)
		return (true);
	else
		return (false);
};


t_bool	parser_bt(t_array *tokens, size_t tok_num, 	t_grammar_type gram_cur)
{
	t_token	*tok_cur;
	uint32_t	g_list;
	uint32_t	g_final;

	tok_num = 0;
	tok_cur = (t_token *)array_get_at(tokens, tok_num);
	g_list = 0;
	g_final = 0;
	while (grammar[gram_cur][g_list][g_final])
	{
		if (is_grammar_type(grammar[gram_cur][g_list][g_final]))
		{
			if (parser_bt(tokens, tok_num, grammar[gram_cur][g_list][g_final]))
				g_final += 1;
			else
				g_list += 1;
		}
		else
		{
			if (grammar[gram_cur][g_list][g_final] == tok_cur->type)
				return (true);
			else
				return (false);
		}
	}
	return (false);
}

t_bool parser_parse(t_array *tokens)
{
	return (parser_bt(tokens, 0, E_GRAM_PROGRAM));
}