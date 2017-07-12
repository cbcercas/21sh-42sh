#include <expand/expand.h>

char 	find_first_quote(const char *str)
{
	int 	i;

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

void	expand_antislash(t_string *string)
{
	int 	i;

	i = -1;
	while (string->s[++i])
	{
		if (string->s[i] == '\\')
			string_remove_char(string, i);
	}
}

t_exp   *expand_remove_quote(t_exp *exp)
{
	t_string	string;
	char		*c;
	char 		quote;

	string_init(&string);
	if (!string_growth_cap(&string, ft_strlen(exp->str)))
		exit(1); // Are you sure????
	ft_strcpy(string.s, exp->str);
	string.len = ft_strlen(string.s);
	//remove '\'
	if (exp->type != E_TOKEN_SQUOTE)
		expand_antislash(&string);
	//remove the first of ' or "
	if ((quote = find_first_quote(string.s)) != 0)
		while ((c = ft_strchr(string.s, quote)))
			string_remove_char(&string, c - string.s);
	exp->str = string.s;
	return (exp);
}