/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_display_cols.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:28:14 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/10 16:33:35 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>
#include <string/ft_string.h>
#include <libtcaps.h>

static size_t		autocomplete_find_longest_word(t_array *content)
{
	size_t		i;
	t_string	*string;
	size_t			len;

	i = 0;
	len = 0;
	if (!content || !content->used)
		return (0);
	while (content->used > i && (string = (t_string *)array_get_at(content, i)))
	{
		if (string->len > len)
			len = string->len;
		i++;
	}
	return (len);
}

static int		autocomplete_nb_of_col(size_t len)
{
	t_ts	ts;

	if (!len)
		return (0);
	ts = get_term_size();
	return ((ts.ts_cols / (len + 2)));
}

static char	*autocomplete_remove_path(t_string *string)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!string || !string->s)
		return ("");
	if (!ft_strchr(string->s, '/'))
		return (string->s);
	ret = string->s;
	while (string->s[i] && i < string->len - 2)
	{
		if (string->s[i] == '/')
			ret = &string->s[i + 1];
		i++;
	}
	return (ret);
}

static void	display_one(t_array *content, size_t pos, size_t size)
{
	size_t		len;
	char		*str;
	t_string	*string;

	if (!content)
		return ;
	string = (t_string *)array_get_at(content, pos);
	if (!string || !string->len || !string->s)
		return ;
	str = autocomplete_remove_path(string);
	len = str ? ft_strlen(str) : 0;
	if (size >= len + 2)
		size = size - len + 2;
	else
		size = 0;
	ft_putstr(str);
	while(size-- > 0)
		ft_putchar(' ');
}

void	autocomplete_display_cols(t_array *content)
{
	int		nb_col;
	size_t	len;
	int		cnt_col;
	size_t	i;

	i = 0;
	cnt_col = 0;
	if (!content)
		return ;
	len = autocomplete_find_longest_word(content);
	nb_col = autocomplete_nb_of_col(len);
	if (nb_col < 2)
		nb_col = 2;
	while (i < content->used)
	{
		cnt_col = 0;
		while (cnt_col++ < nb_col && i < content->used)
			display_one(content, i++, len);
		ft_putchar('\n');
	}
}
