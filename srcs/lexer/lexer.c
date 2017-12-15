/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 04:03:46 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/21 15:08:49 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <tools/tools.h>

static const uint32_t g_char_type[129] = {
	[0] = E_CHAR_TYPE_NONE,
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
	['&'] = E_CHAR_TYPE_AND,
	['\''] = E_CHAR_TYPE_SQUOTE,
	['('] = E_CHAR_TYPE_LETTER,
	[')'] = E_CHAR_TYPE_LETTER,
	['*'] = E_CHAR_TYPE_LETTER,
	['+'] = E_CHAR_TYPE_LETTER,
	[','] = E_CHAR_TYPE_LETTER,
	['-'] = E_CHAR_TYPE_LETTER,
	['.'] = E_CHAR_TYPE_LETTER,
	['/'] = E_CHAR_TYPE_LETTER,
	['0'] = E_CHAR_TYPE_DIGIT,
	['1'] = E_CHAR_TYPE_DIGIT,
	['2'] = E_CHAR_TYPE_DIGIT,
	['3'] = E_CHAR_TYPE_DIGIT,
	['4'] = E_CHAR_TYPE_DIGIT,
	['5'] = E_CHAR_TYPE_DIGIT,
	['6'] = E_CHAR_TYPE_DIGIT,
	['7'] = E_CHAR_TYPE_DIGIT,
	['8'] = E_CHAR_TYPE_DIGIT,
	['9'] = E_CHAR_TYPE_DIGIT,
	[':'] = E_CHAR_TYPE_LETTER,
	[';'] = E_CHAR_TYPE_SEMI,
	['<'] = E_CHAR_TYPE_LESSGREAT,
	['='] = E_CHAR_TYPE_LETTER,
	['>'] = E_CHAR_TYPE_LESSGREAT,
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
	['`'] = E_CHAR_TYPE_SQUOTE,
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
	['|'] = E_CHAR_TYPE_PIPE,
	['}'] = E_CHAR_TYPE_LETTER,
	['~'] = E_CHAR_TYPE_LETTER,
	[127] = E_CHAR_TYPE_LETTER
};

/*
** @brief
*/

static const uint32_t g_stepper[E_STATE_MAX][E_CHAR_TYPE_MAX][2] =
{
	[E_STATE_NONE] =
	{
		[E_CHAR_TYPE_NONE] = {0, 0}
	},
	[E_STATE_BLANK] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_NEWLINE] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_WORD] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 0},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 0},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_SQUOTE] =
	{
		[E_CHAR_TYPE_NONE] = {0, 0},
		[E_CHAR_TYPE_BLANK] = {0, 0},
		[E_CHAR_TYPE_NEWLINE] = {0, 0},
		[E_CHAR_TYPE_LETTER] = {0, 0},
		[E_CHAR_TYPE_SQUOTE] = {0, 2},
		[E_CHAR_TYPE_BQUOTE] = {0, 0},
		[E_CHAR_TYPE_DQUOTE] = { 0, 0},
		[E_CHAR_TYPE_PIPE] = {0, 0},
		[E_CHAR_TYPE_LESSGREAT] = {0, 0},
		[E_CHAR_TYPE_AND] = {0, 0},
		[E_CHAR_TYPE_SEMI] = {0, 0},
		[E_CHAR_TYPE_DIGIT] = {0, 0},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_BQUOTE] =
	{
		[E_CHAR_TYPE_NONE] = {0, 0},
		[E_CHAR_TYPE_BLANK] = {0, 0},
		[E_CHAR_TYPE_NEWLINE] = {0, 0},
		[E_CHAR_TYPE_LETTER] = {0, 0},
		[E_CHAR_TYPE_SQUOTE] = {0, 0},
		[E_CHAR_TYPE_BQUOTE] = {0, 2},
		[E_CHAR_TYPE_DQUOTE] = { 0, 0},
		[E_CHAR_TYPE_PIPE] = {0, 0},
		[E_CHAR_TYPE_LESSGREAT] = {0, 0},
		[E_CHAR_TYPE_AND] = {0, 0},
		[E_CHAR_TYPE_SEMI] = {0, 0},
		[E_CHAR_TYPE_DIGIT] = {0, 0},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_DQUOTE] =
	{
		[E_CHAR_TYPE_NONE] = {0, 0},
		[E_CHAR_TYPE_BLANK] = {0, 0},
		[E_CHAR_TYPE_NEWLINE] = {0, 0},
		[E_CHAR_TYPE_LETTER] = {0, 0},
		[E_CHAR_TYPE_SQUOTE] = {0, 0},
		[E_CHAR_TYPE_BQUOTE] = {0, 0},
		[E_CHAR_TYPE_DQUOTE] = { 0, 2},
		[E_CHAR_TYPE_PIPE] = {0, 0},
		[E_CHAR_TYPE_LESSGREAT] = {0, 0},
		[E_CHAR_TYPE_AND] = {0, 0},
		[E_CHAR_TYPE_SEMI] = {0, 0},
		[E_CHAR_TYPE_DIGIT] = {0, 0},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_PIPE] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 0},
		[E_CHAR_TYPE_LESSGREAT] = {0, 0},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_OR_IF] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_LESSGREAT] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 0},
		[E_CHAR_TYPE_AND] = {0, 0},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_AND] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 0},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_SEMI] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_IO_NUMBER] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 0},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 0},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_DLESS] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_DGREAT] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_AND_IF] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_LESSAND] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_GREATAND] =
	{
		[E_CHAR_TYPE_NONE] = {0, 1},
		[E_CHAR_TYPE_BLANK] = {0, 1},
		[E_CHAR_TYPE_NEWLINE] = {0, 1},
		[E_CHAR_TYPE_LETTER] = {0, 1},
		[E_CHAR_TYPE_SQUOTE] = {0, 1},
		[E_CHAR_TYPE_BQUOTE] = {0, 1},
		[E_CHAR_TYPE_DQUOTE] = {0, 1},
		[E_CHAR_TYPE_PIPE] = {0, 1},
		[E_CHAR_TYPE_LESSGREAT] = {0, 1},
		[E_CHAR_TYPE_AND] = {0, 1},
		[E_CHAR_TYPE_SEMI] = {0, 1},
		[E_CHAR_TYPE_DIGIT] = {0, 1},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_START] =
	{
		[E_CHAR_TYPE_NONE] = { 0, 0},
		[E_CHAR_TYPE_BLANK] = { 1, 0},
		[E_CHAR_TYPE_NEWLINE] = { 1, 0},
		[E_CHAR_TYPE_LETTER] = { 1, 0},
		[E_CHAR_TYPE_SQUOTE] = { 1, 0},
		[E_CHAR_TYPE_BQUOTE] = { 1, 0},
		[E_CHAR_TYPE_DQUOTE] = {1, 0},
		[E_CHAR_TYPE_PIPE] = { 1, 0 },
		[E_CHAR_TYPE_LESSGREAT] = {1, 0},
		[E_CHAR_TYPE_AND] = {1, 0},
		[E_CHAR_TYPE_SEMI] = {1, 0},
		[E_CHAR_TYPE_DIGIT] = {1, 0},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_END] =
	{
		[E_CHAR_TYPE_NONE] = { 0, 0},
		[E_CHAR_TYPE_BLANK] = { 1, 0},
		[E_CHAR_TYPE_NEWLINE] = { 1, 0},
		[E_CHAR_TYPE_LETTER] = { 1, 0},
		[E_CHAR_TYPE_SQUOTE] = { 1, 0},
		[E_CHAR_TYPE_BQUOTE] = { 1, 0},
		[E_CHAR_TYPE_DQUOTE] = {1, 0},
		[E_CHAR_TYPE_PIPE] = { 1, 0 },
		[E_CHAR_TYPE_LESSGREAT] = {1, 0},
		[E_CHAR_TYPE_AND] = {1, 0},
		[E_CHAR_TYPE_SEMI] = {1, 0},
		[E_CHAR_TYPE_DIGIT] = {1, 0},
		[E_CHAR_TYPE_ERROR] = {1, 0}
	},
	[E_STATE_ERROR] =
	{
		[E_CHAR_TYPE_NONE] = {0, 0}
	}
};

static const uint32_t g_tok_redir[129][129] =
{
	['<'] =
	{
		['<'] = E_TOKEN_DLESS,
		['&'] = E_TOKEN_LESSAND
	},
	['>'] =
	{
		['>'] = E_TOKEN_DGREAT,
		['&'] = E_TOKEN_GREATAND
	},
	['|'] =
	{
		['|'] = E_TOKEN_OR_IF
	},
	['&'] =
	{
		['&'] = E_TOKEN_AND_IF
	}
};

/*
** @brief Tokenizes one part of a string
** @param in The input
** @param tok The t_array containing the tokens
** @param a The automaton stepper
*/

static void			lexer_tokenize_one_loop(char const ***in, t_automaton **a,
									t_token *tok)
{
	if (tok->type == E_TOKEN_IO_NUMBER && g_char_type[(int)***in]
										== E_CHAR_TYPE_LETTER)
		tok->type = E_TOKEN_WORD;
	if (tok->type != E_TOKEN_SQUOTE && ***in == '\\')
		(**in) += 2;
	else
		(**in) += 1;
	if (g_stepper[(*a)->cur_state][g_char_type[(int)*(**in)]][0])
	{
		if (g_char_type[(int)***in] != (*a)->cur_state)
			automaton_step((*a), g_char_type[(int)***in], E_PUSH);
	}
	else if (g_stepper[(*a)->cur_state][g_char_type[(int)*(**in)]][1])
	{
		if (g_stepper[(*a)->cur_state][g_char_type[(int)*(**in)]][1] == 2)
			(**in)++;
		automaton_step((*a), E_STATE_NONE, E_POP);
	}
}

static void			lexer_tokenize_one(char const **in, t_array *toks,
									t_automaton *a)
{
	t_token	tok;

	tok.str = *in;
	if (g_tok_redir[(int)**in][(int)*(*in + 1)] > E_TOKEN_NONE)
	{
		tok.type = g_tok_redir[(int)**in][(int)*(*in + 1)];
		(*in) += 1;
	}
	else
		tok.type = g_char_type[(int)**in];
	while (**in && a->cur_state < E_STATE_END &&
			((tok.type != E_TOKEN_LESSGREAT && tok.type != E_TOKEN_DGREAT &&
					tok.type != E_TOKEN_DLESS) || (*in) - tok.str <= 1))
		lexer_tokenize_one_loop(&in, &a, &tok);
	tok.len = (*in) - tok.str;
	if (tok.type == E_TOKEN_AND)
		automaton_step(a, E_STATE_ERROR, E_PUSH);
	array_push(toks, &tok);
}

/*
** @brief Tokenizes the input
** @param in The input
** @param toks The t_array containing the tokens
** @param a The automaton stepper
*/

static void			lexer_tokenize(char const **in, t_array *toks,
									t_automaton *a)
{
	while (**in)
	{
		if ((**in == '\\') && (*(*in + 1) == '\n'))
		{
			*in += 2;
			return ;
		}
		if (g_stepper[a->cur_state][g_char_type[(int)**in]][0])
		{
			if (g_tok_redir[(int)**in][(int)*(*in + 1)] > E_TOKEN_NONE)
				automaton_step(a, g_tok_redir[(int)**in][(int)*(*in + 1)],
						E_PUSH);
			else
				automaton_step(a, g_char_type[(int)**in], E_PUSH);
		}
		if (a->cur_state == E_STATE_ERROR)
			return ;
		lexer_tokenize_one(in, toks, a);
	}
}

static void			lexer_lex_err(t_return *ret)
{
	ft_dprintf(STDERR_FILENO, "%s: Lexing error.\n", PROGNAME);
	*ret = E_RET_LEXER_ERROR;
}

/*
** @brief Main function for the lexer
** @param tokens The t_array conaining the tokens. (uninitialized at
** beginning of function)
** @param in The input
** @return Returns a ret value
*/

t_return			lexer_lex(t_array *tokens, char const *in)
{
	static t_automaton	automaton;
	t_return			ret;

	ret = E_RET_LEXER_OK;
	if (automaton_init(&automaton) == NULL)
		sh_exit_error("automaton init fail");
	if (in == NULL || !ft_strlen(in))
	{
		stack_destroy(&automaton.stack, NULL);
		return ((in) ? E_RET_EMPTY_LINE : E_RET_LEXER_ERROR);
	}
	while ((*in != 0) && (automaton.cur_state < E_STATE_ERROR))
		lexer_tokenize(&in, tokens, &automaton);
	if (automaton.cur_state == E_STATE_ERROR)
		lexer_lex_err(&ret);
	else if (!is_empty_stack(automaton.stack))
		ret = lexer_get_incomplete_ret(automaton.cur_state);
	if (tokens && tokens->used)
		lexer_clean_tokens(tokens);
	if (ret != E_RET_LEXER_OK)
		array_reset(tokens, NULL);
	stack_destroy(&automaton.stack, NULL);
	return (ret);
}
