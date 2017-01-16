/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:19 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 11:25:58 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "init.h"

void			*cbc_main_data_free(t_main_data	**data)
{
	if ((*data)->env)
		// TODO add free tenv list cbc_tenv_del((*data)->env);
		ft_printf("free data->env\n");
	if ((*data)->cwd)
		ft_strdel(&(*data)->cwd);
	if (*data)
		ft_memdel((void**)data);
	return (NULL);
}

t_main_data		*init(void)
{
	t_main_data	*data;

	if ((data = ft_memalloc(sizeof(*data))))
	{
		data->env = cbc_copy_environ();
		data->cwd = getwd(data->cwd);
	}
	if (!data || !data->env || !data->cwd)
	{
		// TODO add error function malloc
		ft_printf("minishell: error when initialising main data\n");
		return(cbc_main_data_free(&data));
	}
	return (data);
}