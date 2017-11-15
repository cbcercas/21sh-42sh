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
** @brief Finds the starting '..' (TODO)
**
** @param path The path string to search
**
** @return Returns the pointer to the '..' (?)
*/

static char 	*find_start_ddots(char *path)
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
** @brief Removes the extraenous dots for given path
**
** @param path Path to search
**
** @return Returns the path without the extraenous dots
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
			break;
		ft_memcpy(start, start2 + 3, ft_strlen(start2) - 1);
	}
	if (path && ft_strlen(path) > 2 && ft_strequ(&path[ft_strlen(path) - 2], "/."))
		path[ft_strlen(path) - 1] = 0;
	return (path);
}

/*
** @brief Removes the extraneous backslashes from a given path
**
** @param path String from which to remove the extraenous backslashes
**
** @return The path modified without the backslashes
*/

static	char	*remove_backslash(char *path)
{
	char	*start;

	while ((start = ft_strstr(path, "//")) && ft_strlen(start + 2))
		ft_memcpy(start + 1, start + 2, ft_strlen(start + 1));
	if (path && ft_strlen(path) > 1 && path[ft_strlen(path) - 1] == '/')
		path[ft_strlen(path) - 1] = 0;
	return (path);
}

/*
** @brief Expands the path
** @param path (TODO)
** @return (TODO)
*/

char	*expand_path(char **path)
{
	char		*current;
	char		*ret;
	struct stat	bufstat;

	if (!path || !*path || stat(*path, &bufstat) || lstat(*path, &bufstat)
		|| !(current = get_pwd()))
		return (NULL);
	ret = ft_strdup(*path);
	if (*path[0] != '/' && (!(current = ft_strjoincl(current, "/", 1)) ||
							!(ret = ft_strjoincl(current, ret, 2))))
		sh_exit(NULL, NULL);
	ret = remove_dots(ret);
	ret = remove_backslash(ret);
	if (ft_strstr(ret, "./") || ft_strstr(ret, "/.") || ft_strstr(ret, "//"))
	{
		log_warn("CD expand PATH wrong ! (%s) so return (%s)", ret, current);
		ft_strdel(&ret);
		return (*path = current);
	}
	ft_strdel(&current);
	*path = ret;
	return (ret);
}
