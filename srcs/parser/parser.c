#include <lexer/lexer.h>
#include <array/array.h>
#include <core/main.h>

t_array	*parser_parse(t_array *tokens)
{
	t_token	*tok;

	tok = array_get_at(tokens, 0);
	if (tok->type == E_TOKEN_WORD)
		return tokens;
	ft_printf("%s: parsing error or not supported\n", PROG_NAME);
	return (NULL);
}