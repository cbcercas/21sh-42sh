#include <parser/parser.h>

void    dbg_logger(char *str, int line, char *file, char *func)
{
	ft_printf("%s at %s, function %s:%d\n", str, file, func, line);
}

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
** Check_operators returns true if the token at the actuall where is an operator ( > | & etc...)
**
*/

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

t_bool check_semi(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	if (tok->type == E_TOKEN_SEMI)
	{
		tok = (t_token *)array_get_at(tokens, where + 1);
		if (tok->type == E_TOKEN_SEMI)
		{
			return (false);
		}
		else
		{
			tok = (t_token *)array_get_at(tokens, where + 2);
			if (tok->type == E_TOKEN_SEMI)
				return (false);
			else if (tok->type != E_TOKEN_SEMI)
				return (true);
		}
	}
	else
		return (true);8
	return (false);
}

t_bool check_before_after_operator(t_array *tokens, size_t where)
{
	t_token *tok;
	t_token *toknext;
	t_token *toknextnext;
	t_token *tokprev;
	t_token *tokprevprev;

	tok = (t_token *)array_get_at(tokens, where);
	toknext = (t_token *)array_get_at(tokens, where + 1);
	toknextnext = (t_token *)array_get_at(tokens, where + 2);
	tokprev = (t_token *)array_get_at(tokens, where - 1);
	tokprevprev = (t_token *)array_get_at(tokens, where - 2);

	if (toknext->type == E_TOKEN_BLANK)
		;
	if (toknext->type == E_TOKEN_WORD)
		;
	if (check_operators(tokens, where + 1) == true)
		return (false);
	if (toknextnext->type == E_TOKEN_BLANK)
		;
	if (toknextnext->type == E_TOKEN_WORD)
		;
	if (tokprev->type == E_TOKEN_BLANK)
		;
	if (tokprev->type == E_TOKEN_WORD)
		;
	if (tokprevprev->type == E_TOKEN_BLANK)
		;
	if (tokprevprev->type == E_TOKEN_WORD)
		;
}


t_bool gr_check_token(t_array *tokens, size_t where)
{
	if (where != 0)
		if (check_operators(tokens, where) == true)
			if (check_before_after_operator(tokens, where) == true)
				return true;
			else
				return false;
	/*
			if (tokens->used > where + 1)
				if (check_operators(tokens, where + 1))
					return (false);
				else
					if (check_blank(tokens, where + 1) == true)
						if (check_operators(tokens, where + 2) == true)
							return (false);
						else
							return (true);
					else
						if (check_word(tokens, where + 1) == true)
							if (check_operators(tokens, where + 2) == true)
								return (true);
							else
								return (true);
			else
				return (false);
		else
			return (check_semi(tokens, where));
	else
		return (true); //TODO: Check if this should return true or false here :/




				if ((check_operators(tokens, where + 1) == true) || (check_operators(tokens, where + 2) == true))
					else if (tok->type = E_TOKEN_BLANK)
					return (false);
				else
					return (true);
			else if (where - 1 > 0) //TODO: To be changed to a token check
				if (check_operators(tokens, where) == true)
						return (false);
				else
					return (true);
			else
				return (false);

		else
			return (check_semi(tokens, where));
	else
		return (true);*/
}

t_bool gr_checkcmd(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	if (where == 0)
		if (check_operators(tokens, where) == true)
			return (false);
		else
			return (gr_check_token(tokens, where));
	else
		return (gr_check_token(tokens, where));
}

t_bool parser_parse_new(t_array *tokens)
{
	t_bool ok;
	size_t where;
	size_t used;

	used = tokens->used;
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
	{
		ft_printf("Parser said ok to all !\n");
		return (true);
	}
}