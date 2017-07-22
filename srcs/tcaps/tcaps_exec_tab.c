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
int is_input_at_first_word(char *input)
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

int is_input_after_first_word(char *input)
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

int is_input_at_options(char *input)
{
	size_t len;

	if (!input)
		return (0);
	len = ft_strlen(input);
	if (len == 0)
		return (0);
	if (input[len - 1] == '-')
		return (1);
	return (0);
}

BOOL	exec_tab(const t_key *key, t_input *input)
{
	char *last_word;
	t_array *possibilities;

	log_dbg1("Autocomplete: User pressed tab.");
	log_dbg2("Autocomplete: User input when tab was pressed is |%s|", input->str->s);
	(void) key;
	possibilities = array_create(sizeof(char *));
	last_word = autoc_get_last_word(input->str->s);
	log_dbg3("Autocomplete: Last word from input is |%s|", last_word);
	if (is_input_empty(input->str->s) == 1)
	{
		log_dbg2("Autocomplete: User pressed tab when input was empty."); //user pressed tab without anything before = ALL CMD
		possibilities = autoc_get_binaries();
	}
	else if (is_input_at_first_word(input->str->s) == 1)
	{
		log_dbg2("Autocomplete: User pressed tab when input was at first word."); //user pressed tab with a command started = CMD
		possibilities = autoc_get_binaries();
	}
	if (is_input_at_options(input->str->s) == 1)
	{
		log_dbg2("Autocomplete: User pressed tab when input was at options (-)."); //user pressed tab after writing a '-'
		//TODO: go fetch the options
	}
	else if (is_input_after_first_word(input->str->s) == 1)
	{
		log_dbg2("Autocomplete: User pressed tab when input was after the first word."); //user pressed tab after writing the first command = DIR
		possibilities = autoc_get_dir_content("./");
	}
	autoc_array_print(possibilities);
	return (false);
}
