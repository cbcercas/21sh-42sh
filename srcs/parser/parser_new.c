#include <parser/parser.h>

/*
**
** This function prints token one by one on every iteration
**
*/

static void	dbg_printtok_str(t_array *tokens, size_t i)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, i);
	lexer_print_token(tok);
	ft_putstr(": ");
	ft_putnstr(tok->str, tok->len);
	ft_putchar('\n');
}

/*
**
** This is the function that call all the other functions needed for the parser.
**
*/

t_bool gr_checkcmd(t_array *tokens, size_t where)
{

	if (check_first(tokens, where) == false)
		return (false);
	if (check_last(tokens, where) == false)
		return (false);
	if (check_double(tokens, where) == false)
		return (false);
	if (check_double_semi(tokens, where) == false)
		return (false);
}

/*
**
** This is the main function for the parser, does the loop
**
*/

t_bool parser_parse(t_array *tokens)
{
	t_bool ok;
	size_t where;

	where = 0;
	ok = false;
	while (where <= tokens->used)
	{
		dbg_printtok_str(tokens, where);
		ok = gr_checkcmd(tokens, where);
		if (ok == false)
			break ;
		where++;
	}
	if (ok == false)
	{
		ft_printf("Parsing error\n");
		return (false);
	}
	else
		return (true);
}