/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_get_words.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:08:33 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/09 14:37:11 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>
#include <core/input.h>
#include <secure_memory/ft_secu_malloc.h>

int		nb_of_word(char *s)
{
	int i;
	int	count;

	i = 0;
	count = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (is_white(s[i]))
		{
			count++;
			while (is_white(s[i]))
				i++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

char	*find_word_after(t_input *input)
{
	char	*tmp;
	int		i;
	int		end;

	i = pos_in_str(input);
	tmp = NULL;
	while (!is_white(input->str->s[i]) && i != 0)
		i--;
	while (is_white(input->str->s[i]) && i != 0)
		i--;
	end = i;
	while (!is_white(input->str->s[i]) && i != 0)
		i--;
	if (!i)
		tmp = ft_strsub_secu(input->str->s, i, end - i + 1, M_LVL_AUTOC);
	else
		tmp = ft_strsub_secu(input->str->s, i + 1, end - i, M_LVL_AUTOC);
	return (tmp);
}

char	*find_word_cur(t_input *input)
{
	int		i;
	int		end;
	char	*tmp;

	if (!input || !input->str || !input->str->s)
		return (NULL);
	end = pos_in_str(input);
	i = end;
	if (!end)
		return (NULL);
	if (is_white(input->str->s[end]))
		i--;
	while (!is_white(input->str->s[i]) && i != 0)
		i--;
	if (!i && (end - i) > 0)
		tmp = ft_strsub_secu(input->str->s, i, end - i, M_LVL_AUTOC);
	else if ((end - i - 1) > 0)
		tmp = ft_strsub_secu(input->str->s, i + 1, end - i - 1, M_LVL_AUTOC);
	else
		return (NULL);
	return (tmp);
}

int		get_nb_word_cur(t_input *input)
{
	int		i;
	int		count;
	char	*s;

	s = input->str->s;
	i = pos_in_str(input);
	count = 1;
	if (!s)
		return (0);
	while (i)
	{
		if (is_white(s[i]))
		{
			count++;
			while (i && is_white(s[i]))
				i--;
		}
		if (i)
			i--;
	}
	return (count);
}

size_t	get_index_cur(t_input *input)
{
	size_t	i;

	if (!input || !input->str || !input->str->s)
		return (0);
	i = pos_in_str(input);
	if (!i || !input || !input->str || !input->str->s)
		return (i);
	if (is_white(input->str->s[i]) && is_white(input->str->s[i - 1]))
		return (i);
	if (is_white(input->str->s[i]))
		i--;
	while (!is_white(input->str->s[i]) && i != 0)
		i--;
	if (i)
		i++;
	return (i);
}
