/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_secu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:17:21 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/16 15:58:50 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <secure_memory/ft_secu_malloc.h>

char	*ft_str_insert_secu(char *src1, char *src2, int index, size_t lvl)
{
	char	*begin;
	char	*end;
	char	*ret;

	if (!src1 || ft_strlen(src1) < (size_t)(index + 1))
		return (src1);
	begin = ft_strnew_secu((index + 1), lvl);
	begin = ft_strncpy(begin, src1, index);
	end = ft_strjoincl_secu(src2, &src1[index], 0, lvl);
	ret = ft_strjoincl_secu(begin, end, 3, lvl);
	ft_secu_free(src1);
	return (ret);
}
