/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:57:29 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 12:41:27 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include <array/array.h>
# include <lexer/lexer.h>
# include <string/ft_string.h>
# include <environ/env_utils.h>
# include <environ/getter_env.h>
# include <core/input.h>
# include <history/history.h>

/*
** @file   expand.h
**
** @brief  Function prototypes for the expand module
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @struct s_exp
**
** @brief TODO
*/

typedef struct			s_exp
{
	t_string			*str;
	t_token_type		type;
}						t_exp;

/*
** @file expand.c
**
** @brief Main functions for the expand module
*/

t_return				expand(t_array *tokens, t_array *array_exp);
t_exp					*expand_exp(t_exp *exp);

/*
** @file expand_dol.c
**
** @brief Functions used to expand the $ (As in $PATH for example)
*/

void					expand_dol(t_string *str);

/*
** @file expand_utils.c
**
** @brief Utility functions used by the expand module
*/

t_array					*expand_init(t_array *expand_array);
t_exp					*exp_create_new(t_token *tok);
void					sh_exp_del(void *i);
void					sh_expand_destroy(t_array *array_exp);

/*
** @file expand_history.c
**
** @brief Functions used to expand history (!1 for example)
*/

BOOL					expand_hist(t_input *str);
size_t					find_last_quote(const char *s);

/*
** @file ft_replace.c
**
** @brief Function used to replace a string with another (Use for the expand)
*/

char					*ft_replace_exp(char *src1, char *src2, size_t index, \
																	int size);

/*
** @file expand_print.c
**
** @brief Prints the expand
*/

void					expand_print(t_array *array_exp);
void					expand_print_token(t_token_type type);

/*
** @file expand_history_tools.c
**
** @brief Tools used by the expand module for the history
*/

size_t					ft_strlen_before(const char *str);
size_t					ft_numlen(const char *str);

BOOL					expand_hist_digit(t_input *str, size_t *i);

BOOL					expand_hist_alpha(t_input *inp, size_t *i);
t_input					*expand_hist_find(t_input *input, size_t *i);

/*
** @file expand_quote.c
**
** @brief Functions used to remove quotes and expand them
*/

t_exp					*expand_remove_quote(t_exp *exp);
BOOL					expand_antislash(t_string *string, t_token_type type);

/*
** @file expand_merge.c
**
** @brief Functions used to merge tokens
*/

void					expand_merge_tokens_word(t_array *array_exp);
void					expand_merge_now(t_exp *tmp1, t_exp *tmp2,
												t_array *array_exp, size_t *i);

BOOL					expand_hist_replace(t_input *input, char *hist,
											size_t *index, size_t len_rep);

#endif
