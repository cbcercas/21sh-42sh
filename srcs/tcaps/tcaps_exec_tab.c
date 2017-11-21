/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:47:05 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/04 11:53:45 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_tab(const t_key *key, t_input *input)
{
	char *current;

	if (get_select()->is)
		return (false);
	/*current = find_word_cur(input);
	(void) key;
		if (autocomplete_is_path(input))
			input = autocomplete(autocomplete_get_content_paths(autocomplete_get_path(current)), input);
		else
			input = autocomplete(autocomplete_get_bin(current), input);
		ft_secu_free_lvl(M_LVL_AUTOC);*/
		return (false);
}
