/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 11:49:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/20 19:23:03 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

/*
** @brief         function for redirections
**                dup fd with STDIN or STDOUT
**
** @param  data    The data of shell
** @param  ast     The AST (Analyse Syntax Tree[binary])
** @param  item    The item in AST
**
** @return         g_ret ("g_" global) ("ret" return of exec)
*/

int   sh_exec_redir(t_sh_data *data, t_btree *ast, t_cmd *item)
{
  int		fd;


  if ((fd = sh_open_exec(ast)) == -1)
    return((g_ret = 1));
  if (sh_fork() == 0)
  {
    if (fd != -1)
    {
       if (item->av[0][0] == '<')
       {
         if ((fd = sh_heradoc(ast, item, fd)) != -1)
          dup2(fd, STDIN_FILENO);
       }
      else
        dup2(fd, STDOUT_FILENO);
      sh_process_exec(data, ast->left);
      close(fd);
    }
    exit(1);
  }
  wait_sh();
  return(g_ret);
}

/*
** @brief         function for dup redirections in greatand commands (>&)
**
** @param  fd_out  The fd to display out
** @param  fd_in   The fd not display
** @param  item    The item in AST
**
** @return         no return
*/

static void sh_exec_greatand_dup2(int fd_out, int fd_in, t_cmd *item)
{
  if (ft_isdigit(item->av[0][0]))
    dup2(fd_out, fd_in);
  else
  {
    dup2(fd_out, STDOUT_FILENO);
    dup2(fd_out, STDIN_FILENO);
    dup2(fd_out, STDERR_FILENO);
  }
}

/*
** @brief         function for open fd redirections in greatand commands (>&)
**
** @param  fd_out  The fd to display out
** @param  fd_in   The fd not display
** @param  item    The item in AST
**
** @return         0 or 1 if error
*/

static int sh_exec_greatand_open(int *fd_out, int *fd_in, t_cmd *item)
{
  if (!item || !item->av || !item->av[0] || !item->av[1])
    return(ft_dprintf(2, "Error: in exec (redir greatand)\n"));
  if((item->av[2] && ft_strequ(item->av[2], "-"))|| ft_strequ(item->av[1], "-"))
    *fd_out = sh_open("/dev/null", O_RDWR | O_CREAT);
  else if((item->av[2] && ft_isdigit_str(item->av[2])) || (!item->av[2] && ft_isdigit_str(item->av[1])))
    *fd_out = (item->av[2] ? atoi(item->av[2]) : atoi(item->av[1]));
  else if (item->av[2])
    *fd_out = sh_open(item->av[2], O_RDWR | O_CREAT);
  else
    *fd_out = sh_open(item->av[1], O_RDWR | O_CREAT);
  if (*fd_out == -1)
    return((g_ret = 1));
  if ((*fd_in = ft_atoi(item->av[0])) >= 3)
  {
    ft_dprintf(2, "Error: Wrong redirection\n");
    return((g_ret = 1));
  }
  return (0);
}

/*
** @brief         function main for redirections in greatand commands (>&)
**                call sh_exec_greatand_open and sh_exec_greatand_dup2
**
** @param  data    The data of shell
** @param  ast     The AST (Analyse Syntax Tree[binary])
** @param  item    The item in AST
**
** @return         0 or 1 if error
*/

int   sh_exec_greatand(t_sh_data *data, t_btree *ast, t_cmd *item)
{
  pid_t pid;
  int		fd_out;
  int   fd_in;

  if (sh_exec_greatand_open(&fd_out, &fd_in, item))
    return (1);
  pid = sh_fork();
  if (pid == 0)
  {
    if (fd_out != -1)
    {
      sh_exec_greatand_dup2(fd_out, fd_in, item);
      sh_process_exec(data, ast->left);
      close(fd_out);
      close(fd_in);
    }
    exit(1);
  }
  wait_sh();
  if (fd_out > 2)
    close(fd_out);
  if (fd_in > 2)
    close(fd_in);
  return(g_ret);
}
