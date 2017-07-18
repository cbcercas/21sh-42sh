/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:43:08 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/07 22:04:23 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

t_array	*expand_init(t_array *expand_array)
{
	expand_array = array_init(expand_array, sizeof(t_exp));
	if (expand_array)
	{
		log_info("Expand: Initialization done");
		return (expand_array);
	}
	log_fatal("Expand: Initialization failed");
	return (NULL);
}

t_exp *exp_create_new(t_token *tok)
{
  t_exp	*exp;

  if (!tok || !tok->str || !(exp = (t_exp*)malloc(sizeof(t_exp))))
    return (NULL);
  exp->type = tok->type;
  exp->str = string_ndup(tok->str, tok->len);
  return (exp);
}

void sh_exp_del(void *i)
{
	t_exp *exp;

	exp = (t_exp *)i;
	if (exp && exp->str->s)
		ft_strdel(&(exp->str->s));
}

void sh_expand_destroy(t_array *array_exp)
{
	if (array_exp)
		array_destroy(&array_exp, sh_exp_del);
}