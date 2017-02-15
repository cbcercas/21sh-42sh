/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:19 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/15 11:00:06 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/init.h>

static void			*ms_data_free(t_ms_data	**data)
{
	if ((*data)->env)
		ms_lst_env_del(&(*data)->env);
	if ((*data)->cwd)
		ft_strdel(&(*data)->cwd);
	if (*data)
		ft_memdel((void**)data);
	return (NULL);
}

void	ms_print_env(t_env *env)
{
	ft_printf("\n-------------- DEBUG --------------\n");
	while (env)
	{
		ft_printf("%s=%s\n",env->name, env->value);
		env = env->next;
	}
	ft_printf("-----------------------------------\n");
}


t_ms_data		*ms_init(void)
{
	t_ms_data	*data;

	if ((data = ft_memalloc(sizeof(*data))))
	{
		data->env = ms_copy_environ();
		data->cwd = getwd(data->cwd);
		data->builtins = ms_builtins_init();
	}
	if (!(ms_getenv(data->env, "TERM")) || ft_strequ(ms_getenv(data->env, "TERM"), ""))
		ms_setenv(data->env, "TERM", "dumb");
	if (!data || !data->env || !data->cwd)
	{
		// TODO add error function malloc
		ft_printf("minishell: error when initialising main data\n");
		return(ms_data_free(&data));
	}
	//ms_print_env(data->env);
	return (data);
}

void		ms_deinit(t_ms_data **data)
{
	ms_data_free(data);
}