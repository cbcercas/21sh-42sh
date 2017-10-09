/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:34:58 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/04 18:58:08 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {

	pid_t pid;
	int pipout[2];
	int piperr[2];
	int status;
	char buf[2];

/*
** faire les pipes
*/
	pipe(pipout);
	pipe(piperr);

/*
** EXEC
*/
	if (!(pid = fork()))
	{

		close(pipout[0]);
		dup2(pipout[1], STDOUT_FILENO);

		execve("/bin/ls", argv, NULL);
	}

	wait(&status);
/*
** ECRIRE
*/
	close(pipout[1]);
	while(read(pipout[0], buf, 1))
	{
		write(STDOUT_FILENO, buf, 1);
	}
	return 0;
}
