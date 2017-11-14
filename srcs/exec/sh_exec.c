/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:12:03 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/15 13:02:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

static int sh_exec_parent(t_list **fds, char *path, int pipe[3][2], int pid)
{
	if (!multi_close(pipe, fds, START))
		return (EXIT_FAILURE);
	manage_fds(pipe, fds);
	if (!multi_close(pipe, fds, END))
		return (EXIT_FAILURE);
	ft_strdel(&path);
	*get_cmd_ret() = sh_ret(sh_wait(pid, 0)); // TODO a mettre dans
	signal(SIGWINCH, signals_handler);
	return (*get_cmd_ret());
}

/*
 ** @brief          exec a system command
 **
 ** @param  data    The data of shell
 ** @param  item    The item in AST
 **
 ** @return         status set by wait
 */

static int sh_exec(t_cmd *item, t_list **fds)
{
	char	*path;
	int		pipe[3][2];
	pid_t	pid;

	pid = -1;
	if ((path = get_filename(item->av[0])))
	{
		if (!manage_create_pipe(pipe, fds))
			return (EXIT_FAILURE);
		if((pid = sh_fork(E_PID_CMD)) == -1)
			return (EXIT_FAILURE);
		signal(SIGWINCH, NULL);
		if (!pid)
		{
			if (!manage_dup2(pipe, fds))
				exit(EXIT_FAILURE);
			manage_close(fds);
			execve(path, item->av, var_to_tab(get_envs()));
			exit(EXIT_FAILURE);
		}
	}
	get_pid_child(pid);
	return (sh_exec_parent(fds, path, pipe, pid));
}

/*
 ** @brief          exec a builtin command
 **
 ** @param  data    The data of shell
 ** @param  item    The item in AST
 **
 ** @return         result of builtin
 */

static int sh_exec_builtin(t_sh_data *data, t_cmd *item, t_list **fds)
{
	t_builtin *builtin;
	int		pipe[3][2];

	if (!manage_create_pipe(pipe, fds))
		return (EXIT_FAILURE);
	if (!manage_dup2(pipe, fds))
		return (EXIT_FAILURE);
	manage_close(fds);
	builtin = get_builtin(item->av[0]);
	if (builtin)
		*get_cmd_ret() = builtin->fn(data, item->av);
	if (fds[STDOUT_FILENO])
		close(STDOUT_FILENO);
	if (fds[STDIN_FILENO])
		close(STDIN_FILENO);
	if (fds[STDERR_FILENO])
		close(STDERR_FILENO);
	if (!multi_close(pipe, fds, START))
		return (EXIT_FAILURE);
	manage_fds(pipe, fds);
	if (!multi_close(pipe, fds, END))
		return (EXIT_FAILURE);
	return (*get_cmd_ret());
}

/*
 ** @brief          call sh_exec_builtin or sh_exec
 **
 ** @param  data    The data of shell
 ** @param  item    The item in AST
 **
 ** @return         result of sh_exec_builtin or sh_exec
 */

int sh_exec_simple(t_sh_data *data, t_cmd *item, t_list **fds)
{
	int ret;

	ret = 1;
	log_info("EXEC: %s", item->av[0]);
	if(fds[PIPE_OUT])
		dup2((int)fds[PIPE_OUT]->content_size, STDOUT_FILENO);
	if(fds[PIPE_IN])
		dup2((int)fds[PIPE_IN]->content_size, STDIN_FILENO);
	if (item && item->av && ft_strchr(item->av[0], '=') && ft_strlen(item->av[0]) != 1)
		sh_exec_local_var(data, item, fds);
	else if (sh_is_builtin(item->av[0]))
		ret = sh_exec_builtin(data, item, fds);
	else
		ret = sh_exec(item, fds);
	return(ret);
}
