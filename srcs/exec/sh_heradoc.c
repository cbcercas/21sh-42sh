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

static void	mini_input(char *end, int pipe_fd)
{
	char *line;

	if (!end)
	{
		ft_dprintf(2, "%s: exec parser error \\n\n", PROGNAME);
		return ;
	}
	ft_putstr("heredoc>");
	log_info("EXEC: HEREDOC word end = (%s)", end);
	while (get_next_line(0, &line))
	{
		if (line && ft_strequ(line, end))
			break ;
		ft_putendl_fd(line, pipe_fd);
		ft_strdel(&line);
		ft_putstr("heredoc>");
	}
	ft_strdel(&line);
}

static BOOL	sh_heredoc_get_fd(t_cmd *item, int *fd)
{
	if (ft_isdigit(item->av[0][0]))
	{
		if (check_fd(atoi(item->av[0])))
			*fd = atoi(item->av[0]);
		else
			return (false);
	}
	else
		*fd = STDIN_FILENO;
	return (true);
}

static int heredoc_init(t_btree *ast, int *fd, int pipe[2], int *pid)
{
	if (!sh_heredoc_get_fd(((t_cmd *)ast->item), fd))
		return ((*get_cmd_ret() = EXIT_FAILURE));
	if(sh_pipe(pipe) != 0)
		return((*get_cmd_ret() = EXIT_FAILURE));
	signal(SIGWINCH, SIG_IGN);
	if((*pid = sh_fork(E_PID_HERE)) == -1)
		return((*get_cmd_ret() = EXIT_FAILURE));
	if (!*pid)
		signal(SIGINT, SIG_IGN);
	return (EXIT_SUCCESS);
}

static char	*sh_heredoc_search_end(t_cmd *item)
{
	if (ft_isdigit(item->av[0][0]))
		return (item->av[2]);
	return (item->av[1]);
}

int sh_heredoc(t_sh_data *data, t_btree *ast, t_list **fds)
{
	int		fd;
	int		pipe[2];
	int		pid;

	if (!ast || heredoc_init(ast, &fd, pipe, &pid) == EXIT_FAILURE)
		return (*get_cmd_ret());
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
		(fds[PIPE_IN] ? ft_lstdel(&fds[PIPE_IN], &exec_list_nothing) : 0); //TODO si ft_lstdel est secure on peut remove le ternaire :D
		exec_list_push(&fds[PIPE_IN], pipe[END]);
		sh_process_exec(data, ast->left, fds);
		exit(EXIT_FAILURE);
	}
	sh_wait(0, 0);
	signal(SIGWINCH, signals_handler);
	close(pipe[END]);
	kill(0, SIGUSR2);
	return (*get_cmd_ret());
}
