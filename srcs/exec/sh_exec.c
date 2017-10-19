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

# include <exec/exec.h>

/*
 ** @brief          exec a system command
 **
 ** @param  data    The data of shell
 ** @param  item    The item in AST
 **
 ** @return         status set by wait
 */

int sh_exec(t_cmd *item, t_list *fds[5], int wait_flag)
{
	char	*path;
	int		pipe[3][2];
	pid_t	pid;

	if ((path = get_filename(item->av[0])))
	{
		if (!manage_create_pipe(pipe, fds))
			return (EXIT_FAILURE);
		signal(SIGWINCH, NULL);
		if (fds[4] && (dup2(fds[4]->content_size,
							STDOUT_FILENO) == -1))
			return (false);
		if (!(pid = sh_fork()))
		{
			if (!manage_dup2(pipe, fds))
				exit(EXIT_FAILURE);
			manage_close(fds);
			execve(path, item->av, var_to_tab(get_envs()));
			exit(EXIT_FAILURE);
		}
		g_ret = sh_ret(sh_wait(pid, wait_flag)); // TODO a mettre dans
		signal(SIGWINCH, signals_handler);
	}
	if (!multi_close(pipe, fds, START))
		return (EXIT_FAILURE);

	log_info("EXEC: manage_fds %s = [%d]", item->av[0], getpid());
		manage_fds(pipe, fds);
	if (!multi_close(pipe, fds, END))
		return (EXIT_FAILURE);
	ft_strdel(&path);
	return (g_ret);
}

/*
 ** @brief          exec a builtin command
 **
 ** @param  data    The data of shell
 ** @param  item    The item in AST
 **
 ** @return         result of builtin
 */

int sh_exec_builtin(t_sh_data *data, t_cmd *item, t_list *fds[5])
{
	t_builtin *builtin;
	int		pipe[3][2];

	if (!manage_create_pipe(pipe, fds))
		return (EXIT_FAILURE);
	if (!manage_dup2(pipe, fds))
		return (EXIT_FAILURE);
	manage_close(fds);
	if (fds[4] && (dup2(fds[4]->content_size,
						STDOUT_FILENO) == -1))
		return (false);
	builtin = get_builtin(item->av[0]);
	if (builtin)
		g_ret = builtin->fn(data, item->av);
	if (fds[STDOUT_FILENO])
		close(STDOUT_FILENO);
	if (fds[STDIN_FILENO])
		close(STDERR_FILENO);
	if (!multi_close(pipe, fds, START))
		return (EXIT_FAILURE);
	manage_fds(pipe, fds);
	if (!multi_close(pipe, fds, END))
		return (EXIT_FAILURE);
	return (g_ret);
}

/*
 ** @brief          call sh_exec_builtin or sh_exec
 **
 ** @param  data    The data of shell
 ** @param  item    The item in AST
 **
 ** @return         result of sh_exec_builtin or sh_exec
 */

int sh_exec_simple(t_sh_data *data, t_cmd *item, t_list *fds[5], int wait_flag)
{
	int ret;

	//log_info("EXEC: %s", item->av[0]);
	if (item->av[0][0] == 'c')
		log_info("EXEC: %s = [%d]", item->av[0], getpid());
	ret = 0;
	if (sh_is_builtin(item->av[0]))
		ret = sh_exec_builtin(data, item, fds);
	else
		ret = sh_exec(item, fds, wait_flag);
	return(ret);
}
