/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_get_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 13:37:14 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/09 17:56:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

char		*autocomplete_get_path(char *s)
{
	char *ret;
	char *tmp;

	if (!s)
		return (".");
	if (ft_strchr(s, '/'))
	{
		ret = ft_strdup_secu(s, M_LVL_AUTOC);
		tmp = ft_strrchr(ret, '/');
		*++tmp = 0;
		return (ret);
	}
	return (".");
}

static t_string	*make_content_path(t_array *content, char *path,
									  struct dirent *file)
{
	t_string	*tmp;

	tmp = (t_string*)array_get_at(content, content->used);
	if (!autocomplete_is_dots(file->d_name))
		tmp = string_insert_front(tmp, file->d_name);
	if (tmp && path && tmp->s && tmp->len && !ft_strequ(path, "."))
		tmp = string_insert_front(tmp, path);
	if (tmp && tmp->s && autocomplete_is_directory(tmp->s))
		tmp = string_insert_back(tmp, "/");
	content->used += (tmp) ? 1 : 0;
	if (!tmp)
		string_clear(array_get_at(content, content->used));
	if (tmp && (!tmp->s || !tmp->len))
	{
		array_pop(content, NULL);
		string_clear(tmp);
	}
	return (tmp);
}

t_array		*autocomplete_get_content_paths(char *path)
{
	t_array			*content;
	DIR				*dir;
	struct dirent	*file;

	content = array_create(sizeof(t_string));
	dir = opendir(path);
	if (content && dir != NULL)
	{
		while ((file = readdir(dir)) && content->used <= 3000)
		{
			if (!(content->used == content->capacity && !array_growth(content)))
				if (make_content_path(content, path, file))
					continue ;
			array_destroy(&content, &string_clear);
			return (NULL);
		}
	}
	(dir) ? closedir(dir) : 0;
	return (content);
}
