/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_environ_env_i.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:21:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/02 14:42:05 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_env.h>

t_array	*sh_builtin_env_i(t_array *tmp, char **argv)
{
	t_env *env;

	if (tmp == NULL)
		return (NULL);
	while (g_optind != -1 && argv[g_optind] && ft_strchr(argv[g_optind], '='))
	{
		if ((env = var_new(split_var_name(argv[g_optind]), \
                        split_var_value(argv[g_optind]))))
		{
			array_push(tmp, (void *)env);
			ft_memdel((void**)&env);
		}
		else
			ft_dprintf(2, "env: ERROR: env_new() creation local env\n");
		g_optind++;
	}
	return (tmp);
}
