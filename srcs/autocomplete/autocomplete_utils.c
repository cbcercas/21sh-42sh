#include <stddef.h>
#include <libft.h>
#include <autocomplete/autocomplete.h>

int autocomplete_case_compare(const char s1, const char s2)
{
	return (ft_toupper(s1) == ft_toupper(s2));
}

int		autocomplete_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while ((autocomplete_case_compare(*s1, *s2)) && (*s1 != '\0' || *s2 != '\0') && (--n > 0))
	{
		s1++;
		s2++;
	}
	if (ft_toupper(*s1) == ft_toupper(*s2))
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int		autocomplete_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2 && n && autocomplete_strncmp(s1, s2, n))
		return (0);
	return (1);
}

BOOL autocomplete_is_dots(const char *s)
{
	if (!s)
		return (false);
	if (ft_strequ(s, ".") || ft_strequ(s, ".."))
		return (true);
	return (false);
}

BOOL	autocomplete_get_repons(size_t possibilities)
{
	char	buff[MAX_KEY_STRING_LEN];
	int		res;

	if (possibilities <= 42)
		return (true);
	default_terminal_mode();
	if (possibilities >= 3000)
	{
		ft_printf("\n%s: too many (%d possibilities)", PROGNAME,\
				possibilities);
		return (false);
	}
	ft_printf("\n%s: do you wish to see all %d possibilities ?", PROGNAME,\
			possibilities);
	raw_terminal_mode();
	(void)ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
	res = read(STDIN_FILENO, buff, MAX_KEY_STRING_LEN);
	buff[res] = '\0';
	if (!ft_strcmp(buff, "y") || !ft_strcmp(buff, KEY_CODE_TAB))
		return (true);
	default_terminal_mode();
	ft_printf("\n");
	autocomplete_display_prompt(g_input);
	raw_terminal_mode();
	return (false);
}
