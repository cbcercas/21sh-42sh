/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiforge <guiforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:12:03 by guiforge          #+#    #+#             */
/*   Updated: 2017/07/19 23:22:34 by guiforge         ###   ########.fr       */
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

int nb_of_pipe(t_btree *ast)
{
  int   i;
  t_btree *tmp;
  t_cmd *item;

  tmp = ast;
  i = 0;
    item = (t_cmd *)ast->item;
  while(tmp && item->type == E_TOKEN_PIPE)
  {
    i++;
    tmp = tmp->right;
    item = (t_cmd *)ast->item;
  }
  return (i);
}

int sh_exec_pipe(t_sh_data *data, t_btree *ast)
{
  /*pid_t	pid;
  int		statut;
  int		tube[2];*/
  (void)data;
  (void)ast;
  ft_printf("PIPE IS PROGRESS\n");
  return (0);
}

int sh_exec(t_sh_data *data, t_cmd *item)
{
  char	*cmd;
  char  **envtab = NULL;
  pid_t	pid;

  (void)data; // pourquoi je me le trimbal sans jamais, l'utiliser :D
  //envtab = sh_tenv_to_tab();
	item->info.ret = -1;
  cmd = NULL;
  if ((cmd = get_filename(item->av[0])))
  {
    pid = sh_fork();
    if (pid == 0)
    {
      execve(cmd, item->av, NULL);
      exit(0);
    }
    else
      item->info.ret = wait_sh();// status, revois int, et look si segfault et tout, et wait evidement
  }
  ft_strdel(&cmd);
  //ft_strdblfree(envtab);
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
