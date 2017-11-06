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

#include <sys/wait.h>

//TODO Rename this
int sh_ret(int status)
{
    if(WIFEXITED(status))
        return(WEXITSTATUS(status));
    return(0);
}
