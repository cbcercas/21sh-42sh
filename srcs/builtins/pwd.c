# include <builtins/pwd.h>

int sh_builtin_pwd(t_sh_data *data, char **args)
{
	char cwd[1024];
	if (args[1] != NULL)
	{
		ft_printf("pwd: Too many arguments\n");
		return (1);
	}
	getcwd(cwd, sizeof(cwd));
	ft_printf("%s\n", cwd);
	return (0);
}