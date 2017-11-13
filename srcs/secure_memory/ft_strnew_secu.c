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
#include <secure_memory/ft_secu_malloc.h>



char	*ft_strnew_secu(size_t size, size_t lvl)
{
	char *str;

	str = (char *)ft_secu_malloc_lvl(size + 1, lvl);
	if (str != NULL)
		ft_bzero(str, size + 1);
	return (str);
}
