#include <parser/parser.h>
#include <types/bool.h>
#include <array/array.h>


t_bool	is_grammar_type(t_grammar_type g)
{
	if (g > E_GM_NONE && g < E_GM_END)
		return (true);
	else
		return (false);
};

t_bool parser_parse(t_array *tokens)
{
	(void)tokens;
	return (false);
}