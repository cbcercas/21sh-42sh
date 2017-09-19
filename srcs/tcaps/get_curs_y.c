/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curs_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 19:29:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/19 11:46:43 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <core/tcaps.h>

int		get_curs_y(void)
{
	char b[(MAX_KEY_STRING_LEN * 2) + 1];
	int i;
	size_t count;

	i = 0;
	count = 0;
	bzero(b, MAX_KEY_STRING_LEN * 2);
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
	while (!ft_isdigit(b[i]) && b[i])
		i++;
	return (ft_atoi(b + i));
}
