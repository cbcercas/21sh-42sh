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

	log_dbg2("Parser: Now checking if token %d is the first one and if it is correct", where);
	if (check_first(tokens, where) == false)
		return (false);
	log_dbg2("Parser: Now checking if token %d is the last one and if it is correct", where);
	if (check_last(tokens, where) == false)
		return (false);
	log_dbg2("Parser: Now checking if token %d is an operator and if it is surrounded correctly", where);
	if (check_double(tokens, where) == false)
		return (false);
	log_dbg2("Parser: Now checking if token %d is a semicolon and if it is surrounded correctly", where);
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
	log_info("Parser: in %s:%d is initialized.", __FILE__, __LINE__);
	log_dbg1("Parser: Cycling through tokens.");
	while (where <= tokens->used)
	{
		log_dbg2("Parser: Cycling through tokens: Now at token %d.", where);
		dbg_printtok_str(tokens, where);
		ok = gr_checkcmd(tokens, where);
		if (ok == false)
			break ;
		where++;
	}
	if (ok == false)
	{
		log_fatal("Parser: returned false at token %d.\n\nPARSER ERROR\n", where);
		ft_printf("Parser Error\n");
		return (false);
	}
	else
	{
		log_info("Parser: return true after cycling through all tokens.");
		return (true);
	}
}