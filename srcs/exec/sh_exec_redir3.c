/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_redir3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:48:58 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/15 18:49:09 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

/*
** @brief   push fd in fd list (less)
** @param  item    struct of command
** @param  fds     The list of fd
** @param  fd1      the first fd
** @param  fd2      the second fd
**
** @return
*/

static void		sh_exec_greatand_push_dup2(int fd1, int fd2, t_list **fds)
{
	if (fd2 == -2)
	{
		if (fd1 != -1)
			exec_list_push(&fds[CLOSE], (size_t)fd1);
		else
			exec_list_push(&fds[CLOSE], STDIN_FILENO);
		return ;
	}
	if (fd1 != -1)
	{
		(fds[fd1] ? ft_lstdel(&fds[fd1], &exec_list_nothing) : 0);
		exec_list_push(&fds[fd1], (size_t)fd2);
	}
	else
	{
		(fds[STDIN_FILENO] ? ft_lstdel(&fds[STDIN_FILENO], &exec_list_nothing)
						: 0);
		exec_list_push(&fds[STDIN_FILENO], (size_t)fd2);
	}
}

/*
** @brief   push fd in fd list
** @param  item    struct of command
** @param  fds     The list of fd
** @param  fd1      the first fd
** @param  fd2      the second fd
**
** @return
*/

void			sh_exec_greatand_push_dup(int fd1, int fd2, t_cmd *item,
											t_list **fds)
{
	if (item && item->type == E_TOKEN_GREATAND)
	{
		if (fd2 == -2)
		{
			if (fd1 != -1)
				exec_list_push(&fds[CLOSE], (size_t)fd1);
			else
				exec_list_push(&fds[CLOSE], STDOUT_FILENO);
			return ;
		}
		if (fd1 != -1)
		{
			(fds[fd1] ? ft_lstdel(&fds[fd1], &exec_list_nothing) : 0);
			exec_list_push(&fds[fd1], (size_t)fd2);
		}
		else
		{
			(fds[STDOUT_FILENO] ? ft_lstdel(&fds[STDOUT_FILENO],
											&exec_list_nothing) : 0);
			exec_list_push(&fds[STDOUT_FILENO], (size_t)fd2);
		}
		return ;
	}
	sh_exec_greatand_push_dup2(fd1, fd2, fds);
}
