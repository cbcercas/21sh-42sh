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
#include <core/select.h>

BOOL	exec_tab(const t_key *key, t_input *input)
{
	char	*current;
	t_array	*arr;
	t_window	*wd;

	(void) key;
	wd = get_windows(0);
	if (get_select()->is) // TODO secure
		return (false);
	if (wd->autocomp)
	{
		if (!wd->autocomp->active)
		{
			get_windows(0)->autocomp->active = true;//TODO secure
			select_get_data()->disp.first->prev->cursor = true;//TODO secure
			tputs(tgetstr("do", NULL), 0, &ft_putc_in);
			tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
		}
		exec_arrow_right_select(select_get_data());
		return (false);
	}
	current = find_word_cur(input);
	if (autocomplete_is_path(input))
		arr = autocomplete_get_content_paths(autocomplete_get_path(current));
	else
		arr = autocomplete_get_bin(current);
	arr = autocomplete(arr, input);
	if (arr)
		select_select(1, get_data(NULL)->opts.color, arr);
	return (false);
}
