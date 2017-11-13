
#include <builtins/chdir.h>
#include <libft.h>
#include <tools/tools.h>
#include <builtins/exit.h>
#include <sys/stat.h>

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

static	char	*remove_backslash(char *path)
{
	char	*start;

	while ((start = ft_strstr(path, "//")) && ft_strlen(start + 2))
		ft_memcpy(start + 1, start + 2, ft_strlen(start + 1));
	if (path && ft_strlen(path) > 1 && path[ft_strlen(path) - 1] == '/')
		path[ft_strlen(path) - 1] = 0;
	return (path);
}

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
