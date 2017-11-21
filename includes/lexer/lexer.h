/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 05:59:37 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/21 13:46:59 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <types/bool.h>
# include <parser/enum.h>
# include <automaton/automaton.h>
# include <core/return.h>
# include <core/progname.h>

typedef struct s_token		t_token;
typedef struct s_lexer_data	t_lexer_data;

/*
** @file   lexer.h
**
** @brief  Function prototypes for the lexer module
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @struct s_token
** @brief Token structure used for the lexer
**
** @arg str Pointer to the begining of the word in the string for this token
** @arg len Lenght of the "word" of a token
** @arg type The token type (cf lexer.c)
*/

struct						s_token
{
	char const				*str;
	size_t					len;
	t_token_type			type;
};

/*
** @brief TODO
*/

struct						s_lexer_data
{
	t_automaton				automaton;
};

/*
** @brief TODO
*/

enum						e_char_type
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

/*
** @file lexer_init.c
**
** @brief Functions used to initialize the lexer
*/

t_array						*lexer_init(t_array *toks);

/*
** @file lexer.c
**
** @brief Functions for the lexer itself
*/

t_return					lexer_lex(t_array *tokens, char const *input);
void						lexer_print_tokens(t_array *tokens);

/*
** @file lexer_clean.c
**
** @brief Functions used to clear tokens (TODO)
*/

void						lexer_clean_tokens(t_array *tokens);

/*
** @file lexer_utils.c
**
** @brief Utility functions for the lexer modules
*/

t_bool						is_token_type(t_token_type t);

#endif
