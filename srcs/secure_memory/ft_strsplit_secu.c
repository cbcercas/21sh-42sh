/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_secu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 09:59:19 by gpouyat           #+#    #+#             */
/*   Updated: 2017/08/01 10:10:46 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <secure_memory/ft_secu_malloc.h>


char		**ft_strsplit_secu(char const *s, char c, size_t lvl)
{
	char	**tab;
	size_t	nb[3];

	if (!s || !c)
		return (NULL);
	nb[0] = ft_nbword(s--, c);
	nb[1] = 0;
	tab = (char **)ft_secu_malloc_lvl(sizeof(*tab) * (nb[0] + 1), lvl);
	if (tab)
	{
		while (*++s != '\0')
			if (*s != c && *s != '\0')
			{
				nb[2] = ft_wordlen(s, c);
				tab[nb[1]] = ft_strsub_secu((char *)s, 0, nb[2], lvl);
				if (!tab[nb[1]++])
					return (NULL);
				s += nb[2] - 1;
			}
		tab[nb[1]] = NULL;
	}
	return (tab);
}
