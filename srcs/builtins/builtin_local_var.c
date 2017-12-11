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
**
** @param vars The local env
** @param color If set to true then the variable will be colored. Otherwise no.
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

/*
** @brief Executes option -p
**
** @param color If set to true then the variables will be colored. Otherwise no.
** @param args The arguments passed to the builtin
*/

static void	builtin_export_p(char **args, BOOL color)
{
	t_env	*var;

	if (!args || !(*args))
		return (builtin_export_print(get_envs(), color));
	while (*args)
	{
		if ((var = get_var(get_envs(), *args)) && color)
			ft_printf("\033[91m%s \033[94m%s\033[0m=%s\n",
				var->is_export ? "export" : "typeset", var->name, var->value);
		else if ((var = get_var(get_vars(), *args)) && color)
			ft_printf("\033[91m%s \033[94m%s\033[0m=%s\n",
				var->is_export ? "export" : "typeset", var->name, var->value);
		else if ((var = get_var(get_envs(), *args)))
			ft_printf("%s %s=%s\n",
				var->is_export ? "export" : "typeset", var->name, var->value);
		else if ((var = get_var(get_vars(), *args)))
			ft_printf("%s %s=%s\n",
				var->is_export ? "export" : "typeset", var->name, var->value);
		else
			ft_dprintf(STDERR_FILENO,
						"%s: export: no such variable: %s\n", PROGNAME, *args);
		args++;
	}
}

/*
** @brief Unsets a name and value from the local env
**
** @param data The shell's data used across the program
** @param args Arguments passed to unset builtin
**
** @return Returns a ret value based on success of the operation
*/

int			builtin_unset(t_sh_data *data, char **args)
{
	(void)data;
	if (args && *args)
		(args)++;
	else
		return (1);
	if (!(*args))
	{
		ft_putstr_fd("unset: not enough arguments\n", STDERR_FILENO);
		return (1);
	}
	while (*args)
	{
		del_var(get_vars(), *args);
		del_var(get_envs(), *args);
		args++;
	}
	return (0);
}

/*
** @brief Exports a variable in the local var
**
** @param args The arguments used to export
** @param color If set to true, the printed vars will be colored
**
** @return Returns a ret value based on success of the operation
*/

int			builtin_export_var(char **args, BOOL color)
{
	t_env	*var;
	char	*name;
	char	*value;

	value = NULL;
	if (args && *args)
		(args)++;
	else
		return (1);
	if (!args || !(*args))
		builtin_export_print(get_envs(), color);
	while (args && *args)
	{
		name = ft_strchr(*args, '=') ? split_var_name(*args) : ft_strdup(*args);
		var = get_var(get_vars(), name);
		if (ft_strchr(*args, '='))
			set_var(get_envs(), name, (value = split_var_value(*args)), true);
		else if (var)
			set_var(get_envs(), var->name, var->value, true);
		del_var(get_vars(), name);
		args++;
		ft_strdel(&name);
		ft_strdel(&value);
	}
	return (0);
}

/*
** @brief Exports a value in the local env
**
** @param data The shell's data used across the program
** @param args The args used
**
** @return Returns Returns a ret value based on success of the operation
*/

int			builtin_export(t_sh_data *data, char **args)
{
	int		opt;

	(void)data;
	ft_getopt_reset();
	opt = ft_getopt(((int)ft_tablen(args)), args, "pn:");
	if (opt == 'p')
		builtin_export_p(&args[g_optind], data->opts.color);
	else if (opt == 'n')
		builtin_unset(data, args);
	else if (opt == '?')
	{
		ft_dprintf(STDERR_FILENO, "export [-n] [name[=value] ...] or export "
				"-p\n");
		return (1);
	}
	else if (opt == -1 && builtin_export_var(args, data ?
												data->opts.color : false))
		return (1);
	return (0);
}
