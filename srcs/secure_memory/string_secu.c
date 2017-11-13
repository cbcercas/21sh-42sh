/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_secu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:38:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/16 16:51:21 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <secure_memory/ft_secu_malloc.h>

t_string	*string_init_cap_secu(t_string *string, size_t cap, size_t lvl)
{
	string->capacity = cap;
	if (string->capacity < STRING_MIN_SIZE)
		string->capacity = STRING_MIN_SIZE;
	if (!(string->s = ft_strnew_secu(string->capacity, lvl)))
		return (string_del(&string));
	string->len = 0;
	return (string);
}

t_string	*string_create_cap_secu(size_t cap, size_t lvl)
{
	t_string	*string;
	size_t		new_cap;

	new_cap = (cap / STRING_MIN_SIZE + 1) * STRING_MIN_SIZE;
	if (!(string = ft_secu_malloc_lvl(sizeof(*string), lvl)))
		return (NULL);
	if (!(string = string_init_cap_secu(string, new_cap, lvl)))
	{
		ft_secu_free(string);
		return (NULL);
	}
	return (string);
}

t_string	*string_create_secu(size_t lvl)
{
	return (string_create_cap_secu(1, lvl));
}
