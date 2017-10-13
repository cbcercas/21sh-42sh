/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:12:03 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/13 19:50:58 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

BOOL	manage_fds(t_list *fds[4])
{
	t_list	*tmp;

	tmp = fds[STDOUT_FILENO];
	while (tmp)
	{
		if (dup2(tmp->content_size, STDOUT_FILENO) == -1)
		{
			ft_dprintf(STDERR_FILENO, "Exec: Error dup2\n");
			return (false);
		}
		exec_list_push(&fds[3], tmp->content_size);
		tmp = tmp->next;
	}
	//ft_lstdel(&fds[STDOUT_FILENO], NULL);


	tmp = fds[STDIN_FILENO];
	while (tmp)
	{
		if (dup2(tmp->content_size, STDIN_FILENO) == -1)
		{
			ft_dprintf(STDERR_FILENO, "Exec: Error dup2\n");
			return (false);
		}
		exec_list_push(&fds[3], tmp->content_size);
		tmp = tmp->next;
	}
	//ft_lstdel(&fds[STDIN_FILENO], NULL);


	tmp = fds[STDERR_FILENO];
	while (tmp)
	{
		if (dup2(tmp->content_size, STDERR_FILENO) == -1)
		{
			ft_dprintf(STDERR_FILENO, "Exec: Error dup2\n");
			return (false);
		}
		exec_list_push(&fds[3], tmp->content_size);
		tmp = tmp->next;
	}
	//ft_lstdel(&fds[STDERR_FILENO], NULL);
	return (true);
}

BOOL	multi_close(t_list *fds[4])
{
	t_list	*tmp;

	tmp = fds[3];
	while (tmp)
	{
		if (close(tmp->content_size) == -1)
		{
			ft_dprintf(STDERR_FILENO, "Exec: Error close\n");
			return (false);
		}
		tmp = tmp->next;
	}
	//ft_lstdel(&fds[3], NULL);
	return (true);
}

/*
 ** @brief          exec a system command
 **
 ** @param  data    The data of shell
 ** @param  item    The item in AST
 **
 ** @return         status set by wait
 */

int		sh_exec(t_sh_data *data, t_cmd *item, t_list *fds[4])
{
	char	*cmd;
	char  **envtab = NULL;
	pid_t	pid;

	(void)data;
	envtab = var_to_tab(get_envs());
	item->info.ret = -1;
	cmd = NULL;
	if ((cmd = get_filename(item->av[0])))
	{
		pid = sh_fork();
		manage_fds(fds);
		if (pid == 0)
		{
			execve(cmd, item->av, envtab);
			exit(0);
		}
		item->info.ret = sh_ret(wait_sh());
	}
	multi_close(fds);
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

int  sh_exec_simple(t_sh_data *data, t_cmd *item, t_list *fds[4])
{
	int ret;

	ret = 0;
	if (sh_is_builtin(item->av[0]))
		ret = sh_exec_builtin(data, item);
	else
		ret = sh_exec(data, item, fds);
	return(ret);
}
