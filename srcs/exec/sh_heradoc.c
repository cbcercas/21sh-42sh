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
	while (get_next_line(0, &line))
	{
		if (line && ft_strequ(line, end))
			break ;
		ft_putendl_fd(line, pipe_fd);
		ft_strdel(&line);
		ft_putstr("heredoc>");
	}
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

static char	*sh_heredoc_search_end(t_cmd *item)
{
	if (ft_isdigit(item->av[0][0]))
		return (item->av[2]);
	return (item->av[1]);
}

int sh_heredoc(t_sh_data *data, t_btree *ast, t_list *fds[4], int wait_flag)
{
	int		fd;
	int		pipe[2];
	t_cmd	*item;

	if (!ast)
		return (g_ret);
	item = (t_cmd *)ast->item;
	if (!sh_heredoc_get_fd(item, &fd))
		return ((g_ret = -1));
	signal(SIGINT, SIG_IGN);
	if (!sh_pipe(pipe) && !sh_fork())
	{
		close(pipe[END]);
		mini_input(sh_heredoc_search_end(item), pipe[START]);
		exit(EXIT_SUCCESS);
	}
	sh_wait(0, 0);
	signal(SIGINT, signals_handler);
	close(pipe[START]);
	if (!sh_fork())
	{
		dup2(pipe[END], fd);
		sh_process_exec(data, ast->left, fds, wait_flag);
		exit(EXIT_FAILURE);
	}
	sh_wait(0, 0);
	close(pipe[END]);
	return (g_ret);
}
