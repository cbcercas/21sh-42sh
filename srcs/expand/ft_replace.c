/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:17:21 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/06 18:43:57 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

int		ft_replace_init(char *src1, char *src2, int index, int size)
{
	if (!src1 || ft_strlen(src1) < (index + 1))
		return (-1);
	if ((ft_strlen(&src1[index]) < size))
		return (-1);
	return (0);
}

char	*ft_replace_exp(char *src1, char *src2, int index, int size)
{
	char	*begin;
	char	*end;
	char	*ret;

	if (ft_replace_init(src1, src2, index, size))
		return (NULL);
	begin = ft_strnew((index + 1));
	begin = ft_strncpy(begin, src1, index);
	end = ft_strjoin(src2, &src1[index + size]);
	ret = ft_strjoin(begin, end);
	ft_strdel(&begin);
	ft_strdel(&end);
	// ft_strdel(&src1);
	return (ret);
}
