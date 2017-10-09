/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_secu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:09:38 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/15 14:12:02 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>

char	*ft_strdup_secu(char const *src, size_t lvl)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(src);
	if ((dup = ft_strnew_secu(size, lvl)))
	{
		ft_memcpy(dup, src, size);
		return (dup);
	}
	return (NULL);
}
