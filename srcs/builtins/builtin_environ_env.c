/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_environ_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:21:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/02 14:33:52 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_env.h>

extern int g_optind;

/*
** @brief Destroys the array containing the env
**
** @param env_local The env to be destroyed
** @param ret The return value
**
** @return Returns the return value ret
*/

int				builtins_env_over(t_array *env_local, int ret)
{
	array_destroy(&env_local, (void *(*)(void *))&del_env);
	return (ret);
}

/*
** @brief Handles the options for the env builtin
**
** @param args The parameters passed to env
**
** @return Returns the return value of env based on success of operation or not
*/

static int		builtin_env_opt(char **args)
{
	int opt;
	int tmp;

	ft_getopt_reset();
	tmp = 0;
	while ((opt = ft_getopt(((int)ft_tablen(args)), args, "ui")) != -1)
	{
		if (opt == 'u')
			break ;
		else if (opt == '?')
			break ;
		else if (opt == 'i')
			tmp = opt;
	}
	if (opt == 'u' && g_optind != -1 && !args[g_optind])
	{
		ft_dprintf(2, "env: option requires an argument -- 'u'\n");
		opt = -1;
	}
	else if (tmp == 'i' && opt != 'u')
		opt = 'i';
	else if (opt == '?')
		opt = -1;
	g_optind = (ft_strequ(args[g_optind], "--") ? g_optind + 1 : g_optind);
	return (opt);
}

/*
** @brief create new local env
**
** @param opt Options passed to env
** @param args The options passed to env under string form
**
** @return Returns the env
*/

static t_array	*sh_get_env_builtins(int opt, char **args)
{
	t_array *tmp;

	if ((tmp = array_create(sizeof(t_env))) == NULL)
		sh_exit_error("Environ: can't initialise local environment variables");
	if (opt == 'i')
		return (sh_builtin_env_add(tmp, args));
	else if (opt == 'u')
		return (sh_builtin_env_u(tmp, args));
	else
		return (sh_builtin_env_add(clone_vars(get_envs(), tmp), args));
}

/*
** @brief Main env builtin function
**
** @param data Shell data passed throughout the program
** @param args The args passed to env
**
** @return Returns the ret value based on a successful operation or not
*/

int				sh_builtin_env(t_sh_data *data, char **args)
{
	int		opt;
	t_array *env_local;

	(void)data;
	if (!args[1])
	{
		print_vars(get_envs(), data ? data->opts.color : false);
		return (0);
	}
	opt = builtin_env_opt(args);
	if (!(env_local = sh_get_env_builtins(opt, args)))
		return (1);
	if (g_optind != -1 && sh_builtin_env_exec(&args[g_optind], env_local))
		return (builtins_env_over(env_local, 1));
	if (g_optind != -1 && !args[g_optind])
		print_vars(env_local, data ? data->opts.color : false);
	ft_getopt_reset();
	return (builtins_env_over(env_local, 0));
}
