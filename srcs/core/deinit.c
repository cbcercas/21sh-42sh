/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:33:26 by gpouyat           #+#    #+#             */
/*   Updated: 2017/12/09 15:33:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <logger.h>
#include <termios.h>
#include <stdlib.h>
#include <core/progname.h>
#include <libft.h>
#include <ftprintf.h>
#include <core/data.h>

/*
** @brief      Restores the terminal attributes once the program is finished
**
** @param[in]  tattr  Structure containing the current terminal attributes
**
** @return     int  Returns 0 if successful, and will return 1 otherwise.
*/

int			sh_restore_tattr(struct termios *tattr)
{
	struct termios term;

	if (!tattr)
	{
		log_warn("No terminal attributes");
		return (1);
	}
	term = *tattr;
	ft_memdel((void **)&tattr);
	tattr = NULL;
	if (isatty(0) && tcsetattr(STDIN_FILENO, TCSAFLUSH, &term) < 0)
	{
		ft_dprintf(2, "%s: STDIN error while", PROGNAME);
		ft_dprintf(2, " restoring terminal attributes\n");
		log_warn("error while restoring terminal attributes");
		return (1);
	}
	return (0);
}

/*
** @brief      uninitializes the program before exiting
**
** @param[in]  data  This structure contains the shell's data needed to deinit.
*/

void		sh_deinit(t_sh_data *data)
{
	sh_restore_tattr(data->tattr);
	ft_bzero(data, sizeof(data));
}
