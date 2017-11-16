/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:10:43 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/18 13:39:55 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

/*
** @brief Gets the env or local var value of a `name` named variable
** @param name The name of the variable you want
** @return Returns the value of var `name`
*/

char	*sh_getenv_exp(const char *name)
{
	char		*value;

	if ((value = get_var_value(get_envs(), name)))
		return (value);
	if ((value = get_var_value(get_vars(), name)))
		return (value);
	return (NULL);
}

/*
** @brief Checks if `c` is a `$`, `?` or `0`
**
** @param c The char to check
**
** @return Returns 1 if `c` is any of the three char, else returns 0
*/

int ft_is_spec(int c)
{
	return (c == '$' || c == '?' || c == '0');
}

/*
** @brief TODO
** @param str TODO
** @param i TODO
*/

void expand_dol_spec_replace(t_string *str, size_t *i)
{
	char	*tmp;
	BOOL	fri;

	fri = false;
	tmp = NULL;
	if (str->s[*i + 1] == '?' && (fri = true))
		tmp = ft_itoa(*get_cmd_ret());
	else if (str->s[*i + 1] == '0' && !(fri = false))
		tmp = PROGNAME;
	else if (str->s[*i + 1] == '$' && (fri = true))
		tmp = ft_itoa(getpid());
	if (tmp)
	{
		str->s = ft_replace_exp(str->s, tmp, *i, 2);
		*i += ft_strlen(tmp);
	}
	(fri && tmp) ? ft_strdel(&tmp) : 0;
}

/*
** @brief Replaces in `str` from `i` for `len` size a variable
**
** @param str String to be changed
** @param len For how long to change
** @param i Where to start
*/

void expand_dol_replace(t_string *str, int len, size_t *i)
{
	char	car_tmp;
	char	*tmp;

	car_tmp = str->s[*i + 1 + len];
	str->s[*i + 1 + len] = 0;
	tmp = sh_getenv_exp(&str->s[*i + 1]);
	str->s[*i + 1 + len] = car_tmp;
	if (tmp)
		str->s = ft_replace_exp(str->s, tmp, *i, len + 1);
	else
		str->s = ft_replace_exp(str->s, "", *i, len + 1);
	*i += ft_strlen(tmp);
}

/*
** @brief Expands the $
** @param str String to be expanded
*/

void expand_dol(t_string *str)
{
	size_t			i;
	int			len;
	char		*tmp;

	i = 0;
	while (str->s[i])
	{
		len = 0;
		if (str->s[i] == '\\' && str->s[i + 1])
			i += 2;
		if (str->s[i] == '$' && str->s[i + 1])
		{
			while(str->s[i + 1 + len] && ft_isalnum(str->s[i + 1 + len]))
				len++;
			ft_is_spec(str->s[i + 1])? expand_dol_spec_replace(str, &i) :
			expand_dol_replace(str, len, &i);
		}
		else if (str->s[i] == '~' && ((tmp = get_var_value(get_envs(),
						   "HOME")) || (tmp =
										  get_var_value(get_vars(), "HOME"))))
			str->s = ft_replace_exp(str->s, tmp, i, 1);
		else
			i++;
	}
	str->len = ft_strlen(str->s);
}
