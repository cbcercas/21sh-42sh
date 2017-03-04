/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 04:03:46 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/04 07:36:24 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <lexer/lexer.h>

static const int g_char_type[129] = {
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
['\n'] = E_CHAR_TYPE_NEWLINE,
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

void	lexer_tokenise_one(char const **input, t_array	*tokens)
{
	t_token	tok;

	tok.str = *input;
	tok.type = g_char_type[(int)**input];
	while (**input && g_char_type[(int)**input] == tok.type)
		(*input)++;
	tok.len = *input - tok.str;
	array_push(tokens, &tok);
}


t_array	*lexer_lex(char const *input)
{
	t_array	*tokens;

	if (!(tokens = array_create(sizeof(t_token))))
		return (NULL);
	while (*input)
		lexer_tokenise_one(&input, tokens);
	return (tokens);
}

void	lexer_print_tokens(t_array *tokens)
{
	size_t	cnt;
	t_token	*tok;

	cnt = -1;
	ft_putchar('\n');
	while (++cnt < tokens->used)
	{
		tok = (t_token *)array_get_at(tokens, cnt);
		ft_putchar('<');
		ft_putnstr(tok->str, tok->len);
		ft_putstr("> = ");
		if (tok->type == E_CHAR_TYPE_LETTER)
			ft_putstr("E_CHAR_TYPE_LETTER");
		else if (tok->type == E_CHAR_TYPE_BLANK)
			ft_putstr("E_CHAR_TYPE_BLANK");
		else if (tok->type == E_CHAR_TYPE_SQUOTE)
			ft_putstr("E_CHAR_TYPE_SQUOTE");
		else if (tok->type == E_CHAR_TYPE_BQUOTE)
			ft_putstr("E_CHAR_TYPE_BQUOTE");
		else if (tok->type == E_CHAR_TYPE_DQUOTE)
			ft_putstr("E_CHAR_TYPE_DQUOTE");
		else if (tok->type == E_CHAR_TYPE_SEMI)
			ft_putstr("E_CHAR_TYPE_SEMI");
		else if (tok->type == E_CHAR_TYPE_NEWLINE)
			ft_putstr("E_CHAR_TYPE_NEWLINE");
		ft_putchar('\n');
	}
}