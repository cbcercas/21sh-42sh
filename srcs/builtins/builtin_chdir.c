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
** @return Returns `true` if user has perm to chdir in the requested folder.
** This function will return `false` by default or if permissions aren't ok.
*/

static BOOL	sh_test_path(char **dir, char *arg)
{
	struct stat	bufstat;

	if (!arg)
		arg = *dir;
	if (!stat(*dir, &bufstat))
	{
		if (bufstat.st_mode & S_IXUSR && S_ISDIR(bufstat.st_mode))
			return (true);
		else if (S_ISDIR(bufstat.st_mode))
			ft_dprintf(2, "cd: permission denied: %s\n", arg);
		else
			ft_dprintf(2, "cd: not a directory: %s\n", arg);
	}
	else
		ft_dprintf(2, "cd: no such file or directory: %s\n", arg);
	ft_strdel(dir);
	return (false);
}

/*
** @brief Gets the path from `HOME` or `OLDPWD` environment values if available.
**
** @param arg The arguments passed to the cd builtin
** @param dir The path to fill with the values from the environment
** @param disp Indicator whether or not the path is displayed.
**
** @return Returns true if `dir` has any content in it. Otherwise, `false` is
** returned.
*/

static BOOL	sh_get_dir(char *arg, char **dir, BOOL *disp)
{
	if (!arg)
	{
		if (!(*dir = get_var_value(get_envs(), "HOME")))
			ft_dprintf(2, "%s: cd: HOME not set\n", PROGNAME);
	}
	else if (ft_strequ(arg, "-"))
	{
		if (!(*dir = get_var_value(get_envs(), "OLDPWD")))
			ft_dprintf(2, "%s: cd: OLDPWD not set\n", PROGNAME);
		else
			*disp = true;
	}
	else
		*dir = arg;
	if (*dir)
		return (true);
	return (false);
}

/*
** @brief This function will initialize the chdir.
** First, it'll get the directory and change it to an absolute path before
** testing it.\n
** Then, the path will be expanded if needed and displayed if needed
** (for example `cd -`).
**
** @param arg The arguments passed to the cd builtin
**
** @return Returns the dir if everything went well.
** This function will return NULL otherwise.
*/

static char	*sh_do_chdir_init(char *arg)
{
	BOOL	disp;
	char	*dir;

	disp = false;
	if (!sh_get_dir(arg, &dir, &disp))
		return (NULL);
	dir = ft_strdup(dir);
	if (!change_in_abs(&dir, &disp))
	{
		ft_strdel(&dir);
		return (NULL);
	}
	if (!sh_test_path(&dir, arg))
	{
		ft_strdel(&dir);
		return (NULL);
	}
	expand_path(&dir);
	if (disp)
		ft_putendl(dir);
	return (dir);
}

/*
** @brief This function is the main function for the `chdir`/`cd` builtin.
**
** @param arg The arguments passed to the cd builtin
** @param opt The options passed to the cd builtin
**
** @return Returns the status of `cd`.\n
** `cd` will return 1 if there's an error,\n
** otherwise it will return 0.
*/

static int	sh_do_chdir(char *arg, int opt)
{
	char	*dir;
	char	*cur;

	if (!(dir = sh_do_chdir_init(arg)))
		return ((*get_cmd_ret() = 1));
	set_var(get_envs(), "OLDPWD", (cur = get_pwd()), true);
	ft_strdel(&cur);
	if (chdir(dir) == -1)
	{
		ft_dprintf(2, "cd: can't cd with: %s\n", dir);
		ft_strdel(&dir);
		return ((*get_cmd_ret() = 1));
	}
	if (opt == 'P')
		set_var(get_envs(), "PWD", (cur = getcwd(NULL, 0)), true);
	else
		set_var(get_envs(), "PWD", dir, true);
	ft_strdel(&dir);
	ft_strdel(&cur);
	return ((*get_cmd_ret() = 0));
}

/*
** @brief The function called when cd is typed. It handles options passed to it.
**
** @param data The shell data used throughout the program
** @param arg The arguments passed to cd
**
** @return Returns the return value of cd (success or not of said builtin)
*/

int			sh_chdir(t_sh_data *data, char **arg)
{
	int		opt;
	int		ret;

	(void)data;
	ret = -1;
	ft_getopt_reset();
	while ((opt = ft_getopt(((int)ft_tablen(arg)), arg, "LPh")) != -1)
	{
		if (opt == 'h' || opt == '?')
			return (ft_dprintf(2, "cd: [-L/-P] [path], use \"help cd\"\n"));
		else if (ret == -1 && opt == 'P')
			ret = 'P';
		else if (ret == -1 && opt == 'L')
			ret = 'L';
	}
	opt = ret;
	if (arg && ft_tablen(&arg[g_optind]) > 1)
		return (ft_dprintf(2, "cd: too many arguments\n"));
	if (arg)
		ret = sh_do_chdir(arg[g_optind], opt);
	else
		ret = sh_do_chdir(NULL, opt);
	ft_getopt_reset();
	return (ret);
}
