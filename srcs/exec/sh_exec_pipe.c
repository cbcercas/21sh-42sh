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

static void sh_pipe_right(t_sh_data *data, t_btree *ast, t_list **fds, int
*pipe)
{
	close(pipe[START]);
	//dup2(pipe[END], STDIN_FILENO);
	fds[PIPE_IN] = NULL;
	exec_list_push(&fds[PIPE_IN], pipe[END]);
	sh_process_exec(data, ast->right, fds);
	exit(EXIT_SUCCESS);
}

static void sh_pipe_left(t_sh_data *data, t_btree *ast, t_list **fds, int
*pipe)
{
	close(pipe[END]);
	exec_list_push(&fds[PIPE_OUT], pipe[START]);
	//dup2(pipe[START], STDOUT_FILENO);
	sh_process_exec(data, ast->left, fds);
	exit(EXIT_SUCCESS);
}

static t_list *sh_exec_pipe2(t_sh_data *data, t_btree *ast, t_list **fds)
{
	int 	pid;
	int		pipe[2];
	static t_list		*pids = NULL;

	if(sh_pipe(pipe) != 0)
		return (NULL);
	if((pid = sh_fork()) == -1)
		return (NULL);
	if(pid == 0)
		sh_pipe_left(data, ast, fds, pipe);
	exec_list_push(&pids, pid);
	//TODO: wait heredoc
	if((pid = sh_fork()) == -1)
		return (NULL);
	if(pid == 0)
		sh_pipe_right(data, ast, fds, pipe);
	exec_list_push(&pids, pid);
	close(pipe[START]);
	close(pipe[END]);
	return(pids);
}
int sh_exec_pipe(t_sh_data *data, t_btree *ast, t_list **fds)
{
	t_list		*pids;

	signal(SIGWINCH, SIG_IGN);
	pids = sh_exec_pipe2(data, ast, fds);
	log_info("MULTI WAIT");
	while (pids)
	{
		sh_wait(pids->content_size, 0);
		pids = pids->next;
	}
	signal(SIGWINCH, signals_handler);
	return(g_ret);
}