/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_environ_env_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:21:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/02 14:46:11 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/env_list_utils.h>
#include <array/array.h>
#include <logger.h>
#include <secure_memory/ft_secu_malloc.h>
#include <ftprintf.h>
#include <environ/env_utils.h>
#include <environ/modif_env.h>

extern int g_optind;

t_array			*sh_builtin_env_u(t_array *tmp, char **argv)
{
	if (tmp == NULL)
		return (NULL);
	tmp = clone_vars(get_envs(), tmp);
	if (g_optind != -1 && argv[g_optind])
	{
		del_var(tmp, argv[g_optind]);
		g_optind++;
	}
	return (tmp);
}
