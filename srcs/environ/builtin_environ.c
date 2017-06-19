//
// Created by Jules LASNE on 6/19/17.
//

#include <environ/builtin_env.h>

int sh_builtin_setenv(t_sh_data *data, char **args)
{
	(void)data;
	int i;

	i = 1;
	while(args[i] && ft_strchr(args[i], '='))
	{
		sh_setenv(split_env_name(args[i]), split_env_value(args[i]));
		i++;
	}
	return (0);
}

int sh_builtin_unsetenv(t_sh_data *data, char **args)
{
	(void)data;
	int		i;

	i = 1;
	while(args[i])
	{
		sh_delenv(args[i]);
		i++;
	}
	return (0);
}

int sh_builtin_env(t_sh_data *data, char **args)
{
	(void)data;
	(void)args;
	return (0);
}