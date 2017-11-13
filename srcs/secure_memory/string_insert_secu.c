/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_insert_secu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:38:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/16 16:59:57 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <secure_memory/ft_secu_malloc.h>

t_string	*string_insert_secu(t_string *string, const char *str, size_t pos, size_t lvl)
{
	size_t	len;

	if (!str)
		return (string);
	len = ft_strlen(str);
	if (!(string_growth_cap_secu(string, string->len + len, lvl)))
		return (NULL);
	if (pos <= string->len)
		ft_memmove(string->s + pos + len, string->s + pos, string->len - pos);
	ft_memcpy(string->s + pos, str, len);
	string->len += len;
	return (string);
}

t_string	*string_insert_front_secu(t_string *string, const char *str, size_t lvl)
{
	return (string_insert_secu(string, str, 0, lvl));
}

t_string	*string_insert_back_secu(t_string *string, const char *str, size_t lvl)
{
	return (string_insert_secu(string, str, string->len, lvl));
}
