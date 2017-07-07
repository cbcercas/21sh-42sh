/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:10:43 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/08 00:10:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

char	*sh_getenv_exp(const char *name)
{
	t_array	*envs;
	t_env	*e;
	size_t	i;

	i = 0;
	envs = sh_get_envs();
	while (i < envs->used)
	{
		e = (t_env *)array_get_at(envs, i);
		if (e->name && ft_strequ(e->name, name))
			return (e->value);
		i++;
	}
	return (NULL);
}

void expand_dol_replace(t_exp *exp, int len, int *i)
{
	char	car_tmp;
	char	*tmp;

	car_tmp = exp->str[*i + 1 + len];
	exp->str[*i + 1 + len] = 0;
	tmp = sh_getenv_exp(&exp->str[*i + 1]);
	exp->str[*i + 1 + len] = car_tmp;
	if (tmp)
		exp->str = ft_replace_exp(exp->str, tmp, *i, len + 1);
	else
		exp->str = ft_replace_exp(exp->str, "", *i, len + 1);
	i += ft_strlen(tmp);
}

void expand_dol(t_exp *exp)
{
	int			i;
  int     len;
  char    *tmp;

	i = 0;
  len = 0;
  if (exp->type != E_TOKEN_WORD && exp->type != E_TOKEN_DQUOTE)
    return ;
	while (exp->str[i])
	{
		if (exp->str[i] == '$' && exp->str[i + 1] &&\
		 		(i == 0 || exp->str[i - 1] != '\\'))
		{
      while(exp->str[i + 1 + len] && ft_isalnum(exp->str[i + 1 + len]))
        len++;
      if (len >= 1)
				expand_dol_replace(exp, len, &i);
		}
		else if (exp->str[i] == '~' && (tmp = sh_getenv_value("HOME")) &&\
		 				(i == 0 || exp->str[i - 1] != '\\') )
			exp->str = ft_replace_exp(exp->str, tmp, i, 1);
		else
			i++;
	}
}
