/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:12:03 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/20 13:40:06 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

pid_t  sh_fork(void)
{
  pid_t pid;

  pid = 0;
  if ((pid = fork()) == -1)
    ft_printf("fork error\n");
  return (pid);
}

int sh_exec(t_sh_data *data, t_cmd *item)
{
  char	*cmd;
  char  **envtab = NULL;
  pid_t	pid;

  (void)data; // pourquoi je me le trimbal sans jamais, l'utiliser :D
  envtab = sh_tenv_to_tab();
	item->info.ret = -1;
  cmd = NULL;
  if ((cmd = get_filename(item->av[0])))
  {
    pid = sh_fork();
    if (pid == 0)
    {
      execve(cmd, item->av, envtab);
      exit(0);
    }
    else
      item->info.ret = wait_sh();// status, revois int, et look si segfault et tout, et wait evidement
  }
  ft_strdel(&cmd);
  ft_strdblfree(envtab);
  envtab = NULL;
  return (item->info.ret);
}

int sh_exec_builtin(t_sh_data *data, t_cmd *item)
{
  t_builtin *builtin;

  builtin	= get_builtin(item->av[0]);
  item->info.ret = -1;
  if (builtin)
    item->info.ret = builtin->fn(data, item->av);
  return (item->info.ret);
}

int  sh_exec_simple(t_sh_data *data, t_cmd *item)
{
    if (sh_is_builtin(item->av[0]))
      return(sh_exec_builtin(data, item));
    return (sh_exec(data, item));
}
