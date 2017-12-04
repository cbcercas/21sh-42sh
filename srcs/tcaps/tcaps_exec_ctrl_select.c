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

BOOL exec_ctrl_j_select(t_input *input)
{
	t_sel_word	*word;
	size_t		len;

	word = word_get_current();
	if (!string_insert(input->str, word->word, pos_in_str(input)))
		return (false);
	len = ft_strlen(word->word);
	exec_escape_select();
	redraw_input(input);
	while (len--)
		exec_arrow_right(NULL, input);
	return (false);
}
