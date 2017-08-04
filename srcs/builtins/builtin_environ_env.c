/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_environ_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:21:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/08/04 14:08:16 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_env.h>

int builtins_env_over(t_array *env_local, int ret)
{
  array_destroy(&env_local,  (void (*)(void*))&sh_free_elem_env);  
  return (ret);
}

int sh_builtin_env_opt(char **argv)
{
  int opt;
  int tmp;

  ft_getopt_reset();
  tmp = 0;
  while ((opt = ft_getopt(ft_tablen(argv), argv, "ui")) != -1)
  {
    if (opt == 'u')
       break;
    else if (opt == '?')
      break ;
    else if (opt == 'i')
      tmp = opt;
  }
  if (opt == 'u' && g_optind != -1 && !argv[g_optind])
  {
    ft_dprintf(2, "env: option requires an argument -- 'u'\n");
    opt = -1;
  }
  else if (tmp == 'i' && opt != 'u')
    opt = 'i';
  else if (opt == '?')
    opt = -1;
  return (opt);
}

void	sh_builtin_env_print_env(t_array *envs)
{
	t_env	*e;
	size_t	i;

	i = 0;
  if (!envs || !envs->used)
    return ;
	while (i < envs->used)
	{
		e = (t_env *)array_get_at(envs, i);
		ft_printf("\033[94m%s\033[0m=%s\n", e->name, e->value);
		i++;
	}
}

t_array *sh_get_env_builtins(int opt, char **argv)
{
  t_array *tmp;

  if ((tmp = array_create(sizeof(t_env))) == NULL)
  {
    ft_dprintf(STDERR_FILENO, "Environ: can't initialise local environment\
        variables\n");
    exit(1);
  }
  if (opt == 'i')
    return (sh_builtin_env_i(tmp, argv));
  else if (opt == 'u')
    return (sh_builtin_env_u(tmp, argv));
  return(NULL);
}

int		sh_builtin_env(t_sh_data *data, char **argv)
{
  int opt;
  t_array *env_local;

	(void)data;
	if (!argv[1])
  {
		sh_print_env();
    return (0);
  }
  opt = sh_builtin_env_opt(argv);
  if (opt == -1 && g_optind == 1)
  {
    if (g_optind != -1 && sh_builtin_env_exec(&argv[g_optind], sh_get_envs()))
      return (1);
    return (0);
  }
  if(!(env_local = sh_get_env_builtins(opt, argv)))
    return(1);
  if (g_optind != -1 && sh_builtin_env_exec(&argv[g_optind], env_local))
    return (builtins_env_over(env_local, 1));
  if (g_optind != -1 && !argv[g_optind])
    sh_builtin_env_print_env(env_local);
  ft_getopt_reset();
	return (builtins_env_over(env_local, 0));
}
