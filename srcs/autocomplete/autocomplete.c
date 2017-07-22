/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:35 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/19 10:01:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

t_array	*autoc_create_array(void)
{
	static t_array	*e = NULL;
	if (e == NULL)
	{
		if ((e = array_create(sizeof(char *))) == NULL)
		{
			log_fatal("Autocomplete: can't initialise autocomplete array");
			ft_dprintf(STDERR_FILENO, "Autocomplete: can't initialise autocomplete");
			exit(1);
		}
	}
	return (e);
}

char *autoc_get_last_word(char *current_input)
{
	char *last_word;
	size_t len;
	size_t i;
	size_t last_word_len;
	size_t nb_spaces;

	last_word_len = 0;
	nb_spaces = 0;
	if (current_input == NULL || current_input[0] == '\0')
		return (NULL);
	len = ft_strlen(current_input);
	i = len - 1;
	while (current_input[i] == ' ' && i > 0)
	{
		i--;
		nb_spaces++;
	}
	while (ft_isalnum(current_input[i]) == 1)
	{
		last_word_len++;
		i--;
	}
	last_word = ft_strsub(current_input, len - last_word_len - nb_spaces, last_word_len);
	return (last_word);
}