/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 13:37:14 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/15 17:24:57 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

BOOL is_directory(char *path)
{
  struct stat bufstat;

  if (lstat(path, &bufstat) == -1)
		return (false);
  if (S_ISDIR(bufstat.st_mode))
    return (true);
  return (false);
}

char *get_path(char *s)
{
  char *ret;
  char *tmp;

	if (!s)
		return (".");
  if (ft_strchr(s, '/'))
  {
    ret = ft_strdup_secu(s, 1);
    tmp = ft_strrchr(ret, '/');
    *++tmp = 0;
    return (ret);
  }
	return(".");
}

t_array *get_content_paths(char *path)
{
	t_array *content;
	DIR *dir;
	struct dirent *file;
	t_string *tmp;

	content = array_create(sizeof(t_string));
	dir = opendir(path);
	if (dir != NULL)
	{
		while ((file = readdir(dir)))
		{
        tmp = string_dup(file->d_name);
        if (path && !ft_strequ(path, "."))
          tmp = string_insert_front(tmp, path);
        if (tmp && tmp->s && is_directory(tmp->s))
          tmp = string_insert_back(tmp, "/");
        else
          tmp = string_insert_back(tmp, " ");
  			array_push(content, (void *)tmp);
		}
		closedir(dir);
	}
	return (content);
}
