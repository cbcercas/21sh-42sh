/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:10:45 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 12:18:15 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>

/*
** @brief Returns the value of last command based on wait
 *
** @param status return of wait
 *
** @return Returns the return value
*/

int		sh_return_cmd(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
