/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 05:59:37 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/04 07:37:03 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include <array/array.h>

typedef struct s_token t_token;

enum e_token_type
{
	E_TOKEN_NONE,
	E_TOKEN_BLANK,
	E_TOKEN_WORD,
	E_TOKEN_SQUOTE,
	E_TOKEN_DQUOTE,
	E_TOKEN_BQUOTE,
	E_TOKEN_SEMI
};

struct s_token
{
	char const				*str;
	size_t				len;
	enum e_token_type	type;
};

enum e_char_type
{
	E_CHAR_TYPE_NONE,
	E_CHAR_TYPE_BLANK,
	E_CHAR_TYPE_LETTER,
	E_CHAR_TYPE_SQUOTE,
	E_CHAR_TYPE_BQUOTE,
	E_CHAR_TYPE_DQUOTE,
	E_CHAR_TYPE_SEMI,
	E_CHAR_TYPE_NEWLINE
};

void	lexer_tokenise_one(char const **input, t_array	*tokens);
t_array	*lexer_lex(char const *input);
void	lexer_print_tokens(t_array *tokens);

#endif