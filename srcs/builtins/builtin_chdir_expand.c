
#include <builtins/chdir.h>
#include <libft.h>
#include <tools/tools.h>
#include <builtins/exit.h>

char 	*find_start_ddots(char *path)
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
	return (path);
}

char	*expand_path(char **path)
{
	char		*current;
	char		*ret;

	if (!path || !*path || !(current = get_pwd()))
		return (NULL);
	if (ft_strstr(*path, "...") || ft_strstr(*path, "//"))
		return (NULL);
	ret = ft_strdup(*path);
	if (*path[0] != '/' && (!(current = ft_strjoincl(current, "/", 1)) ||
							!(ret = ft_strjoincl(current, ret, 2))))
		sh_exit(NULL, NULL);
	ret = remove_dots(ret);
	ft_strdel(&current);
	if (ret && ft_strlen(ret) > 1 && ret[ft_strlen(ret) - 1] == '/')
		ret[ft_strlen(ret) - 1] = 0;
	*path = ret;
	return (ret);
}
