/* ************************************************************************** */ 
/*                                                                            */ 
/*                                                        :::      ::::::::   */ 
/*   is_printstr.c                                      :+:      :+:    :+:   */ 
/*                                                    +:+ +:+         +:+     */ 
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */ 
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2017/07/20 16:10:45 by gpouyat           #+#    #+#             */ 
/*   Updated: 2017/12/09 18:27:23 by gpouyat          ###   ########.fr       */
/*                                                                            */ 
/* ************************************************************************** */ 
 
#include <tools/tools.h> 

/*
** @brief Checks if a given string is printable
**
** @param line String to be checked
**
** @return Returns true if the string is printable, false otherwise
*/

BOOL	is_printstr(char const *line)
{
	if (!line)
		return (false);
	while (line && (ft_isprint(*line) || *line == '\n' || *line == '\t'))
		line++;
	return (line && *line != '\0') ? false : true;
}

