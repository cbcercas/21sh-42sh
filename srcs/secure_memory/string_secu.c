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

#include <secure_memory/secure_memory.h>

/**
 * @brief Initializes securely a t_string
 *
 * @param string The t_string to be initialized
 * @param cap The size of the cap
 * @param lvl TODO
 *
 * @return Returns an initialized t_string
 */

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

/**
 * @brief Creates a cap for a t_string securely
 * @param cap TODO
 * @param lvl TODO
 * @return TODO
 */

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

/**
 * @brief Creates a t_string
 *
 * @param lvl TODO
 *
 * @return Returns a created and initialized t_string
 */

t_string	*string_create_secu(size_t lvl)
{
	return (string_create_cap_secu(1, lvl));
}
