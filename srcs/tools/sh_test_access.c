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
	struct stat *buf;
	int		ret;

	if (!(buf = ft_secu_malloc_lvl(sizeof(*buf), M_LVL_FUNCT)))
		return (-2);
	ret = 0;
	ft_bzero(buf, sizeof(*buf));
	if (stat(filename, buf) == 0)
	{
		if (buf->st_mode & S_IXUSR)
			ret = 1;
		else
			ret = -1;
	}
	ft_secu_free(buf);
	return (ret);
}
