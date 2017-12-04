/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:30:45 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/15 19:21:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

BOOL			check_fd_search(t_list **fds, int fd_search)
{
	int		cnt;

	cnt = 0;
	log_info("EXEC: sh_exec_restore_fd");
	while (cnt < FD_SETSIZE)
	{
		if ((cnt == fd_search && fds[cnt]) ||\
		(fds[cnt] && (int)fds[cnt]->content_size == fd_search))
			return (true);
		cnt++;
	}
	return (false);
}

BOOL			check_fd(int fd, t_list **fds)
{
	struct stat test;

	if (!fstat(fd, &test) || check_fd_search(fds, fd))
		return (true);
	ft_dprintf(2, "%s: %d: bad file descriptor\n", PROGNAME, fd);
	return (false);
}

static int		here_find_fd(t_cmd *item)
{
	int			fd;
	struct stat	test;

	fd = ft_atoi(item->av[0]);
	if (ft_isdigit(item->av[0][0]))
	{
		if (!fstat(fd, &test))
			return (fd);
		else
		{
			ft_dprintf(2, "%s: %d: bad file descriptor\n", PROGNAME, fd);
			return (-1);
		}
	}
	return (STDOUT_FILENO);
}

int				sh_open_exec(t_btree *ast)
{
	t_cmd	*item;
	int		fd;
	int		pos;

	if (!ast || ast->right)
		return (-1);
	item = (t_cmd *)ast->item;
	pos = 0;
	fd = -1;
	if (!item || ft_tablen(item->av) < 2)
		return (fd);
	if (ft_isdigit(item->av[0][0]))
		pos++;
	if (item->type == E_TOKEN_LESSGREAT && ft_strequ(item->av[pos], ">"))
		fd = open(item->av[pos + 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (item->type == E_TOKEN_LESSGREAT)
		fd = open(item->av[pos + 1], O_RDWR, 0644);
	else if (item->type == E_TOKEN_DGREAT)
		fd = open(item->av[pos + 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (item->type == E_TOKEN_DLESS)
		fd = here_find_fd(item);
	if (fd == -1)
		ft_dprintf(2, "%s: %s: No such file or directory\n", PROGNAME,
				item->av[pos + 1]);
	return (fd);
}
