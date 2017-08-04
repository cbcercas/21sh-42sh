/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:51:28 by gpouyat           #+#    #+#             */
/*   Updated: 2017/08/04 15:19:57 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

/*
** @brief         count number of pipe
**
** @param  ast     The AST (Analyse Syntax Tree[binary])
**
** @return         number of pipe
*/

int nb_of_pipe(t_btree *ast)
{
  int   i;
  t_btree *tmp;
  t_cmd *item;

  if (!ast)
    return (-1);
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

/*
** @brief         main function for execute pipe command
**
** @param  data    The data of shell
** @param  ast     The AST (Analyse Syntax Tree[binary])
**
** @return         return of sh_exec_pipe
*/

int sh_process_pipe(t_sh_data *data, t_btree *ast)
{
  int   endfd;
  int   ret;

  endfd = -1;
  ret = 0;
  while (nb_of_pipe(ast) >= 0)
  {
    if (ast->left)
      ret = sh_exec_pipe(data, ast->left, &endfd, false);
    else
      ret = sh_exec_pipe(data, ast, &endfd, true);
    ast = ast->right;
  }
  return (ret);
}

static int sh_exec_pipe_parent(int tube[2], int *endfd, t_cmd *item)
{
  item->info.ret = sh_ret(wait_sh());//TODO: probleme si $> command infini | command fini
  close(tube[START]);
  if (*endfd != -1)
    close(*endfd);
    *endfd = tube[END];
  return ((g_ret = item->info.ret));
}

/*
** @brief          create pipe, and dup STDIN_FILENO and STDOUT_FILENO in pipe
**
** @param  data    The data of shell
** @param  ast     The AST (Analyse Syntax Tree[binary])
** @param  endfd   it is end of pipe of the last pipe command
** @param  is_out  true: last command, false: dup STDOUT
**
** @return          return of sh_exec_pipe_parent, (the status set by wait)
*/

int sh_exec_pipe(t_sh_data *data, t_btree *ast, int *endfd, BOOL is_out)
{
  pid_t pid;
	int tube[2];
  char  *cmd;
  t_cmd *item;

  item = (t_cmd *)ast->item;
  cmd = NULL;
	if(sh_pipe(tube) != 0)
		return (EXIT_FAILURE);
	 if((pid = sh_fork()) == -1)
    return (EXIT_FAILURE);
	if(pid == 0)
	{
    ((*endfd != -1) ? dup2(*endfd, STDIN_FILENO) : 0);
    ((!is_out) ? dup2(tube[START], STDOUT_FILENO) : 0);
    close(tube[END]);
    if (!sh_process_exec(data, ast))
      exit (EXIT_SUCCESS);
    exit (EXIT_FAILURE);
	}
  return(sh_exec_pipe_parent(tube, endfd, item));
}
