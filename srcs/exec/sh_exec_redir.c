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

static void		redir_great(t_cmd *item, t_list **fds, int fd)
{
	if (ft_isdigit(item->av[0][0]))
	{
		if (check_fd(ft_atoi(item->av[0])))
		{
			fds[ft_atoi(item->av[0])] = NULL;
			exec_list_push(&fds[ft_atoi(item->av[0])], fd);
		}
		else
			exit(EXIT_FAILURE);
	}
	else
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

static BOOL		sh_exec_redir_init(t_btree *ast, t_cmd **item, int *fd)
{
	if (!ast)
	{
		return (false);
	}
	*item = (t_cmd *)ast->item;
	if ((*fd = sh_open_exec(ast)) == -1)
	{
		*get_cmd_ret() = EXIT_FAILURE;
		return (false);
	}
	ignore_sigwinch();
	return (true);
}

int				sh_exec_redir(t_sh_data *data, t_btree *ast, t_list **fds)
{
	int		fd;
	t_cmd	*item;

	if (!sh_exec_redir_init(ast, &item, &fd))
		return (*get_cmd_ret());
	if (sh_fork(E_PID_REDIR) == 0)
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
	restore_sigwinch();
	close(fd);
	return (*get_cmd_ret());
}
