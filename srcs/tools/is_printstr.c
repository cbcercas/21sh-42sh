/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:10:45 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/20 16:11:09 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <tools/tools.h>

BOOL        is_printstr(char const *line)
{
    while (line && ft_isprint(*line))
        line++;
    return (*line != '\0') ? false :true;
}
