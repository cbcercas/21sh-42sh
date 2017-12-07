/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:21:42 by mleroy            #+#    #+#             */
/*   Updated: 2017/12/07 16:46:53 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

void		*expand_bquote(t_string *str)
{
	int		tube[2];
	char	buffer[4096];

	sh_pipe(tube);
	dup2(STDOUT_FILENO, tube[0]);
	//delete//////////////////////////////////////////
	ft_putnstr(str->s, str->len);
	ft_putchar(10);
	//////////////////////////////////////////////////
	while (get_next_line(tube[1], &buffer) == 1)
	{
		ft_printf("buffer=>%s\n", buffer);
	}
}
