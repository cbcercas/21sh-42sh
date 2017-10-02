/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:18:31 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/15 17:11:53 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

BOOL is_command(t_input *input)
{
	int nb_word;
	char *tmp;

	tmp = NULL;
	if (!input || !input->str || !input->str->s)
		return (true);
  if (!pos_in_str(*input) || get_nb_word_cur(input) == 1)
    return (true);
	nb_word = nb_of_word(input->str->s);
	if (nb_word == 1)
		return (true);
	else if (nb_word > 1)
		tmp = find_word_after(input);
	if (!tmp || !ft_strlen(tmp) || ft_strequ(tmp, "&&") || ft_strequ(tmp, "||")\
	 				|| ft_strequ(tmp, ";") || ft_strequ(tmp, "|") || ft_strequ(tmp, "&"))
		return (true);
	return (false);
}

BOOL is_path(t_input *input)
{
	char *tmp;

	if (!input || !input->str || !input->str->s)
		return (false);
	tmp = find_word_cur(input);
	if  (tmp && ft_strchr(tmp, '/'))
		return (true);
	if (is_command(input) == true)
		return (false);
	return (true);
}
