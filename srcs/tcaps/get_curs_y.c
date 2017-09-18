/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curs_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 19:29:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/18 21:06:55 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <core/tcaps.h>

int		get_curs_y(void)
{
	char b[41];
	int i;

	i = 0;
	bzero(b, 41);
	while (b[0] != 27 && b[1] != '[')
	{
		bzero(b, 41);
		ft_putchar(27);
		ft_putstr("[6n");
		read(0, b, 40);
	}
	while (!ft_isdigit(b[i]) && b[i])
		i++;
  //  tputs(tgetstr("ce", NULL), 0, &ft_putchar2);
	return (ft_atoi(b + i));
}
