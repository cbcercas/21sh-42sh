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
