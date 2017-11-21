/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

/*
** @brief Searches the string `str` to find a `'` or `"`
** @param str String to be searched
** @return Returns the first `'` or `"` it'll find
*/

char	find_first_quote(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			return (str[i]);
		else if (str[i] == '"')
			return (str[i]);
	}
	return (0);
}

/*
** @brief Expands the `\`
**
** @param string String to be expanded
** @param type The type of the current token (?TODO)
**
** @return Returns true if ignored, false otherwise
*/

BOOL	expand_antislash(t_string *string, t_token_type type)
{
	int		i;
	BOOL	ignore;

	ignore = false;
	i = -1;
	while (string->s[++i])
	{
		if (string->s[i] == '\\' && (string->s[i + 1] == '\\' ||
						string->s[i + 1] == '\'' || string->s[i + 1] == '\"'))
		{
			if (string->s[i + 1] != '\\')
				ignore = true;
			string_remove_char(string, i);
			i++;
		}
		if (type == E_TOKEN_WORD)
			if (string->s[i] == '\\' && string->s[i + 1] != '\\')
				string_remove_char(string, i);
	}
	return (ignore);
}

t_exp	*expand_remove_quote(t_exp *exp)
{
	char		*c;
	char		quote;
	BOOL		ignore;

	ignore = false;
	if (exp->type != E_TOKEN_SQUOTE)
		ignore = expand_antislash(exp->str, exp->type);
	if (ignore == false)
	{
		if ((quote = find_first_quote(exp->str->s)) != 0)
			while ((c = ft_strchr(exp->str->s, quote)))
				string_remove_char(exp->str, c - exp->str->s);
	}
	if (exp->type == E_TOKEN_SQUOTE || exp->type == E_TOKEN_DQUOTE)
		exp->type = E_TOKEN_WORD;
	return (exp);
}
