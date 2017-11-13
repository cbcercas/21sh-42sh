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

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ftprintf.h>
#include <core/progname.h>
#include <environ/getter_env.h>
#include <environ/builtin_env_utils.h>
#include <core/prompt.h>
#include <environ/modif_env.h>
#include <unistd/ft_unistd.h>
#include <builtins/echo.h>
#include <tools/tools.h>
#include <builtins/chdir.h>

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
