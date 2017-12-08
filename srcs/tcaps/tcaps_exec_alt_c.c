/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_alt_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:42:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/13 14:44:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

static void		alt_c_end(t_input *tmp, char *str, size_t start, size_t end)
{
	if (tmp && tmp->select_pos.is_set)
	{
		start = tmp->select_pos.cur_start;
		end = tmp->select_pos.cur_end;
		if (start < end)
			str = ft_strjoincl(str, ft_strsub(tmp->str->s,
										(unsigned int)start, end - start), 3);
		else if (start > end)
			str = ft_strjoincl(str, ft_strsub(tmp->str->s,
										(unsigned int)end, start - end), 3);
	}
	ft_strdel(&get_select()->str);
	get_select()->str = str;
	log_info("copie str =[%s]", str);
}

static t_input	*alt_c_mid(t_input *tmp, char **str, size_t start, size_t end)
{
	if (tmp->next && tmp->next->select_pos.is_set && tmp->next->str->len)
		*str = ft_strjoincl(*str, "\\\n", 1);
	tmp = tmp->next;
	while (tmp && tmp->select_pos.is_set && tmp->next &&
			tmp->next->select_pos.is_set)
	{
		if ((start - end))
		{
			if (!(*str = ft_strjoincl(*str, tmp->str->s, 1)))
				return (NULL);
			if ((tmp->next && tmp->next->str->len)
				&& !(*str = ft_strjoincl(*str, "\\\n", 1)))
				return (NULL);
			tmp = tmp->next;
		}
	}
	return (tmp);
}

BOOL			exec_alt_c(const t_key *key, t_window *wd)
{
	t_input		*tmp;
	char		*str;
	size_t		start;
	size_t		end;

	(void)key;
	if (wd->autocomp && wd->autocomp->active)
		return (false);
	else if (wd->autocomp)
		get_windows(100);
	if (!get_select()->is)
		return (false);
	str = NULL;
	tmp = get_windows(0)->cur_head;
	while (tmp && !tmp->select_pos.is_set)
		tmp = tmp->next;
	if (!tmp)
		return (false);
	start = tmp->select_pos.cur_start;
	end = tmp->select_pos.cur_end;
	if (start < end)
		str = ft_strsub(tmp->str->s, (unsigned int)start, end - start);
	else if (start > end)
		str = ft_strsub(tmp->str->s, (unsigned int)end, start - end);
	tmp = alt_c_mid(tmp, &str, start, end);
	alt_c_end(tmp, str, start, end);
	return (false);
}
