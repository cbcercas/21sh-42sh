/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 05:59:37 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/05 10:03:01 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>

# include <array/array.h>
# include <types/stack.h>
# include <automaton/automaton.h>
# include <ft_printf/libftprintf.h>
# include <logger/logger.h>

typedef struct s_token	t_token;
typedef uint32_t		t_token_type;

enum e_token_type
{
	E_TOKEN_NONE,
	E_TOKEN_BLANK,
	E_TOKEN_NEWLINE,
	E_TOKEN_WORD,
	E_TOKEN_SQUOTE,
	E_TOKEN_BQUOTE,
	E_TOKEN_DQUOTE,
	E_TOKEN_PIPE,
	E_TOKEN_OR_IF,
	E_TOKEN_LESSGREAT,
	E_TOKEN_DLESS,
	E_TOKEN_DGREAT,
	E_TOKEN_AND,
	E_TOKEN_MAX
};

struct s_token
{
	char const			*str;
	size_t				len;
	t_token_type		type;
};

enum e_char_type
{
	E_CHAR_TYPE_NONE,
	E_CHAR_TYPE_BLANK,
	E_CHAR_TYPE_NEWLINE,
	E_CHAR_TYPE_LETTER,
	E_CHAR_TYPE_SQUOTE,
	E_CHAR_TYPE_BQUOTE,
	E_CHAR_TYPE_DQUOTE,
	E_CHAR_TYPE_PIPE,
	E_CHAR_TYPE_LESSGREAT,
	E_CHAR_TYPE_AND,
	E_CHAR_TYPE_ERROR,
	E_CHAR_TYPE_MAX
};

t_array	*lexer_init(t_array *toks);
t_array	*lexer_lex(t_array *tokens, t_automaton *automaton, char const *input);
void	lexer_print_tokens(t_array *tokens);
void	lexer_clean_tokens(t_array *tokens);

#endif