#include <core/data.h>
#include <environ/environ.h>

int	builtin_unset(t_sh_data *data, char **argv)
{
	(void) data;

	if (argv && *argv)
		*argv++;
	else
		return (1);
	while (*argv)
	{
		del_var(get_vars(), *argv);
		argv++;
	}
	return (0);
}

int	builtin_export(t_sh_data *data, char **argv)
{
	t_env	*var;

	(void) data;
	if (argv && *argv)
		*argv++;
	else
		return (1);
	while (*argv)
	{
		var = get_var(get_vars(), *argv);
		if (var)
		{
			array_push(get_envs(), var);
			del_var(get_vars(), *argv);
		}
		else
		{
			var = var_new(split_var_name(*argv), split_var_value(*argv));
			array_push(get_envs(), var);
			ft_memdel((void**)&var);
		}
		argv++;
	}
	return (0);
}