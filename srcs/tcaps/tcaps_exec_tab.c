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

static BOOL	exec_tab_select(t_sel_data *data)
{
	if (!data->active)
	{
		data->active = true;
		if (data->disp.first && data->disp.first->prev)
			data->disp.first->prev->cursor = true;
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
		tputs(tgetstr("vi", NULL), 0, &ft_putc_in);
	}
	exec_arrow_right_select(data);
	return (false);
}

static BOOL	exec_tab_one(char *cur, t_array *arr, t_input *input)
{
	t_string	*string;
	size_t		len;

	string = array_get_at(arr, 0);
	if (!cur)
		return (false);
	len = ft_strlen(cur);
	if (string->len > len)
	{
		if (!string_insert(input->str, string->s + len, pos_in_str(input)))
			return (false);
	}
	else
		tcaps_bell();
	array_destroy(&arr, &string_clear);
	return (false);
}

BOOL	exec_tab(const t_key *key, t_input *input)
{
	char	*current;
	t_array	*arr;
	t_window	*wd;

	(void) key;
	if (!(wd = get_windows(0)) || wd->select.is
		|| !input || !input->str || !input->str->len)
		return (false);
	if (wd->autocomp)
		return (exec_tab_select(wd->autocomp));
	current = find_word_cur(input);
	if (autocomplete_is_path(input))
		arr = autocomplete_get_content_paths(autocomplete_get_path(current));
	else
		arr = autocomplete_get_bin(current);
	arr = autocomplete(arr, input);
	if (arr && arr->used > 1)
		select_select(1, get_data(NULL)->opts.color, arr, current);
	else if (arr)
		exec_tab_one(current, arr, input);
	else
		tcaps_bell();
	ft_strdel(&current);
	return (false);
}
