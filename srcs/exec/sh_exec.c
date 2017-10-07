/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:12:03 by gpouyat           #+#    #+#             */
/*   Updated: 2017/08/01 15:26:34 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

/*
** @brief          exec a system command
**
** @param  data    The data of shell
** @param  item    The item in AST
**
** @return         status set by wait
*/

int sh_exec(t_sh_data *data, t_cmd *item)
{
  char	*cmd;
  char  **envtab = NULL;
  pid_t	pid;

  (void)data;
  envtab = var_to_tab(get_envs());
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
      item->info.ret = sh_ret(wait_sh());
  }
  ft_strdel(&cmd);
  ft_strdblfree(envtab);
  envtab = NULL;
  g_ret = item->info.ret;
  return (item->info.ret);
}

/*
** @brief          exec a builtin command
**
** @param  data    The data of shell
** @param  item    The item in AST
**
** @return         result of builtin
*/

int sh_exec_builtin(t_sh_data *data, t_cmd *item)
{
  t_builtin *builtin;

  builtin	= get_builtin(item->av[0]);
  item->info.ret = -1;
  if (builtin)
    item->info.ret = builtin->fn(data, item->av);
  g_ret = item->info.ret;
  return (item->info.ret);
}

/*
** @brief          call sh_exec_builtin or sh_exec
**
** @param  data    The data of shell
** @param  item    The item in AST
**
** @return         result of sh_exec_builtin or sh_exec
*/

int  sh_exec_simple(t_sh_data *data, t_cmd *item)
{
    if (sh_is_builtin(item->av[0]))
      return(sh_exec_builtin(data, item));
    return (sh_exec(data, item));
}
