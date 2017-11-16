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

void	raw_terminal_mode(void)
{
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	tattr.c_oflag &= ~(OPOST);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tgetent(NULL, getenv("TERM"));

	return;
}

void	default_terminal_mode(void)
{
	struct termios	tattr;
	int 			ret;

	ret = tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= (ECHO | ICANON | IEXTEN | ISIG);
	tattr.c_oflag |= ( OPOST);
	if (!ret)
		tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);

	return;
}

/*
** @brief         Stores the attributes to be restored later
**
** @param[in,out] data  Struct that will contain the data
**
** @return        void
*/

void				sh_store_tattr(t_sh_data *data)
{
	int				ttydevice;
	struct termios	save_tattr;

	ttydevice = STDOUT_FILENO;
	if (!isatty(STDOUT_FILENO))
	{
		data->tattr = NULL;
		return ;
	}
	if (tcgetattr(ttydevice, &save_tattr) != 0)
	{
		ft_printf("%s: tcgetattr error when trying", PROGNAME);
		ft_printf(" to save terminal attributes\n");
		data->tattr = NULL;
		return ;
	}
	else if ((data->tattr = (struct termios*)malloc(sizeof(struct termios))))
		ft_memcpy(data->tattr, &save_tattr, sizeof(struct termios));
	return ;
}