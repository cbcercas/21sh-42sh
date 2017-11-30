/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_escape_enter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiforge <guiforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:48:52 by guiforge          #+#    #+#             */
/*   Updated: 2017/11/30 15:48:53 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_escape_enter(const t_key *key, t_input *input)
{
	char	*after_cur;
	t_cpos		dest;

	if (!input || get_windows(0)->select.is)
		return (false);
	(void)key;
	after_cur = NULL;
	if (input->str && input->str->len)
	{
		after_cur = ft_strdup(&input->str->s[pos_in_str(input)]);
		string_remove(input->str, (size_t)pos_in_str(input), input->str->len);
		input_draw(input);
	}
	tputs(tgetstr("do", NULL), 0, &ft_putc_in);
	tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
	tputs(tgetstr("cd", NULL), 0, &ft_putc_in);
	input_add_new(input);
	get_windows(0)->cur = input->next;
	get_windows(0)->cur->prompt_type = input->prompt_type;
	string_insert_back(get_windows(0)->cur->str, after_cur);
	ft_strdel(&after_cur);
	input_draw(get_windows(0)->cur);
	return (false);
}