/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:47:05 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/19 10:02:00 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

int is_input_empty(char *input)
{
	if (input == NULL)
		return (1);
	else if (input[0] == '\0')
		return (1);
	else
		return (0);
}
int is_input_at_first(char *input)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(input);

	while (input[i] != '\0' && i <= len)
	{
		if (input[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int is_input_after_first(char *input)
{
	size_t len;
	size_t i;
	size_t j;

	len = ft_strlen(input);
	i = 0;

	while (input[i] != '\0')
	{
		if (input[i] == ' ')
		{
			j = i;
			while (input[j] == ' ')
				j--;
			if (ft_isalnum(input[j]) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

BOOL	exec_tab(const t_key *key, t_input *input)
{
	(void)key;
	(void)input;
	if (is_input_empty(input->str->s) == 1)
		; //user pressed tab without anything before
	if (is_input_at_first(input->str->s) == 1)
		; //user pressed tab with a command started
	if (is_input_after_first(input->str->s) == 1)
		; //user pressed tab after writing the first command
	ft_printf("\n|%s|\n", autoc_get_last_word(input->str->s));
	//TODO: Savoir si c'est le premier mot, sans mot, ou deuxieme mot et + dans l'input
	return (false);
}
