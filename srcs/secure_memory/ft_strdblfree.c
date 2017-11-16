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

#include <secure_memory/secure_memory.h>

/*
** @brief Frees securely a double string (`char **`)
** @param strdb The double string to be freed
*/

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
