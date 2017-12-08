/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincl_secu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:45:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/09/16 15:54:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <secure_memory/secure_memory.h>

/*
** @brief TODO
** @param s1 TODO
** @param s2 TODO
** @param free TODO
** @param lvl TODO
** @return TODO
*/

char	*ft_strjoincl_secu(char *s1, char *s2, int free, size_t lvl)
{
	char	*s;
	size_t	ls1;
	size_t	ls2;

	ls1 = (s1) ? ft_strlen(s1) : 0;
	ls2 = (s2) ? ft_strlen(s2) : 0;
	if (s1 || s2)
	{
		s = ft_strnew_secu(ls1 + ls2 + 1, lvl);
		if (s)
		{
			if (s1)
				s = ft_strcpy(s, s1);
			if (s2)
				ft_strlcat(s, s2, ls1 + ls2 + 1);
		}
	}
	else
		return (NULL);
	((free == 1 || free == 3) && s1) ? ft_secu_free(s1) : 0;
	((free == 2 || free == 3) && s2) ? ft_secu_free(s2) : 0;
	return (s);
}
