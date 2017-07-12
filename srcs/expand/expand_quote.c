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
	while ((c = ft_strchr(string.s, '\\')))
		string_remove_char(&string, c - string.s);
	//remove the first of ' or "
	if ((quote = find_first_quote(string.s)) != 0)
		while ((c = ft_strchr(string.s, quote)))
			string_remove_char(&string, c - string.s);
	exp->str = string.s;
	return (exp);
}