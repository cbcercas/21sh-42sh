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

#include <builtins/builtin_env.h>

extern int g_optind;

/*
** @brief Removed a value from the env
**
** @param tmp The current environment
** @param argv Contains the values to be removed
**
** @return Returns the modified env
*/

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
