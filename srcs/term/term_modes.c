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