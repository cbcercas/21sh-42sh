/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_modes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:38:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/18 12:38:50 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

void		raw_terminal_mode(void)
{
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	tattr.c_oflag &= ~(OPOST);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tgetent(NULL, get_var_value(get_envs(), "TERM"));
}

void		default_terminal_mode(void)
{
	struct termios	tattr;
	int				ret;

	ret = tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= (ECHO | ICANON | IEXTEN | ISIG);
	tattr.c_oflag |= (OPOST);
	if (!ret)
		tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
}

/*
** @brief         Stores the attributes to be restored later
**
** @param[in,out] data  Struct that will contain the data
**
** @return        void
*/

void		sh_store_tattr(t_sh_data *data)
{
	int				ttydevice;
	struct termios	save_tattr;

	ttydevice = STDIN_FILENO;
	if (!isatty(STDIN_FILENO))
	{
		data->tattr = NULL;
		return ;
	}
	if (tcgetattr(ttydevice, &save_tattr) != 0)
	{
		ft_dprintf(2, "%s: tcgetattr error when trying", PROGNAME);
		ft_dprintf(2, " to save terminal attributes\n");
		data->tattr = NULL;
		return ;
	}
	else if (!(data->tattr = (struct termios*)ft_memalloc(sizeof(struct
																	termios))))
		sh_exit_error("Error Malloc");
	ft_memcpy(data->tattr, &save_tattr, sizeof(struct termios));
}
