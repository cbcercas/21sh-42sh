/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:34:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 14:20:09 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_chdir.h>

extern int g_optind;
/*
** @brief Tests the path, to check if the user has the permission to cd in it.
**
** @param path The path to be tested
**
** @return Returns true if everything is ok. False otherwise
*/

static	BOOL	sh_test_path(char *path)
{
	struct stat	bufstat;

	if (!lstat(path, &bufstat) && !stat(path, &bufstat))
	{
		if (bufstat.st_mode & S_IXUSR && S_ISDIR(bufstat.st_mode))
			return (true);
		else if (S_ISDIR(bufstat.st_mode))
			ft_dprintf(2, "cd: permission denied: %s\n", path);
		else
			ft_dprintf(2, "cd: not a directory: %s\n", path);
		return (false);
	}
	ft_dprintf(2, "cd: no such file or directory: %s\n", path);
	return (false);
}

/*
** @brief Gets the path
**
** @param arg The arg passed at cd
**
** @return Returns the path to cd into
*/

static	char	*sh_get_path(char *arg)
{
	char		*path;

	if (!arg)
	{
		if (!(path = get_var_value(get_envs(), "HOME")))
			ft_dprintf(2, "%s: cd: HOME not set\n", PROGNAME);
	}
	else if (ft_strequ(arg, "-"))
	{
		if (!(path = get_var_value(get_envs(), "OLDPWD")))
			ft_dprintf(2, "%s: cd: OLDPWD not set\n", PROGNAME);
		else
			ft_putendl(path);
	}
	else
		path = arg;
	return (path);
}

/*
** @brief This function is the one that does the chdir and does all the tests
** @param arg The args passed at cd
** @param opt The options
** @return Returns the status of cd
*/

static int		sh_do_chdir(char *arg, int opt)
{
	char	*path;
	char	*cur;

	if (!(path = sh_get_path(arg)))
		return ((*get_cmd_ret() = 1));
	if (!sh_test_path(path))
		return ((*get_cmd_ret() = 1));
	expand_path(&path);
	set_var(get_envs(), "OLDPWD", (cur = get_pwd()), true);
	ft_strdel(&cur);
	if (chdir(path) == -1)
	{
		ft_dprintf(2, "cd: can't cd with: %s\n", path);
		ft_strdel(&path);
		return ((*get_cmd_ret() = 1));
	}
	if (opt == 'P')
		set_var(get_envs(), "PWD", (cur = getcwd(NULL, 0)), true);
	else
		set_var(get_envs(), "PWD", path, true);
	ft_strdel(&path);
	ft_strdel(&cur);
	return ((*get_cmd_ret() = 0));
}

/*
** @brief The function called when cd is typed.
** @param data The shell data used throughout the program
** @param arg The args passed to cd
** @return Returns the ret value of cd
*/

int				sh_chdir(t_sh_data *data, char **arg)
{
	int opt;
	int ret;

	(void)data;
	ft_getopt_reset();
	if ((opt = ft_getopt(ft_tablen(arg), arg, "LPh")) != -1 && (opt == 'h' ||
			opt == '?'))
		return (ft_dprintf(2, "cd: [-L/-P] [path], use \"help cd\"\n"));
	ret = sh_do_chdir(arg[g_optind], opt);
	ft_getopt_reset();
	return (ret);
}
