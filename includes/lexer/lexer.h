/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 05:59:37 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 16:49:30 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>

# include <array/array.h>
# include <types/stack.h>
# include <automaton/automaton.h>
# include <parser/enum.h>
# include <ftprintf.h>
# include <logger.h>

typedef struct s_token	t_token;
typedef struct s_lexer_data	t_lexer_data;

struct s_token
{
	char const			*str;
	size_t				len;
	t_token_type		type;
};

struct s_lexer_data
{
	t_automaton	automaton;

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
	E_CHAR_TYPE_SEMI,
	E_CHAR_TYPE_DIGIT,
	E_CHAR_TYPE_ERROR,
	E_CHAR_TYPE_MAX
};

t_array	*lexer_init(t_array *toks);
t_array	*lexer_lex(t_array *tokens, char const *input);
void	lexer_print_token(t_token *tok);
void	lexer_print_tokens(t_array *tokens);
void	lexer_clean_tokens(t_array *tokens);
t_bool	is_token_type(t_token_type t);

#endif