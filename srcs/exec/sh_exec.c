/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:12:03 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/04 19:42:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

int manage_fds_start(t_array *fds, int pipes[3][3])
{
	int *fd;

	fd = (int *)array_get_at(fds, START);
	if (!fd)
		return (EXIT_FAILURE);
	close(pipes[STDIN_FILENO][END]);
	close(pipes[STDOUT_FILENO][END]);
	close(pipes[STDERR_FILENO][END]);

	if (dup2(pipes[STDIN_FILENO][START], fd[STDIN_FILENO]) == -1)
		return (EXIT_FAILURE);
	if (dup2(pipes[STDOUT_FILENO][START], fd[STDOUT_FILENO]) == -1)
		return (EXIT_FAILURE);
	if (dup2(pipes[STDERR_FILENO][START], fd[STDERR_FILENO]) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int manage_fds_end(t_array *fds, int pipes[3][3])
{
	int *fd;
	char buf[2];

	fd = (int *)array_get_at(fds, END);
	if (!fd)
		return (EXIT_FAILURE);
	close(pipes[STDIN_FILENO][START]);
	close(pipes[STDOUT_FILENO][START]);
	close(pipes[STDERR_FILENO][START]);

	while(read(pipes[STDIN_FILENO][END], buf, 1))
		write(STDIN_FILENO, buf, 1);
	while(read(pipes[STDOUT_FILENO][END], buf, 1))
		write(STDOUT_FILENO, buf, 1);
	while(read(pipes[STDERR_FILENO][END], buf, 1))
		write(STDERR_FILENO, buf, 1);
	return (EXIT_SUCCESS);
}

int multipl_pipe(int pipes[3][3])
{
	if(sh_pipe(pipes[STDIN_FILENO]) != 0)
		return (EXIT_FAILURE);
	if(sh_pipe(pipes[STDOUT_FILENO]) != 0)
		return (EXIT_FAILURE);
	if(sh_pipe(pipes[STDERR_FILENO]) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
 ** @brief          exec a system command
 **
 ** @param  data    The data of shell
 ** @param  item    The item in AST
 **
 ** @return         status set by wait
 */

int sh_exec(t_sh_data *data, t_cmd *item, t_array *fds)
{
	char	*cmd;
	char  **envtab = NULL;
	pid_t	pid;
	int	pipes[3][3];

	(void)fds;
	if (multipl_pipe(pipes) != 0)
		return ((g_ret = EXIT_FAILURE));
	(void)data;
	envtab = sh_tenv_to_tab();
	item->info.ret = -1;
	cmd = NULL;
	if ((cmd = get_filename(item->av[0])))
	{
		pid = sh_fork();
		if (pid == 0)
		{
			if (manage_fds_start(fds, pipes))
				return ((g_ret = EXIT_FAILURE));
			execve(cmd, item->av, envtab);
			exit(0);
		}
		item->info.ret = sh_ret(wait_sh());
		manage_fds_end(fds, pipes);
	}
	ft_strdel(&cmd);
	ft_strdblfree(envtab);
	envtab = NULL;
	g_ret = item->info.ret;
	return (item->info.ret);
}

/*
 ** @brief          exec a builtin command
 **
 ** @param  data    The data of shell
 ** @param  item    The item in AST
 **
 ** @return         result of builtin
 */

int sh_exec_builtin(t_sh_data *data, t_cmd *item)
{
	t_builtin *builtin;

	builtin	= get_builtin(item->av[0]);
	item->info.ret = -1;
	if (builtin)
		item->info.ret = builtin->fn(data, item->av);
	g_ret = item->info.ret;
	return (item->info.ret);
}

/*
 ** @brief          call sh_exec_builtin or sh_exec
 **
 ** @param  data    The data of shell
 ** @param  item    The item in AST
 **
 ** @return         result of sh_exec_builtin or sh_exec
 */

int  sh_exec_simple(t_sh_data *data, t_cmd *item, t_array *fds)
{
	int ret;

	ret = 0;
	if (sh_is_builtin(item->av[0]))
		ret = sh_exec_builtin(data, item);
	else
		ret = sh_exec(data, item, fds);
	return(ret);
}
