/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_environ_env_i.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:21:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/08/04 13:18:06 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_env.h>

t_array *sh_builtin_env_i(t_array *tmp, char **argv)
{
  t_env *env;

  if (tmp == NULL)
    return(NULL);
  while (g_optind != -1 && argv[g_optind] && ft_strchr(argv[g_optind], '='))
  {
    if ((env = env_new(split_env_name(argv[g_optind]), split_env_value(argv[g_optind]))))
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
