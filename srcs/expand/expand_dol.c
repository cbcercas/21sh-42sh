/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:10:43 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/08 14:05:49 by gpouyat          ###   ########.fr       */
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

int ft_is_spec(int c)
{
	return (c == '$' || c == '?' || c == '0');
}

void expand_dol_spec_replace(t_exp *exp, int len, int *i)
{
	char	*tmp;
	BOOL	fri;

	fri = false;
	tmp = NULL;
	if (exp->str.s[*i + 1] == '?' && !(fri = false))
		tmp = "0";// TODO: faire quand exec termine, avec global
	else if (exp->str.s[*i + 1] == '0' && !(fri = false))
		tmp = PROGNAME;
	else if (exp->str.s[*i + 1] == '$' && (fri = true))
		tmp = ft_itoa(getpid());
	if (tmp)
	{
		exp->str.s = ft_replace_exp(exp->str.s, tmp, *i, 2);
		*i += ft_strlen(tmp);
	}
	(fri && tmp) ? ft_strdel((char **)&tmp) : 0;
}

void expand_dol_replace(t_exp *exp, int len, int *i)
{
	char	car_tmp;
	char	*tmp;

	car_tmp = exp->str.s[*i + 1 + len];
	exp->str.s[*i + 1 + len] = 0;
	tmp = sh_getenv_exp(&exp->str.s[*i + 1]);
	exp->str.s[*i + 1 + len] = car_tmp;
	if (tmp)
		exp->str.s = ft_replace_exp(exp->str.s, tmp, *i, len + 1);
	else
		exp->str.s = ft_replace_exp(exp->str.s, "", *i, len + 1);
	*i += ft_strlen(tmp);
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
	while (exp->str.s[i])
	{
		  len = 0;
		if (exp->str.s[i] == '$' && (ft_isalnum(exp->str.s[i + 1]) ||\
		 ft_is_spec(exp->str.s[i + 1])) && (i == 0 || exp->str.s[i - 1] != '\\'))
		{
      while(exp->str.s[i + 1 + len] && ft_isalnum(exp->str.s[i + 1 + len]))
        len++;
			(ft_is_spec(exp->str.s[i + 1])) ? expand_dol_spec_replace(exp, len, &i) :\
			 expand_dol_replace(exp, len, &i);
		}
		else if (exp->str.s[i] == '~' && (tmp = sh_getenv_value("HOME")) &&\
		 				(i == 0 || exp->str.s[i - 1] != '\\') )
			exp->str.s = ft_replace_exp(exp->str.s, tmp, i, 1);
		else
			i++;
	}
}
