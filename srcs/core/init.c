/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:19 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 15:12:52 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "init.h"

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

t_ms_data		*ms_init(void)
{
	t_ms_data	*data;

	if ((data = ft_memalloc(sizeof(*data))))
	{
		data->env = ms_copy_environ();
		data->cwd = getwd(data->cwd);
		data->builtins = ms_builtins_init();
	}
	if (!data || !data->env || !data->cwd)
	{
		// TODO add error function malloc
		ft_printf("minishell: error when initialising main data\n");
		return(ms_data_free(&data));
	}
	return (data);
}

void		ms_deinit(t_ms_data **data)
{
	ms_data_free(data);
}