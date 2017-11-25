/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_redir2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 19:50:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/16 19:50:43 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

static BOOL		sh_exec_greatand_open_fd1(int *fd1, t_cmd *item, int *pos)
{
	if (!item || ft_tablen(item->av) < 2)
		return (false);
	if (ft_isdigit(item->av[0][0]))
	{
		*pos = *pos + 1;
		if (ft_isdigit(item->av[0][0]) && ft_strlen(item->av[0]) == 1)
			*fd1 = ft_atoi(item->av[0]);
		else
			return (false);
	}
	return (true);
}

static BOOL		sh_exec_greatand_open(int *fd1, int *fd2, t_cmd *item)
{
	int		pos;

	pos = 0;
	*fd2 = -1;
	*fd1 = -1;
	if (!sh_exec_greatand_open_fd1(fd1, item, &pos))
		return (false);
	if (ft_strequ(item->av[pos + 1], "-"))
		*fd2 = -2;
	else if (ft_isdigit_str(item->av[pos + 1]))
	{
		if (check_fd(ft_atoi(item->av[pos + 1])))
			*fd2 = ft_atoi(item->av[pos + 1]);
		else
			return (false);
	}
	else if (ft_atoi(item->av[0]) == 1 || pos == 0)
		*fd2 = open(item->av[pos + 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		ft_dprintf(2, "%s: %s ambiguous redirect\n", PROGNAME, item->av[pos + 1]);
	return (true);
}

int				sh_exec_greatand(t_sh_data *data, t_btree *ast, t_list **fds)
{
	int		fd1;
	int		fd2;
	t_cmd	*item;

	if (!ast)
		return (*get_cmd_ret());
	item = (t_cmd *)ast->item;
	if (!sh_exec_greatand_open(&fd1, &fd2, item))
		return ((*get_cmd_ret() = EXIT_FAILURE));
	if (fd2 != -1)
	{
		sh_exec_greatand_push_dup(fd1, fd2, item, fds);
		sh_process_exec(data, ast->left, fds);
	}
	return (*get_cmd_ret());
}
