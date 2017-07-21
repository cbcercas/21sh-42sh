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
	int i;

	i = 0;
	while (input[i] != '\0')
	{
		if (ft_isalnum(input[i]))
			;
		else
			return (0);
		i++;
	}
	return (1);
}

int is_input_at_first(char *input)
{
	(void)input;
	return (0);
}

int is_input_after_first(char *input)
{
	(void)input;
	return (0);
}

BOOL	exec_tab(const t_key *key, t_input *input)
{
	//char *last_word;
	//char **possibilities;

	(void)key;
	(void)input;
	if (is_input_empty(input->str->s) == 1)
		ft_printf("YA QQCH\n"); //user pressed tab without anything before
	else
		ft_printf("NOPE\n");
	if (is_input_at_first(input->str->s) == 1)
		; //user pressed tab with a command started
	if (is_input_after_first(input->str->s) == 1)
		; //user pressed tab after writing the first command
	//last_word = autoc_get_last(input->str->s);
	//possibilities = autoc_get_possibilities(last_word);
	//TODO: Savoir si c'est le premier mot, sans mot, ou deuxieme mot et + dans l'input
	//ft_print_array(possibilities);
	exec_ctrl_c(key, input);
	return (false);
}
