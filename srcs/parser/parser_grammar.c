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