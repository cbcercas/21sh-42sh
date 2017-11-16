/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_secu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 10:06:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/08/01 10:08:03 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <secure_memory/secure_memory.h>

/*
** @brief Securely creates a new string of size `size`
**
** @param size Size of new string
** @param lvl TODO
**
** @return Returns a newly created string of size `size` filled up with \0
*/

char	*ft_strnew_secu(size_t size, size_t lvl)
{
	char *str;

	str = (char *)ft_secu_malloc_lvl(size + 1, lvl);
	if (str != NULL)
		ft_bzero(str, size + 1);
	return (str);
}
