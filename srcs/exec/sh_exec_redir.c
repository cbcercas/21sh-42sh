/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 11:49:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/15 12:45:54 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>
#include <btree/ft_btree.h>
#include <ast/ast.h>
#include <tools/tools.h>
#include <core/prompt.h>
#include <signals/signals.h>
#include <ftprintf.h>
#include <fcntl.h>
#include <signal.h>

static	void	redir_great(t_cmd *item, t_list **fds, int fd)
{
	if (ft_isdigit(item->av[0][0]))
	{
		if (check_fd(ft_atoi(item->av[0])))
		{
			fds[ft_atoi(item->av[0])] = NULL;
			exec_list_push(&fds[ft_atoi(item->av[0])], fd);
		} else
			exit(EXIT_FAILURE);
	} else
	{
		fds[STDOUT_FILENO] = NULL;
		exec_list_push(&fds[STDOUT_FILENO], fd);
	}
}

static void		redir_less(t_cmd *item, int fd)
{
	if (ft_isdigit(item->av[0][0]))
	{
		if (check_fd(ft_atoi(item->av[0])))
			dup2(fd, ft_atoi(item->av[0]));
		else
			exit(EXIT_FAILURE);
	}
	else
		dup2(fd, STDIN_FILENO);
}

int sh_exec_redir(t_sh_data *data, t_btree *ast, t_list **fds)
{
	int		fd;
	t_cmd	*item;

	if (!ast)
		return (g_ret);
	item = (t_cmd *)ast->item;
	if ((fd = sh_open_exec(ast)) == -1)
		return((g_ret = EXIT_FAILURE));
	signal(SIGWINCH, SIG_IGN);
	if (sh_fork() == 0)
	{
		if (fd != -1)
		{
			if (item->type == E_TOKEN_DGREAT || ft_strequ(item->av[0], ">")
				|| ft_strequ(item->av[1], ">"))
				redir_great(item, fds, fd);
			else
				redir_less(item, fd);
			sh_process_exec(data, ast->left, fds);
		}
		exit(EXIT_SUCCESS);
	}
	sh_wait(0, 0);
	signal(SIGWINCH, signals_handler);
	close(fd);
	return(g_ret);
}

