/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdblfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:54:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/20 13:40:06 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>

void	ft_strdblfree(char **strdb)
{
	int		i;

	i = 0;
	if (!strdb)
		return ;
	while (strdb && strdb[i])
	{
		if (strdb[i])
			ft_strdel(&strdb[i]);
		i++;
	}
	free(strdb);
}
