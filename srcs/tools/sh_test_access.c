/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_test_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:00:31 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/09 18:02:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>

int	sh_test_access(char const *filename)
{
	struct stat buf;

	if (stat(filename, &buf) == 0)
	{
		if (buf.st_mode & S_IXUSR)
			return (0);
		else
			return (1);
	}
	else
		return (2);
}
