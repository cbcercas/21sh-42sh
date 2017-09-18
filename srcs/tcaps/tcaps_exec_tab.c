/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:47:05 by jlasne            #+#    #+#             */
/*   Updated: 2017/09/18 21:09:43 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>
#include <autocomplete/autocomplete.h>

BOOL	exec_tab(const t_key *key, t_input *input)
{
	char *current;

	clean_term();
	current = find_word_cur(input);
	(void) key;
	(void) input;
		if (is_path(input))
			input = autocomplete(get_content_paths(get_path(current)), input);
		else
			input = autocomplete(get_bin(current), input);
		ft_secu_free_lvl(M_LVL_AUTOC);
		return (false);
}
