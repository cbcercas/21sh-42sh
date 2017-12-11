/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chdir_abs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiforge <guiforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:52:05 by guiforge          #+#    #+#             */
/*   Updated: 2017/11/25 01:52:06 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_chdir.h>

/*
** @brief Joins the current path with dir if it isn't absolute already
** This function will test the first character of the given `dir` and if it
** isnt a `/` it will get the current absolute path and join them together.
**
** @param dir The path/filename that you need to join with the current path
**
** @return void The dir is edited through a pointer
*/

static void		join_current(char **dir)
{
	char	*current;

	if (**dir != '/')
	{
		current = get_pwd();
		current = ft_strjoincl(current, "/", 1);
		*dir = ft_strjoincl(current, *dir, 3);
	}
}

/*
** @brief function check path for CDPATH
**
** @param cdpath is the cdpath environ variable
** @param dir The path not absolute
** @param indicator whether or not the path is displayed.
**
** @return Returns true if everything is ok. False otherwise
*/

static BOOL		change_in_abs_loop(char **cdpath, char **dir, BOOL *disp)
{
	char		tmp[PATH_MAX + 1];
	struct stat	buff;

	ft_bzero(tmp, PATH_MAX + 1);
	if (**cdpath == '/' || **cdpath == '.')
	{
		ft_strlcat(tmp, *cdpath, PATH_MAX);
		ft_strlcat(tmp, "/", PATH_MAX);
		ft_strlcat(&tmp[ft_strlen(tmp)], *dir, PATH_MAX);
		if (!stat(tmp, &buff))
		{
			free(*dir);
			*dir = ft_strdup(tmp);
			*disp = true;
			return (true);
		}
	}
	return (false);
}

/*
** @brief Changes the path to an absolute path
**
** @param dir The path not yet absolute
** @param disp Indicator whether or not the path should be displayed.
**
** @return This function will return `true` if the given `dir` containing a
** filename/path has successfully been changed into an absolute path.\n
** It will otherwise return `false`
*/

BOOL			change_in_abs(char **dir, BOOL *disp)
{
	char	**cdpath;
	char	**tmp_cdpath;

	if (!*dir)
		return (false);
	if (**dir == '/')
		return (true);
	if (**dir == '.' ||
			!(cdpath = ft_strsplit(get_var_value(get_envs(), "CDPATH"), ':')))
		cdpath = NULL;
	tmp_cdpath = cdpath;
	while (cdpath && *cdpath && !change_in_abs_loop(cdpath, dir, disp))
		cdpath++;
	join_current(dir);
	if (tmp_cdpath)
		ft_freetab(tmp_cdpath, ft_tablen(tmp_cdpath));
	if (*dir)
		return (true);
	return (false);
}
