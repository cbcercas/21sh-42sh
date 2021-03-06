/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_local_var.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

/*
** @brief Checks if arg is set only
**
** @param s vars
**
** @return true if is only set or false otherwise
*/

static BOOL	is_only_set(char **s)
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] && ((!ft_strchr(s[i], '=')) || ft_strlen(s[i]) == 1))
			return (false);
		i++;
	}
	return (true);
}

/*
** @brief restore env
** @param env_save the tmp env
** @param tmp arguments passed by user
** @param i index in arguments (tmp)
** @param ret The return value of exec
**
** @return The return value
*/

static int	sh_exec_local_var_ret(t_array *env_save, char **tmp, int i, int ret)
{
	t_env	*var;
	char	*name;

	if (i > 0)
		i--;
	while (i >= 0)
	{
		name = split_var_name(tmp[i]);
		var = get_var(get_envs(), name);
		if (var && !var->is_export)
			del_var(get_envs(), name);
		else
		{
			var = get_var(env_save, name);
			if (var)
				set_var(get_envs(), var->name, var->value, true);
		}
		ft_strdel(&name);
		i--;
	}
	array_destroy(&env_save, (void *(*)(void *))&del_env);
	return (ret);
}

/*
** @brief set the env
** @param only_set if it is true the env is only set not exec
** @param item struct of commands
** @param i index in arguments
*/

static void	sh_exec_local_set(BOOL only_set, t_cmd *item, int i)
{
	char	*name;
	char	*value;

	if (!item->av[i] || !ft_strchr(item->av[i], '='))
		return ;
	value = split_var_value(item->av[i]);
	if (get_var(get_envs(), (name = split_var_name(item->av[i]))))
		set_var((get_envs()), name, value, false);
	else
		set_var((only_set ? get_vars() : get_envs()), name, value, false);
	ft_strdel(&name);
	ft_strdel(&value);
}

/*
** @brief Executes local var
** @param  data    The data of shell
** @param item struct of command
** @param fds list of fd
** @return Return value based on success or failure
*/

int			sh_exec_local_var(t_sh_data *data, t_cmd *item, t_array *fds)
{
	int			i;
	BOOL		only_set;
	t_array		*env_save;
	char		**tmp;

	tmp = item->av;
	env_save = array_create(sizeof(t_env));
	env_save = clone_vars(get_envs(), env_save);
	i = 0;
	only_set = is_only_set(item->av);
	while (item->av[i] && ft_strchr(item->av[i], '='))
	{
		sh_exec_local_set(only_set, item, i);
		i++;
	}
	if (only_set)
	{
		array_destroy(&env_save, (void *(*)(void *))&del_env);
		return (0);
	}
	item->av = &item->av[i];
	return (sh_exec_local_var_ret(env_save, tmp, i,
								sh_exec_simple(data, item, fds)));
}
