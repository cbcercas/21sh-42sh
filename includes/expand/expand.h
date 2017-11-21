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

t_exp					*expand_hist(t_exp *exp);

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

int						ft_strlen_before(const char *str);
int						ft_numlen(const char *str);
int						expand_hist_digit(t_exp *exp, int *i, int len);
int						expand_hist_alpha(t_exp *exp, int *i, int len);

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

#endif
