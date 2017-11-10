/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:57:29 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/14 16:01:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include <string/ft_string.h>
# include <core/return.h>
# include <lexer/lexer.h>

typedef struct 			s_exp
{
	t_string 			*str;
	t_token_type		type;
}               		t_exp;

t_return	expand(t_array *tokens, t_array *array_exp);
t_exp		*expand_exp(t_exp *exp);
void 		expand_dol(t_exp *exp);
t_array		*expand_init(t_array *expand_array);
t_exp		*exp_create_new(t_token *tok);
t_exp		*expand_hist(t_exp *exp);
char		*ft_replace_exp(char *src1, char *src2, int index, int size);

void		sh_exp_del(void *i);
void		sh_expand_destroy(t_array *array_exp);

void		expand_print(t_array *array_exp);
void		ft_expand_print_token(t_token_type type);

int     ft_strlen_before(const char *str);
int     ft_numlen(const char *str);
int     histisclear(const char *str);
int 	expand_hist_digit(t_exp *exp, int *i, int len);
int    	expand_hist_alpha(t_exp *exp, int *i, int len);
t_exp   *expand_remove_quote(t_exp *exp);
BOOL 	expand_antislash(t_string *string, t_token_type type);
void 	expand_merge_tokens_word(t_array *array_exp);
void	expand_merge_now(t_exp *tmp1, t_exp *tmp2, t_array *array_exp, size_t *i);

#endif
