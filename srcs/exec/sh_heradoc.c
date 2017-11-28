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

#include <exec/exec.h>

static BOOL		sh_heredoc_get_fd(t_cmd *item, int *fd, t_list **fds)
{
	if (ft_isdigit(item->av[0][0]))
	{
		if (check_fd(ft_atoi(item->av[0]), fds))
			*fd = ft_atoi(item->av[0]);
		else
			return (false);
	}
	else
		*fd = STDIN_FILENO;
	return (true);
}

static int		heredoc_init(int pipe[2], int *pid)
{
	if (sh_pipe(pipe) != 0)
		return ((*get_cmd_ret() = EXIT_FAILURE));
	ignore_sigwinch();
	if ((*pid = sh_fork(E_PID_HERE)) == -1)
		return ((*get_cmd_ret() = EXIT_FAILURE));
	if (!*pid)
		signals(SIGINT, SIG_DFL);
	return (EXIT_SUCCESS);
}

static char		*sh_heredoc_search_end(t_cmd *item)
{
	if (ft_isdigit(item->av[0][0]))
		return (item->av[2]);
	return (item->av[1]);
}

static int		sh_heredoc_father(int pipe[2])
{
	sh_wait(0, 0);
	restore_sigwinch();
	close(pipe[END]);
	return (*get_cmd_ret());
}

int				sh_exec_heredoc(t_sh_data *data, t_btree *ast, t_list **fds)
{
	int		fd;
	int		pipe[2];
	int		pid;

	if (!ast || heredoc_init(pipe, &pid) == EXIT_FAILURE)
		return (*get_cmd_ret());
	if (!sh_heredoc_get_fd(((t_cmd *) ast->item), &fd, NULL))
		return ((*get_cmd_ret() = EXIT_FAILURE));
	if (!pid)
	{
		close(pipe[END]);
		mini_input(sh_heredoc_search_end(((t_cmd *)ast->item)), pipe[START]);
		exit(EXIT_SUCCESS);
	}
	sh_wait(0, 0);
	close(pipe[START]);
	if (!sh_fork(E_PID_HERE))
	{
		(fds[STDIN_FILENO] ? ft_lstdel(&fds[STDIN_FILENO], &exec_list_nothing)
						: 0);
		exec_list_push(&fds[STDIN_FILENO], pipe[END]);
		sh_process_exec(data, ast->left, fds);
		exit(EXIT_FAILURE);
	}
	return (sh_heredoc_father(pipe));
}
