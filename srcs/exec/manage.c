/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 14:01:25 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/15 18:31:43 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

/*
** @brief Creates pipes and tests for success
**
** @param pipe contains pipes
** @param fds Contains fds
**
** @return Returns true if successful or false if pipe failed
*/

BOOL	manage_create_pipe(int pipe[3][2], t_list *fds[5])
{
	if (fds[STDOUT_FILENO] && sh_pipe(pipe[STDOUT_FILENO]) == EXIT_FAILURE)
		return (false);
	if (fds[STDIN_FILENO] && sh_pipe(pipe[STDIN_FILENO]) == EXIT_FAILURE)
		return (false);
	if (fds[STDERR_FILENO] && sh_pipe(pipe[STDERR_FILENO]) == EXIT_FAILURE)
		return (false);
	return (true);
}

/*
** @brief TODO
** @param pipe TODO
** @param fds TODO
** @return TODO
*/

BOOL	manage_dup2(int pipe[3][2], t_list *fds[5])
{
	if (fds[STDOUT_FILENO] && (dup2(pipe[STDOUT_FILENO][START],
					STDOUT_FILENO) == -1))
		return (false);
	if (fds[STDIN_FILENO] && (dup2(pipe[STDIN_FILENO][START],
					STDIN_FILENO) == -1))
		return (false);
	if (fds[STDERR_FILENO] && (dup2(pipe[STDERR_FILENO][START],
					STDERR_FILENO) == -1))
		return (false);
	return (true);
}

/*
** @brief TODO
** @param pipe TODO
** @param fds TODO
** @param pos TODO
** @return TODO
*/

BOOL	multi_close(int pipe[3][2], t_list *fds[5], BOOL pos)
{
	if (fds[STDOUT_FILENO] && close(pipe[STDOUT_FILENO][pos]))
		return (false);
	if (fds[STDIN_FILENO] && close(pipe[STDIN_FILENO][pos]))
		return (false);
	if (fds[STDERR_FILENO] && close(pipe[STDERR_FILENO][pos]))
		return (false);
	return (true);
}

/*
** @brief TODO
** @param pipe TODO
** @param fds TODO
*/

void	manage_fds(int pipe[3][2], t_list *fds[5])
{
	t_list	*tmp;
	char	buf[1];
	int		i;
	ssize_t	ret;

	i = CLOSE;
	log_info("EXEC manage_fds");
	while (i--)
	{
		while (fds[i] && (ret = read(pipe[i][END], buf, 1)) && ret != -1)
		{
			tmp = fds[i];
			while (tmp)
			{
				write(tmp->content_size, buf, 1);
				tmp = tmp->next;
			}
		}
	}
}

/*
** @brief TODO
** @param fds TODO
*/

void	manage_close(t_list *fds[5])
{
	t_list		*tmp;

	tmp = fds[CLOSE];
	log_info("EXEC manage_close");
	while (tmp)
	{
		log_info("close = %d", tmp->content_size);
		close(tmp->content_size);
		tmp = tmp->next;
	}
}
