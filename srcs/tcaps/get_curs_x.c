/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curs_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 19:29:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/19 12:58:10 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <core/tcaps.h>

int		get_curs_x(void)
{
	char b[(MAX_KEY_STRING_LEN * 2) + 1];
	int i;
	struct termios	tattr;

	i = 0;
	tcgetattr(STDIN_FILENO, &tattr);
	raw_terminal_mode();
	bzero(b, MAX_KEY_STRING_LEN * 2);
	tputs(tgetstr("mk", NULL), 1, ft_putchar2);
	while (42)
	{
		bzero(b, MAX_KEY_STRING_LEN * 2);
		ft_putchar(27);
		ft_putstr("[6n");
		read(STDIN_FILENO, b, MAX_KEY_STRING_LEN * 2);
		b[MAX_KEY_STRING_LEN] = 0;
		if ((b[0] == 27) && (b[1] == '[') && (b[ft_strlen(b) - 1] == 'R'))
			break;
	}
	tputs(tgetstr("me", NULL), 1, ft_putchar2);
	while (b[i] != ';' && b[i])
		i++;
	if(b[i])
		i++;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	return (ft_atoi(b + i));
}
