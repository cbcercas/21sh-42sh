/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:47:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/31 14:28:45 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/select.h>
#include <sys/stat.h>

static t_sel_word	*word_list_add(t_sel_word **list, t_sel_word *word)
{
	if (!word)
		return (NULL);
	if (!(*list))
	{
		*list = word;
		//word->cursor = true;
	}
	else
	{
		(*list)->next = word;
		word->prev = *list;
		word->num = (*list)->num + 1;
	}
	return (word);
}

static t_sel_word *word_new(const char *word)
{
	t_sel_word	*e;
	struct stat st;

	if (!(e = ft_memalloc(sizeof(*e))))
	{
		select_exit("Malloc failed... Exiting!");
		return (NULL);
	}
	if(stat(word, &st) == 0)
		ft_memmove(&e->st_mode, &st.st_mode, sizeof(st.st_mode));
	e->word = word;
	e->len = ft_strlen(word);
	e->prev = NULL;
	e->next = NULL;
	e->num = 0;
	e->select = false;
	e->cursor = false;
	return (e);
}

t_sel_word			*word_list_destroy(t_sel_word **list)
{
	if ((*list)->next && (*list)->next->num)
		word_list_destroy(&(*list)->next);
	ft_memdel((void**)list);
	return (NULL);
}

t_sel_word			*word_list_create(t_array *words)
{
	t_string	*word;
	char		*str;
	t_sel_word	*list;
	t_sel_word	*last;
	size_t		i;

	i = 0;
	list = NULL;
	last = NULL;
	while (i++ < words->used)
	{
		word = array_get_at(words, i - 1);
		if (!(str = ft_strclean(word->s)))
			return (word_list_destroy(&list));
		if (ft_strcmp(str, ""))
			if (!(last = word_list_add((list) ? &last : &list, word_new(word->s))))
				return (word_list_destroy(&list));
		ft_strdel(&str);
	}
	if (list && last)
	{
		last->next = list;
		list->prev = last;
	}
	return (list);
}
