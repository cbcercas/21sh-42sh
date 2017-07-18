/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:35 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 16:38:41 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

char *autoc_get_last(char *current_input)
{
	char *last_word;
	size_t input_len;
	size_t i;
	size_t j;

	j = 0;
	input_len = ft_strlen(current_input);
	i = input_len - 1;
	while (ft_isalnum(current_input[i]) == 1)
	{
		j++;
		i--;
	}
	last_word = ft_strsub(current_input, input_len - j, j);
	return (last_word);
}