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

BOOL	manage_create_pipe(int pipe[FD_SETSIZE + 3][2], t_list **fds)
{
	int		cnt;

	cnt = 0;
	while (cnt < FD_SETSIZE)
	{
		if (fds[cnt] && sh_pipe(pipe[cnt]) == EXIT_FAILURE)
		{
			log_fatal("ERROR: file: %s pipe cnt", __FILE__, cnt);
			return (false);
		}
		cnt++;
	}
	return (true);
}

/*
** @brief TODO
** @param pipe TODO
** @param fds TODO
** @return TODO
*/

BOOL	manage_dup2(int pipe[FD_SETSIZE + 3][2], t_list **fds)
{
	int		cnt;

	cnt = 0;
	while (cnt < FD_SETSIZE)
	{
		if (fds[cnt] && (dup2(pipe[cnt][START], cnt) == -1))
		{
			log_fatal("ERROR: file: %s dup2 cnt %d", __FILE__, cnt);
			return (false);
		}
		cnt++;
	}
	return (true);
}

/*
** @brief TODO
** @param pipe TODO
** @param fds TODO
** @param pos TODO
** @return TODO
*/

BOOL	multi_close(int pipe[FD_SETSIZE + 3][2], t_list **fds, BOOL pos)
{
	int		cnt;

	cnt = 0;
	while (cnt < FD_SETSIZE)
	{
		if (fds[cnt] && close(pipe[cnt][pos]))
		{
			log_fatal("ERROR: file: %s close cnt %d", __FILE__, cnt);
			return (false);
		}
		cnt++;
	}
	return (true);
}

/*
** @brief TODO
** @param pipe TODO
** @param fds TODO
*/

void	manage_fds(int pipe[FD_SETSIZE + 3][2], t_list **fds)
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

void	manage_close(t_list **fds)
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
