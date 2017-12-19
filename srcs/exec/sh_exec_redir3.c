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
**
** @param  fds     The list of fd
** @param  fd1      the first fd
** @param  fd2      the second fd
*/

static void		sh_exec_greatand_push_dup2(int fd1, int fd2, t_array *fds)
{
	if (fd2 == -2)
	{
		if (fd1 != -1)
			sh_exec_new_redir_fd(fds, fd1, -1, true);
		else
			sh_exec_new_redir_fd(fds, STDIN_FILENO, -1, true);
		return ;
	}
	if (fd1 != -1)
		sh_exec_new_redir_fd(fds, fd1, fd2, false);
	else
		sh_exec_new_redir_fd(fds, STDIN_FILENO, fd2, false);
}

/*
** @brief   push fd in fd list
**
** @param  item    struct of command
** @param  fds     The list of fd
** @param  fd1      the first fd
** @param  fd2      the second fd
*/

void			sh_exec_greatand_push_dup(int fd1, int fd2, t_cmd *item,
																t_array *fds)
{
	if (item && item->type == E_TOKEN_GREATAND)
	{
		if (fd2 == -2)
		{
			if (fd1 != -1)
				sh_exec_new_redir_fd(fds, fd1, -1, true);
			else
				sh_exec_new_redir_fd(fds, STDOUT_FILENO, -1, true);
			return ;
		}
		if (fd1 != -1)
			sh_exec_new_redir_fd(fds, fd1, fd2, false);
		else
			sh_exec_new_redir_fd(fds, STDOUT_FILENO, fd2, false);
		return ;
	}
	sh_exec_greatand_push_dup2(fd1, fd2, fds);
}
