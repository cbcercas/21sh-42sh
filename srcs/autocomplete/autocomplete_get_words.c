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

#include <autocomplete/autocomplete.h>

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
	ssize_t		i;
	ssize_t		end;

	i = pos_in_str(input);
	while (!is_white(input->str->s[i]) && i != 0)
		i--;
	while (is_white(input->str->s[i]) && i != 0)
		i--;
	end = i;
	while (!is_white(input->str->s[i]) && i != 0)
		i--;
	if (!i)
		tmp = ft_strsub(input->str->s, (unsigned int)i, (size_t)end - i + 1);
	else
		tmp = ft_strsub(input->str->s, (unsigned int)i + 1, (size_t)end - i);
	return (tmp);
}

char	*find_word_cur(t_input *input)
{
	size_t		i;
	size_t		end;
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
		tmp = ft_strsub(input->str->s, (unsigned int)i, end - i);
	else if ((end - i - 1) > 0)
		tmp = ft_strsub(input->str->s, (unsigned int)i + 1, end - i - 1);
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
