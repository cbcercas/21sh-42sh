/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:07:36 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/15 18:29:34 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/check_path.h>
#include <core/input.h>

/*
** @brief Creates a filepath from a `path` and a `filename`
**
** @param path The path to use
** @param filename The filename to use
**
** @return Returns the filename (`path` + `filename`)
*/

char			*makefilepath(char const *path, char const *filename)
{
	char	*filepath;

	if (path)
	{
		if (path[ft_strlen(path) - 1] != '/')
		{
			filepath = ft_strjoin(path, "/");
			filepath = ft_strjoincl(filepath, (char *)filename, 1);
		}
		else
			filepath = ft_strjoin(path, filename);
	}
	else
		filepath = ft_strdup(filename);
	return (filepath);
}

/*
** @brief Returns a malloc string containing the path
**
** @return Returns a malloc string containing the path
*/

static char		**get_env_path(void)
{
	char	**env_path;

	env_path = ft_strsplit(get_var_value(get_envs(), "PATH"), ':');
	if (env_path)
		return (env_path);
	return (ft_strsplit(get_var_value(get_vars(), "PATH"), ':'));
}

/*
** @brief Checks the ret value and prints an error accordingly
**
** @param ret The error value
** @param cmd_name The cmd executed that errored
*/

static void		sh_check_path_print_err(int ret, char const *cmd_name, char **free)
{
	if (ret == -1)
		ft_dprintf(STDERR_FILENO, "%s: permission denied: %s\n",
				PROGNAME, cmd_name);
	else if (ret == 0 || ret == 2)
		ft_dprintf(STDERR_FILENO, "%s: command not found: %s\n",
				PROGNAME, cmd_name);
	*get_cmd_ret() = 1;
	ft_freetab(free, ft_tablen(free));
}

/*
** @brief Checks the path for a given command name (`cmd_name`)
**
** @param cmd_name Command name to be checked
**
** @return Returns the filename or NULL otherwise
*/

char			*sh_check_path(char const *cmd_name)
{
	char	**env_path;
	char	**save;
	char	*file;
	int		ret;

	ret = 0;
	env_path = get_env_path();
	save = env_path;
	while (env_path && *env_path)
	{
		if (!(file = makefilepath(*env_path, cmd_name)))
			break ;
		if (!(ret = sh_test_access(file)))
		{
			ft_freetab(save, ft_tablen(save));
			return (file);
		}
		else if (ret == 1)
			ret = -1;
		ft_strdel(&file);
		env_path++;
	}
	sh_check_path_print_err(ret, cmd_name, save);
	ft_secu_free_lvl(M_LVL_FUNCT);
	return (NULL);
}

/*
** @brief get path of bin or test absolute path
** @param av arguments exec
** @return the absolute pathof bin or NULL otherwise
*/

char			*get_filename(char *av)
{
	char		*ret;
	int			err;
	struct stat	buf;

	ret = NULL;
	if (ft_strchr(av, '/'))
	{
		if (!(err = lstat(av, &buf)) && buf.st_mode & S_IXUSR &&
				!(S_ISDIR(buf.st_mode)))
			return (ft_strdup(av));
		if (!err && !(buf.st_mode & S_IXUSR))
			ft_dprintf(STDERR_FILENO, "%s: permission denied: %s\n",
					PROGNAME, av);
		else if (err)
			ft_dprintf(STDERR_FILENO, "%s: %s: No such file or directory\n",
					PROGNAME, av);
		else if (S_ISDIR(buf.st_mode))
			ft_dprintf(STDERR_FILENO, "%s: sh: %s: is a directory\n",
					PROGNAME, av);
	}
	else
		ret = sh_check_path(av);
	ft_secu_free_lvl(M_LVL_FUNCT);
	return (ret);
}
