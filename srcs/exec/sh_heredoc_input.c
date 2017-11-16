/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_heredoc_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:18:46 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/15 19:18:47 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

void		mini_input(char *end, int pipe_fd)
{
	char *line;

	if (!end)
	{
		ft_dprintf(2, "%s: exec parser error \\n\n", PROGNAME);
		return ;
	}
	if (*is_in_pipe())
		ft_putstr("pipe ");
	ft_putstr("heredoc>");
	log_info("EXEC: HEREDOC word end = (%s)", end);
	while (get_next_line(0, &line))
	{
		if (line && ft_strequ(line, end))
			break ;
		ft_putendl_fd(line, pipe_fd);
		ft_strdel(&line);
		ft_putstr("heredoc>");
	}
	ft_strdel(&line);
}
