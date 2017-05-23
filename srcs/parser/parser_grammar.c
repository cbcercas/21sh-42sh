//
// Created by Jules LASNE on 5/23/17.
//

#include <parser/parser_grammar.h>

t_bool check_first(t_array *tokens, size_t where)
{
	if (where == 0)
		if (check_operators(tokens, where) == true)
			return (false);
		else
			return (true);
	else
		return (true);
}

t_bool check_last(t_array *tokens, size_t where)
{
	if (check_operators(tokens, where) == true)
		if (where < tokens->used)
			return (true);
		else
			return (false);
	else
		return (true);
}

t_bool check_word_blank(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	if (tok->type == E_TOKEN_BLANK || tok->type == E_TOKEN_WORD)
		return (true);
	else
		return (false);
}

t_bool check_operators(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	if (tok->type == E_TOKEN_PIPE || tok->type == E_TOKEN_AND || \
	tok->type == E_TOKEN_AND_IF || tok->type == E_TOKEN_DGREAT || \
	tok->type == E_TOKEN_DLESS || tok->type == E_TOKEN_GREATAND || \
 	tok->type == E_TOKEN_LESSAND || tok->type == E_TOKEN_LESSGREAT || \
	tok->type == E_TOKEN_OR_IF)
		return (true);
	else
		return (false);
}