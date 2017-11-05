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

#include <builtins/chdir.h>

static	BOOL	sh_test_path(char *path, char *arg)
{
	struct stat	bufstat;

	if (!stat(path, &bufstat) && !lstat(path, &bufstat))
	{
		if (bufstat.st_mode & S_IXUSR)
			return (true);
		else
			ft_dprintf(2, "%s: cd: permission denied: %s\n", PROGNAME, arg);
	}
	ft_dprintf(2, "cd: no such file or directory: %s\n", arg);
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
		return ((g_ret = 1));
	expand_path(&path);
	if (!sh_test_path(path, arg))
	{
		ft_strdel(&path);
		return ((g_ret = 1));
	}
	set_var(get_envs(), "OLDPWD", (cur = get_pwd()), true);
	ft_strdel(&cur);
	if (chdir(path) == -1)
	{
		ft_dprintf(2, "cd: can't cd with: %s\n", path);
		ft_strdel(&path);
		return ((g_ret = 1));
	}
	if (opt == 'P')
		set_var(get_envs(), "PWD", (cur = getcwd(NULL, 0)), true);
	else
		set_var(get_envs(), "PWD", path, true);
	ft_strdel(&path);
	ft_strdel(&cur);
	return ((g_ret = 0));
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
