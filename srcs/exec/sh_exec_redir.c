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

static BOOL		redir_great(t_cmd *item, t_list **fds, int fd)
{
	if (ft_isdigit(item->av[0][0]))
	{
		if (ft_isdigit(item->av[0][0]) && ft_strlen(item->av[0]) == 1)
		{
			(fds[ft_atoi(item->av[0])] ? ft_lstdel(&fds[ft_atoi(item->av[0])],
												&exec_list_nothing) : 0);
			exec_list_push(&fds[ft_atoi(item->av[0])], fd);
		}
		else
			return (false);
	}
	else
	{
		(fds[STDOUT_FILENO] ? ft_lstdel(&fds[STDOUT_FILENO],
										&exec_list_nothing) : 0);
		exec_list_push(&fds[STDOUT_FILENO], fd);
	}
	return (true);
}

static BOOL		redir_less(t_cmd *item, int fd, t_list **fds)
{
	if (ft_isdigit(item->av[0][0]))
	{
		if (ft_isdigit(item->av[0][0]) && ft_strlen(item->av[0]) == 1)
		{
			(fds[fd] ? ft_lstdel(&fds[fd], &exec_list_nothing) : 0);
			exec_list_push(&fds[fd], (size_t)ft_atoi(item->av[0]));
		}
		else
			return (false);
	}
	else
	{
		(fds[STDIN_FILENO] ? ft_lstdel(&fds[STDIN_FILENO], &exec_list_nothing)
						: 0);
		exec_list_push(&fds[STDIN_FILENO], (size_t)fd);
		fds[STDIN_FILENO]->content = (void *)true;
	}
	return (true);
}

static BOOL		sh_exec_redir_init(t_btree *ast, t_cmd **item, int *fd)
{
	if (!ast)
		return (false);
	*item = (t_cmd *)ast->item;
	if ((*fd = sh_open_exec(ast)) == -1)
	{
		*get_cmd_ret() = EXIT_FAILURE;
		return (false);
	}
	return (true);
}

int				sh_exec_redir(t_sh_data *data, t_btree *ast, t_list **fds)
{
	int		fd;
	t_cmd	*item;

	if (!sh_exec_redir_init(ast, &item, &fd))
		return (*get_cmd_ret());
	if (item->type == E_TOKEN_DGREAT || ft_strequ(item->av[0], ">")
		|| ft_strequ(item->av[1], ">"))
	{
		if (!redir_great(item, fds, fd))
			return (*get_cmd_ret() = 2);
	}
	else if (!redir_less(item, fd, fds))
		return (*get_cmd_ret() = 2);
	sh_process_exec(data, ast->left, fds);
	return (*get_cmd_ret());
}
