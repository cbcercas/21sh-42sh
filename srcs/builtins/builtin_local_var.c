#include <core/data.h>
#include <environ/environ.h>
#include <unistd/ft_unistd.h>
#include <environ/modif_env.h>
#include <environ/builtin_env_utils.h>
#include <environ/getter_env.h>
#include <ftprintf.h>

extern char const	*g_optarg;

static void builtin_export_print(t_array *vars)
{
	t_env	*e;
	size_t	i;

	i = 0;
	if (!vars || !vars->used)
		return ;
	while (i < vars->used)
	{
		e = (t_env *) array_get_at(vars, i);
		if (e->is_export)
			ft_printf("\033[91mexport \033[94m%s\033[0m=%s\n", e->name,
					  e->value);
		i++;
	}
}

int	builtin_unset(t_sh_data *data, char **argv)
{
	(void) data;

	if (argv && *argv)
		(argv)++;
	else
		return (1);
	if(!(*argv))
	{
		ft_putstr_fd("unset: not enough arguments\n", STDERR_FILENO);
		return (1);
	}
	while (*argv)
	{
		del_var(get_vars(), *argv);
		del_var(get_envs(), *argv);
		argv++;
	}
	return (0);
}

int		builtin_export_var(char **argv)
{
	t_env	*var;
	char	*name;
	char	*value;

	value = NULL;
	if (argv && *argv)
		(argv)++;
	else
		return (1);
	if (!argv || !(*argv))
		builtin_export_print(get_envs());
	while (*argv)
	{
		name = ft_strchr(*argv, '=') ? split_var_name(*argv) : ft_strdup(*argv);
		var = get_var(get_vars(), name);
		if (ft_strchr(*argv, '='))
			set_var(get_envs(), name, (value = split_var_value(*argv)), true);
		else if (var)
			set_var(get_envs(), var->name, var->value, true);
		del_var(get_vars(), name);
		argv++;
		ft_strdel(&name);
		ft_strdel(&value);
	}
	return (0);
}

int	builtin_export(t_sh_data *data, char **argv)
{
	int		opt;

	(void)data;
	ft_getopt_reset();
	opt = ft_getopt(ft_tablen(argv), argv, "pn:");
	if (opt == 'p')
		builtin_export_print(get_envs());
	else if (opt == 'n')
		builtin_unset(data, argv);
	else if (opt == '?')
	{
		ft_dprintf(STDERR_FILENO, "export [-n] [name[=value] ...] or export "
				"-p\n");
		return (1);
	}
	else if (opt == -1 && builtin_export_var(argv))
		return (1);
	return (0);
}