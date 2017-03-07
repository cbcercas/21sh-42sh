/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 04:03:46 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/05 13:07:33 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <lexer/lexer.h>

static const uint32_t g_char_type[129] = {
[0] = E_CHAR_TYPE_LETTER,
[1] = E_CHAR_TYPE_LETTER,
[2] = E_CHAR_TYPE_LETTER,
[3] = E_CHAR_TYPE_LETTER,
[4] = E_CHAR_TYPE_LETTER,
[5] = E_CHAR_TYPE_LETTER,
[6] = E_CHAR_TYPE_LETTER,
[7] = E_CHAR_TYPE_LETTER,
[8] = E_CHAR_TYPE_LETTER,
['\t'] = E_CHAR_TYPE_BLANK,
['\n'] = E_CHAR_TYPE_BLANK,
[11] = E_CHAR_TYPE_LETTER,
[12] = E_CHAR_TYPE_LETTER,
[13] = E_CHAR_TYPE_LETTER,
[14] = E_CHAR_TYPE_LETTER,
[15] = E_CHAR_TYPE_LETTER,
[16] = E_CHAR_TYPE_LETTER,
[17] = E_CHAR_TYPE_LETTER,
[18] = E_CHAR_TYPE_LETTER,
[19] = E_CHAR_TYPE_LETTER,
[20] = E_CHAR_TYPE_LETTER,
[21] = E_CHAR_TYPE_LETTER,
[22] = E_CHAR_TYPE_LETTER,
[23] = E_CHAR_TYPE_LETTER,
[24] = E_CHAR_TYPE_LETTER,
[25] = E_CHAR_TYPE_LETTER,
[26] = E_CHAR_TYPE_LETTER,
[27] = E_CHAR_TYPE_LETTER,
[28] = E_CHAR_TYPE_LETTER,
[29] = E_CHAR_TYPE_LETTER,
[30] = E_CHAR_TYPE_LETTER,
[31] = E_CHAR_TYPE_LETTER,
[' '] = E_CHAR_TYPE_BLANK,
['!'] = E_CHAR_TYPE_LETTER,
['"'] = E_CHAR_TYPE_DQUOTE,
['#'] = E_CHAR_TYPE_LETTER,
['$'] = E_CHAR_TYPE_LETTER,
['%'] = E_CHAR_TYPE_LETTER,
['&'] = E_CHAR_TYPE_LETTER,
['\''] = E_CHAR_TYPE_SQUOTE,
['('] = E_CHAR_TYPE_LETTER,
[')'] = E_CHAR_TYPE_LETTER,
['*'] = E_CHAR_TYPE_LETTER,
['+'] = E_CHAR_TYPE_LETTER,
[','] = E_CHAR_TYPE_LETTER,
['-'] = E_CHAR_TYPE_LETTER,
['.'] = E_CHAR_TYPE_LETTER,
['/'] = E_CHAR_TYPE_LETTER,
['0'] = E_CHAR_TYPE_LETTER,
['1'] = E_CHAR_TYPE_LETTER,
['2'] = E_CHAR_TYPE_LETTER,
['3'] = E_CHAR_TYPE_LETTER,
['4'] = E_CHAR_TYPE_LETTER,
['5'] = E_CHAR_TYPE_LETTER,
['6'] = E_CHAR_TYPE_LETTER,
['7'] = E_CHAR_TYPE_LETTER,
['8'] = E_CHAR_TYPE_LETTER,
['9'] = E_CHAR_TYPE_LETTER,
[':'] = E_CHAR_TYPE_LETTER,
[';'] = E_CHAR_TYPE_SEMI,
['<'] = E_CHAR_TYPE_LETTER,
['='] = E_CHAR_TYPE_LETTER,
['>'] = E_CHAR_TYPE_LETTER,
['?'] = E_CHAR_TYPE_LETTER,
['@'] = E_CHAR_TYPE_LETTER,
['A'] = E_CHAR_TYPE_LETTER,
['B'] = E_CHAR_TYPE_LETTER,
['C'] = E_CHAR_TYPE_LETTER,
['D'] = E_CHAR_TYPE_LETTER,
['E'] = E_CHAR_TYPE_LETTER,
['F'] = E_CHAR_TYPE_LETTER,
['G'] = E_CHAR_TYPE_LETTER,
['H'] = E_CHAR_TYPE_LETTER,
['I'] = E_CHAR_TYPE_LETTER,
['J'] = E_CHAR_TYPE_LETTER,
['K'] = E_CHAR_TYPE_LETTER,
['L'] = E_CHAR_TYPE_LETTER,
['M'] = E_CHAR_TYPE_LETTER,
['N'] = E_CHAR_TYPE_LETTER,
['O'] = E_CHAR_TYPE_LETTER,
['P'] = E_CHAR_TYPE_LETTER,
['Q'] = E_CHAR_TYPE_LETTER,
['R'] = E_CHAR_TYPE_LETTER,
['S'] = E_CHAR_TYPE_LETTER,
['T'] = E_CHAR_TYPE_LETTER,
['U'] = E_CHAR_TYPE_LETTER,
['V'] = E_CHAR_TYPE_LETTER,
['W'] = E_CHAR_TYPE_LETTER,
['X'] = E_CHAR_TYPE_LETTER,
['Y'] = E_CHAR_TYPE_LETTER,
['Z'] = E_CHAR_TYPE_LETTER,
['['] = E_CHAR_TYPE_LETTER,
['\\'] = E_CHAR_TYPE_LETTER,
[']'] = E_CHAR_TYPE_LETTER,
['^'] = E_CHAR_TYPE_LETTER,
['_'] = E_CHAR_TYPE_LETTER,
['`'] = E_CHAR_TYPE_BQUOTE,
['a'] = E_CHAR_TYPE_LETTER,
['b'] = E_CHAR_TYPE_LETTER,
['c'] = E_CHAR_TYPE_LETTER,
['d'] = E_CHAR_TYPE_LETTER,
['e'] = E_CHAR_TYPE_LETTER,
['f'] = E_CHAR_TYPE_LETTER,
['g'] = E_CHAR_TYPE_LETTER,
['h'] = E_CHAR_TYPE_LETTER,
['i'] = E_CHAR_TYPE_LETTER,
['j'] = E_CHAR_TYPE_LETTER,
['k'] = E_CHAR_TYPE_LETTER,
['l'] = E_CHAR_TYPE_LETTER,
['m'] = E_CHAR_TYPE_LETTER,
['n'] = E_CHAR_TYPE_LETTER,
['o'] = E_CHAR_TYPE_LETTER,
['p'] = E_CHAR_TYPE_LETTER,
['q'] = E_CHAR_TYPE_LETTER,
['r'] = E_CHAR_TYPE_LETTER,
['s'] = E_CHAR_TYPE_LETTER,
['t'] = E_CHAR_TYPE_LETTER,
['u'] = E_CHAR_TYPE_LETTER,
['v'] = E_CHAR_TYPE_LETTER,
['w'] = E_CHAR_TYPE_LETTER,
['x'] = E_CHAR_TYPE_LETTER,
['y'] = E_CHAR_TYPE_LETTER,
['z'] = E_CHAR_TYPE_LETTER,
['{'] = E_CHAR_TYPE_LETTER,
['|'] = E_CHAR_TYPE_LETTER,
['}'] = E_CHAR_TYPE_LETTER,
['~'] = E_CHAR_TYPE_LETTER,
[127] = E_CHAR_TYPE_LETTER,
};
#include <ft_printf/libftprintf.h>

void	lexer_tokenise_one(char const **input, t_array	*tokens, t_automaton *automaton)
{
	t_token			tok;

	tok.str = *input;
	tok.type = g_char_type[(int)**input];
	if (automaton->cur_state > E_STATE_WORD)
	{
		if (g_char_type[(int)**input] > E_CHAR_TYPE_LETTER)
			(*input)++;
		else
			while (**input && g_char_type[(int)**input] <= E_CHAR_TYPE_LETTER)
				(*input)++;
	}
	else
		while (**input && g_char_type[(int)**input] == tok.type)
		{
			(*input)++;
		}
	tok.len = *input - tok.str;
	array_push(tokens, &tok);
}

void	lexer_tokenise(char const **input, t_array	*tokens, t_automaton *automaton)
{

	while (**input)
	{
		if (g_char_type[(int)**input] > E_CHAR_TYPE_LETTER)
		{
			if (automaton->cur_state == (t_stack_state)g_char_type[(int)**input])
			{
				stack_pop(automaton->stack);

				automaton->cur_state = *(t_stack_state *)get_top_stack(automaton->stack);

			}
			else
			{
				stack_push(automaton->stack, &g_char_type[(int)**input]);
				automaton->cur_state = (t_stack_state)g_char_type[(int)**input];
			}
		}
			lexer_tokenise_one(input, tokens, automaton);
	}
}


t_array	*lexer_lex(char const *input)
{
	t_array		*tokens;
	t_automaton	*automaton;

	if (!(tokens = array_create(sizeof(t_token))) || !(automaton = automaton_init()))
		return (NULL);
	int i;

	i = 0;
	while (*input && i++ < 10)
		lexer_tokenise(&input, tokens, automaton);
	if (automaton->cur_state > E_STATE_START)
	{
		ft_printf("Minishell: Lexing error: Incomplete command.\n");
		//ls TODO free automate and tokens;
		return (NULL);
	}
	return (tokens);
}

void	lexer_print_tokens(t_array *tokens)
{
	size_t	cnt;
	t_token	*tok;

	cnt = 0;
	while (cnt < tokens->used)
	{
		tok = (t_token *)array_get_at(tokens, cnt);
		ft_putchar('<');
		ft_putnstr(tok->str, tok->len);
		ft_putstr("> = ");
		if (tok->type == E_CHAR_TYPE_LETTER)
			ft_putstr("TOKEN_TYPE_WORD");
		else if (tok->type == E_CHAR_TYPE_BLANK)
			ft_putstr("TOKEN_TYPE_BLANK");
		else if (tok->type == E_CHAR_TYPE_SQUOTE)
			ft_putstr("TOKEN_TYPE_SQUOTE");
		else if (tok->type == E_CHAR_TYPE_BQUOTE)
			ft_putstr("TOKEN_TYPE_BQUOTE");
		else if (tok->type == E_CHAR_TYPE_DQUOTE)
			ft_putstr("TOKEN_TYPE_DQUOTE");
		else if (tok->type == E_CHAR_TYPE_SEMI)
			ft_putstr("TOKEN_TYPE_SEMI");
		ft_putchar('\n');
		cnt++;
	}
}