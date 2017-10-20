/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_growth_secu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:38:33 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/16 16:51:08 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>
#include <ft_secu_malloc/ft_secu_malloc.h>

t_string	*string_growth_cap_secu(t_string *string, size_t cap, size_t lvl)
{
	char	*new_string;
	size_t	new_cap;

	new_cap = (cap / ARRAY_MIN_SIZE + 1) * ARRAY_MIN_SIZE;
	if (new_cap < string->capacity)
		return (string);
	if (!(new_string = ft_secu_malloc_lvl(new_cap, lvl)))
		return (NULL);
	new_string = ft_memcpy(new_string, string->s, string->len);
	ft_secu_free(string->s);
	string->s = new_string;
	string->capacity = new_cap;
	return (string);
}

t_string	*string_growth_secu(t_string *string, size_t lvl)
{
	return (string_growth_cap_secu(string, string->capacity + 1, lvl));
}
