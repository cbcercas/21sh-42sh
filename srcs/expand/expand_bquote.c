/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:21:42 by mleroy            #+#    #+#             */
/*   Updated: 2017/12/08 14:27:38 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>
#include <exec/exec.h>

void		expand_bquote(t_string *str)
{
	int		tube[2];
//	char	*buffer;
	pid_t	pid;

	sh_pipe(tube);
	pid = sh_fork(E_PID_SHELL);
	if (pid > 0)
	{
		sh_wait(pid, 0);
		ft_printf("father is called here\n");
	}
	if (pid == 0)
	{
		dup2(STDOUT_FILENO, tube[0]);
		char	*board[4];
		board[0] = get_data(NULL)->cwd;
		board[1] = "-c";
		board[2] = ft_strndup_free(str->s, 1, str->len - 2, 0);
		ft_printf("board[2]=%s\n", board[2]);

		board[3] = NULL;

		ft_printf("son is called here\n");
		ft_putnstr(str->s, str->len);
		ft_putchar(10);
		//execve(tab)
		exit(EXIT_FAILURE);
	}
	//////////////////////////////////////////////////
//	while (get_next_line(tube[1], &buffer) == 1)
//	{
//		ft_printf("buffer=>%s\n", buffer);
//	}
}
