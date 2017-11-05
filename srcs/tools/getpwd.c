

#include <environ/getter_env.h>
#include <sys/stat.h>

char	*get_pwd(void)
{
	char	*pwd;
	struct stat	bufstat;

	pwd = get_var_value(get_envs(), "PWD");
	if (!pwd || *pwd != '/')
		return (NULL);
	if (!stat(pwd, &bufstat) && !lstat(pwd, &bufstat))
		return(ft_strdup(pwd));
	pwd = getcwd(NULL, 0);
	return (pwd);
}