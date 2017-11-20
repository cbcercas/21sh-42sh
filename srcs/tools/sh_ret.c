/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:10:45 by gpouyat           #+#    #+#             */
/*   Updated: 2017/08/01 15:30:32 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>

/*
** @brief TODO
** @param status TODO
** @return TODO
*/

int sh_return_cmd(int status)
{
    if(WIFEXITED(status))
        return(WEXITSTATUS(status));
    return(0);
}
