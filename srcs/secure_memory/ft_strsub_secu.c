/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_secu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 10:08:25 by gpouyat           #+#    #+#             */
/*   Updated: 2017/08/01 10:13:27 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <secure_memory/ft_secu_malloc.h>


char		*ft_strsub_secu(char const *s, unsigned int start, size_t len, size_t lvl)
{
	char	*str;

	if (len <= 0)
		return (ft_strnew_secu(0, lvl));
	str = ft_strnew_secu(len, lvl);
	if (s && str && ft_strlen(s) >= len)
		str = ft_strncpy(str, &s[start], len);
	return (str);
}
