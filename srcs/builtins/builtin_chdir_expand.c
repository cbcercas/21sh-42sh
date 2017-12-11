/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chdir_expand.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_chdir.h>

/*
** @brief This function will find the first `..` it will find in the string
** `path` and return a pointer to it.
**
** @param path The string to search into
**
** @return Returns a pointer to the first `..` it'll find in `path`
*/

static char		*find_start_ddots(char *path)
{
	char	*start;
	char	*find;
	char	*tmp;

	start = path;
	find = ft_strstr(path, "..");
	while ((tmp = ft_strchr(start, '/')) + 1 != find && tmp)
	{
		start = tmp;
		start++;
	}
	return (start);
}

/*
** @brief Removes the extraneous dots for given `path`.
**
** @param path String containing a path to remove the extraneous dots from.
**
** @return Returns the modified path without the extraneous dots inside.
*/

static	char	*remove_dots(char *path)
{
	char	*start;
	char	*start2;

	while ((start = ft_strstr(path, "/./")))
		ft_memcpy(start, start + 2, ft_strlen(start + 1));
	while ((start2 = ft_strstr(path, "..")))
	{
		start = find_start_ddots(path);
		if (start == path)
			start++;
		if (!*start)
			break ;
		ft_memcpy(start, start2 + 3, ft_strlen(start2) - 1);
	}
	if (path && ft_strlen(path) > 2 &&
									ft_strequ(&path[ft_strlen(path) - 2], "/."))
		path[ft_strlen(path) - 1] = 0;
	return (path);
}

/*
** @brief Removes the extraneous backslashes from a given `path`
**
** @param path String containing a path to remove the extraneous backslashes
** from.
**
** @return Returns the modified path without the extraneous backslashes inside.
*/

static char		*remove_backslash(char *path)
{
	char	*start;

	while ((start = ft_strstr(path, "//")) && ft_strlen(start + 2))
		ft_memcpy(start + 1, start + 2, ft_strlen(start + 1));
	while (path && ft_strlen(path) > 1 && path[ft_strlen(path) - 1] == '/')
		path[ft_strlen(path) - 1] = 0;
	return (path);
}

/*
** @brief This function will expand a path given through a pointer.\n
** It will first remove the dots then the backslashes. If a `./` or a `//` are
** found in the modified string, the function will reset the modified path
** and return the original one.
**
** @param path The filename/path you want to modify
**
** @return path Returns the modified path
*/

char			*expand_path(char **path)
{
	char		*current;
	char		*ret;

	if (!path || !*path || !(current = get_pwd()))
		return (NULL);
	ret = *path;
	ret = remove_dots(ret);
	ret = remove_backslash(ret);
	if (ft_strstr(ret, "./") || ft_strstr(ret, "//"))
	{
		log_warn("CD expand PATH wrong ! (%s) so return (%s)", ret, current);
		ft_strdel(&ret);
		return (*path = current);
	}
	ft_strdel(&current);
	*path = ret;
	return (ret);
}
