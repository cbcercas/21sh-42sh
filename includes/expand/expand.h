/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:57:29 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/07 22:18:11 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EXPAND_H__
# define __EXPAND_H__

#include <lexer/lexer.h>
#include <core/main.h>

typedef struct s_exp
{
	char 			*str;
	t_token_type	type;
}               t_exp;

t_array *expand(t_array *tokens, t_array *array_exp);
void expand_dol(t_exp *exp);
t_array	*expand_init(t_array *expand_array);
t_array	*expand(t_array *tokens, t_array *array_exp);
t_exp	*exp_create_new(t_token *tok);
t_exp	*expand_hist(t_exp *exp);
char	*ft_replace_exp(char *src1, char *src2, int index, int size);

void	sh_exp_del(void *i);
void	sh_expand_destroy(t_array *array_exp);

void	expand_print(t_array *array_exp);
void	ft_expand_print_token(t_token_type type);
#endif
