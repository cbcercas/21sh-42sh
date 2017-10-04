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

/*
**TODO: j'arrive pas à forcer chdir à aller dans le lien sans le suivre
*/

static char		*sh_get_path_p(char *arg, char *buf)
{
	ssize_t		len;
	struct stat	bufstat;

	if (lstat(arg, &bufstat) || !(bufstat.st_mode & S_IFLNK))
		return (arg);
	if ((len = readlink(arg, buf, sizeof(buf) - 1)) != -1)
		buf[len] = '\0';
	else
	{
		ft_dprintf(2, "%s : cd : Error readlink of %s\n", PROGNAME, arg);
		buf = NULL;
	}
	return (buf);
}

static char		*sh_get_path(char *arg, int opt)
{
	char *path;
	char buf[1024];

	(void)opt;
	if (!arg)
	{
		if (!(path = sh_getenv_value("HOME")))
			ft_dprintf(2, "%s: cd: HOME not set\n", PROGNAME);
	}
	else if (ft_strequ(arg, "-"))
	{
		if (!(path = sh_getenv_value("OLDPWD")))
			ft_dprintf(2, "%s: cd: OLDPWD not set\n", PROGNAME);
		else
			ft_putendl(path);
	}
	else
		path = arg;
	if (path && opt == 'P')
		path = sh_get_path_p(path, buf);
	return (path);
}

static BOOL		sh_test_dirpath(char *path, int opt)
{
	struct stat	bufstat;
	BOOL		ret;

	ret = false;
	if ((!stat(path, &bufstat) && opt == 'P') || !lstat(path, &bufstat))
	{
		if (bufstat.st_mode & S_IXUSR)
			ret = true;
		else
		{
			ret = false;
			ft_dprintf(2, "%s: cd: permission denied: %s\n", PROGNAME, path);
		}
	}
	return (ret);
}

static int		sh_do_chdir(char *arg, int opt)
{
	char cwd[1024];
	char *path;

	path = sh_get_path(arg, opt);
	if (!sh_test_dirpath(path, opt))
		return ((g_ret = 1));
	if (chdir(path) == -1)
	{
		ft_dprintf(2, "%s: cd: no such file or directory: %s\n",\
																PROGNAME, path);
		return ((g_ret = 1));
	}
	sh_setenv("OLDPWD", sh_getenv_value("PWD"));
	getcwd(cwd, sizeof(cwd));
	sh_setenv("PWD", cwd);
	return ((g_ret = 0));
}

int				sh_chdir(t_sh_data *data, char **arg)
{
	int opt;
	int ret;

	(void)data;
	ret = 0;
	ft_getopt_reset();
	if ((opt = ft_getopt(ft_tablen(arg), arg, "LPh")) != -1)
	{
		if (opt == 'h')
			return (ft_dprintf(2, "%s: cd: [-L/-P] [path], use \"help cd\"\n",\
																	PROGNAME));
		else if (opt == '?')
			return (ft_dprintf(2, "%s: cd: [-L/-P] [path], use \"help cd\"\n",\
																	PROGNAME));
	}
	ret = sh_do_chdir(arg[g_optind], opt);
	ft_getopt_reset();
	return (ret);
}
