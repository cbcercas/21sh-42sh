/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiforge <guiforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:11:19 by guiforge          #+#    #+#             */
/*   Updated: 2017/11/29 16:11:20 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>
#include <core/tcaps.h>

static BOOL		read_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s: read error\n", PROGNAME);
	return (false);
}

BOOL			sh_get_char(char *buff)
{
	char		tmp;
	int			cnt;

	cnt = 0;
	if (read(STDIN_FILENO, &tmp, 1) == -1)
		return (read_error());
	ft_strncpy(buff, &tmp, 1);
	buff++;
	if (tmp == 27)
	{
		while (cnt < 4 && read(STDIN_FILENO, &tmp, 1) != -1  &&
			   tmp != '\n' && !ft_isalpha((int)tmp))
		{
			log_dbg1("capt %c", tmp);
			ft_strncpy(buff, &tmp, 1);
			buff++;
			cnt++;
		}
		if (cnt < 4 && tmp != '\n')
			ft_strncpy(buff, &tmp, 1);
		else if (!ft_isalpha((int) tmp))
			return (read_error());
	}
	return (true);
}