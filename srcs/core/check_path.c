/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:07:36 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/24 18:00:38 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/check_path.h>

char		*makefilepath(char const *path, char const *filename)
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

static int	sh_test_access(char const *filename)
{
	struct stat *buf;
	int		ret;

	if (!(buf = ft_memalloc(sizeof(*buf))))
		return (-2);
	ret = 0;
	ft_bzero(buf, sizeof(*buf));
	if (stat(filename, buf) == 0)
	{
		if (buf->st_mode & S_IXUSR)
			ret = 1;
		else
			ret = -1;
	}
	return (ret);
}

char	*sh_check_path(char const *cmd_name)
{
	char	**env_path;
	char	*file;
	int		ret;
	int		tmp;

	if (!(env_path = ft_strsplit(sh_getenv_value("PATH"), ':')))
		return (NULL);
	ret = 0;
	while (*env_path != NULL)
	{
		if (!(file = makefilepath(*env_path, cmd_name)))
			break;
		if ((tmp = sh_test_access(file)) == 1)
			return (file);
		else if (tmp == -1)
			ret = -1;
		ft_strdel(&file);
		env_path++;
	}
	if (ret == -1)
		ft_printf("minishell: permission denied: %s\n", cmd_name);
	else if (ret == 0)
		ft_printf("minishell: command not found: %s\n", cmd_name);
	return (NULL);
}