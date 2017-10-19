/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:51:28 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/14 12:32:26 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

int sh_exec_pipe2(t_sh_data *data, t_btree *ast, t_list *fds[4], int wait_flag);

int sh_exec_pipe(t_sh_data *data, t_btree *ast, t_list *fds[4], int wait_flag)
{
	int		pid;

	pid = 0;
	if (!(pid = sh_fork()))
	{
		sh_exec_pipe2(data, ast, fds, wait_flag);
		exit(0);
	}
	sh_wait(pid, 0);
	return (g_ret);
}

int sh_exec_pipe2(t_sh_data *data, t_btree *ast, t_list *fds[4], int wait_flag)
{
	pid_t pid;
	int pipe[2];

	if(sh_pipe(pipe) != 0)
		return (EXIT_FAILURE);
	if((pid = sh_fork()) == -1)
		return (EXIT_FAILURE);
	if(pid == 0)
	{
		dup2(pipe[START], STDOUT_FILENO);
		log_info("fd = %d", pipe[START]);
		//exec_list_push(&fds[STDOUT_FILENO], pipe[START]);
		close(pipe[END]);
		if (!sh_process_exec(data, ast->left, fds, WNOHANG))
			exit (EXIT_SUCCESS);
		exit (EXIT_FAILURE);
	}
	sh_wait(pid, 0);
	close(pipe[START]);
	if (!sh_fork())
	{
		dup2(pipe[END], STDIN_FILENO);
		sh_process_exec(data, ast->right, fds, wait_flag);
		exit(EXIT_FAILURE);
	}
	sh_wait(-1, 0);
	close(pipe[END]);
	return (g_ret);
}

/*int sh_exec_pipe(t_sh_data *data, t_btree *ast, t_list *fds[4], int wait_flag)
{
	pid_t pid;
	int pipe[2];


	if(sh_pipe(pipe) != 0)
		return (EXIT_FAILURE);
	if((pid = sh_fork()) == -1)
		return (EXIT_FAILURE);
	if(pid == 0)
	{
		log_info("G: %d", getpid());
		close(pipe[END]);
		exec_list_push(&fds[STDOUT_FILENO], pipe[START]);
		exec_list_push(&fds[3], pipe[END]);
		if (!(sh_process_exec(data, ast->left, fds, 0)))
			exit (EXIT_SUCCESS);
		exit (EXIT_FAILURE);
	}
	sh_wait(pid, 0);

	if (!sh_fork())
	{
		//log_info("D: %d", getpid());
		exec_list_push(&fds[3], pipe[START]);
		close(pipe[START]);
		dup2(pipe[END], STDIN_FILENO);
		sh_process_exec(data, ast->right, fds, wait_flag);
		exit(EXIT_SUCCESS);
	}
	sh_wait(0, wait_flag);
	//kill(pid, SIGKILL);
	//log_info("P: %d", getpid());
	close(pipe[END]);
	close(pipe[START]);
	return (g_ret);
}*/
/*int sh_exec_pipe(t_sh_data *data, t_btree *ast, t_list *fds[4])
{
	pid_t	pid;
	int		pipe[2];

	if(sh_pipe(pipe) != 0)
		return (EXIT_FAILURE);
	if((pid = sh_fork()) == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		close(pipe[START]);
		dup2(pipe[END], STDOUT_FILENO);
		sh_process_exec(data, ast->right, fds);
		exit(g_ret);
	}
	exec_list_push(&fds[STDOUT_FILENO], pipe[START]);
	sh_process_exec(data, ast->left, fds);
	waitpid(pid, NULL, 0);
	close(pipe[END]);
	return (g_ret);
}*/
/*
** @brief         count number of pipe
**
** @param  ast     The AST (Analyse Syntax Tree[binary])
**
** @return         number of pipe
*/
/*
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
*/
/*
** @brief         main function for execute pipe command
**
** @param  data    The data of shell
** @param  ast     The AST (Analyse Syntax Tree[binary])
**
** @return         return of sh_exec_pipe
*/
/*
int sh_process_pipe(t_sh_data *data, t_btree *ast)
{
  int   endfd;
  int   ret;

  endfd = -1;
  ret = 0;
  if (sh_fork() == 0)
  {
    while (nb_of_pipe(ast) >= 0)
    {
      if (ast->left)
        ret = sh_exec_pipe(data, ast->left, &endfd, false);
      else
        ret = sh_exec_pipe(data, ast, &endfd, true);
      ast = ast->right;
    }
    exit(EXIT_SUCCESS);
  }
  wait_sh();
  return (ret);
}

static int sh_exec_pipe_parent(int tube[2], int *endfd, t_cmd *item, BOOL is_out)
{
  if (is_out)
    item->info.ret = sh_ret(sh_wait());
  close(tube[START]);
  if (*endfd != -1)
    close(*endfd);
  *endfd = tube[END];
  return ((g_ret = item->info.ret));
}
*/
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
/*
int sh_exec_pipe(t_sh_data *data, t_btree *ast, int *endfd, BOOL is_out)
{
  pid_t pid;
	int tube[2];
  t_cmd *item;

  item = (t_cmd *)ast->item;
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
  return(sh_exec_pipe_parent(tube, endfd, item, is_out));
}
*/
