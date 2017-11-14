/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_alt_v.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:42:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/13 14:44:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

static BOOL	alt_v_limit_len(char *save)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = save;
	while (save[len] && save[len] != '\\')
		len ++;
	if ((len + input_get_cur()->str->len) >= MAX_LEN_INPUT)
		return (true);
	while (save)
	{
		tmp = save;
		save = ft_strchr(save, '\n');
		save++;
	}
	if ((input_get_last(input_get_cur())->str->len + ft_strlen(tmp)) >= MAX_LEN_INPUT)
		return (true);
	return (false);
}

static BOOL	alt_v_limit_nb(char *save)
{
	int		count;

	count = 0;
	if (!save)
		return (true);
	while ((save = ft_strchr(save, '\n')))
	{
		count++;
		save++;
	}
	if (MAX_NB_INPUT >= count)
		return (true);
	return (false);
}

static BOOL	alt_v_check_limit(char *save)
{
	if (alt_v_limit_nb(save) || alt_v_limit_len(save))
	{
		tputs(tgetstr("vb", NULL), 0, &ft_putchar2);
		tcaps_bell();
		return (false);
	}
	return (true);
}

static void	exec_alt_v_multi(t_input *input, char *save)
{
	char	*tmp;
	t_input		*next_save;
	size_t		len;

	len = 0;
	get_select()->str = ft_strjoincl(get_select()->str,
									 &input->str->s[pos_in_str(input)], 0);
	string_remove(input->str, pos_in_str(input), input->str->len);
	while (get_select()->str[len] && get_select()->str[len] != '\\')
		len ++;
	string_insert_back(input->str, tmp = ft_strsub(get_select()->str, 0, len));
	ft_strdel(&tmp);
	tmp = get_select()->str;
	get_select()->str = ft_strchr(get_select()->str, '\n') + 1;
	next_save = input->next;
	input->next = input_from_history(get_select()->str);
	if (next_save)
		next_save->prev = input_get_last(input);
	if (input->next)
		input->next->prev = input;
	input_get_last(input)-> next = next_save;
	redraw_input(input);
	ft_strdel(&tmp);
	get_select()->str = save;
	get_windows(0)->cur = input;
}

BOOL	exec_alt_v(const t_key *key, t_input *input)
{
	char	*save;

	(void)key;
	if (get_select()->is || !input || !input->str || !get_select()->str)
		return (false);
	save = get_select()->str;
	if (!alt_v_check_limit(save)) //TODO a checker sur les mac les limit d'input avec alt-v
		return (false);
	if (ft_strchr(get_select()->str, '\\'))
	{
		log_dbg3("copy multi");
		exec_alt_v_multi(input, save);
	}
	else
	{
		log_dbg3("copy simple");
		string_insert(input->str, get_select()->str, pos_in_str(input));
		redraw_input(input);
		return (false);
	}
	return (false);
}
