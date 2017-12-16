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

/*
** @brief   search fd in fd list
** @param  fd_search   The fd to look for
** @param  fds         the list of fd
**
** @return true if fd_search is find, false otherwise
*/

static t_redir_fd		*check_fd_search(t_array *fds, int fd_search)
{
	size_t		cnt;
	t_redir_fd	*fd;

	cnt = 0;
	while (cnt < fds->used)
	{
		fd = (t_redir_fd *)array_get_at(fds, cnt);
		if (fd && ((!fd->close && fd->new_fd == fd_search) || fd->old_fd == fd_search))
			return (fd);
		cnt++;
	}
	return (NULL);
}

/*
** @brief   check if fd is open or if fd is on fds list + print errror
**
** @param  fds         the list of fd
** @param fd The curent fd
**
** @return true if fd is open, false otherwise
*/

BOOL			check_fd(int fd, t_array *fds)
{
	struct stat test;
	t_redir_fd	*find;

	if ((find = check_fd_search(fds, fd)) && !find->close)
		return (true);
	if (!fstat(fd, &test) && !find)
		return (true);
	ft_dprintf(2, "%s: %d: bad file descriptor\n", PROGNAME, fd);
	return (false);
}

/*
** @brief   find fd in heredoc
** @param item   The struct of command
**
** @return true return fd find
*/

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

/*
** @brief   open fd for exec redirection
**
** @param  ast     The AST (Analyse Syntax Tree[binary])
**
** @return fd find
*/

static int		sh_open_exec_type(t_cmd *item, int *pos)
{
	int		fd;

	fd = -1;
	if (!item || ft_tablen(item->av) < 2)
		return (fd);
	if (ft_isdigit(item->av[0][0]))
		*pos = *pos + 1;
	if (item->type == E_TOKEN_LESSGREAT && ft_strequ(item->av[*pos], ">"))
		fd = open(item->av[*pos + 1], O_CREAT | O_TRUNC | O_WRONLY , 0644);
	else if (item->type == E_TOKEN_LESSGREAT && ft_strequ(item->av[*pos], "<>"))
		fd = open(item->av[*pos + 1], O_CREAT | O_RDWR , 0644);
	else if (item->type == E_TOKEN_LESSGREAT)
		fd = open(item->av[*pos + 1],O_RDONLY, 0644);
	else if (item->type == E_TOKEN_DGREAT)
		fd = open(item->av[*pos + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (item->type == E_TOKEN_DLESS)
		fd = here_find_fd(item);
	return (fd);
}

int				sh_open_exec(t_btree *ast)
{
	t_cmd		*item;
	int			fd;
	int			pos;

	if (!ast || ast->right)
		return (-1);
	item = (t_cmd *)ast->item;
	pos = 0;
	fd = sh_open_exec_type(item, &pos);
	if (fd == -1 && access(item->av[pos + 1], F_OK))
		ft_dprintf(2, "%s: %s: No such file or directory\n", PROGNAME,
				item->av[pos + 1]);
	else if (fd == -1)
		ft_dprintf(2, "%s: permission denied: %s\n", PROGNAME, item->av[pos + 1]);
	return (fd);
}
