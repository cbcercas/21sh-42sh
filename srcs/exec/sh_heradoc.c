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

/*
** @brief   find fd
** @param  item is the struct of commands
** @param  fds     The list of fd
** @param  fd      the fd
**
** @return true if everything is ok, false otherwise
*/

static BOOL		sh_heredoc_get_fd(t_cmd *item, int *fd, t_array *fds)
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

/*
** @brief   init heredoc, create pipe and fork
** @param  pipe     the pipe
** @param  pid      the pid of fork
**
** @return return the word
*/

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

/*
** @brief   find the word "stop"
** @param  item is the struct of commands
**
** @return return the word
*/

static char		*sh_heredoc_search_end(t_cmd *item)
{
	if (ft_isdigit(item->av[0][0]))
		return (item->av[2]);
	return (item->av[1]);
}

/*
** @brief   wait, restore signal, and close pipe
** @param  pipe     the pipe
**
** @return ret of exec
*/

static int		sh_heredoc_father(int pipe[2])
{
	sh_wait(0, 0);
	restore_sigwinch();
	close(pipe[END]);
	return (*get_cmd_ret());
}

/*
** @brief   exec heredoc
** @param  data    The data of shell
** @param  ast     The AST (Analyse Syntax Tree[binary])
** @param  fds     The list of fd
**
** @return ret of exec
*/

int				sh_exec_heredoc(t_sh_data *data, t_btree *ast, t_array *fds)
{
	int		fd;
	int		pipe[2];
	int		pid;

	if (!ast || heredoc_init(pipe, &pid) == EXIT_FAILURE)
		return (*get_cmd_ret());
	if (!sh_heredoc_get_fd(((t_cmd *)ast->item), &fd, fds))
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
		sh_exec_new_redir_fd(fds, STDIN_FILENO, pipe[END], false);
		sh_process_exec(data, ast->left, fds);
		exit(EXIT_SUCCESS);
	}
	return (sh_heredoc_father(pipe));
}
