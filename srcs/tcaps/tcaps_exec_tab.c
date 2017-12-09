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

static BOOL	exec_tab_select(t_sel_data *data)
{
	if (!data->active)
	{
		data->active = true;
		if (data->words && data->words->prev)
			data->words->prev->cursor = true;
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
		tputs(tgetstr("vi", NULL), 0, &ft_putc_in);
	}
	exec_arrow_right_select(data);
	return (false);
}

static BOOL	exec_tab_one(char *cur, t_array *arr, t_window *wd)
{
	t_string	*string;
	size_t		len;

	string = array_get_at(arr, 0);
	if (!cur)
		return (false);
	len = ft_strlen(cur) - autocomplete_len_useless(cur);
	if (string->len > len)
	{
		if (!string_insert(wd->cur->str, string->s + len, pos_in_str(wd->cur)))
			return (false);
		redraw_input(wd->cur);
		while (len--)
			exec_arrow_right_normal(wd);
	}
	else
		tcaps_bell();
	array_destroy(&arr, (void *(*)(void *))&string_clear);
	return (false);
}

BOOL		exec_tab(const t_key *key, t_window *wd)
{
	char	*current;
	t_array	*arr;

	(void)key;
	if (wd->select.is
		|| !wd->cur || !wd->cur->str || !wd->cur->str->len)
		return (false);
	if (wd->autocomp)
		return (exec_tab_select(wd->autocomp));
	current = find_word_cur(wd->cur);
	if (autocomplete_is_path(wd->cur))
		arr = autocomplete_get_content_paths(autocomplete_get_path(current));
	else
		arr = autocomplete_get_bin(current);
	arr = autocomplete(arr, wd->cur);
	if (arr && arr->used > 1)
		select_select(1, get_data(NULL)->opts.color, arr, current);
	else if (arr)
		exec_tab_one(current, arr, wd);
	else
		tcaps_bell();
	ft_strdel(&current);
	return (false);
}
