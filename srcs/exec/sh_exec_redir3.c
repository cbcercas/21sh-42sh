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

static void		sh_exec_greatand_push_dup2(int fd1, int fd2, t_list **fds)
{
	if (fd2 == -2)
	{
		if (fd1 != -1)
			exec_list_push(&fds[CLOSE], fd1);
		else
			exec_list_push(&fds[CLOSE], STDIN_FILENO);
		return ;
	}
	if (fd1 != -1)
		dup2(fd1, fd2);
	else
		dup2(STDIN_FILENO, fd2);
}

void			sh_exec_greatand_push_dup(int fd1, int fd2, t_cmd *item,
											t_list **fds)
{
	if (item && item->type == E_TOKEN_GREATAND)
	{
		if (fd2 == -2)
		{
			if (fd1 != -1)
				exec_list_push(&fds[CLOSE], fd1);
			else
				exec_list_push(&fds[CLOSE], STDOUT_FILENO);
			return ;
		}
		if (fd1 != -1)
		{
			(fds[fd1] ? ft_lstdel(&fds[fd1], &exec_list_nothing) : 0);
			log_info("REDIR fd =%d", fd1);
			exec_list_push(&fds[fd1], fd2);
		}
		else
		{
			fds[STDOUT_FILENO] = NULL;
			exec_list_push(&fds[STDOUT_FILENO], fd2);
		}
		return ;
	}
	sh_exec_greatand_push_dup2(fd1, fd2, fds);
}
