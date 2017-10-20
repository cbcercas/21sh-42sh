/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_heradoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:35:43 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/20 18:38:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <btree/ft_btree.h>
#include <ast/ast.h>
#include <exec/exec.h>
#include <gnl/get_next_line.h>
#include <tools/tools.h>
#include <signals/signals.h>

static void mini_input(char *end, int fd)
{
  char *line;

  ft_putstr("heredoc>");
  while (get_next_line(0, &line))
  {
    if (!ft_strcmp(line, end))
      break;
    ft_putendl_fd(line, fd);
    ft_strdel(&line);
    ft_putstr("heredoc>");
  }
  exit(EXIT_SUCCESS);
}

static char *heradoc_find_end(t_btree *ast)
{
  t_cmd *item;

  item = NULL;
  if (ast && ast->right && !ast->right->left)
    item = (t_cmd *)ast->right->item;
  else if (ast && ast->right && ast->right->left)
    item = (t_cmd *)ast->right->left->item;
  if (item)
    return (item->av[0]);
  return (NULL);
}

static void more_heradoc(t_btree *ast, int tube[2])
{
  pid_t pid;
  t_cmd *tmp;

  if((pid = sh_fork()) == -1)
    return ;
  if (pid == 0)
  {
    close(tube[END]);
    mini_input(heradoc_find_end(ast), tube[START]);
    exit (1);
  }
  wait_sh();
  if (ast->right && (tmp = (t_cmd *)ast->right->item) && tmp->type == E_TOKEN_DLESS)
    more_heradoc(ast->right, tube);
}

int   sh_heradoc(t_btree *ast, t_cmd *item, int fd)
{
  pid_t pid;
  int tube[2];
  t_cmd *tmp;

  (void)ast;
  if (item->type != E_TOKEN_DLESS)
    return (fd);
  if((sh_pipe(tube) != 0) || ((pid = sh_fork()) == -1))
    return (-1);
  if (pid == 0)
  {
    close(tube[END]);
    mini_input(heradoc_find_end(ast), tube[START]);
    exit (EXIT_SUCCESS);
  }
  wait_sh();
  if (ast->right && (tmp = (t_cmd *)ast->right->item) &&\
        tmp->type == E_TOKEN_DLESS)
    more_heradoc(ast->right, tube);
  close(tube[START]);
  return (tube[END]);
}
