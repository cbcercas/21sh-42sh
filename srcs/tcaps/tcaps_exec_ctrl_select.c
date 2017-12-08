/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_select.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:47:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 14:30:38 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL exec_ctrl_j_select(t_window *wd)
{
	t_sel_word	*word;
	size_t		len;

	word = word_get_current();
	if (!string_insert(wd->cur->str, word->word + wd->autocomp->cur_word, pos_in_str(wd->cur)))
		return (false);
	len = ft_strlen(word->word);
	exec_escape_select(wd);
	redraw_input(wd->cur);
	while (len--)
		exec_arrow_right_normal(wd);
	get_windows(100);
	return (false);
}
