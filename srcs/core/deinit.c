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

#include <core/deinit.h>

/**
 * @brief      Frees the data stored
 *             in t_sh_data *data
 *
 * @param[in]  data  The struct containing the data to be freed
 *
 * @return     void
 */

void		sh_data_free(t_sh_data *data)
{
	(void)data;
	return ;
}

/*
** sh_data_free
**TODO: Free local and apps environment variables.
**TODO: Free correctly data.
*/

/**
 * @brief      Restores the terminal attributes
 *             once the program is ended
 *
 * @param[in]  tattr  struct containing the current terminal attributes
 *
 * @return     int  Returns 0 if success and 1 otherwise
 */

int			sh_restore_tattr(struct termios *tattr)
{
	struct termios term;

	term = *tattr;
	free(tattr);
	tattr = NULL;
	if (isatty(0) && tcsetattr(STDIN_FILENO, TCSAFLUSH, &term) < 0)
	{
		ft_printf("%s: STDIO error while", PROGNAME);
		ft_printf(" restoring terminal attributes\n");
		return (1);
	}
	return (0);
}

/*
** TODO: Do something with the return values + logger
*/

/**
 * @brief      Uninitialize the program before exiting
 *
 * @param[in]  data  data needed to uninitialize
 *
 * @return     void
 */

void		sh_deinit(t_sh_data *data)
{
	sh_restore_tattr(data->tattr);
	//ft_putstr("\033[?1049l");
	sh_data_free(data);
}





/*
 * @brief
 *
 * @param[in]
 *
 * @return
 */
