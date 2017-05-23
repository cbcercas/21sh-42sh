//
// Created by Jules LASNE on 5/23/17.
//

#include <parser/parser_grammar.h>

/*
**
** This function returns true if the token at 'where' is an operator
**
*/

static t_bool check_operators(t_array *tokens, size_t where)
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

/*
**
** This function returns true if the token at 'where' is a word or a blank
**
*/

static t_bool check_word_blank(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	if (tok->type == E_TOKEN_BLANK || tok->type == E_TOKEN_WORD)
		return (true);
	else
		return (false);
}

/*
**
** This function returns true if the token at 'where' is a blank
**
*/

static t_bool check_blank(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	if (tok->type == E_TOKEN_BLANK)
		return (true);
	else
		return (false);
}

/*
**
** This function returns true if the token at 'where' is a word
**
*/

static t_bool check_word(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	if (tok->type == E_TOKEN_WORD)
		return (true);
	else
		return (false);
}

/*
**
** This function returns true if the token at 'where' is a semicolon
**
*/

static t_bool check_semi(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	if (tok->type == E_TOKEN_SEMI)
		return (true);
	else
		return (false);
}

/*
**
** This function returns false if the first token in the user input is an operator or a semicolon
**
*/

t_bool check_first(t_array *tokens, size_t where)
{
	if (where == 0)
	{
		if (check_operators(tokens, where) == true)
			return (false);
		if (check_semi(tokens, where) == true)
			return (false);
	}
	else
		return (true);
}

/*
**
** This function returns false if the last token in the user input is an operator
**
*/

t_bool check_last(t_array *tokens, size_t where)
{
	if (check_operators(tokens, where) == true)
	{
		if (where < tokens->used - 1)
			return (true);
		else
			return (false);
	}
	else
		return (true);
}

/*
**
** This function returns false if a semicolon is followed by an operator or another semicolon (space or not in between)
**
*/

t_bool check_double_semi(t_array *tokens, size_t where)
{
	if (where <= tokens->used - 2)
	{
		if (check_semi(tokens, where) == true)
		{
			if (check_blank(tokens, where + 1) == true)
			{
				if (check_semi(tokens, where + 2) == true)
					return (false);
				else
				{
					if (check_operators(tokens, where + 2) == true)
						return (false);
					else
						return (true);
				}
			}
			else
			{
				if (check_word(tokens, where + 1) == true)
					return (true);
				else
				{
					if (check_semi(tokens, where + 1) == true)
						return (false);
					else
						return (true);
				}
			}
		}
		else
			return (true);
	}
	else
		return (true);
}

/*
**
** This function returns false if an operator is followed by another operator or a semicolon (space or not in between)
**
*/

t_bool check_double(t_array *tokens, size_t where)
{
	if (where <= tokens->used - 2)
	{
		if (check_operators(tokens, where) == true)
		{
			if (check_blank(tokens, where + 1) == true)
			{
				if (check_word_blank(tokens, where + 2) == true)
					return (true);
				else
					return (false);
			}
			else
			{
				if (check_word(tokens, where + 1) == true)
					return (true);
				else
					return (false);
			}
		}
		else
			return (true);
	}
	else
		return (true);
}