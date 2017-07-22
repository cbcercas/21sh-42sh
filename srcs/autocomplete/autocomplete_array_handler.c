/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_array_handler.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:35 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/19 10:01:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <autocomplete/autocomplete.h>

void    autoc_add_to_array(char *to_add, t_array *array)
{
	if (!array)
		array = array_create(sizeof(char *));
	if (array)
		array_push(array, (void *)to_add);
}

char	*autoc_get_from_array_at(size_t pos, t_array *array)
{
	return ((char *)array_get_at(array, pos));
}

void autoc_array_print(t_array *array)
{
	size_t i;

	i = 0;
	while (i < array->used)
	{
		log_dbg3("%s", autoc_get_from_array_at(i, array));
		i++;
	}
}