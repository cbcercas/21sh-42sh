#include <expand/expand.h>

char 	find_first_quote(const char *str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			ft_putchar(str[i]);
			return (str[i]);
		}
		else if (str[i] == '"')
		{
			ft_putchar(str[i]);
			return (str[i]);
		}
		i++;
	}
	return (0);
}

void	expand_antislash(t_string *string)
{
	int 	i;

	i = 0;
	while (string->s[i + 1])
	{
		if (string->s[i] == '\\' && string->s[i + 1] == '\\')
		{
			ft_printf("removed\n");
			string_remove_char(string, i + 1);
		}
		i++;
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