/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:51:28 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/20 13:40:06 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

int nb_of_pipe(t_btree *ast)
{
  int   i;
  t_btree *tmp;
  t_cmd *item;

  tmp = ast;
  i = -1;
    item = (t_cmd *)ast->item;
  while(tmp && item->type == E_TOKEN_PIPE)
  {
    i++;
    tmp = tmp->right;
    item = (t_cmd *)ast->item;
  }
  return (i);
}

int sh_process_pipe(t_sh_data *data, t_btree *ast)
{
  t_btree  *tmp;

  tmp = ast;
  log_info("PIPE");
  while (nb_of_pipe(tmp) > 0)
  {
    log_info("++pipe boucle");
    sh_exec_pipe(data, ast->left);
    tmp = tmp->right;
  }
  log_info("fin pipe");
  return (sh_process_exec(data, ast->right));
}

int sh_exec_pipe(t_sh_data *data, t_btree *ast)
{
  pid_t pid;
	int tube[2];
  char  *cmd;
  t_cmd *item;

  (void)data;
  item = (t_cmd *)ast->item;
  cmd = NULL;
	if(pipe(tube) != 0)
	{
		ft_putstr_fd("Error creation of pipe.\n", 2);
		return (EXIT_FAILURE);
	}
  if ((cmd = get_filename(item->av[0])))
	 pid = sh_fork();
  else
    return (-1);
	if(pid == 0)
	{
    dup2(tube[START], STDOUT_FILENO);
    close(tube[END]);
    log_info("exec: %s", item->av[0]);
      execve(cmd, item->av, NULL);
    exit (1);
	}
  close(tube[START]);
  wait(NULL);
  dup2(tube[END], STDIN_FILENO);
  ft_strdel(&cmd);
  return (0);
}
