/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:17:21 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/18 13:38:25 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

/*
** @brief Replaces in string `scr1` from `index` and during `size` with `scr2`
**
** @param src1 String to be modified
** @param src2 String used to modify
** @param index where to start
** @param size For how long to modify
**
** @return Returns the mofified string
*/

t_string	*ft_replace_str(t_string *str, char *src, size_t pos, size_t len)
{
	if (!src)
		return (str);
	string_remove(str, pos, len);
	string_insert(str, src, pos);
	return (str);
}