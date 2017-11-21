/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_local_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_local_var.h>
#include <core/progname.h>

extern char const	*g_optarg;
extern int			g_optind;

/*
** @brief Prints the exported value and name
** @param vars The local env
*/

static void	builtin_export_print(t_array *vars, BOOL color)
{
	t_env	*e;
	size_t	i;

	i = 0;
	if (!vars || !vars->used)
		return ;
	while (i < vars->used)
	{
		e = (t_env *)array_get_at(vars, i);
		if (e->is_export && color)
			ft_printf("\033[91mexport \033[94m%s\033[0m=%s\n", e->name,
					e->value);
		else if (e->is_export)
			ft_printf("export %s=%s\n", e->name,
					e->value);
		i++;
	}
}

static void	builtin_export_p(char **argv, BOOL color)
{
	t_env	*var;

	if (!argv || !(*argv))
		builtin_export_print(get_envs(), color);
	while (*argv)
	{
		if ((var = get_var(get_envs(), *argv)) && color)
			ft_printf("\033[91m%s \033[94m%s\033[0m=%s\n",
				var->is_export ? "export" : "typedef", var->name, var->value);
		else if ((var = get_var(get_vars(), *argv)) && color)
			ft_printf("\033[91m%s \033[94m%s\033[0m=%s\n",
				var->is_export ? "export" : "typedef", var->name, var->value);
		else if ((var = get_var(get_envs(), *argv)))
			ft_printf("%s %s=%s\n",
				var->is_export ? "export" : "typedef", var->name, var->value);
		else if ((var = get_var(get_vars(), *argv)))
			ft_printf("%s %s=%s\n",
				var->is_export ? "export" : "typedef", var->name, var->value);
		else
			ft_dprintf(STDERR_FILENO,
						"%s: export: no such variable: %s\n", PROGNAME, *argv);
		argv++;
	}
}

/*
** @brief Unsets a name and value from the local env
** @param data The shell's data used across the program
** @param argv Args passed to unset builtin
** @return Returns a ret value
*/

int			builtin_unset(t_sh_data *data, char **argv)
{
	(void)data;
	if (argv && *argv)
		(argv)++;
	else
		return (1);
	if (!(*argv))
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

/*
** @brief Exports a variable in the local var
** @param argv The arguments used to export
** @return Returns a ret value
*/

int			builtin_export_var(char **argv, BOOL color)
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
		builtin_export_print(get_envs(), color);
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

/*
** @brief Exports a value in the local env
** @param data The shell's data used across the program
** @param argv The args used
** @return Returns a ret value based on success or failure
*/

int			builtin_export(t_sh_data *data, char **argv)
{
	int		opt;

	(void)data;
	ft_getopt_reset();
	opt = ft_getopt(ft_tablen(argv), argv, "pn:");
	if (opt == 'p')
		builtin_export_p(&argv[g_optind], data->opts.color);
	else if (opt == 'n')
		builtin_unset(data, argv);
	else if (opt == '?')
	{
		ft_dprintf(STDERR_FILENO, "export [-n] [name[=value] ...] or export "
				"-p\n");
		return (1);
	}
	else if (opt == -1 && builtin_export_var(argv, data ?
												data->opts.color : false))
		return (1);
	return (0);
}
