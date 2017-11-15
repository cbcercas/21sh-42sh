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

extern int g_optind;

t_array	*sh_builtin_env_add(t_array *tmp, char **argv)
{
	char	*name;
	char	*value;

	if (tmp == NULL)
		return (NULL);
	while (g_optind != -1 && argv[g_optind] && ft_strchr(argv[g_optind], '='))
	{
		name = split_var_name(argv[g_optind]);
		value = split_var_value(argv[g_optind]);
		set_var(tmp, name, value, true);
		ft_strdel(&name);
		ft_strdel(&value);
		g_optind++;
	}
	return (tmp);
}
