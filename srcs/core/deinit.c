/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:30:34 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/02 15:31:32 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/data.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <ftprintf.h>
#include <core/progname.h>
#include <libft.h>

/*
** @brief      Restores the terminal attributes
**             once the program is ended
**
** @param[in]  tattr  struct containing the current terminal attributes
**
** @return     int  Returns 0 if success and 1 otherwise
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
** @brief      Uninitialize the program before exiting
**
** @param[in]  data  data needed to uninitialize
**
** @return     void
*/

void		sh_deinit(t_sh_data *data)
{
	sh_restore_tattr(data->tattr);
	ft_bzero(data, sizeof(data));
}
