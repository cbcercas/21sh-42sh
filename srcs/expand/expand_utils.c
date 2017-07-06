/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiforge <guiforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:43:08 by guiforge          #+#    #+#             */
/*   Updated: 2017/07/06 15:33:25 by guiforge         ###   ########.fr       */
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

t_exp *exp_create_new(t_token *tok)//etape 1 on dublique
{
  t_exp	*exp;

  if (!tok || !tok->str || !(exp = (t_exp*)malloc(sizeof(t_exp))))
    return (NULL);
  exp->type = tok->type;
  exp->str = ft_strsub(tok->str, 0, tok->len);//malloc à la bonne taille
  return (exp);
}

void sh_exp_del(void *i)
{
	t_exp *exp;

	exp = (t_exp *)i;
	if (exp && exp->str)
		ft_strdel(&(exp->str));
}

void sh_expand_destroy(t_array *array_exp)
{
	if (array_exp)
		array_destroy(&array_exp, sh_exp_del);
}