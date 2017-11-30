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
	default_terminal_mode();
	ft_dprintf(STDERR_FILENO, "%s: read error\n", PROGNAME);
	raw_terminal_mode();
	return (false);
}

BOOL			sh_get_char(char *buff)
{
	char		tmp;
	int			cnt;
	int			ret;

	cnt = 0;
	if (read(STDIN_FILENO, &tmp, 1) == -1)
		return (read_error());
	ft_strncpy(buff++, &tmp, 1);
	if (tmp == 27)
	{
		while (cnt < 4 && (ret = read(STDIN_FILENO, &tmp, 1) != -1)  &&
			tmp != '\n' && !ft_isalpha((int)tmp))
		{
			ft_strncpy(buff++, &tmp, 1);
			cnt++;
		}
		if (cnt < 4)
			ft_strncpy(buff, &tmp, 1);
		else if (ret == -1)
			return (read_error());
	}
	return (true);
}